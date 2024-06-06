/* This C program demonstrates the switch statement without using breaks. */
#include <stdio.h>

//Function main missed return type
void main()
{
	
	//Variable declaration/initialization
	char ch = '+';
	double a = 10, b = 20;//Changed type for '/' operation
	double f;
	
	//Char verification
	printf("ch = %c\n", ch);

	//Sequence of switches
	//Switch 1
	switch(ch)
	{
		
		//No break statements lead to execution of multiple statements
		case '+': f = a + b; printf("f = %f\n", f); break;//Addition operation
		case '-': f = a - b; printf("f = %f\n", f); break;//Subtraction operation
		case '*': f = a * b; printf("f = %f\n", f); break;//Multiplication operation
		case '/': f = a / b; printf("f = %f\n", f); break;//Division operation
		default: printf("invalid operator\n");//Invalid flag

	}//End of 1st switch

	//Char assignment
	ch = '-';

	//Char verification
	printf("ch = %c\n", ch);

	//Switch 2
	switch(ch)
	{
		
		//No break statements lead to execution of multiple statements
		case '+': f = a + b; printf("f = %f\n", f); break;//Addition operation
		case '-': f = a - b; printf("f = %f\n", f); break;//Subtraction operation
		case '*': f = a * b; printf("f = %f\n", f); break;//Multiplication operation
		case '/': f = a / b; printf("f = %f\n", f); break;//Division operation
		default: printf("invalid operator\n");//Invalid flag

	}//End of 2nd switch

	//Char assignment
	ch = '*';

	//Char verification
	printf("ch = %c\n", ch);

	//Switch 3
	switch(ch)
	{
		
		//No break statements lead to execution of multiple statements
		case '+': f = a + b; printf("f = %f\n", f); break;//Addition operation
		case '-': f = a - b; printf("f = %f\n", f); break;//Subtraction operation
		case '*': f = a * b; printf("f = %f\n", f); break;//Multiplication operation
		case '/': f = a / b; printf("f = %f\n", f); break;//Division operation
		default: printf("invalid operator\n");//Invalid flag

	}//End of 3rd switch

	//Char assignment
	ch = '/';

	//Char verification
	printf("ch = %c\n", ch);

	//Switch 4
	switch(ch)
	{
		
		//No break statements lead to execution of multiple statements
		case '+': f = a + b; printf("f = %f\n", f); break;//Addition operation
		case '-': f = a - b; printf("f = %f\n", f); break;//Subtraction operation
		case '*': f = a * b; printf("f = %f\n", f); break;//Multiplication operation
		case '/': f = a / b; printf("f = %f\n", f); break;//Division operation
		default: printf("invalid operator\n");//Invalid flag

	}//End of 4th switch

	//Char assignment
	ch = '-';

	//Char verification
	printf("ch = %c\n", ch);

	//Switch 5
	switch(ch)
	{
		
		//No break statements lead to execution of multiple statements
		case '+': f = a + b; printf("f = %f\n", f); break;//Addition operation
		case '-': f = a - b; printf("f = %f\n", f); break;//Subtraction operation
		case '*': f = a * b; printf("f = %f\n", f); break;//Multiplication operation
		case '/': f = a / b; printf("f = %f\n", f); break;//Division operation
		default: printf("invalid operator\n");//Invalid flag

	}//End of 5th switch
		
}//End of function main