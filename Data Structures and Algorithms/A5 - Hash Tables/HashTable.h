#pragma once
// Assignment #5
// Name: Vincent Latona
// Description: This header file defines and implements
//				Hash Table functions to be used by the driver

#include <iostream>
#include <string>

using namespace std;

//Macro for size of hash table
#define SIZE(a) (a)

//Structure for courses
struct Course
{

	int collisions;
	string courseId;
	int credits;
	int capacity;
	string days;
	string time;

};//End of structure course

/*
* This class constructs a Hash Table
*/
class HashTable
{

//Private variables/functions
private:
	int tableSize;
	Course* table;
	int occupied;
	int getKey(string courseId);

//Public functions
public:
	HashTable();
	HashTable(int size);
	~HashTable();
	int h(int key, int i);
	int h1(int key);
	int h2(int key);
	int insertElement(string element);
	Course* searchElement(string courseID);
	bool changeCapacity(string idCapacity);
	void printTable();

};//End of class HashTable

/*
* Default Constructor for HashTable
*/
HashTable::HashTable()
{

	//Initialize private variables
	tableSize = 0;
	occupied = 0;
	table = new Course[SIZE(tableSize)];

}//End of default Constructor

/* 
* Constructor for HashTable of defined size
*/
HashTable::HashTable(int size)
{

	//Initialize private variables
	tableSize = size;
	occupied = 0;
	table = new Course[SIZE(tableSize)];
	
	//Initialize table to empty
	for (int i = 0; i < tableSize; i++)
	{

		//Initialize course contents
		table[i].collisions = 0;
		table[i].courseId = "none";
		table[i].credits = 0;
		table[i].capacity = 0;
		table[i].days = "none";
		table[i].time = "none";

	}//End of table initialization

}//End of defined size Constructor

/*
* Destructor for HashTable
*/
HashTable::~HashTable()
{

	//Delete the array of Courses
	delete[] table;

}//End of Destructor

/*
* This function performs overall hash function on a course key
*/
int HashTable::h(int key, int i)
{

	//Perform double hash function
	int p1 = h1(key);
	int p2 = h2(key);

	//Return overall hash function
	return (p1 + p2 * i) % tableSize;

}//End of overall hash function

/*
* This function performs the first hash
*/
int HashTable::h1(int key)
{

	//Return first hash
	return (key) % 11;

}//End of first hash

/*
* This function performs the second hash
*/
int HashTable::h2(int key)
{

	//Return first hash
	return (key) % 7;

}//End of second hash

/*
* This function is a helper to obtain the key of a course
*/
int HashTable::getKey(string courseId)
{

	//Key to be returned
	int key = 0;
	
	//String conversion to integer iterator
	for (int i = 0; i < courseId.length(); i++)
	{

		//Individual character
		char c = courseId[i];

		//Add converted char to key
		key = key + static_cast<int>(c);

	}//End of string conversion iterator

	//Return computed key
	return key;

}//End of function getKey

/*
* This function attempts to add a course to the hash table
*/
int HashTable::insertElement(string element)
{

	//Full table case
	if (occupied == tableSize)
	{

		//Return -1 for full table
		return -1;

	}//End of full table case

	//Search and Insert case
	else
	{

		//Parse input for positions for substrings
		int pos1 = element.find(':');
		string parse1 = element.substr(pos1+1);
		int pos2 = parse1.find(':');
		string parse2 = parse1.substr(pos2+1);
		int pos3 = parse2.find(':');
		string parse3 = parse2.substr(pos3+1);
		int pos4 = parse3.find(',');
		string parse4 = parse3.substr(pos4+1);

		//Create entries from substrings
		string courseId = element.substr(0, pos1);

		//Uppercase string iterator
		for (int i = 0; i < courseId.length(); i++)
		{

			//Convert string to uppercase
			courseId[i] = toupper(courseId[i]);

		}//End of uppercase conversion

		//Search for duplicate
		Course* exists = searchElement(courseId);

		//Duplicate case
		if (exists != NULL)
		{

			//Return 0 for duplicate
			return 0;

		}//End of duplicate case

		//Insert case
		else
		{

			//Define course variable entries
			int collisions = 0;
			int credits = stoi(parse1.substr(0, pos2));
			int capacity = stoi(parse2.substr(0, pos3));
			string days = parse3.substr(0, pos4);
			string time = parse4.substr(0);

			//Find key for the course
			int k = getKey(courseId);

			//Insertion iterator
			for (int i = 0; i < tableSize; i++)
			{

				//Calculate hash function
				int j = h(k, i);

				//Check for insertion
				if (table[j].courseId == "none")
				{

					//Insert element and data
					table[j].courseId = courseId;
					table[j].collisions = collisions;
					table[j].credits = credits;
					table[j].capacity = capacity;
					table[j].days = days;
					table[j].time = time;

					//Increment occupied spots
					occupied++;
					break;

				}//End of insertion check

				//Collision case
				else
				{

					//Increment collision counter
					collisions++;

				}//End of collision case

			}//End of insertion iterator

			//Return 1 for successful insert
			return 1;

		}//End of insert case

	}//End of search and insert case
	
}//End of function insert element

/*
* This function searches the contents of the table
*/
Course* HashTable::searchElement(string courseId)
{

	//Initialize return pointer
	struct Course* course = NULL;

	//Get key for given course
	int key = getKey(courseId);

	//Searching iterator
	for (int i = 0; i < tableSize; i++)
	{

		//Index where course could be
		int index = h(key, i);

		//Check for course
		if (table[index].courseId == courseId)
		{

			//Assign pointer to course and break loop
			course = &table[index];
			break;

		}//End of course check

		//Empty slot case
		else if (table[index].courseId == "none")
		{
			
			//Break if hash slot is empty
			break;

		}//End of empty slot case

	}//End of searching iterator

	//Return pointer for course
	return course;

}//End of function searchElement

/*
* This function changes capacity of a course if the course exists
*/
bool HashTable::changeCapacity(string idCapacity)
{

	//Parse idCapacity
	int pos = idCapacity.find(':');
	string courseId = idCapacity.substr(0, pos);
	int newCapacity = stoi(idCapacity.substr(pos+1));

	//Uppercase string iterator
	for (int i = 0; i < courseId.length(); i++)
	{

		//Convert string to uppercase
		courseId[i] = toupper(courseId[i]);

	}//End of uppercase conversion

	//Search for element
	Course* course = searchElement(courseId);

	//Change capacity case
	if (course != NULL)
	{

		//Change capacity and return true
		course->capacity = newCapacity;
		return true;

	}//End of capacity change case

	//Return false for non-existent element
	return false;

}//End of function changeCapacity

/*
* This function prints the table
*/
void HashTable::printTable()
{

	//Print Table Header
	cout << "Index\tCollisions\tCourseID\tCredits\tCapacity\tDays\tTime\t\n";

	//Display iterator
	for (int i = 0; i < tableSize; i++)
	{

		//Print contents
		cout << i << "\t";
		cout << table[i].collisions << "\t\t";
		cout << table[i].courseId << "\t\t";
		cout << table[i].credits << "\t";
		cout << table[i].capacity << "\t\t";
		cout << table[i].days << "\t";
		cout << table[i].time << endl;

	}//End of display iterator

}//End of function printTable