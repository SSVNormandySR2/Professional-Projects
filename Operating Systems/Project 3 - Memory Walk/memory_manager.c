/*
 * Vincent Latona
 * April 21, 2022
 * This module performs Memory Management analysis.
 */
 
#include <linux/module.h> //Module libraries
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/kthread.h>
#include <linux/timekeeping.h>
#include <linux/proc_fs.h>
#include <linux/ktime.h>
#include <linux/time.h>
#include <linux/timer.h>
#include <linux/slab.h>
#include <linux/hrtimer.h> //New includes
#include <linux/mm.h>
#include <linux/sched/mm.h>

static int pid = 0; //Initialize parameters
module_param(pid, int, 0); //Associate parameter

unsigned long timer_interval_ns = 10e9; //10 sec timer
static struct hrtimer hr_timer; //HRTimer
static struct task_struct* task; //Task for VMA use
static long int wss = 0; //Set size variables
static long int rss = 0;
static long int swap = 0;

/*
 * This function walks the Page Table
 */
pte_t* pageWalk(struct mm_struct* mm, unsigned long addr)
{
	pgd_t* pgd; //Declare local level variables
	p4d_t* p4d;
	pud_t* pud;
	pmd_t* pmd;
	pte_t* pte;
	
	pgd = pgd_offset(mm, addr); //Get pgd
	if(pgd_none(*pgd) || pgd_bad(*pgd)) //Verify pgd
	{
		return NULL; //Indicate error
	}
	
	p4d = p4d_offset(pgd, addr); //Get p4d
	if(p4d_none(*p4d) || p4d_bad(*p4d)) //Verify p4d
	{
		return NULL; //Indicate error
	}
	
	pud = pud_offset(p4d, addr); //Get pud
	if(pud_none(*pud) || pud_bad(*pud)) //Verify p4d
	{
		return NULL; //Indicate error
	}
	
	pmd = pmd_offset(pud, addr); //Get pmd
	if(pmd_none(*pmd) || pmd_bad(*pmd)) //Verify pmd
	{
		return NULL; //Indicate error
	}
	
	pte = pte_offset_map(pmd, addr); //Get pte
	if(!pte) //Verify pte
	{
		return NULL; //Indicate error
	}
	
	return pte; //Return found PTE
}

/*
 * This function clears the accessed bit of a table entry
 */
int ptep_test_and_clear_young(struct vm_area_struct* vma, unsigned long addr, pte_t* ptep)
{
	int bit = 0; //Initialize access bit state
	if(pte_young(*ptep)) //Young PTE case
	{
		bit = test_and_clear_bit(_PAGE_BIT_ACCESSED, (unsigned long*) &ptep->pte); //Clear bit
	}
	return bit; //Return previous access bit state
}

/*
 * This function executes timing and set size calculation
 */
enum hrtimer_restart timer_callback(struct hrtimer* timer_for_restart)
{
	ktime_t currtime, interval; //Define local variables
	currtime = ktime_get(); //Get current time
	interval = ktime_set(0, timer_interval_ns); //Set interval
	hrtimer_forward(timer_for_restart, currtime, interval); //Advance expiration
	struct mm_struct* mm = task->mm; //Get current MM pointer
	if(mm != NULL) //MM
	{
		struct vm_area_struct* vma = mm->mmap; //Get VMA pointer
		while(vma != NULL) //Iterate VMA
		{
			unsigned long addr = vma->vm_start; //Initialize logical address
			while(addr < vma->vm_end) //Iterate addr
			{
				pte_t* pte = pageWalk(mm, addr); //Walk page
				if(pte != NULL) //RSS case
				{
					rss++; //Increase RSS
					if(pte_young(*pte)) //WSS case
					{
						wss++; //Increase WSS
						ptep_test_and_clear_young(vma, addr, pte); //Test and clear accessed bit
					}
				}
				else //SWAP case
				{
					swap++; //Increase SWAP
				}
				addr = addr + PAGE_SIZE; //Iterate addr
			}
			vma = vma->vm_next; //Iterate
		}
		
	}
	wss = (wss*PAGE_SIZE) / 1024; //Complete measurements
	rss = (rss*PAGE_SIZE) / 1024;
	swap = (swap*PAGE_SIZE) / 1024;
	printk("PID %d: RSS=%ld KB, SWAP=%ld KB, WSS=%ld KB\n", pid, rss, swap, wss); //Display set sizes
	wss = 0; //Reset measurements
	rss = 0;
	swap = 0;
	return HRTIMER_RESTART; //Return from function
}

/*
 * This function initializes the module
 */
static int __init memory_manager_start(void)
{
	for_each_process(task) //Process iterator
	{
		if(task->pid == pid) //PID found
		{
			break; //Stop iterator
		}
	}
	ktime_t ktime = ktime_set(0, timer_interval_ns); //Set ktime
	hrtimer_init(&hr_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL); //Init timer
	hr_timer.function = &timer_callback; //Set timer function
	hrtimer_start(&hr_timer, ktime, HRTIMER_MODE_REL); //Start timer
	return 0; //Return from function
}

/*
 * This function ends the module
 */
static void __exit memory_manager_end(void)
{
	hrtimer_cancel(&hr_timer); //Stop timer
	return; //Return from function
}
 
module_init(memory_manager_start); //Start module
module_exit(memory_manager_end); //End module

MODULE_LICENSE("GPL"); //Module information
MODULE_AUTHOR("Vincent Latona, Vyom Khare, Amroger Singh");
MODULE_DESCRIPTION("This module performs Memory Management analysis.");
MODULE_VERSION("1.0");
