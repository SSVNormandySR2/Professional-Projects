// Assignment #7
// Name: Vincent Latona
// Description: This header file is responsible for
//				the creation of stack objects and their operations

#include <cstdlib>
#include <iostream>
#include <string>
#include "LinkedList.h"

//Stack class for edge information
class Stack
{

private:
	int size;
	int count;
	Edge** edges;

public:
	Stack(int);
	bool push(Edge*);
	Edge* pop();
	void stackContents();
	void printStack();
	string printEdge(int);

};