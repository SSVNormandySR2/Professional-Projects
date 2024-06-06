###########################################################
# Assignment #: 3
#  Name: Vincent Latona
#  Description: This MIPS program will read user inputs from
#				the keyboard and perform operations on them.
###########################################################

#Data declarations for the given program
					.data
msg1: .asciiz "Enter a value:\n" #Input text prompts
msg2: .asciiz "Enter another value:\n"
msg3: .asciiz "Enter one more value:\n"

msg4: .asciiz "num3 + num1 = " #Output text prompts
msg5: .asciiz "\nnum1 - num2 = "
msg6: .asciiz "\nnum3 * num4 = "
msg7: .asciiz "\nnum2 / num1 = "
msg8: .asciiz "\nnum1 % num4 = "
msg9: .asciiz "\n((num4 % num1) * 5) - (num2 / num3) = "

#Program running function declaration
					.text
					.globl		main

#Main function
main:
		#Input prompts
		la $a0, msg1 
		li $v0, 4 #Display prompt 1
		syscall
		li $v0, 5 #Read integer input
		syscall
		move $s0, $v0 #$s0 = num1

		la $a0, msg2 
		li $v0, 4 #Display prompt 2
		syscall
		li $v0, 5 #Read integer input
		syscall
		move $s1, $v0 #$s1 = num2

		la $a0, msg3
		li $v0, 4 #Display prompt 3
		syscall
		li $v0, 5 #Read integer input
		syscall
		move $s2, $v0 #$s2 = num3

		la $a0, msg3 
		li $v0, 4 #Display prompt 4
		syscall
		li $v0, 5 #Read integer input
		syscall
		move $s3, $v0 #$s2 = num4

		#Summation
		add $t0, $s0, $s2 #$t0 = num1 + num3

		la $a0, msg4 
		li $v0, 4 #Display sum prompt
		syscall
		move $a0, $t0 #$a0 = sum
		li $v0, 1 #Display sum
		syscall

		#Subtraction
		sub $t0, $s0, $s1 #$t1 = num1 - num2

		la $a0, msg5
		li $v0, 4 #Display difference prompt
		syscall
		move $a0, $t0 #$a0 = difference
		li $v0, 1 #Display difference
		syscall

		#Multiplication
		mult $s2, $s3 #num3 * num4

		la $a0, msg6
		li $v0, 4 #Dispaly product prompt
		syscall
		mflo $a0 #$a0 = lo product
		li $v0, 1 #Display lo product
		syscall

		#Division
		div $s1, $s0 #num2 / num1

		la $a0, msg7
		li $v0, 4 #Display integer quotient prompt
		syscall
		mflo $a0 #$a0 = integer quotient
		li $v0, 1 #Display integer quotient
		syscall

		#Remainder
		div $s0, $s3 #num1 % num4

		la $a0, msg8
		li $v0, 4 #Display remainder prompt
		syscall
		mfhi $a0 #$a0 = remainder
		li $v0, 1 #Display remainder
		syscall

		#((num4 % num1) * 5) - (num2 / num3)
		div $s1, $s2 # num2 / num3
		mflo $t0 #$t0 = integer quotient

		div $s3, $s0 #num4 % num1
		mfhi $t1 #$t1 = remainder

		addi $t2, $zero, 5 #Constant 5

		mult $t1, $t2 #(num4 mod num1) * 5
		mflo $t1 #Move to $t2

		sub $t0, $t1, $t0 #Final answer

		la $a0, msg9
		li $v0, 4 #Display equation prompt
		syscall
		move $a0, $t0 #$a0 = answer
		li $v0, 1 #Display equation answer
		syscall

		jr $ra #Return at the end of main