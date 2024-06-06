###########################################################
# Assignment #: 5
#  Name: Vincent Latona
#  Description: This MIPS program prompts the user for integer
#				inputs that will manipulate an array through
#				the use of a loop
###########################################################

#Data declarations for the given program
					.data
msg1: .asciiz "Enter an integer:\n"
msg2: .asciiz "Enter another integer:\n"
msg3: .asciiz "Result Array Content:\n"
msg4: .asciiz "\n"
numbers_len: .word 11
numbers: .word 15, -17, 11, -4, 23, -26, 27, 8, -21, 31, 15

#Program running function declaration
					.text
					.globl		main

#Main function
main:
			#Integer input prompts
			la $a0, msg1
			li $v0, 4 #Prompt for num1
			syscall
			li $v0, 5 #Read for num1
			syscall
			move $s0, $v0 #$s0 = num1

			la $a0, msg2
			li $v0, 4 #Prompt for num2
			syscall
			li $v0, 5 #Read for num2
			syscall
			move $s1, $v0 #$s1 = num2

			#Begin for-loop process
			la $s2, numbers #$s2 = addr of numbers
			li $s3, 0 #int i = 0
			la $t0, numbers_len
			lw $s4, 0($t0) #$s3 = length
			li $s5, 5 #$s5 = 5

			#Manipulation loop
			Loop:
						slt $t0, $s3, $s4 #while(i<length) 1:0
						beq $t0, $zero, LoopExit #Exit loop when complete

						sll $t0, $s3, 2 #i*4 for lw/sw
						add $t1, $t0, $s2 #addr of numbers[i]
						lw $t0, 0($t1) #$t0 = numbers[i]

						div $t0, $s0
						mfhi $t2 #numbers[i] % num1
						
						slt $t3, $s5, $t2 #if(5<$t2) 1:0
						beq $t3, $zero, Else #Go to Else when false

						div $t0, $s1 #numbers[i] / num2
						mflo $t3
						sw $t3, 0($t1) #numbers[i] = $t3

						#Else condition
						Else:
									addi $s3, $s3, 1 #i++
									j Loop #Reiterate

			#Exit loop to begin display process
			LoopExit:
						la $a0, msg3
						li $v0, 4 #Display result array message
						syscall

						#Begin for-loop process
						la $s2, numbers #$s2 = addr of numbers
						li $s3, 0 #int i = 0
						la $t0, numbers_len
						lw $s4, 0($t0) #$s3 = length

						#Loop to display the modified array
						DisplayLoop:
									slt $t0, $s3, $s4 #while(i<length) 1:0
									beq $t0, $zero, Exit #Exit loop when complete

									sll $t0, $s3, 2 #i*4 for lw/sw
									add $t1, $t0, $s2 #addr of numbers[i]
									lw $t0, 0($t1) #$t0 = numbers[i]

									move $a0, $t0
									li $v0, 1 #Display element numbers[i]
									syscall
									la $a0, msg4
									li $v0, 4 #Newline character
									syscall

									addi $s3, $s3, 1 #i++
									j DisplayLoop #Reiterate

						#End the program
						Exit:
									jr $ra #End of main