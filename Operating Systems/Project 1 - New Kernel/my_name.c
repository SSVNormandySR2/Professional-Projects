/*
Vincent Latona
January 27, 2022
This program is meant to print "Vincent Latona"
in /var/log/messages.
*/

//Import necessary libraries
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

//Module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vincent Latona");
MODULE_DESCRIPTION("This module prints a name in the linux kernel log.");
MODULE_VERSION("1.0");

//This function starts the module
static int __init my_name_start(void)
{
	printk(KERN_INFO "Vincent Latona\n");
	return 0;
}//End of function my_name_start

//This function ends the module
static void __exit my_name_end(void)
{
	printk(KERN_INFO "Module successfully removed!\n");
	return;
}//End of function my_name_end

//Start and end the module
module_init(my_name_start);
module_exit(my_name_end);
