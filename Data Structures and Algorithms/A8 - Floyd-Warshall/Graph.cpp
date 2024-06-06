// Assignment #8
// Name: Vincent Latona
// Description: This program implements the operations defined
//				on graph objects.

#include "Graph.h"

/*
* This constructor builds an initial Graph
*/
Graph::Graph(int n, int m)
{

	//Set private data
	nodes = n;
	edges = m;
	odds = 0;
	nodeList = new LinkedList[nodes+1];
	color = new int[nodes+1];
	index = 0;
	distance = new int*[nodes+1];
	pi = new int*[nodes+1];

	//Adj list initialization
	for (int a = 1; a < nodes+1; a++)
	{

		//Initialize array contents
		nodeList[a] = LinkedList();
		color[a] = 0;

	}//End of adj list initialization

	//Initialization of arrays
	for (int a = 0; a < nodes+1; a++)
	{

		//Create 2-D arrays
		distance[a] = new int[nodes+1];
		pi[a] = new int[nodes+1];

	}//End of array initialization

}//End of Constructor

/*
* This destructor handles allocated memory no longer needed
*/
Graph::~Graph()
{

	//Delete all heap arrays
	delete[] nodeList;
	delete[] color;
	delete[] oddSet;
	delete[] match;
	
	//Delete large FW arrays
	for (int a = 0; a < nodes+1; a++)
	{

		//Delete large FW arrays of arrays
		delete[] distance[a];
		delete[] pi[a];

	}//End of large FW deletion

	//Delete large FW arrays
	delete[] distance;
	delete[] pi;

	//Delete small FW arrays
	for (int a = 0; a < odds; a++)
	{

		//Delete small FW arrays of arrays
		delete[] oddNodes[a];
		delete[] oddPi[a];

	}//End of small FW deletion

	//Delete small FW arrays
	delete[] oddNodes;
	delete[] oddPi;

	//Delete stacks
	delete tempStack;
	delete circuit;

}//End of destructor

/*
* This function inserts an edge into the graph
*/
bool Graph::insertEdge(int src, int dst, int weight, bool virt)
{

	//Attempt to insert edges
	Edge* insert1 = nodeList[src].insertEdge(src, dst, weight, virt);
	Edge* insert2 = nodeList[dst].insertEdge(dst, src, weight, virt);

	//Set duplicate path for each node
	bool ins1 = insert1->setDuplicate(insert2);
	bool ins2 = insert2->setDuplicate(insert1);

	//Return true or false
	return (ins1 || ins2);

}//End of function insertEdge

/*
* This function counts the number of nodes with odd degree and modifies the affected arrays
*/
void Graph::buildOdds()
{

	//Stack to build odd set
	Stack builder = Stack(nodes);

	//Adj list iterator
	for (int a = 1; a < nodes+1; a++)
	{

		//Odd degree check
		if (nodeList[a].getDegree() % 2 != 0)
		{

			//Increment odds and push edge to stack
			odds++;
			Edge* insert = nodeList[a].getFirst();
			builder.push(insert);

		}//End of odd degree check

	}//End of adj list iterator

	//Update array size
	int i = ((odds*odds)-odds)/2;
	match = new Edge[i];
	oddSet = new int[odds];
	oddNodes = new int*[odds];
	oddPi = new int*[odds];

	//Initialize oddNodes and oddPi arrays
	for (int a = 0; a < odds; a++)
	{

		//Create 2-D array
		oddNodes[a] = new int[odds];
		oddPi[a] = new int[odds];

	}//End of oddNodes and oddPi array initialization

	//Odd set builder
	for (int a = odds; a > 0; a--)
	{

		//Insert odd nodes
		int insert = builder.pop()->getSrc();
		oddSet[a-1] = insert;

	}//End of odd set builder

	//Odd display message
	cout << "The odd-degree vetices in G: O = { ";

	//Display iterator
	for (int a = 0; a < odds; a++)
	{

		//Dispaly contents
		cout << oddSet[a] << " ";

	}//End of display iterator

	//Finish display message
	cout << "}\n\n";

}//End of function countOdds

