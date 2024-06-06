###########################################################
# Assignment #: 7
#  Name: Vincent Latona
#  Description: This MIPS program demonstrates a recursive 
#				function that has 2 recursive calls.
###########################################################

#Data declarations for the given program
					.data
msg1: .asciiz "Enter an integer:\n"
msg2: .asciiz "The solution is: "

#Program running function declaration
					.text
					.globl		main

#Main function
main:
			#Display integer prompt and accept input
			la $a0, msg1
			li $v0, 4 #Prompt user for input
			syscall
			li $v0, 5 #Read input
			syscall
			move $a1, $v0 #Store for parameter pass

			#Save $ra before function call
			addi $sp, $sp, -4
			sw $ra, 0($sp)

			jal function1 #Call recursive function

			#Load $ra back before end of main
			lw $ra 0($sp)
			addi $sp, $sp, 4

			#Display output from recursive function
			la $a0, msg2
			li $v0, 4 #Display message before result
			syscall
			move $a0, $v1 
			li $v0, 1 #Display recursive output
			syscall

			jr $ra #Return from end of main

###########################################################
#Procedure/Function: function1
#Description: This function models the recursive function
#			(n/4)+17 for n <= 3 and 
#			(function1(n-2)/2)+function1(n-5)*n-(n*n)
#Parameters: $a1 = n value
#Return value: $v1 = computed value
#Registers to be used: $t0, $t1, $t2, $t3, $zero
###########################################################
function1:
			#Save registers before function execution
			addi $sp, $sp, -12
			sw $a1, 0($sp)
			sw $ra, 4($sp)
			sw $t1, 8($sp)

			slti $t0, $a1, 4 #(n<=3)? 1:0
			beq $t0, $zero, recursive #Recursive case for n>3

			li $t0, 4
			div $a1, $t0 #n/4
			mflo $v1
			addi $v1, $v1, 17 #(n/4)+17

			#Load registers back before end of function
			lw $t1, 8($sp)
			lw $ra 4($sp)
			lw $a1, 0($sp)
			addi $sp, $sp, 12

			jr $ra #Return from base case

recursive:
			addi $a1, $a1, -2 #n = n-2

			jal function1 #function1(n-2)

			li $t1, 2
			div $v1, $t1 #function1(n-2)/2
			mflo $t1

			lw $a1, 0($sp) #Restore original value of n
			addi $a1, $a1, -5 #n = n-5

			jal function1 #function1(n-5)

			lw $a1, 0($sp) #Restore original value of n

			mult $v1, $a1 #function1(n-5)*n
			mflo $t2
			mult $a1, $a1 #n*n
			mflo $t3

			add $t2, $t1, $t2 #function1(n-2)/2 + function1(n-5)*n
			sub $v1, $t2, $t3 #function1(n-2)/2 + function1(n-5)*n - n*n

			#Load registers back before end of recursive case
			lw $t1, 8($sp)
			lw $ra, 4($sp)
			lw $a1, 0($sp)
			addi $sp, $sp, 12

			jr $ra #Return from recursive case