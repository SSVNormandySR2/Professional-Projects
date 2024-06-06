// Vincent Latona
// Visual studio


#include "book.h"
#include <iostream>
#include <string.h>

using namespace std;

// Q1 Book (2 points)
// Book() constructor assigns the following default values to class data members
// title: The Alchemist
// ID: 0
// aisle: 101
// BookType: Fiction
Book::Book()
{
	
	//Data member assignment
	title = "The Alchemist";
	ID = 0;
	aisle = 101;
	bookType = "Fiction";

}//End of constructor

// Q2 (18 points)
// 2 points for each function

// Define all the class member functions.
// While defining member functions, note that these functions will be called using 
// a 'Book' object which will represent one book.
// Eg-  Book b[10]; creates 10 Book objects
//		b[2].setAisle(202); will set 3rd book's aisle number to 202.

// setTitle assigns 'title_input' to class data member 'title'
void Book::setTitle(string title_input) 
{
	
	//Set book title
	title = title_input;

}//End of function setTitle

// setID assigns id_input to class data member 'ID'
void Book::setID(int id_input) 
{
	
	//Set ID
	ID = id_input;

}//End of fucntion setID

// setAisle assigns aisle_input to class data member 'aisle'
void Book::setAisle(int aisle_input) 
{
	
	//Set aisle
	aisle = aisle_input;

}//End of function setAisle

// setBookType assigns bookType_input to class data member 'bookType'
void Book::setBookType(string bookType_input) 
{
	
	//Set book type
	bookType = bookType_input;

}//End of function setBookType

// displayBook displays the title, ID, aisle and bookType of the book
// See expected output in question file.
void Book::displayBook() 
{
	
	//Book member display
	cout << "Title: " << title << endl;
	cout << "ID: " << ID << endl;
	cout << "Aisle: " << aisle << endl;
	cout << "Book Type: " << bookType << endl;
	cout << endl;

}//End of function displayBook

// getTitle returns the class data member 'title'.
string Book::getTitle() 
{
	
	//Return title
	return title;

}//End of function getTitle

// getID returns the class data member 'ID'.
int Book::getID() 
{
	
	//Return ID
	return ID;

}//End of function getID

// getAisle returns the class data member 'aisle'.
int Book::getAisle() 
{
	
	//Return aisle
	return aisle;

}//End of function getAisle

// getBookType returns the class data member 'bookType'.
string Book::getBookType() 
{
	
	//Return bookType
	return bookType;

}//End of function getBookType