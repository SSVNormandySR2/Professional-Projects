
/*
* Vincent Latona
* IDE: Visual Studio
*/

#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)  // compiler directive for Visual Studio only


// Global Macro Values. They are used to define the size of 2D array of characters
#define NUM_STRINGS 4
#define STRING_LENGTH 50

// Forward Declarations
void initializeStrings(char[NUM_STRINGS][STRING_LENGTH]);
void printStrings(char[NUM_STRINGS][STRING_LENGTH]);
void toUppercase(char[STRING_LENGTH]);
void toLowercase(char[STRING_LENGTH]);
void changeAllToUpperOrLower(char[NUM_STRINGS][STRING_LENGTH], char);
void wordMatch(char strings[NUM_STRINGS][STRING_LENGTH], char input[STRING_LENGTH]);
void concatStr(char[NUM_STRINGS][STRING_LENGTH], char[NUM_STRINGS * STRING_LENGTH]);


// Problem 1: initializeStrings (5 points)
// Use pointer 'p' to traverse the 2D array of characters variable 'strings' (input from user in main() ) and set all characters in each
// array to a null terminator so that there is a 4 row and 50 column 2D array full of null terminators.
// The null terminator '\0' is used to denote the end of a string.
void initializeStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{

	//Initial pointer
	char *p = &strings[0][0];

	//Row iterator
	for (int a = 0; a < NUM_STRINGS; a++)
	{

		//Column iterator
		for (int b = 0; b < STRING_LENGTH; b++)
		{

			//Pointer assignment and char modification
			p = &strings[a][b];
			*p = '\0';

		}//End of column iterator

	}//End of row iterator

}//End of function initializeStrings

// Problem 2: printStrings (5 points)
// Use pointer 'p' to traverse the 2D character array 'strings' and print each string.
// See the example outputs provided in the word document. Each string should be printed on a new line.
void printStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	
	//Initial pointer
	char *p = &strings[0][0];

	//Row iterator
	for (int a = 0; a < NUM_STRINGS; a++) 
	{

		//Column iterator
		for (int b = 0; b < strlen(strings[a]); b++)
		{

			//Pointer assignment and string print
			p = &strings[a][b];
			printf("%c", *p);

		}//End of column iterator

		//New line for next row
		printf("\n");

	}//End of row iterator
	

}//End of function printStrings

// Problem 3: toUppercase() and toLowercase() (15 points)
// Problem 3-1: toUppercase 
// Convert the string in the array 's' to an uppercase string.
// Traverse the input using pointer 'p' and covert the character to an uppercase letter if it is lowercase.
// You need to write down the code to check whether or not the character is lowercase.
// HINT: Use a pointer to change the ASCII value of a character.
//       The ASCII value of 'a'= 97 and the ASCII value of 'A' = 65 so the difference between them is 32.
void toUppercase(char s[STRING_LENGTH]) 
{

	//Initial pointer
	char *p = &s[0];

	//Char changing loop
	for (int a = 0; a < strlen(s); a++)
	{

		//Pointer assignment
		p = &s[a];

		//Lowercase conditional
		if (*p >= 97 && *p <= 122)
		{

			//Switch to Uppercase
			*p = *p - 32;

		}//End of lowercase condition

	}//End of char changing loop

}//End of function toUppercase

// Problem 3-2: toLowercase 
// HINT : This should be very similar to toUppercase().
// Convert the string in the array 's' to an lowercase string.
// Traverse the input using pointer 'p' and covert the character to a lowercase letter if it is uppercase.
// You need to write down the code to check whether or not the character is uppercase.
// HINT: Use a pointer to change the ASCII value of a character.
//       The ASCII value of 'a'= 97 and the ASCII value of 'A' = 65 so the difference between them is 32.
void toLowercase(char s[STRING_LENGTH]) 
{

	//Initial pointer
	char *p = &s[0];

	//Char changing loop
	for (int a = 0; a < strlen(s); a++)
	{

		//Pointer assignment
		p = &s[a];

		//Lowercase conditional
		if (*p >= 65 && *p <= 90)
		{

			//Switch to Lowercase
			*p = *p + 32;

		}//End of lowercase condition

	}//End of char changing loop
	
}//End of function toLowercase


// Problem 4: changeAllToUpperOrLower (5 points)
// Change all words in the array 'strings' to uppercase or lowercase based on the value of char variable 'set'.
// If the value of char 'set' is 'u' or 'U', change all words to uppercase strings.
// If the value of char 'set' is 'l' or 'L', change all words to lowercase strings.
// No change, otherwise.
// You may use toUppercase() and toLowercase() here.
void changeAllToUpperOrLower(char strings[NUM_STRINGS][STRING_LENGTH], char set) 
{

	//Initial pointer
	char *ptr = &strings[0][0];

	//Uppercase conditional
	if (set == 'u' || set == 'U')
	{

		//String changing iterator
		for (int a = 0; a < NUM_STRINGS; a++)
		{

			//Pointer assignment and uppercase change
			ptr = strings[a];
			toUppercase(ptr);

		}//End of string changing iterator

	}//End of uppercase conditional

	//Lowercase conditional
	else if (set == 'l' || set == 'L')
	{

		//String changing iterator
		for (int a = 0; a < NUM_STRINGS; a++)
		{

			//Pointer assignment and uppercase change
			ptr = strings[a];
			toLowercase(ptr);

		}//End of string changing iterator

	}//End of lowercase conditional

}//End of function changeAllToUpperOrLower

