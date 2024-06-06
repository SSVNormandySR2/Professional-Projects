// Vincent Latona

#include <stdio.h>
// #pragma warning(disable : 4996) // needed if using Visual Studio


int main(){

	// Problem 1: (4 points)
	// The statement below should cause the program to not compile. Correct the error(s). (2 points).

	//Assigned correct type
	double p = 20.18;

	printf("p is equal to %f\n", p);

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Contextual because the type is not specified \n\n"); 


	// Problem 2: (4 points)
	// Half of 50 is 25, why is the program printing that half of 50 is 0? Correct the error(s) (2 points).

	//New type to get correct vlaue
	double q = 50;

	//Changed format for double
	printf("Half of %f is %f\n", q, (q / 2));

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Contextual/Sematic for variable initialization and math operation \n\n");

     //Problem 3    (2 points)
     //Integer variable y is initialized to 100 and its value needs to be printed. Correct the error(s).(1 point)
   int y = 100;

   //Changed format to int
   printf("y is %d\n",y); 
    // Your answer should be either Syntactic, Semantic, or Contextual. (1 point)
	printf("Error Type: Contextual \n\n");
     
     //Give your explanation here:
     printf("I believe it's contextual because format is affected with the type of variable \n\n");
	
	// Problem 4: (2 points)
	// Float variable f has been initialized to 3.14, why does the program seem to think otherwise? Correct the error(s) (2 points).

	float f = 3.14;

	//Must use correct operator
	if (f == 10)
	printf("f is equal to 10.\n");
	if (f > 10)
	printf("f is greater than 10.\n");
	if (f < 10)
	printf("f is less than 10.\n");

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Semantic because syntax is correct for if, but incorrect operator is used \n\n");


	// Problem 5: (4 points)
	// Surely, 60 is an even number. Why is the program printing that 60 is an odd number? Correct the error(s) ( points).

	q = 60;
	
	//Cast for int to use mod
	if (((int) q) % 2 == 0)
		printf("%d is an even number.\n", (int) q);//Cast for int
	if (((int) q) % 2 != 0)
		printf("%d is an odd number.\n", (int) q);//Cast for int

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Semantic because mod will produce remainders, requiring operands to be integers \n\n");


	// Problem 6: (4 points)
	// This bit of code is meant to print "Hello World!". Correct the error(s) (2 points).

	//Use %s for string
	printf("Hello %s\n", "World!");

	// Define what type of error this is, your answer should replace the space next to "Error Type: " below (2 points).
	// Your answer should be either Syntactic, Semantic, or Contextual.
	printf("Error Type: Contextual because of format type \n\n");

return 0;
}
