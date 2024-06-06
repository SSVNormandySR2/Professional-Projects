
/*
* Vincent Latona
* IDE: Visual Studio
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996) // for Visual Studio Only

#define MAX_BOOKS 15
#define MAX_NAME_LENGTH 25

typedef enum { Nonfiction = 0, Fiction } bookType; // enum type 

struct libraryRecord {					// struct for book details
	char bookTitle[MAX_NAME_LENGTH];
	char author[MAX_NAME_LENGTH];
	bookType booktype;
	unsigned int bookId;
	unsigned int aisle;
};

struct libraryRecord list[MAX_BOOKS]; // declare list of books
int count = 0;						  // the number of books currently stored in the list (initialized to 0)

// functions already implmented
void flushStdIn();
void executeAction(char);
void save(char* fileName);

// functions that need implementation:
int add(char* bookTitle_input, char* author_input, char* booktype_input, unsigned int bookId_input, unsigned int aisle_input); // 20 points
void sort();				  // 10 points
int delete(unsigned int bookId_input);  // 10 points
void load(char* fileName);		  // 10 points
void display();				  // given


int main()
{
	char* fileName = "Book_List.txt";
	load(fileName);	// load list of books from file (if it exists). Initially there will be no file.
	char choice = 'i';		// initialized to a dummy value
	do
	{
		printf("\nEnter your selection:\n");
		printf("\t a: add a new book\n");
		printf("\t d: display book list\n");
		printf("\t r: remove a book from list\n");
		printf("\t s: sort book list by ID\n");
		printf("\t q: quit\n");
		choice = getchar();
		flushStdIn();
		executeAction(choice);
	} while (choice != 'q');

	save(fileName); // save list of books to file (overwrites file, if it exists)
	return 0;
}

// flush out leftover '\n' characters
void flushStdIn()
{
	char c;
	do c = getchar();
	while (c != '\n' && c != EOF);
}

// ask for details from user for the given selection and perform that action
void executeAction(char c)
{
	char bookTitle_input[MAX_NAME_LENGTH], author_input[MAX_NAME_LENGTH];
	unsigned int bookId_input, aisle_input, add_result = 0;
	char booktype_input[20];
	switch (c)
	{
	case 'a':
		// input book record from user
		printf("\nEnter book title: ");
		fgets(bookTitle_input, sizeof(bookTitle_input), stdin);
		bookTitle_input[strlen(bookTitle_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Enter author name: ");
		fgets(author_input, sizeof(author_input), stdin);
		author_input[strlen(author_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Enter book type (Fiction/ Nonfiction): ");
		fgets(booktype_input, sizeof(booktype_input), stdin);
		booktype_input[strlen(booktype_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Please enter book ID number: ");
		scanf("%d", &bookId_input);
		printf("Please enter aisle number: ");
		scanf("%d", &aisle_input);
		flushStdIn();

		// add the book to the list
		add_result = add(bookTitle_input, author_input, booktype_input, bookId_input, aisle_input);
		if (add_result == 0)
			printf("\nBook is already on the list! \n\n");
		else if (add_result == 1)
			printf("\nBook successfully added to the list! \n\n");
		else
			printf("\nUnable to add. Book list is full! \n\n");

		break;
	case 'r':
		printf("Please enter ID number of book to be deleted: ");
		scanf("%d", &bookId_input);
		flushStdIn();
		int delete_result = delete(bookId_input);
		if (delete_result == 0)
			printf("\nBook not found in the list! \n\n");
		else
			printf("\nBook deleted successfully! \n\n");
		break;
	case 'd': display();	break;
	case 's': sort();		break;

	case 'q': break;
	default: printf("%c is invalid input!\n", c);
	}
}

// Q1 : add (20 points)
// This function is used to add a book into the list. You can simply add the new book to the end of list (array of structs).
// Do not allow the book to be added to the list if it already exists in the list. You can do that by checking book names AND IDs already in the list.
// If the book already exists then return 0 without adding it to the list. If the book does not exist in the list then add the book at the end of the list and return 1.
// If book list is full, then do not add new book to the list and return 2.
// NOTE: Notice how return type of add() is checked in case 'a' of executeAction()
// NOTE: You must convert the string 'booktype_input' to an enum type and store it in the list because the booktype has enum type (not string type).
// The list should be case sensitive. For instance, 'Roger' and 'roger' should be considered two different names.
// Hint: 'count' holds the number of books currently in the list
int add(char* bookTitle_input, char* author_input, char* booktype_input, unsigned int bookId_input, unsigned int aisle_input)
{
	
	//Full condition
	if (count == MAX_BOOKS)
	{

		//2 for full
		return 2;

	}//End of full condition

	//Search/Add condition
	else
	{

		//Copy found variable
		int found = 0;

		//Searching iterator
		for (int a = 0; a < count; a++)
		{

			//Copy found condition
			if (bookId_input == list[a].bookId)
			{

				//Copy found
				found = 1;
				break;

			}//End of copy found condition

		}//End of searching iterator

		//Exists condition
		if (found == 1)
		{

			//0 for exists
			return 0;

		}//End of exists condition

		//Add
		else
		{

			//Title and author copy
			strcpy(list[count].bookTitle, bookTitle_input);
			strcpy(list[count].author, author_input);

			//Nonfiction case
			if (stricmp(booktype_input, "Nonfiction") == 0)
			{

				//Nonfiction binding
				list[count].booktype = Nonfiction;

			}//End of nonfiction case

			//Default to fiction
			else
			{

				//Fiction binding
				list[count].booktype = Fiction;

			}//End of default fiction

			//ID and aisle assignment
			list[count].bookId = bookId_input;
			list[count].aisle = aisle_input;

			//Increment counter
			count++;

			//1 for successful add
			return 1;

		}//End of add

	}//End of search/add condition

}//End of function add



// This function displays the book list with the details (struct elements) of each book. 
void display()
{
	char* booktypeString = "Nonfiction";						// dummy init

	for (int i = 0; i < count; i++)								// iterate through the list
	{
		printf("\nBook Title: %s", list[i].bookTitle);			// display Book title
		printf("\nAuthor Name: %s", list[i].author);			// display author

		if (list[i].booktype == Nonfiction)						// find what to display for book type
			booktypeString = "Nonfiction";
		else
			booktypeString = "Fiction";

		printf("\nBook Type: %s", booktypeString);			// display book type
		printf("\nBook ID: %d", list[i].bookId);			// display book id
		printf("\nAisle number: %d", list[i].aisle);		// display aisle number
		printf("\n");
	}

}

// Q2 : sort (10 points)
// This function is used to sort the list(array of structs) numerically by book ID.
// Parse the list and compare the book IDs to check which one should appear before the other in the list.
// Sorting should happen within the list. That is, you should not create a new array of structs having sorted books.
// Hint: Use a temp struct (already declared) if you need to swap two structs in your logic
void sort()
{
	struct libraryRecord libraryTemp;	// needed for swapping structs. Not absolutely necessary to use.
	
	//Outer sorting iterator
	for (int a = 0; a < count - 1; a++)
	{

		//Index of smallest element
		int min = a;

		//Inner sorting iterator
		for (int b = a + 1; b < count; b++)
		{

			//Smaller condition
			if (list[min].bookId > list[b].bookId)
			{

				//Assign smallest index
				min = b;

			}//End of smaller condition

			//Copy of preceeding element to temp
			strcpy(libraryTemp.bookTitle, list[a].bookTitle);
			strcpy(libraryTemp.author, list[a].author);
			libraryTemp.booktype = list[a].booktype;
			libraryTemp.bookId = list[a].bookId;
			libraryTemp.aisle = list[a].aisle;

			//Reassignment of smallest element
			strcpy(list[a].bookTitle, list[min].bookTitle);
			strcpy(list[a].author, list[min].author);
			list[a].booktype = list[min].booktype;
			list[a].bookId = list[min].bookId;
			list[a].aisle = list[min].aisle;

			//Reassginment of preceeding element
			strcpy(list[min].bookTitle, libraryTemp.bookTitle);
			strcpy(list[min].author, libraryTemp.author);
			list[min].booktype = libraryTemp.booktype;
			list[min].bookId = libraryTemp.bookId;
			list[min].aisle = libraryTemp.aisle;

		}//End of inner sorting iterator

	}//End of outer sorting iterator

	// display message for user to check the result of sorting.
	printf("\nBook list sorted! Use display option 'd' to view sorted list.\n");

}//End of function sort

// save() is called at the end of main()
// This function saves the array of structures to file. It is already implemented.
// You should read and understand how this code works. It will help you with 'load()' function.
// save() is called at end of main() to save the book list to a file.
// The file is saved at the same place as your C file. For VS, the default directory looks like this:
// C:\Users\<username>\Documents\Visual Studio 2017\Projects\Project1\Project1
// You can simply delete the file to 'reset the list' or to avoid loading from it.
void save(char* fileName)
{
	FILE* file;
	int i, booktypeValue = 0;
	file = fopen(fileName, "wb");		// open file for writing

	fwrite(&count, sizeof(count), 1, file);		// First, store the number of books in the list

	// Parse the list and write book record to file

	for (i = 0; i < count; i++)
	{
		fwrite(list[i].bookTitle, sizeof(list[i].bookTitle), 1, file);
		fwrite(list[i].author, sizeof(list[i].author), 1, file);
		// convert enum to a number for storing
		if (list[i].booktype == Nonfiction)
			booktypeValue = 0;		// 0 for Nonfiction
		else
			booktypeValue = 1;		// 1 for Fiction

		fwrite(&booktypeValue, sizeof(booktypeValue), 1, file);
		fwrite(&list[i].bookId, sizeof(list[i].bookId), 1, file);
		fwrite(&list[i].aisle, sizeof(list[i].aisle), 1, file);
	}

	fclose(file);			// close the file after writing
}

// Q3 : delete (10 points)
// This function is used to delete a book by ID.
// Parse the list and compare the book IDs to check which one should be deleted.
// Restore the array structure after removal of the book record.
// Return 0 if the specified ID was not found. Return 1 upon successful removal of a record.
int delete(unsigned int bookId_input)
{
	struct libraryRecord libraryTemp;	// needed for swapping structs. Not absolutely necessary to use.
	
	//Index to remove
	int target = -1;

	//Searching iterator
	for (int a = 0; a < count; a++)
	{

		//Target found
		if (list[a].bookId == bookId_input)
		{

			//Assign index and break iterator
			target = a;
			break;

		}//End of target found

	}//End of serarching iterator

	//No target condition
	if (target == -1)
	{

		//0 for not found
		return 0;

	}//End of no target condition

	//Delete condition
	else
	{
	
			//Removal iterator
			for (int b = target; b < count; b++)
			{

				//Element replacement
				strcpy(list[b].bookTitle, list[b + 1].bookTitle);
				strcpy(list[b].author, list[b + 1].author);
				list[b].booktype = list[b + 1].booktype;
				list[b].bookId = list[b + 1].bookId;
				list[b].aisle = list[b + 1].aisle;

			}//End of removal iterator

			//Update count
			count--;

	}//End of delete condition

}//End of function delete

// Q4:  load (10 points)
// This function is called in the beginning of main().
// This function reads the book list from the saved file and builds the array of structures 'list'. 
// In the first run of the program, there will be no saved file because save() is called at the end of program.
// So at the begining of this function, write code to open the file and check if it exists. If file does not exist, then return from the function.
// (See expected output of add() in homework question file. It displays "Book_List.txt not found" because the file did not exist initially.)
// If the file exists, then parse the book list to read the book details from the file.
// Use the save function given above as an example of how to write this function. Notice the order in which the struct elements are saved in save()
// You need to use the same order to read the list back.
// NOTE: The saved file is not exactly readable because all elements of the struct are not string or char type.
//       So you need to implement load() similar to how save() is implemented. Only then the 'list' will be loaded correctly.
//		You can simply delete the file to 'reset the list' or to avoid loading from it.
void load(char* fileName)
{
	
	//Local variables
	FILE* fileBuffer;
	int bookTypeValue = 0;
	fileBuffer = fopen(fileName, "rb");

	//Error catch
	if (fileBuffer != NULL)
	{

		//Read count
		fread(&count, sizeof(count), 1, fileBuffer);

		//Reading iterator
		for (int a = 0; a < count; a++)
		{

			//Read members
			fread(list[a].bookTitle, sizeof(list[a].bookTitle), 1, fileBuffer);
			fread(list[a].author, sizeof(list[a].author), 1, fileBuffer);

			//Fiction case
			if (list[a].booktype == Fiction)
			{

				bookTypeValue = 1;

			}//End of fiction case

			//Read members
			fread(&bookTypeValue, sizeof(bookTypeValue), 1, fileBuffer);
			fread(&list[a].bookId, sizeof(list[a].bookId), 1, fileBuffer);
			fread(&list[a].aisle, sizeof(list[a].aisle), 1, fileBuffer);

		}//End of reading iterator

		fclose(fileBuffer);

		//Successful Load
		printf("Books record loaded from %s.\n", fileName);

	}//End of error catch

	//Error print
	else
	{

		//Actual print
		printf("%s not found\n", fileName);

	}//End of error print

}//End of function load