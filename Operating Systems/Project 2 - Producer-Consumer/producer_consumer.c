/*
 * Vincent Latona
 * Vyom Khare
 * Amroger Singh
 * March 24, 2022
 * This program is intended to solve the
 * producer-consumer problem with semaphores.
 */

#include <linux/module.h> //Module libraries
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/semaphore.h>
#include <linux/kthread.h>
#include <linux/timekeeping.h>
#include <linux/proc_fs.h>
#include <linux/ktime.h>
#include <linux/time.h>
#include <linux/timer.h>
#include <linux/slab.h>

/*
 * Macro for array-size
 */
#define BUFFER_SIZE 55

/*
 * Struct for process information
 */
struct process
{
    struct task_struct* task; //Task pointer
    int itemNum; //Item number
};

/*
 * Global variable declarations
 */
static int uid = 0; //Parameters for module
static int buff_size = 1;
static int p = 0;
static int c = 0;

module_param(uid, int, 0); //Parameter associations
module_param(buff_size, int, 0);
module_param(p, int, 0);
module_param(c, int, 0);

static unsigned int totalTime = 0; //Total elapsed time of all processes
static int in = 0; //Index of add
static int out = 0; //Index of remove
static int totalProcs = 0; //Complete indicator
static struct process buffer[BUFFER_SIZE]; //Stack for processes
static struct task_struct* producer; //Create producer thread
static struct task_struct* consumer; //Create consumer thread
static struct semaphore mutex; //Semaphore creation
static struct semaphore empty;
static struct semaphore full;

/*
 * This function executes producer functionality
 */
static int producer_function(void* arg)
{
    int itemCount = 0; //Local item counter
    int buffFull = 0; //Full buffer indictor
    struct task_struct* list; //Produce iterator
    struct task_struct* counter; //Counting iterator
    for_each_process(counter) //Iterate to count
    {
    	if(counter->cred->uid.val == uid) //Find new processes
    	{
    		totalProcs++; //Count added processes
    	}
    }
    while(!kthread_should_stop()) //Run thread
    {
    	for_each_process(list) //Iterate through new processes to produce
    	{
    		if(buffFull == 1) //No consumer/full case
    		{
    			break; //Break iterator
    		}
    		else if(list->cred->uid.val == uid) //Find UID
    		{
    			itemCount++; //Increment item count
    			down_interruptible(&empty); //Check if buffer full
    			down_interruptible(&mutex); //Check if CS is clear
    			while(buffer[in].itemNum != -1) //Find valid index
    			{
    				in = ((in + 1) % buff_size); //Go to next index
    			}
    			int index = in; //Get index to add to
    			struct process proc; //Define and initialize local process
    			proc.task = list;
    			proc.itemNum = itemCount;
    			buffer[in] = proc; //Produce
    			in = ((in + 1) % buff_size); //Iterate to next index
    			if(c < 1 && in == 0) //Full buffer case
    			{
    				buffFull = 1; //Indicate full buffer
    			}
    			up(&mutex); //Clear CS
    			up(&full); //Signal consumers
    			printk("[%s] Produced Item#-%d at buffer index:%d for PID:%d\n", current->comm, itemCount, index, proc.task->pid); //Added message
    		}
    	}
    	kthread_stop(current); //Stop thread
    }
    return 0; //Return from function
}

/*
 * This function executes consumer functionality
 */
static int consumer_function(void* arg)
{
    if(p < 1) //No producer case
    {
    }
    else //Producer case
    {
    	while(!kthread_should_stop()) //Run thread
    	{
    		if(totalProcs == 0) //All processes consumed
    		{
    			kthread_stop(current); //Stop thread
    		}
    		down_interruptible(&full); //Check if empty
    		down_interruptible(&mutex); //Check if CS is clear
    		while(buffer[out].itemNum == -1) //Find valid index
    		{
    			out = ((out + 1) % buff_size); //Go to next index
    		}
    		int index = out; //Get index to remove from
    		struct process proc = buffer[out]; //Consume 
    		buffer[out].itemNum = -1; //Indicate consumed
    		out = ((out + 1) % buff_size); //Iterate to next index
    		totalProcs--; //Decrement remaining processes
    		up(&mutex); //Clear CS
    		up(&empty); //Signal producers
    		unsigned int secTime = ((ktime_get_ns() - proc.task->start_time)/1000000000); //Get seconds
    		unsigned int minTime = (secTime/60); //Get mins
    		unsigned int hrTime = (minTime/60); //Get hours
    		totalTime = totalTime + secTime; //Add to total elapsed time
    		printk("[%s] Consumed Item#-%d on buffer index:%d PID:%d Elapsed Time-%u:%u:%u\n", current->comm, proc.itemNum, index, proc.task->pid, hrTime, minTime, secTime); //Removed message
    	}
    }
    return 0;
}

/*
 * This function starts the module
 */
static int __init producer_consumer_start(void)
{
    sema_init(&mutex, 1); //Initialize semaphores
    sema_init(&empty, buff_size);
    sema_init(&full, 0);
    int a = 0; //Looping variable
    while(a < buff_size) //Initialize processes in buffer
    {
        struct process proc; //Create process struct
        proc.task = NULL; //NULL for task
        proc.itemNum = -1; //-1 for initial item number
        buffer[a] = proc; //Add process to buffer
        a++; //Increment
    }
    a = 0; //Reset
    if(p == 1) //Producer case
    {
    	producer = kthread_run(producer_function, NULL, "Producer-1"); //Run thread
    }
    while(a < c) //Consumers case
    {
    	consumer = kthread_run(consumer_function, NULL, "Consumer-1"); //Run thread
    	a++; //Iterate
    }
    return 0; //Return from function
}

/*
 * This function ends the module
 */
static void __exit producer_consumer_end(void)
{
    int a = 0; //Looping variable
    while(a < buff_size) //Wake-up iterator
    {
    	up(&mutex); //Signal semaphores
    	up(&empty);
    	up(&full);
    	a++; //Iterate and repeat
    }
    unsigned int secTime = (totalTime % 60); //Get total seconds
    unsigned int minTime = (totalTime/60); //Get total minutes
    unsigned int hrTime = (minTime/60); //Get total hours
    printk("The total elapsed time of all processes for UID %d is %u:%u:%u\n", uid, hrTime, minTime, secTime); //Print total time
    return; //Return from function
}

module_init(producer_consumer_start); //Start module
module_exit(producer_consumer_end); //End module

MODULE_LICENSE("GPL"); //Module information
MODULE_AUTHOR("Vincent Latona, Vyom Khare, Amroger Singh");
MODULE_DESCRIPTION("This module solves the producer-consumer problem.");
MODULE_VERSION("1.0");
