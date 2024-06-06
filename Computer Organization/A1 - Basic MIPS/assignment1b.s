###########################################################
# Assignment #: 1
#  Name: Vincent Latona
#  Description: This is my first assembly language program.
#                         It prints "Goodbye World".
###########################################################

#data declarations: declare variable names used in program, storage allocated in RAM
                            .data  
message1:         .asciiz "Goodbye world.\n" #create a string containing "Hello world.\n"

#program code is contained below under .text
                        .text
                        .globl    main    #define a global function main

# the program begins execution at main()
main:
            la          $a0, message1  # $a0 = address of message1
            li           $v0, 4                # $v0 = 4  --- this is to call print_string()
            syscall                           # call print_string()
            jr          $ra                      # return