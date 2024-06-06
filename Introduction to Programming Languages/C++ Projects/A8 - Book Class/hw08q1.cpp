// Vincent Latona
// Visual studio

#include "book.h"
#include <iostream>
#include <string.h>

#define MAX_BOOKS 5

using namespace std;

// forward declaration of functions (already implmented)
void executeAction(char);

// functions that need implementation:
// in book.cpp :
// Q1 Book constructor		// 2 points
// Q2 Book member functions // 18 points

// in this file (hw08q1.cpp) : Q3 to Q6
int addBook(string title_input, int id_input, int aisle_input, string bookType_input); // 10 points
void displayBooks();				// 5 points
void sort();						// 10 points
void bookTypeWithSpecificString();		// 5 points


Book b[MAX_BOOKS];		// array of objects
int currentCount = 0;				// number of books in the list


int main()
{
	char choice = 'i';		// initialized to a dummy value
	do
	{
		cout << "\nCSE240 HW8\n";
		cout << "Please select an action:\n";
		cout << "\t a: add a new book\n";
		cout << "\t d: display book list\n";
		cout << "\t s: sort the books in descending order based on ID (within a range)\n";
		cout << "\t n: display the book with the longest title among the books whose bookType contain a specific substring\n";
		cout << "\t q: quit\n";
		cin >> choice;
		cin.ignore();			// ignores the trailing \n
		executeAction(choice);
	} while (choice != 'q');

	return 0;
}


// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	string title_input, bookType_input;
	int ID_input, aisle_input, result = 0;

	switch (c)
	{
	case 'a':	// add book
				// input book details from user
		cout << "Please enter book title: ";
		getline(cin, title_input);
		cout << "Please enter book ID: ";
		cin >> ID_input;
		cin.ignore();
		cout << "Please enter aisle number: ";
		cin >> aisle_input;
		cin.ignore();
		cout << "Please enter bookType: ";
		getline(cin, bookType_input);

		// add the book to the list
		result = addBook(title_input, ID_input, aisle_input, bookType_input);
		if (result == 0)
			cout << "\nThat book is already in the list or list is full! \n\n";
		else
			cout << "\nBook successfully added to the list! \n\n";
		break;

	case 'd':		// display the list
		displayBooks();
		break;

	case 's':		// sort the list
		sort();
		break;

	case 'n':		// find and display book with the longest title among the books whose bookType contain a specific substring.
		bookTypeWithSpecificString();
		break;

	case 'q':		// quit
		break;

	default: cout << c << " is invalid input!\n";
	}

}

// Q3 addBook (10 points)
// This function adds a new book with the details given in function arguments.
// Add the book in 'b' (array of objects) only if there is remaining capacity in the array and if the book does not already exist in the list (title or ID)
// This function returns 1 if the book is added successfully, else it returns 0 for the cases mentioned above.
// Assume user enters ID and aisle number  in 0 - any positive integer range.
int addBook(string title_input, int id_input, int aisle_input, string bookType_input)
{

	//Duplicate identifier
	bool found = false;

	//Searching iterator
	for (int a = 0; a < currentCount; a++)
	{

		//Duplicate case
		if (id_input == b[a].getID())
		{

			//Change sentinel and end iterator
			found = true;
			break;

		}//End of duplicate case

	}//End of searching iterator

	//Full or duplicate case
	if (currentCount >= MAX_BOOKS || found)
	{

		//0 for full or duplicate
		return 0;

	}//End of full or duplicate case

	//Add case
	else
	{

		//Member assignment and count increment
		b[currentCount].setTitle(title_input);
		b[currentCount].setID(id_input);
		b[currentCount].setAisle(aisle_input);
		b[currentCount].setBookType(bookType_input);
		currentCount++;

		//1 for successful add
		return 1;

	}//End of add case

}//End of function addBook

// Q4 displayBooks (5 points)
// This function displays the list of books.
// Parse the object array 'b' and display the details of all books in the array. See expected output given in question file.
// You can call the class function 'displayBook()' here. Note that these are two different functions.
// Book::displayBook() displays details of one Book object, while displayBooks() should display all books.
void displayBooks()
{

	//Display iterator
	for (int a = 0; a < currentCount; a++)
	{

		//Display books
		b[a].displayBook();

	}//End of display iterator

}//End of function displayBooks

