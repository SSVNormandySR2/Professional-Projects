###########################################################
# Assignment #: 4
#  Name: Vincent Latona
#  Description: This MIPS program will apply a discount through
#				the use of conditional control structures.
###########################################################

#Data declarations for the given program
					.data
msg1: .asciiz "Are you a store member? Enter 1 for a member, 0 for a non-member\n"
msg2: .asciiz "Invalid Answer.\n"
msg3: .asciiz "Enter your purchase amount in cents:\n"
msg4: .asciiz "Your total payment is "

#Program running function declaration
					.text
					.globl		main

#Main function
main:
		#Input prompt
		la $a0, msg1
		li $v0, 4 #Display input prompt
		syscall
		li $v0, 5 #Read integer input
		syscall
		move $t0, $v0

		#if(membership != 0)
		li $t1, 1
		bne $t0, $zero, Check #Go to Check1 for membership != 0
		j Member
		
		#AND evaluation for if(membership != 0 && membership != 1)
		Check:
					bne $t0, $t1, Invalid #Go to Invalid for membership != 1
					j Member #Determine discount eligibility

		#Discount eligibility
		Member:
				#Prompt for amount input
				la $a0, msg3
				li $v0, 4 #Display input prompt
				syscall
				li $v0, 5 #Read integer input
				syscall
				move $s0, $v0
		
				li $s1, 10
				li $s2, 9
				bne $t0, $zero, Discount #Apply discount to purchase ammount in Discount
				j Exit #Full price for non-members

				Discount:
							li $t2, 10000
							slt $t3, $t2, $s0 #if(10000<$s0)1:0
							beq $t3, $t1, BigDiscount #Go to BigDiscount for larger purchase

							div $s0, $s1 #Get 10% of purchase
							mflo $s0
							mult $s0, $s2 #Multiply it by 9 to get final price
							mflo $s0
							j Exit

				BigDiscount:
							div $s0, $s1 #Get 10% of purchase
							mflo $s0
							mult $s0, $s2 #Multiply it by 9 to get initial discount
							mflo $s0
							addi $s0, $s0, -100 #-100 from discounted price
							j Exit


		#Invalid control branch
		Invalid:
					la $a0, msg2
					li $v0, 4 #Display error message
					syscall
					jr $ra

		#Exit condition
		Exit:
				la $a0, msg4
				li $v0, 4 #Display payment message
				syscall
				move $a0, $s0
				li $v0, 1 #Display payment
				syscall
				jr $ra