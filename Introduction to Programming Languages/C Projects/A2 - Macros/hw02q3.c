#include <stdio.h>
#pragma warning(disable : 4996) // needed in VS

//Vincent Latona

#define ABS(x) (((x) < 0) ? -(x) : (x))

#define polyMacro(a, b) (a*a + 5*a- 4*a*b + b*b)

int polyFunc(int a, int b) {
	return (a * a + 5 * a - 4 * a * b + b * b);
}

// Part 1:
// We want to pass the value of 6 to ABS and expect the result of ABS to be 6, why is the result 7? Correct the error (5 points)
void part1(int x) {

	int result;
	++x;
	result = ABS(x);

	printf("absm(6) = %d \n\n", result);

	// Why did this error occur? Please provide the answer in your own words below.
	printf("Explanation: The macro directly substitutes the preincremented variable, which is executed twice because of the conditional.\n\n\n"); // (2.5 points)
}


// Part 2:
// We want to pass incremented values of x and y to the macro and function to compare their outputs in VS and GCC.
// Run this program in Visual Studio(VS) and then again in GCC. Fill the blanks below with the output values for polyFunc and polyMacro.
// Then correct/edit this function so that polyFun and polyMacro produce same correct output of 22.			// (5 points)
// 
void part2(int x, int y) {						// increment before passing to macro
	int x_copy = x, y_copy = y;
	++x_copy, ++y_copy;

	printf("polyFunc(x, y) = %d \npolyMacro(x, y) = %d \n\n", polyFunc(++x, ++y), polyMacro(x_copy, y_copy));


	// Replace the 4 blank spaces below with the actual output observed when running the code in VS and GCC.
	// The blanks should have the answers of unedited program. Keep the answers in blanks as they were, after editing the program.
	printf("In VS : the result of polyFunc = 22 and polyMacro = -2 \n"); 			// (5 points)
	printf("In GCC: the result of polyFunc = 22 and polyMacro = 33 \n\n"); 		// (5 points)

	// Explain in a short sentence why VS and GCC could possibly produce a different value for the same program and for the same input.
	printf("Explanation: They would produce different values because of the compilers and how they handle their order of operations with respect to incrementation.\n\n"); //  (2.5 points)
}

// Do not edit main()  
int main()
{
	int x = 5, y = 1;

	printf("Part 1:\n\n");
	part1(x);
	printf("Part 2:\n\n");
	part2(x, y);

	while (1);	// needed to keep console open in VS
	return 0;
}