/*
* This function performs the Floyd-Warshall algorithm for the entire graph, and the odd subset
*/
void Graph::Floyd_Warshall()
{

	//Initializer iterators
	//Row iterator
	for (int a = 1; a < nodes+1; a++)
	{

		//Column iterator
		for (int b = 1; b < nodes+1; b++)
		{

			//Same node case
			if (a == b)
			{

				//Make 0
				distance[a][b] = 0;
				pi[a][b] = 0;

			}//End of same node case

			//Arbitrary node case
			else
			{

				//Initialize pi and distance
				pi[a][b] = 0;
				distance[a][b] = INF;

			}//End of arbitrary node case

		}//End of column iterator

	}//End of row iterator

	//Path adding iterator
	for (int a = 1; a < nodes+1; a++)
	{

		//Edge iterator
		Edge* traverse = nodeList[a].getFirst();

		//Adj list iterator
		while (traverse != NULL)
		{

			//Get path information
			int b = traverse->getDst();
			int w = traverse->getWeight();

			//Update distance and pi
			distance[a][b] = w;
			pi[a][b] = a;

			//Iterate
			traverse = traverse->getNext();

		}//End of adj list iterator

	}//End of path adding iterator

	//Floyd-Warshall Algorithm
	//Intermediate node iterator
	for (int k = 1; k < nodes+1; k++)
	{

		//Row iterator
		for (int a = 1; a < nodes+1; a++)
		{

			//Column iterator
			for (int b = 1; b < nodes+1; b++)
			{

				//Smaller distance case
				if (distance[a][b] > distance[a][k] + distance[k][b])
				{

					//Update distance and pi arrays
					distance[a][b] = distance[a][k] + distance[k][b];
					pi[a][b] = pi[k][b];

				}//End of smaller distance case

			}//End of column iterator

		}//End of row iterator

	}//End of intermediate node iterator

	//Populate oddNodes and oddPi arrays from Floyd-Warshall
	//Row iterator
	for (int a = 0; a < odds; a++)
	{

		//Column iterator
		for (int b = 0; b < odds; b++)
		{

			//Use distance and pi arrays to make subset
			oddNodes[a][b] = distance[oddSet[a]][oddSet[b]];
			oddPi[a][b] = pi[oddSet[a]][oddSet[b]];

		}//End of column iterator

	}//End of row iterator

}//End of function Floyd_Warshall

/*
* This function performs the perfect matching algorithm
*/
void Graph::perfectMatching()
{

	//Print M contents
	cout << "The perfect matching in O: M = { ";

	//Create perfect array of edges
	int i = ((odds)*(odds)-odds)/2;
	Edge* perfect = new Edge[i];

	//Insertion case
	if (index > 0)
	{

		//Size of filled perfect array
		int c = 0;

		//Insert first edge
		perfect[0] = match[0];
		c++;

		//Print edge
		cout << "(" << perfect[0].getSrc() << "," << perfect[0].getDst() << ") ";

		//Match array iterator
		for (int a = 1; a < index; a++)
		{

			//Perfect array iterator
			int b = 0;
			
			//Checking iterator
			while (b < c)
			{

				//Possible insert case
				if ((match[a].getSrc() != perfect[b].getSrc()) && (match[a].getDst() != perfect[b].getSrc())
					&& (match[a].getSrc() != perfect[b].getDst()) && (match[a].getDst() != perfect[b].getDst()))
				{

					//Iterate and check again
					b++;

				}//End of possible insert case

				//Edge fail case
				else
				{

					//Break loop
					break;

				}//End of edge fail case

			}//Checking iterator

			//Insertion case
			if (b == c)
			{

				//Add edge to M, print the edge, and increment count in M
				perfect[c] = match[a];
				cout << "(" << perfect[c].getSrc() << "," << perfect[c].getDst() << ") ";
				c++;

			}//End of insertion case

		}//End of match array iterator

		//Insert edges into the table as virtual
		for (int a = 0; a < c; a++)
		{

			//Insert virtual edges and increment edge count
			insertEdge(perfect[a].getSrc(), perfect[a].getDst(), perfect[a].getWeight(), true);
			edges = edges + perfect[a].getWeight();

		}//End of virtual insertion

		//Instantiate stacks for DFS with new edges
		tempStack = new Stack(edges);
		circuit = new Stack(edges);

	}//End of insertion case

	//Terminate print
	cout << "}\n\n";

}//End of function perfectMatching

