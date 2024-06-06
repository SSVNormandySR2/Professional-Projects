
/*
* Vincent Latona
* IDE: Visual Studio
*/

//Necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996) // for Visual Studio Only

//Macro for array length
#define MAX_NAME_LENGTH 25

//Global counter for read/write
int count = 0;

//Typedef for bookType type
typedef enum { Nonfiction = 0, Fiction } bookType;

//Structure for Library Records
struct libraryRecord
{

	//Structure members
	char bookTitle[MAX_NAME_LENGTH];
	char author[MAX_NAME_LENGTH];
	bookType booktype;
	unsigned int bookId;
	unsigned int aisle;
	struct libraryRecord* next;

} *head = NULL;

//Forward Declaration of Functions
void flushStdIn();
void executeAction(char);
void save(char* fileName);
int add(char* bookTitle_input, char* author_input, char* booktype_input, unsigned int bookId_input, unsigned int aisle_input);
void sort();
int delete(unsigned int bookId_input);
void load(char* fileName);
void display();


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
		else if (add_result == -1)
			printf("\nOut of Memory! \n\n");
		else
			printf("\nBook successfully added to the list! \n\n");

		break;
	case 'r':
		printf("Please enter ID number of book to be deleted: ");
		scanf("%d", &bookId_input);
		flushStdIn();
		int delete_result = delete(bookId_input);
		if (delete_result == 0)
			printf("\nBook not found in the list! \n\n");
		else if (delete_result == 1)
			printf("\nBook deleted successfully! \n\n");
		break;
	case 'd': display();	break;
	case 's': sort();		break;

	case 'q': break;
	default: printf("%c is invalid input!\n", c);
	}
}

/*
* This function attemtps to add a node to the end of linked list of Library Records
* This function returns: 0 for a detected duplicate attempting to be added,
* -1 for a failure to acquire memory to add a new node, and
* 1 for successful addition to the end of the list
*/
int add(char* bookTitle_input, char* author_input, char* booktype_input, unsigned int bookId_input, unsigned int aisle_input)
{

	//Temporary pointers to iterate through the linked list
	struct libraryRecord* temp;
	struct libraryRecord* add;

	//Point temporary pointers
	temp = head;
	add = NULL;

	//Duplicate finder
	while (temp != NULL)
	{
		
		//Duplicate condition
		if (bookId_input == temp->bookId)
		{

			//0 for duplicate
			return 0;

		}//End of duplicate condition

		//Move to next node
		add = temp;
		temp = temp->next;

	}//End of duplicate finder

	//
	struct libraryRecord* p;
	p = (struct libraryRecord*) malloc(sizeof(struct libraryRecord));

	//No memory condition
	if (p == NULL)
	{

		//-1 for no more memory
		return -1;

	}//End of no memory condition

	//Safe add case
	else
	{

		//Assignment of members
		strcpy(p->bookTitle, bookTitle_input);
		strcpy(p->author, author_input);

		//Nonfiction case
		if (stricmp(booktype_input, "Nonfiction") == 0)
		{

			//Assign to Nonfiction type
			p->booktype = Nonfiction;

		}//End of nonfiction case

		//Fiction case
		else
		{

			//Assign to Fiction type
			p->booktype = Fiction;

		}//End of fiction case

		//Member assignment continued
		p->bookId = bookId_input;
		p->aisle = aisle_input;

		//Empty list pointer assignment
		if (head == NULL)
		{

			//Pointer assignments, count increment, and 1 for successful add
			head = p;
			p->next = NULL;
			count++;
			return 1;

		}//End of empty list pointer assignment

		//Add to the end assignments
		else
		{

			//Pointer assignments, count increment, and 1 for successful add
			p->next = add->next;
			add->next = p;
			count++;
			return 1;

		}//End of add to the end assignments

	}//End of safe add

}//End of function add

/*
* This function sorts the linked list of Library Records by libraryId
*/
void sort()
{

	//Empty list case
	if (head == NULL)
	{

		//Error message print
		printf("\nBook list is empty!\n\n");

	}//End of empty list case

	//Single node case
	else if (head->next == NULL)
	{

		//Sorted list message print
		printf("\nBook list sorted! Use display option 'd' to view sorted list.\n");

	}//End of single node case

	//Sorting case
	else
	{
		
		//Iterator pointers
		struct libraryRecord* follower;
		struct libraryRecord* iterator;

		//Temporary storage node
		struct libraryRecord temp;

		//Outer sorting iterator
		for (follower = head; follower != NULL; follower = follower->next)
		{

			//Smallest node pointer
			struct libraryRecord* min = follower;

			//Inner sorting iterator
			for (iterator = follower->next; iterator != NULL; iterator = iterator->next)
			{

				//Smaller node case
				if (min->bookId > iterator->bookId)
				{

					//Reassign smallest node
					min = iterator;

				}//End of smaller node case

			}//End of inner sorting iterator

			//Copy to temporary storage
			strcpy(temp.bookTitle, follower->bookTitle);
			strcpy(temp.author, follower->author);
			temp.booktype = follower->booktype;
			temp.bookId = follower->bookId;
			temp.aisle = follower->aisle;

			//Reassign smallest node data
			strcpy(follower->bookTitle, min->bookTitle);
			strcpy(follower->author, min->author);
			follower->booktype = min->booktype;
			follower->bookId = min->bookId;
			follower->aisle = min->aisle;

			//Reassign temporary data to original smallest node
			strcpy(min->bookTitle, temp.bookTitle);
			strcpy(min->author, temp.author);
			min->booktype = temp.booktype;
			min->bookId = temp.bookId;
			min->aisle = temp.aisle;

		}//End of outer sorting iterator

		//Sorted list message print
		printf("\nBook list sorted! Use display option 'd' to view sorted list.\n");

	}//End of sorting case

}//End of function sort

