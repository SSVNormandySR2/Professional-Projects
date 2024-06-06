/*
Vincent Latona
This program tests a new system call.
*/

//Import necessary libraries
#include<stdio.h>
#include<linux/kernel.h>
#include<sys/syscall.h>
#include<unistd.h>

#define __NR_my_syscall 449

//Main function to call system call
int main()
{
	long int call = syscall(__NR_my_syscall);
	printf("System call sys_my_syscall returned %ld\n", call);
	return 0;
}//End of function main
