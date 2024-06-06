// Assignment #8
// Name: Vincent Latona
// Description: This header file is responsible for the creation
//				of graph objects and defining their operations.

#ifndef GRAPH_H
#define GRAPH_H

#define INF 500

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
	int odds;
	int* oddSet;
	Edge* match;
	int index;
	int* color;
	int** distance;
	int** pi;
	int** oddNodes;
	int** oddPi;
	Stack* tempStack;
	Stack* circuit;

public:
	Graph(int, int);
	~Graph();
	bool insertEdge(int, int, int, bool);
	void buildOdds();
	void Floyd_Warshall();
	void perfectMatching();
	void sortEdges();
	void DFS();
	void DFS_VISIT(int);
	void printGraph();

};//End of class Graph

#endif /*GRAPH_H*/
