// Assignment #5
// Name: Vincent Latona
// Description: This program demonstrates the functionality of 
//				a Hash Table class
// Hash Analysis: For my hash function, I decided to use prime numbers
// in order to keep numbers from diving others. The number of collisions
// was about what I expected. I do not believe my function worked very well.
// I changed my function to find remainders against prime numbers.

#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

/*
* This function is to act as the driver for the program
*/
int main() 
{

	//Initialize variables
	int size = 0;
	int success = 0;
	bool done = false;
	bool changed = false;
	char c = '\0';
	string element = "";
	Course* found = NULL;


	//Prompt for table size and accept
	cout << "Please enter a hash table size:\n";
	cin >> size;
	cin.ignore();

	//Create Hash Table of input size
	HashTable* table = new HashTable(size);

	//Interactive loop
	while (!done)
	{

		//Prompt for action and accept
		cout << "What action would you like to perform?\n";
		cin.get(c);
		cin.ignore(20, '\n');

		//Uppercase conversion
		c = toupper(c);

		//Switch for action
		switch (c)
		{

		//Add case
		case 'A':

			//Display input prompt and accept
			cout << "Enter a course information using the format courseId:credits:capacity:days,time\n";
			getline(cin, element);
			cin.ignore('\n');

			//Try to insert element
			success = table->insertElement(element);

			//Full table case
			if (success < 0)
			{

				//Error message for full-table
				cout << "The table is full.\n";

			}//End of full table case

			//Duplicate case
			else if (success == 0)
			{

				//Error message for duplicate course
				cout << "Duplicate course found in table\n";

			}//End of duplicate case
			break;

		//Search case
		case 'B':

			//Prompt for course ID and accept input
			cout << "Enter a coursId\n";
			getline(cin, element);
			cin.ignore('\n');

			//Uppercase string iterator
			for (int i = 0; i < element.length(); i++)
			{

				//Convert string to uppercase
				element[i] = toupper(element[i]);

			}//End of uppercase conversion

			//Search for element
			found = table->searchElement(element);

			//Not found case
			if (found == NULL)
			{
				
				//Print not found
				cout << element << " not found\n";

			}//End of not found case

			//Found case
			else
			{

				//Print course contents
				cout << found->courseId << " found with credit(s) ";
				cout << found->credits << ", capacity ";
				cout << found->capacity << " in the days: ";
				cout << found->days << " and the time: ";
				cout << found->time << endl;

			}//End of found case
			break;

		//Change Capacity case
		case 'C':

			//Prompt for course to change and accept
			cout << "Enter a courseId and a capacity value to change to using the format courseId:capacity\n";
			getline(cin, element);
			cin.ignore('\n');

			//Return value to determine whether capacity changed
			changed = table->changeCapacity(element);

			//Uppercase string iterator
			for (int i = 0; i < element.length(); i++)
			{

				//Convert string to uppercase
				element[i] = toupper(element[i]);

			}//End of uppercase conversion

			//Chagned case
			if (changed)
			{

				//Print update message
				cout << element << "updated\n";

			}//End of changed case

			//Not found case
			else
			{

				//Print not found
				cout << element << "not found\n";

			}//End of not found case
			break;

		//Dispaly case
		case 'D':

			//Print table contents
			table->printTable();
			break;

		//Quit case
		case 'Q':

			//Delete hash table and use sentinel to break loop
			delete table;
			done = true;
			break;

		//Default case
		default:

			//Display error message
			cout << "Unkown input action\n";
			break;

		}//End of action switch

	}//End of iteractive loop

	return 0;

}//End of function Main