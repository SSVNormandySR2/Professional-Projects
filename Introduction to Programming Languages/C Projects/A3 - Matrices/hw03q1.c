
/*
* Vincent Latona
* IDE: Visual Studio
*/

#include <stdio.h>
#include <string.h>


#pragma warning(disable : 4996)  // compiler directive for Visual Studio only

// Global Macro Values. They are used to define the size of 2D array of integers
#define NUM_ROWS 5
#define NUM_COLUMNS 5

#define NUM_STRINGS 5 
#define STRING_LENGTH 50

// Forward Declarations
void printMatrix(int[NUM_ROWS][NUM_COLUMNS]);
void printScalarMultiple(int[NUM_ROWS][NUM_COLUMNS], int);
void squaredSumMatrices(int[NUM_ROWS][NUM_COLUMNS], int[NUM_ROWS][NUM_COLUMNS]);
void squaredTransposeMatrix(int[NUM_ROWS][NUM_COLUMNS]);
void multiplyMatrix(int[NUM_ROWS][NUM_COLUMNS], int[NUM_ROWS][NUM_COLUMNS]);
int noOfOccurencesOfChar(char s[NUM_STRINGS * STRING_LENGTH], char);
void reverseStrings(char strings[NUM_STRINGS * STRING_LENGTH]);



// Problem 1: printMatrix (5 points)
// Traverse the 2D array of integers variable 'matrix' (input from main)
// and print the contents in the following format (actual contents may vary)
// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15
// 16 17 18 19 20
// 21 22 23 24 25
void printMatrix(int matrix[NUM_ROWS][NUM_COLUMNS])
{

	//Row iterator
	for (int a = 0; a < NUM_ROWS; a++)
	{

		//Column iterator
		for (int b = 0; b < NUM_COLUMNS; b++)
		{

			//Print of array contents
			printf("%d ", matrix[a][b]);

		}//End of column iterator

		//New line for next row
		printf("\n");

	}//End of row iterator

}//End of function printMatrix

// Problem 2: printScalarMultiple (5 points)
// Traverse the 2D array of integers 'matrix' and print scalar multiple of the matrix 
// e.g.
// 1 2 3	    2 4 6
// 4 5 6	=>  8 10 12
// 7 8 9        14 16 18
void printScalarMultiple(int matrix[NUM_ROWS][NUM_COLUMNS], int multiple)
{

	//New array
	int matrixResult[NUM_ROWS][NUM_COLUMNS];

	//Row iterator
	for (int a = 0; a < NUM_ROWS; a++)
	{

		//Column iterator
		for (int b = 0; b < NUM_COLUMNS; b++)
		{

			//Element modification
			int c = matrix[a][b];
			matrixResult[a][b] = multiple * c;

			//Print of array contents
			printf("%d ", matrixResult[a][b]);

		}//End of column iterator

		//New line for next row
		printf("\n");

	}//End of row iterator

}//End of the function printScalarMultiple

// Problem 3: printSquaredDiagonal (5 points)
// Traverse the 2D array of integers 'matrix' and print each squared value on the diagonal from the 
// top left to bottom right position.
// e.g.
// 1 2 3		1 25 81
// 4 5 6	=>
// 7 8 9
void printSquaredDiagonal(int matrix[NUM_ROWS][NUM_COLUMNS])
{

	//New array
	int matrixResult[NUM_ROWS][NUM_COLUMNS];

	//Row iterator
	for (int a = 0; a < NUM_ROWS; a++)
	{

		//Column iterator
		for (int b = 0; b < NUM_COLUMNS; b++)
		{

			//Diagonal conditional
			if (a == b)
			{

				//Diagonal assignment
				int c = matrix[a][b];
				matrixResult[a][b] = c * c;

				//Element printing
				printf("%d ", matrixResult[a][b]);

			}//End of diagonal conditional

		}//End of column iterator

	}//End of row iterator

	//New line for next function
	printf("\n");

}//End of function printSquaredDiagonal


// Problem 4: squaredSumMatrices (5 points)
// Traverse the 2D array of integers 'matrices' and print the sum of each squared value.
// Consider both the arrays are of same size.
// e.g.
// 1 2 3   1 2 3        2 8 18
// 4 5 6   4 5 6	=> 32 50 72
// 7 8 9   7 8 9  	   98 128 162  

void squaredSumMatrices(int matrix1[NUM_ROWS][NUM_COLUMNS], int matrix2[NUM_ROWS][NUM_COLUMNS])
{

	//Row iterator
	for (int a = 0; a < NUM_ROWS; a++)
	{

		//Column iterator
		for (int b = 0; b < NUM_COLUMNS; b++)
		{

			//Square storage
			int c = matrix1[a][b] * matrix1[a][b], d = matrix2[a][b] * matrix2[a][b];

			//Print of sum
			printf("%d ", c + d);

		}//End of column iterator

		//New line for next row
		printf("\n");

	}//End of row iterator

}//End of function squaredSumMatrices

