###########################################################
# Assignment #: 6
#  Name: Vincent Latona
#  Description: This MIPS program implements multiple array
#				functions
###########################################################

#Data declarations for the given program
					.data
array: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
arraysize: .word 11
msg1: .asciiz "Specify how many times to repeat:\n"
msg2: .asciiz "Enter an integer for the Nth smallest:\n"
msg3: .asciiz "Enter 11 integers.\n"
msg4: .asciiz "Enter an integer:\n"
msg5: .asciiz "\n"
msg6: .asciiz "Original Array Content:\n"
msg7: .asciiz "Result Array Content:\n"
msg8: .asciiz "The "
msg9: .asciiz "(-th) smallest number is "



#Program running function declaration
					.text
					.globl		main

#Main function
main:
			#Repeats prompt and input
			la $a0, msg1
			li $v0, 4 #howMany prompt
			syscall
			li $v0, 5 #Read howMany
			syscall
			move $s0, $v0 #Put howMany in $s0

			#Nth smallest prompt
			la $a0, msg2
			li $v0, 4 #index prompt
			syscall
			li $v0, 5 #Read index
			syscall
			move $s1, $v0 #Put index in $s1

			la $t0, arraysize
			lw $s2, 0($t0) #$s2 = arraysize
			la $s3, array #$s3 = array[0]

			slti $t0, $s1, 1 #if index<1? 1:0
			beq $t0, $zero, Else #Exit to test other extreme
			li $s1, 1 #index = 1
			j Exit

			Else:
						slt $t0, $s2, $s1 #if arraysize<index? 1:0
						beq $t0, $zero, Exit #Valid range
						move $s1, $s2 #index = arraysize
						
			Exit:
						li $s4, 0 #i = 0
						move $a1, $s3 #Parametrize addr of array to $a1
						move $a2, $s2 #Parametrize arraysize to $a2
						move $a3, $s1 #Parametrize index to $a3

						#Save $ra contents before function call
						addi $sp, $sp, -4
						sw $ra, 0($sp)

						#While loop for howMany
						Loop:
									slt $t0, $s4, $s0 #if i<howMany? 1:0
									beq $t0, $zero, LoopExit #Exit when 0

									jal findTheNthSmallest #Call findTheNthSmallest

									#Display Nth smallest
									la $a0, msg8
									li $v0, 4 #Print initial text
									syscall
									move $a0, $a3
									li $v0, 1 #Print integer
									syscall
									la $a0, msg9
									li $v0, 4 #Print following text
									syscall
									move $a0, $v1
									li $v0, 1 #Print integer
									syscall
									la $a0, msg5
									li $v0, 4 #newline
									syscall
									la $a0, msg5
									li $v0, 4 #newline
									syscall

									addi $s4, $s4, 1 #i++
									j Loop

						LoopExit:
									#Load $ra contents before main exit
									lw $ra, 0($sp)
									addi $sp, $sp, 4

									jr $ra #Return from main

###########################################################
#Procedure/Function: readArray
#Description: This function reads integers and stores them in
#				the array
#Parameters: $a1 = addr of array, $a2 = arraysize
#Return value: void
#Registers to be used: $a0, $v0, $s4, $t1, $t2, $t3, $zero
###########################################################
readArray:
			#Save registers used elsewhere
			addi $sp, $sp, -4
			sw $s4, 0($sp)

			li $s4, 0 #i = 0

			#Display array prompt
			la $a0, msg3
			li $v0, 4 #Display enter prompt
			syscall

			#Loop to read array elements
			ReadLoop:
						slt $t1, $s4, $a2 #if i<arraysize? 1:0
						beq $t1, $zero, ReadLoopExit #Exit when 0

						sll $t2, $s4, 2 #4*i for ith elements
						add $t3, $t2, $a1 #$t3 = addr of array[i]
			
						#Display integer prompt and read
						la $a0, msg4
						li $v0, 4 #Integer prompt
						syscall
						li $v0, 5 #Read integer
						syscall
						sw $v0, 0($t3) #Store read integer into array[i]

						addi $s4, $s4, 1 #i++
						j ReadLoop

			ReadLoopExit:
						#Load registers back for elsewhere
						lw $s4, 0($sp)
						addi $sp, $sp, 4

						jr $ra #Return from readArray