/*
* This function sorts the edges of the odd set
*/
void Graph::sortEdges()
{

	//Iterators to populate the array of edges
	//Row iterator
	for (int a = 0; a < odds; a++)
	{

		//Column iterator
		for (int b = 0; b < odds; b++)
		{

			//Upper triangular matrix
			if (b > a)
			{

				//Create new edge and insert into array to be sorted (primary)
				Edge insert = Edge(oddSet[a], oddSet[b], oddNodes[a][b]);
				match[index] = insert;
				index++;

			}//End of upper triangular matrix

		}//End of column iterator

	}//End of row iterator

	//Sorting case
	if (index > 0)
	{

		//Insertion Sort by weight
		for (int a = 1; a < index; a++)
		{

			//Sorting key
			Edge shift = match[a];
			int keyValue = match[a].getWeight();

			//Sub list demarcation point
			int b = a-1;

			//Array shifter
			while (b > -1 && match[b].getWeight() > keyValue)
			{

				//Array shift and decrement
				match[b+1] = match[b];
				b--;

			}//End of array shifter

			//Final insert
			match[b+1] = shift;

		}//End of InsertionSort by weight

		//Print sorted odd edges
		cout << "The sorted edges of odd-degree vertices from Floyd-Warshall:\n";

		//Printing iterator
		for (int a = 0; a < index; a++)
		{

			//Print edge information
			cout << "(" << match[a].getSrc() << "," << match[a].getDst() << ") "
				<< "with its weight " << match[a].getWeight() << endl;

		}//End of printing iterator

		//Spacing
		cout << endl;

	}//End of sorting case

}//End of function sortEdges

/*
* This function performs an augmented DFS on the graph
*/
void Graph::DFS()
{

	//Graph iterator
	for (int a = 1; a < nodes+1; a++)
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

		//Virtual path case
		if (push->isVirtual() && push->getWeight() > 1)
		{

			//Create local stack for nodes along the path
			int* stack = new int[edges];
			int i = 0;

			//Key destination holder
			int dst = push->getDst();

			//Sentinel for iterator
			bool done = false;

			//Push final destination onto the stack
			stack[0] = dst;
			i++;

			//Path iterator
			while (!done)
			{

				//Stopping condition
				if (push->getSrc() == pi[push->getSrc()][dst])
				{

					//Set sentinel and push to the stack
					stack[i] = push->getSrc();
					done = true;

				}//End of stopping condition

				//Iterative case
				else
				{

					//Change destination holder and push it to the stack
					dst = pi[push->getSrc()][dst];
					stack[i] = dst;
					i++;

				}//End of iterative case

			}//End of path iterator

			//Edge building iterator
			for (int a = 0; a < i; a++)
			{

				//Build edge and insert into circuit
				Edge* insert = new Edge(stack[a], stack[a+1], 1);
				circuit->push(insert);

			}//End of edge building iterator

			//Delete unnecessary memory
			delete[] stack;

		}//End of virtual path case

		//Non-virtual case
		else
		{

			//Populate circuit stack
			circuit->push(push->getDuplicate());

		}//End of non-virtual case

	}//End of push case

}//End of function DFS_VISIT

