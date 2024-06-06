/*
* Vincent Latona
* Homework 2
* Programming Environment: Visual Studio
* January 27, 2021
*/
#include<stdio.h>
#pragma warning(disable : 4996) // needed in VS

/*This function calculates the average of 2 integer values*/
int avgf(int a, int b)
{

	//Return avg of 2 ints
	return (a + b) / 2;

}//End of function avgf

/*This macro calculates the average of 2 values*/
#define avgm(a, b) ((a + b) / 2)

/*This function calculates squares and adds them*/
int squared_addf(int a, int b) 
{

	//Return addition of 2 squares
	return a * a + b * b;

}//End of function squared_addf

/*This macro adds 2 squares*/
#define squared_addm(a, b) (a * a + b * b)

/*This function determines the min of 2 values*/
int minf(int a, int b)
{

	//Conditional for min
	if (a < b)
	{

		//a is min
		return a;

	}//End of if
	else
	{

		//b is min
		return b;

	}//End of else

}//End of function minf

/*This macro finds the min of 2 values*/
#define minm(a, b) ((a < b)? a: b)

/*This function determines if a value is odd*/
int oddf(int a)
{

	//Conditional for odd
	if (a % 2 != 0)
	{

		//a is odd
		return 1;

	}//End of if
	else
	{

		//a is even
		return 0;

	}//End of else

}//End of function oddf

/*This macro determines if a value is odd*/
#define oddm(a) ((a % 2 != 0)? 1: 0)

/*This function drives the program*/
void main()
{

	//Variable declaration
	int a = 2, b = 6;

	//avg macro and function testing
	printf("avgf(a, b) = %d\n", avgf(a, b));
	printf("avgm(a, b) = %d\n", avgm(a, b));
	printf("avgf(++a, b--) = %d\n", avgf(++a, b--));

	//Variable reassignment
	a = 2, b = 6;

	//Final avg macro test
	printf("avgm(++a, b--) = %d\n", avgm(++a, b--));

	//Variable reassignment
	a = 2, b = 6;

	//squared_add macro and function testing
	printf("squared_addf(a, b) = %d\n", squared_addf(a, b));
	printf("squared_addm(a, b) = %d\n", squared_addm(a, b));
	printf("squared_addf(a++, --b) = %d\n", squared_addf(a++, --b));

	//Variable reassignment
	a = 2, b = 6;

	//Final squared_add macro test
	printf("squared_addm(a++, --b) = %d\n", squared_addm(a++, --b));

	//Variable reassignment
	a = 2, b = 6;

	//min macro and function testing
	printf("minf(a, b) = %d\n", minf(a, b));
	printf("minm(a, b) = %d\n", minm(a, b));
	printf("minf(--a, --b) = %d\n", minf(--a, --b));

	//Variable reassignment
	a = 2, b = 6;

	//Final min macro test
	printf("minm(--a, --b) = %d\n", minm(--a, --b));

	//Variable reassignment
	a = 2, b = 6;

	//odd macro and function testing
	printf("oddf(b) = %d\n", oddf(b));
	printf("oddm(b) = %d\n", oddm(b));
	printf("oddf(b++) = %d\n", oddf(b++));

	//Variable reassignment
	a = 2, b = 6;

	//Final odd macro test
	printf("oddm(b++) = %d\n", oddm(b++));

}//End of function main