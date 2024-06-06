/*
Vincent Latona
This system call prints a message
to the linux kernel log.
*/

//Import necessary libraries
#include<linux/kernel.h>
#include<linux/syscalls.h>

//This function prints a message to the kernel log
SYSCALL_DEFINE0(my_syscall)
{
	printk("This is the new system call Vincent Latona implemented.\n");
	return 0;
}//End of function sys_my_syscall
