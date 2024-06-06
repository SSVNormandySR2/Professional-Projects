// Assignment #7
// Name: Vincent Latona
// Description: This header file is responsible for
//				the creation of graph objects and 
//				pre-defines their operations

#include <cstdlib>
#include <iostream>
#include "Stack.h"
#include "LinkedList.h"

using namespace std;

//Graph class represents a graph structure
class Graph
{

private:
	int nodes;
	int edges;
	LinkedList* nodeList;
	int* color;
	Stack* tempStack;
	Stack* circuit;

public:
	Graph(int, int);
	~Graph();
	bool insertEdge(int, int, int);
	void DFS();
	void DFS_VISIT(int);
	void printGraph();

};//End of class Graph