// Assignment #8
// Name: Vincent Latona
// Description: This program implements the operations defined
//				on stack objects.

#include "Stack.h"

/*
* This constructor defines the size of the stack
*/
Stack::Stack(int listSize)
{

	//Set private data
	size = listSize;
	count = 0;
	edges = new Edge*[size];

	//Initialize array of pointers
	for (int a = 0; a < size; a++)
	{

		//Point each element to NULL
		edges[a] = NULL;

	}//End of initialization iterator

}//End of Constructor

/*
* This destructor performs garbage collection for a stack object
*/
Stack::~Stack()
{

	//Delete array of edges
	delete[] edges;

}//End of Destructor

/*
* This function pushes a new element onto a stack
*/
bool Stack::push(Edge* edge)
{

	//Full stack case
	if (count == size)
	{

		//Return false for full stack
		return false;

	}//End of full stack case

	//Push element to stack and return true
	edges[count] = edge;
	count++;
	return true;

}//End of function push

/*
* This function returns the top element of the stack
*/
Edge* Stack::pop()
{

	//Empty stack case
	if (count == 0)
	{

		//Return NULL for empty stack
		return NULL;

	}//End of empty stack case

	//Return top of stack and shift elements
	Edge* pop = edges[count-1];
	edges[count-1] = NULL;
	count--;
	return pop;

}//End of function pop

/*
* This function prints the contents of the stack
*/
void Stack::stackContents()
{

	//Empy stack case
	if (count == 0)
	{

		//Print empty message
		cout << "Empty\n";
		return;

	}//End of empty stack case

	//Display iterator
	for (int a = 0; a < count; a++)
	{

		//Print stack edge
		cout << printEdge(a);

	}//End of display iterator

	cout << endl;

}//End of function stackContents

/*
* This function prints the stack in a list fashion
*/
void Stack::printStack()
{

	//Empy stack case
	if (count == 0)
	{

		//Print empty message
		cout << "Empty\n" << endl;
		return;

	}//End of empty stack case

	//Display iterator
	for (int a = 0; a < count; a++)
	{

		//Print stack edge
		cout << printEdge(a) << endl;

	}//End of display iterator

}//End of function printStack

/*
* This function helps to visualize edges for the stack printers
*/
string Stack::printEdge(int index)
{

	//Get src and dst
	int src = edges[index]->getSrc();
	int dst = edges[index]->getDst();

	//Concatenate string of edge contents
	string separator = ",";
	string edge = "(" + to_string(src) + separator + to_string(dst) + ") ";

	//Return edge string
	return edge;

}//End of function printEdge