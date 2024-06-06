#include <stdio.h>
void main()
{

	//Variables for switch
	double a = 10, b = 20;
	double f;

	//Loop to read input
	for(int c = 0; c < 5; c++)
	{
	
		//Input prompt
		printf("Enter math operation: ");

		//Char input
		char ch = getchar();

		//Char display
		printf("ch = %c\n", ch);
		
		//Switch to verify character
		switch(ch)
		{
		
			case '+': f = a + b; printf("f = %f\n", f); break;//Addition operation
			case '-': f = a - b; printf("f = %f\n", f); break;//Subtraction operation
			case '*': f = a * b; printf("f = %f\n", f); break;//Multiplication operation
			case '/': f = a / b; printf("f = %f\n", f); break;//Division operation
			default: printf("invalid operator\n");//Invalid flag

		}//End of switch

		//Char flush
		ch = getchar();

	}//End of loop

}//End of function main