###########################################################
#Procedure/Function: printArray
#Description: This function prints the contents of an array
#Parameters: $a1 = addr of array, $a2 = arraysize
#Return value: void
#Registers to be used: $a0, $v0, $t1, $zero, $t2, $t3
###########################################################
printArray:
			#Save registers used elsewhere
			addi $sp, $sp, -4
			sw $s4, 0($sp)

			li $s4, 0 #i = 0

			#Loop to read array elements
			DisplayLoop:
						slt $t1, $s4, $a2 #if i<arraysize? 1:0
						beq $t1, $zero, DisplayLoopExit #Exit when 0

						sll $t2, $s4, 2 #4*i for ith elements
						add $t3, $t2, $a1 #$t3 = addr of array[i]
			
						lw $a0, 0($t3) #Get integer at array[i]
						li $v0, 1 #Print integer
						syscall
						la $a0, msg5
						li $v0, 4 #newline character
						syscall

						addi $s4, $s4, 1 #i++
						j DisplayLoop

			DisplayLoopExit:
						#Load registers back for elsewhere
						lw $s4, 0($sp)
						addi $sp, $sp, 4

						jr $ra #Return from readArray

###########################################################
#Procedure/Function: findTheNthSmallest
#Description: This function finds the nth smallest element
#				of a given array
#Parameters: $a1 = addr of array, $a2 = arraysize, $a3 = index
#Return value: $v1 = theNthSmallest
#Registers to be used: $a0, $v0, $s4, $s5, $t0, $zero, $t1, $s6, 
#						$t2, $t3, $t4, $t5
###########################################################
findTheNthSmallest:
			#Save registers used elsewhere
			addi $sp, $sp, -4
			sw $s4, 0($sp)

			#Save $ra for later
			addi $sp, $sp, -4
			sw $ra, 0($sp)

			jal readArray #Call readArray

			#Display original Array
			la $a0, msg6
			li $v0, 4
			syscall

			jal printArray #Call printArray

			li $s4, 0 #i = 0

			OuterLoop:
						slt $t0, $s4, $a3 #if i<index? 1:0
						beq $t0, $zero, OuterLoopExit

						sll $t0, $s4, 2 #4*i
						add $t2, $t0, $a1 #$t2 = addr of array[i]

						addi $s6, $s4, 0 #$s6 = smallIndex
						addi $s5, $s4, 1 #$s5 = j = i+1

						InnerLoop:
									slt $t1, $s5, $a2 #if j<arraysize? 1:0
									beq $t1, $zero, InnerLoopExit

									sll $t0, $s5, 2 #4*j
									add $t1, $t0, $a1 #$t1 = addr of array[j]
									sll $t0, $s6, 2 #4*smallIndex
									add $t3, $t0, $a1 #$t1 = addr of array[smallIndex]

									lw $t4, 0($t1) #$t4 = array[j]
									lw $t5, 0($t3) #$t5 = array[smallIndex]

									slt $t0, $t4, $t5 #if array[j]<array[smallIndex]? 1:0
									beq $t0, $zero, Iterate #Iterate when not smaller

									addi $s6, $s5, 0 #smallIndex = j

						Iterate:
									addi $s5, $s5, 1 #j++
									j InnerLoop


						InnerLoopExit:
									lw $t3, 0($t2) #arry[i] to be swapped
									sll $t0, $s6, 2
									add $t1, $t0, $a1
									lw $t4, 0($t1) #array[smallIndex] to be swapped

									#Swap smallest and i
									sw $t3, 0($t1)
									sw $t4, 0($t2)
						
									addi $s4, $s4, 1 #i++
									j OuterLoop

			OuterLoopExit:
						#Print result array
						la $a0, msg7
						li $v0, 4 #Print result array text
						syscall

						jal printArray #Call printArray to print the result array

						addi $t0, $a3, -1 #index-1
						sll $t1, $t0, 2 #4*(index-1)
						add $t2, $t1, $a1 #$t2 = addr of array[index-1]

						lw $v1, 0($t2) #Return vale of array[index-1]

						#Load registers for return
						lw $ra, 0($sp)
						addi $sp, $sp, 4
						lw $s4, 0($sp)
						addi $sp, $sp, 4

						jr $ra #Return to main