/*
* This function prints the contents of the graph
*/
void Graph::printGraph()
{

	//Display G prompt
	cout << "Results of Floyd-Warshall on G: (distance)\n\n";

	//Printing iterators
	//Row iterator
	for (int a = -1; a < nodes+1; a++)
	{

		//Column iterator
		for (int b = -1; b < nodes+1; b++)
		{

			//First row case
			if (a == -1)
			{

				//First column case
				if (b == -1)
				{

					//Space in upper right
					cout << "     ";

				}//End of first column case

				//Second column case
				else if (b == 0)
				{

					//Print divider
					cout << " |   ";

				}//End of second column case

				//Other column cases
				else
				{

					//Double digit case
					if (b > 9)
					{

						//Single space before number
						cout << " " << b << "  ";

					}//End of double digit case

					//Single digit case
					else
					{

						//Double space before number
						cout << "  " << b << "  ";

					}//End of single digit case

				}//End of other column cases

			}//End of first row case

			//Second row case
			else if (a == 0)
			{

				//Second column case
				if (b == 0)
				{

					//Print intersection
					cout << "-+-  ";

				}//End of second column case

				//Arbitrary column case
				else
				{

					//Print horizontal divider
					cout << "---  ";

				}//End of arbitrary column case

			}//End of second row case


			//Arbitrary row case
			else
			{

				//First column case
				if (b == -1)
				{

					//Double digit case
					if (a > 9)
					{

						//Single space
						cout << " " << a << "  ";

					}//End of double digit case

					//Single digit case
					else
					{

						//Double space
						cout << "  " << a << "  ";

					}//Single digit case

				}//End of first column case

				//Second column case
				else if (b == 0)
				{

					//Vertical divider
					cout << " |   ";

				}//End of second column case

				//Arbitrary column case
				else
				{

					//Print distance array contents
					cout << "  " << distance[a][b] << "  ";

				}//End of arbitrary column case

			}//End of arbitrary row case

		}//End of column iterator

		//Next row
		cout << endl;

	}//End of row iterator

	//Display O prompt
	cout << "\nResults of Floyd-Warshall on O:\n\n";

	//Printing iterators
	//Row iterator
	for (int a = -2; a < odds; a++)
	{

		//Column iterator
		for (int b = -2; b < odds; b++)
		{

			//First row case
			if (a == -2)
			{

				//First column case
				if (b == -2)
				{

					//Space in upper right
					cout << "     ";

				}//End of first column case

				//Second column case
				else if (b == -1)
				{

					//Vertical divider
					cout << " |   ";

				}//End of second column case

				//Arbitrary column case
				else
				{

					//Double digit case
					if (oddSet[b] > 9)
					{

						//Single space
						cout << " " << oddSet[b] << "  ";

					}//End of double digit case

					//Single digit case
					else
					{

						//Double space
						cout << "  " << oddSet[b] << "  ";

					}//End of single digit case

				}//End of arbitrary column case

			}//End of first row case

			//Second row case
			else if (a == -1)
			{

				//Second column case
				if (b == -1)
				{

					//Intersection divider
					cout << "-+-  ";

				}//End of second column case

				//Arbitrary column case
				else
				{

					//Horizontal divider
					cout << "---  ";

				}//End of arbitrary column case

			}//End of second row case

			//Arbitrary row case
			else
			{

				//First column case
				if (b == -2)
				{

					//Double digit case
					if (oddSet[a] > 9)
					{

						//Single space
						cout << " " << oddSet[a] << "  ";

					}//Double digit case

					//Single digit case
					else
					{

						//Double space
						cout << "  " << oddSet[a] << "  ";

					}//End of singl digit case

				}//End of first column case

				//Second column case
				else if (b == -1)
				{

					//Vertical divider
					cout << " |   ";

				}//End of second column case

				//Arbitrary column case
				else
				{

					//Print distance contents
					cout << "  " << oddNodes[a][b] << "  ";

				}//End of arbitrary column case

			}//End of arbitrary row case

		}//End of column iterator

		//Next row
		cout << endl;

	}//End of row iterator

	//Spacing for next print
	cout << endl << endl;

}//End of function printGraph