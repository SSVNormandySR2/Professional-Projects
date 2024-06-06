// Assignment #7
// Name: Vincent Latona
// Description: This program implements the operations
//				associated with the graph class

#include "Graph.h"

/*
* This constructor builds an initial Graph
*/
Graph::Graph(int n, int m)
{

	//Set private data
	nodes = n;
	edges = m;
	tempStack = new Stack(edges);
	circuit = new Stack(edges);
	nodeList = new LinkedList[nodes + 1];
	color = new int[nodes + 1];
	//Color Scheme is as follows:
	//White = 0
	//Gray = 1
	//Black = -1

	//Array initialization
	for (int a = 0; a < nodes + 1; a++)
	{

		//Create objects and initialize variables
		nodeList[a] = LinkedList();
		color[a] = 0;

	}//End of array initialization

}//End of Constructor

/*
* This destructor handles allocated memory no longer needed
*/
Graph::~Graph()
{

	//Delete adjacency list and colors
	delete[] nodeList;
	delete[] color;

}//End of destructor

/*
* This function inserts an edge into the graph
*/
bool Graph::insertEdge(int src, int dst, int weight)
{

	//Attempt to insert edges
	Edge* insert1 = nodeList[src].insertEdge(src, dst, weight);
	Edge* insert2 = nodeList[dst].insertEdge(dst, src, weight);

	//Set duplicate path for each node
	bool ins1 = insert1->setDuplicate(insert2);
	bool ins2 = insert2->setDuplicate(insert1);

	//Return true or false
	return (ins1 || ins2);

}//End of function insertEdge

/*
* This function performs an augmented DFS on the graph
*/
void Graph::DFS()
{

	//Print circuit computation message
	cout << "Computing its circuit . . . . .\n\n";

	//Graph iterator
	for (int a = 1; a < nodes + 1; a++)
	{

		//Traverse case
		if (color[a] == 0 || color[a] == 1)
		{

			//Visit recursively
			DFS_VISIT(a);

		}//End of traverse case

	}//End of graph iterator

	//Print circuit
	cout << "The circuit is: \n";
	circuit->printStack();

}//End of function DFS

/*
* This function assists in performing the augmented DFS
*/
void Graph::DFS_VISIT(int index)
{

	//Set color gray
	if (color[index] == 0)
	{

		//Set color to gray
		color[index] = 1;

	}//End of set color gray

	//Edge iterator
	Edge* visit = nodeList[index].getFirst();

	//Adjacency list iterator
	while (visit != NULL)
	{

		//Untraversed case
		if (!visit->beenTraversed())
		{

			//Recursive case
			if (color[visit->getDst()] == 0 || color[visit->getDst()] == 1)
			{

				//Push edge onto tempStack
				tempStack->push(visit);

				//Document traversal
				visit->setTraversed();
				visit->getDuplicate()->setTraversed();

				//Print stack contents
				cout << "Circuit: ";
				circuit->stackContents();
				cout << "Stack: ";
				tempStack->stackContents();
				cout << endl;

				//Recursively call on next node
				DFS_VISIT(visit->getDst());

			}//End of recursive case

		}//End of untraversed case

		//Iterate to next edge
		visit = visit->getNext();

	}//End of adjacency list iterator

	//Set color black
	color[index] = -1;

	//Pop from stack
	Edge* push = tempStack->pop();

	//Push case
	if (push != NULL)
	{

		//Populate circuit stack
		circuit->push(push->getDuplicate());

		//Print stack contents
		cout << "Circuit: ";
		circuit->stackContents();
		cout << "Stack: ";
		tempStack->stackContents();
		cout << endl;

	}//End of push case

}//End of function DFS_VISIT

/*
* This function prints the contents of the graph
*/
void Graph::printGraph()
{

	//Display graph message
	cout << "The Graph contains:\n"
		<< "-------------------\n";

	//Adjacency list iterator
	for (int a = 1; a < nodes + 1; a++)
	{

		//Print node
		cout << "From: " << a << " with its degree "
			<< nodeList[a].getDegree() << endl;
		nodeList[a].printList();

	}//End of adjacency list iterator

}//End of function printGraph