// Problem 5: squaredTransposeMatrix (10 points)
// Take the 2D array of integers 'matrix' and print the squared tranpose matrix.
// You may assume that row and column counts are equal.
// **Hint: Use printMatrix to print the result**
// e.g.
// 1 2 3	    1 16 49
// 4 5 6	=>  4 25 64
// 7 8 9        9 36 81
void squaredTransposeMatrix(int matrix[NUM_ROWS][NUM_COLUMNS])
{

	//New array
	int matrixResult[NUM_ROWS][NUM_COLUMNS];

	//Row iterator
	for (int a = 0; a < NUM_ROWS; a++)
	{

		//Column iterator
		for (int b = 0; b < NUM_COLUMNS; b++)
		{

			//Storage of original values
			int c = matrix[a][b] * matrix[a][b], d = matrix[b][a] * matrix[b][a];

			//Value reassignment
			matrixResult[a][b] = d;
			matrixResult[b][a] = c;

		}//End of column iterator

	}//End of row iterator

	//Print transposed matrix
	printMatrix(matrixResult);

}//End of function squaredTransposeMatrix

// Problem 6: multiplyMatrix (10 points)
// Take two 2D arrays of integers 'matrix1' and 'matrix2' and print the 
// resulting matrix gained by multiplying the entries in each corresponding location.
// You can assume the two matrices will have the same dimensions.
// **Hint: Use printMatrix to print the result**
// e.g.
// 1 2 3	1 2 3      1 4 9
// 4 5 6	4 5 6  =>  16 25 36
// 7 8 9    7 8 9      49 64 81
void multiplyMatrix(int matrix1[NUM_ROWS][NUM_COLUMNS], int matrix2[NUM_ROWS][NUM_COLUMNS])
{

	//New array
	int matrixResult[NUM_ROWS][NUM_COLUMNS];

	//Row iterator
	for (int a = 0; a < NUM_ROWS; a++)
	{

		//Column iterator
		for (int b = 0; b < NUM_COLUMNS; b++)
		{

			//Multiplication and assignment
			int c = matrix1[a][b] * matrix2[a][b];
			matrixResult[a][b] = c;

			//Print of array contents
			printf("%d ", matrixResult[a][b]);

		}//End of column iterator

		//New line for next row
		printf("\n");

	}//End of row iterator

}//End of function multiplyMatrix

// Problem 7: reverseString (5 points)
// Reverse each word in strings[]. 
// Consider one string at a time and reverse the characters. For instance, "hi hello" should reverse to "olleh ih".
void reverseStrings(char strings[NUM_STRINGS * STRING_LENGTH])
{

	//Temporary storage char array
	char word[NUM_STRINGS * STRING_LENGTH];

	//\0 detection
	int a = strlen(strings) - 1;

	//Index for local string
	int localIndex = 0;

	//Reveral iterator
	for (a; a >= 0; a--)
	{

		//Assignment of strings chars in reverse to local char array
		word[localIndex] = strings[a];
		localIndex++;

	}//End of reveral iterator

	//Ending of reversed string
	word[localIndex] = '\0';

	//Copy to original strings
	strcpy(strings, word);

}//End of function reverseStrings

// Problem 8: noOfOccurencesOfChar (5 points)
// Count all occurrences of the specified character 'filter' from s[]. 
int noOfOccurencesOfChar(char s[NUM_STRINGS * STRING_LENGTH], char filter)
{

	//Occurrence counter
	int count = 0;

	//Searching iterator
	for (int a = 0; a < strlen(s); a++)
	{

		//Char found condition
		if (filter == s[a])
		{

			//Increment counter
			count++;

		}//End of char found condition

	}//End of searching iterator

	return count;

}//End of function noOfOccurencesOfChar

// You should study and understand how this main() works.
// *** DO NOT modify it in any way ***
int main()
{
	printf("CSE240 HW3: 2D Integer Arrays\n\n");

	int matrix[NUM_ROWS][NUM_COLUMNS] =
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};
	int multiple = 2;

	printMatrix(matrix);
	printf("\n\n");
	printScalarMultiple(matrix, multiple);
	printf("\n\n");
	printSquaredDiagonal(matrix);
	printf("\n\n");
	squaredSumMatrices(matrix, matrix);
	printf("\n\n");
	squaredTransposeMatrix(matrix);
	printf("\n\n");
	multiplyMatrix(matrix, matrix);

	printf("\nCSE240 HW3: 2D Character Arrays\n\n");

	char words[NUM_STRINGS * STRING_LENGTH];
	printf("\nEnter sentence with max 5 words: ");
	fgets(words, sizeof(words), stdin);
	reverseStrings(words);
	printf("\nReveresed string: %s", words);
	printf("\nNo of occurences of a: %d", noOfOccurencesOfChar(words, 'a'));
	int i = getchar();
	i = getchar(); // Keep console open
	return 0;
}
