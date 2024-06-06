// Assignment #8
// Name: Vincent Latona
// Description: This header file is responsible for the creation
//				of stack objects and defining their operations

#ifndef STACK_H
#define STACK_H

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
	~Stack();
	bool push(Edge*);
	Edge* pop();
	void stackContents();
	void printStack();
	string printEdge(int);

};

#endif /*STACK_H*/