/*
* This function searches and attempts to delete a user-chosen node
* This function returns: 0 for non-existant node and for an empty list
* and 1 for successfuly deletion
*/
int delete(unsigned int bookId_input)
{

	//Empty list case
	if (head == NULL)
	{

		//0 for empty
		return 0;

	}//End of empty list case

	//Searching case
	else
	{

		//Sentinel for found target
		int found = 0;

		//Iterator pointers
		struct libraryRecord* follower = NULL;
		struct libraryRecord* iterator = head;

		//Searching iterator
		while (iterator != NULL)
		{

			//Target found case
			if (iterator->bookId == bookId_input)
			{

				//Target found
				found = 1;
				break;

			}//End of target found case

			//Pointer reassignments
			follower = iterator;
			iterator = iterator->next;

		}//End of searching iterator

		//Head removal case
		if (found == 1 && follower == NULL)
		{

			//Temporary pointer for deletion
			struct libraryRecord* temp = head;
			
			//Deletion, garbage removal, and 1 for successful deletion
			head = head->next;
			free(temp);
			count--;
			return 1;

		}//End of head removal case

		//Arbitrary removal case
		else if (found == 1)
		{

			//Temporary pointer for deletion
			struct libraryRecord* temp = iterator;

			//Deletion, garbage removal, and 1 for successful deletion
			follower->next = iterator->next;
			free(temp);
			count--;
			return 1;

		}//End of arbitrary removal case

		//Target not found case
		else
		{

			//0 for not found
			return 0;

		}//End of target not found case

	}//End of searching case

}//End of function delete

/*
* This function displays the contents of the linked list of Library Records
*/
void display()
{
	
	//Temporary pointer to head
	struct libraryRecord* temp;
	temp = head;

	//Empty list case
	if (temp == NULL)
	{

		//Display message saying list is empty
		printf("\nBook list is empty!\n");

	}//End of empty list case

	//List printing case
	else
	{

		//Printing iterator
		while (temp != NULL)
		{

			//Member printing
			printf("\nBook Title: %s", temp->bookTitle);
			printf("\nAuthor Name: %s", temp->author);

			//Nonfiction case
			if (temp->booktype == 0)
			{

				//Book type print
				printf("\nBook Type: Nonfiction");

			}//End of nonfiction case

			//Fiction case
			else
			{

				//Book type print
				printf("\nBook Type: Fiction");

			}//End of fiction case

			//Member printing continued
			printf("\nBook ID: %d", temp->bookId);
			printf("\nAisle number: %d\n", temp->aisle);

			//Pointer reassignment
			temp = temp->next;

		}//End of printing iterator

	}//End of list prinitng case

}//End of function display

/*
* This function saves the structures stored in the linked list by writing them to a file
*/
void save(char* fileName)
{

	//Local variables
	FILE* fileBuffer;
	int booktypeValue = 0;

	//Open binary file to write
	fileBuffer = fopen(fileName, "wb");

	//Error test
	if (fileBuffer != NULL)
	{

		//Temporary pointer and head assignment
		struct libraryRecord* temp = head;

		//Write count to file
		fwrite(&count, sizeof(count), 1, fileBuffer);

		//Writing iterator
		while (temp != NULL)
		{

			//Writing data members to file
			fwrite(temp->bookTitle, sizeof(temp->bookTitle), 1, fileBuffer);
			fwrite(temp->author, sizeof(temp->author), 1, fileBuffer);

			//Fiction case
			if (temp->booktype == Fiction)
			{

				//Change book type
				booktypeValue = 1;

			}//End of fiction case

			//Writing data members to file continued
			fwrite(&booktypeValue, sizeof(booktypeValue), 1, fileBuffer);
			fwrite(&temp->bookId, sizeof(temp->bookId), 1, fileBuffer);
			fwrite(&temp->aisle, sizeof(temp->aisle), 1, fileBuffer);

			//Move to next node
			temp = temp->next;

		}//End of writing iterator

		//Close file when finished
		fclose(fileBuffer);

	}//End of error test

}//End of function save

/*
* This function loads the structures stored in the linked list by reading them from a file
*/
void load(char* fileName)
{

	//Local variables
	FILE* fileBuffer;
	int bookTypeValue = 0, read;
	char bookTitle[MAX_NAME_LENGTH], author[MAX_NAME_LENGTH];
	unsigned int bookId, aisle = 0;
	char* bookType;

	//Open binary file to read
	fileBuffer = fopen(fileName, "rb");

	//Error catch
	if (fileBuffer != NULL)
	{

		//Read in counter value
		fread(&count, sizeof(count), 1, fileBuffer);

		//Set read to count and reset count
		read = count;
		count = 0;

		//Reading iterator
		for (int a = 0; a < read; a++)
		{

			//Read data members to local variables
			fread(bookTitle, sizeof(bookTitle), 1, fileBuffer);
			fread(author, sizeof(author), 1, fileBuffer);
			fread(&bookTypeValue, sizeof(bookTypeValue), 1, fileBuffer);

			//Nonfiction case
			if (bookTypeValue == 0)
			{

				//Convert string to nonfiction
				bookType = "Nonfiction";

			}//End of nonfiction case

			//Fiction case
			else
			{

				//Convert string to fiction
				bookType = "Fiction";

			}//End of fiction case

			//Read data members to local variables continued
			fread(&bookId, sizeof(bookId), 1, fileBuffer);
			fread(&aisle, sizeof(aisle), 1, fileBuffer);

			//Add new node with given members
			add(bookTitle, author, bookType, bookId, aisle);

		}//End of reading iterator

		//Close the file when finished
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