// Q5 sort (10 points)
// This function sorts the books in descending order of ID, and then display the books within a given range.
// You need to get lower bound and higher bound from user after printing a prompt. (Check the output in the pdf)
// You may use the 'temp' object for sorting logic, if needed.
void sort()
{
	
	//Local variable declaration
	Book temp;
	int lower_bound;
	int higher_bound;

	//User prompt and input
	cout << "Please enter the lower bound of ID: ";
	cin >> lower_bound;
	cout << "Please enter the upper bound of ID: ";
	cin >> higher_bound;

	//Outer sorting iterator
	for (int c = 0; c < currentCount - 1; c++)
	{

		//Default maximum ID and index
		int maxID = b[c].getID();
		int maxIndex = c;

		//Inner sorting iterator
		for (int d = c + 1; d < currentCount; d++)
		{

			//Larger condition
			if (b[d].getID() > maxID)
			{

				//Reassign and maxID maxIndex
				maxID = b[d].getID();
				maxIndex = d;

			}//End of larger condition

		}//End of inner sorting iterator

		//Storage of c
		temp.setTitle(b[c].getTitle());
		temp.setID(b[c].getID());
		temp.setAisle(b[c].getAisle());
		temp.setBookType(b[c].getBookType());

		//Reassign max to c
		b[c].setTitle(b[maxIndex].getTitle());
		b[c].setID(b[maxIndex].getID());
		b[c].setAisle(b[maxIndex].getAisle());
		b[c].setBookType(b[maxIndex].getBookType());

		//Reassign c
		b[maxIndex].setTitle(temp.getTitle());
		b[maxIndex].setID(temp.getID());
		b[maxIndex].setAisle(temp.getAisle());
		b[maxIndex].setBookType(temp.getBookType());

	}//End of outer sorting iterator

	//Display iterator
	for (int a = 0; a < currentCount; a++)
	{

		//Range check
		if (b[a].getID() >= lower_bound && b[a].getID() <= higher_bound)
		{

			//Book display
			b[a].displayBook();

		}//End of range check

	}//End of display iterator

}//End of function sort

// Q6 bookTypeWithSpecificString (5 points)
// This function displays an book with the longest name among the books whose bookType contain a specific substring.
// You should find the book as follows:
// 1. By traversing all books, you should find the books whose booktype include a specific substring. 
// NOTE: you need to get a substring from user after printing a prompt. (Check the output in the pdf)
// HINT: You may refer to the document of string::find.
// 2. After step 1, you should find the book whose title is the longest. You may use 'titleLength' and 'index' variable.
// 3. After step 2, copy the details of the book to 'bookWithLengthyTitle' object created using 'new' 
// and display the book's details using 'bookWithLengthyTitle' object.
// NOTE: You necessarily have to use the 'bookWithLengthyTitle' object to store the book details in it and delete it after displaying.
//       You should not display book details using 'b[]' object.
// 4. Finally delete the 'bookWithLengthyTitle' object.
void bookTypeWithSpecificString()
{
	string subString;				// Ask the user for a character
	Book* bookWithLengthyTitle = new Book;
	int titleLength = 0;
	int index = -1;
	
	//User prompt
	cout << "Enter the substring of book's bookType: ";
	cin >> subString;

	//Searching iterator
	for (int a = 0; a < currentCount; a++)
	{

		//Check for substring
		if (b[a].getBookType().find(subString) != -1)
		{

			//New longest case
			if (b[a].getTitle().length() > titleLength)
			{

				//Change titleLength and index
				index = a;
				titleLength = b[a].getTitle().length();

			}//End of new longest case

		}//End of check for substring

	}//End of searching iterator
	
	//Range check and display
	if (index != -1)
	{

		//Member assignment
		bookWithLengthyTitle->setTitle(b[index].getTitle());
		bookWithLengthyTitle->setID(b[index].getID());
		bookWithLengthyTitle->setAisle(b[index].getAisle());
		bookWithLengthyTitle->setBookType(b[index].getBookType());

		//Display
		bookWithLengthyTitle->displayBook();

		//Garbage collection
		delete bookWithLengthyTitle;

	}//End of range check and display

}//End of function bookTypeWithSpecificString