###########################################################
# Assignment #: 2
#  Name: Vincent Latona
#  Description: This MIPS program will perform arithmetic 
#				operations on 2 integers.
###########################################################

#Data declarations for the given program
					.data
num1: .word 78591 #num1 = 78591
num2: .word 0xD5A #num2 = 3418
msg1: .asciiz "num1 is: "
msg2: .asciiz "\nnum2 is : "
msg3: .asciiz "\nnum1+num2 = "
msg4: .asciiz "\nnum1-num2 = "

#Program running function declaration
					.text
					.globl		main

#Main function
main:
		#Display num1
		la $a0, msg1 
		li $v0, 4 #Print msg1
		syscall

		la $t0, num1 #Load addr of num1 into $t0
		lw $s0, 0($t0) #$s0 = num1

		move $a0, $s0 #Move num1 to $a0
		li $v0, 1 #Display num1
		syscall

		#Display num2
		la $a0, msg2 
		li $v0, 4 #Print msg2
		syscall

		la $t1, num2 #Load addr of num1 into $t1
		lw $s1, 0($t1) #$s1 = num2

		move $a0, $s1 #Move num2 to $a0
		li $v0, 1 #Display num2
		syscall

		#Display sum
		la $a0, msg3
		li $v0, 4 #Print msg3
		syscall

		add $s2, $s0, $s1 #$s2 = num1+num2

		move $a0, $s2 #Move sum to $a0
		li $v0, 1 #Display sum
		syscall

		#Display difference
		la $a0, msg4
		li $v0, 4 #Print msg4
		syscall

		sub $s3, $s0, $s1 #$s3 = num1-num2

		move $a0, $s3 #Move sum to $a0
		li $v0, 1 #Display sum
		syscall

		jr $ra #Return at the end of main