// Problem 5: wordMatch (10 points)
// This function must be working as follows:
// 1. Compare the strings in the 2D array with input string
// 2. If one of them matches with input string, print "Match found"
// 3. Else print "Match not found"
// Example: strings array -> ["Hi", "Sun", "Devils"], input -> "Sun"  => print "Match found"
// Example: strings array -> ["Hi", "Sun", "Devils"], input -> "Hello"  => print "Match not found"
void wordMatch(char strings[NUM_STRINGS][STRING_LENGTH], char input[STRING_LENGTH]) 
{

	//Pointers and tools
	char *p = &strings[0][0];
	char *ip = input;
	int flag = 0;

	//Outer searching iterator
	for (int a = 0; a < NUM_STRINGS; a++)
	{

		//Match found condition
		if (flag == 1)
		{

			//End loop
			break;

		}//End of match found condition

		//Same size conditional
		else if (strlen(strings[a]) == strlen(input))
		{

			//Character comparison iterator
			for (int b = 0; b < strlen(strings[a]); b++)
			{

				//Pointer assignments
				p = &strings[a][b];
				ip = &input[b];

				//Char verification
				if (*p == *ip)
				{

					//Count as match
					flag = 1;

				}//End of char verification

				//No match
				else
				{

					//End loop
					flag = 0;
					break;

				}//End of no match

			}//End of character comparison iterator

		}//End of same size condition

	}//End of outer searching iterator

	//Match conditional
	if (flag == 1)
	{

		//Print found message
		printf("Match found\n");

	}//End of match conditional

	//No match case
	else
	{

		//Print not found message
		printf("Match not found\n");

	}//End of no match case
	
}//End of fucntion wordMatch

// Problem 6: concatStr (10 points)
// This function must be working as follows:
// 1. Concatenate the string in the array 'strings' together in a sentence.
// 2. Store the string to the array 'result'.
// 3. Print the string in the array 'result'.
// The sample output is shown in document
// NOTE: This is the function partially containing what you have implemented so far.
// Initialize the array 'result' first before you store a string to it.
// You may declare and use more pointers if needed.
void concatStr(char strings[NUM_STRINGS][STRING_LENGTH], char result[NUM_STRINGS * STRING_LENGTH]) 
{

	//Char pointers
	char *p_result = result;
	char *p_input = &strings[0][0];

	//Result initialization iterator
	for (int a = 0; a < NUM_STRINGS * STRING_LENGTH; a++)
	{

		//Pointer assignment and char modification
		p_result = &result[a];
		*p_result = '\0';

	}//End of result initialization iterator

	int index = 0;

	//Row iterator
	for (int b = 0; b < NUM_STRINGS; b ++)
	{

		//Column iterator
		for (int c = 0; c < strlen(strings[b]); c++)
		{

			//Pointer assignment
			p_input = &strings[b][c];
			p_result = &result[index];

			//Char assignment and print
			*p_result = *p_input;
			printf("%c", *p_result);
			index++;

			//Space concatenation condition
			if (c == strlen(strings[b]) - 1)
			{
				//End of string condition
				if (b != NUM_STRINGS - 1)
				{

					//Space adder and print
					p_result = &result[index];
					*p_result = ' ';
					printf("%c", *p_result);
					index++;

				}//End of end of string contition

			}//End of space concatenation condition

		}//End of column iterator

	}//End of row iterator

}//End of function concatStr


// You should study and understand how main() works.
// *** DO NOT modify it in any way ***
int main()
{
	char strings[NUM_STRINGS][STRING_LENGTH]; // will store four strings each with a max length of 34
	int i, key;
	char input[STRING_LENGTH];
	char result[NUM_STRINGS * STRING_LENGTH];

	printf("CSE240 HW4: Pointers\n\n");
	initializeStrings(strings);

	for (i = 0; i < NUM_STRINGS; i++)
	{
		printf("Enter a string: ");				// prompt for string
		fgets(input, sizeof(input), stdin);		// store input string
		input[strlen(input) - 1] = '\0';		// convert trailing '\n' char to '\0' (null terminator)
		strcpy(strings[i], input);				// copy input to 2D strings array
	}

	printf("\nEnter a string to find a match: ");	// prompt for string
	fgets(input, sizeof(input), stdin);			// store input string
	input[strlen(input) - 1] = '\0';			// convert trailing '\n' char to '\0' (null terminator)

	// Word match function call
	wordMatch(strings, input);

	// Concate all strings in array string to a sentence
	printf("\n\nThe concatenated string is: \n");
	concatStr(strings, result);

	// Convert all strings in array string to a particular case
	printf("\n\nChange strings to a particular case: \n");
	changeAllToUpperOrLower(strings, 'l');
	printStrings(strings);
	getchar();									// flush out newline '\n' char



	getchar();									// keep VS console open
	return 0;
}