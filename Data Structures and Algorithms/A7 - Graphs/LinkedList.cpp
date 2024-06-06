// Assignment #7
// Name: Vincent Latona
// Description: This program implements the operations
//				associated with the linkedlist and stack classes

#include "LinkedList.h"

/*/
* This constructor instantiates an edge for a graph
*/
Edge::Edge(int s, int d, int w)
{

	//Set private data
	src = s;
	dst = d;
	weight = w;
	traversed = false;
	duplicate = NULL;
	next = NULL;

}//End of Constructor

/*
* This function sets status to traversed
*/
void Edge::setTraversed()
{

	//Set traversed to true
	traversed = true;

}//End of function setTraversed

/*
* This function points an edge to its duplicate in the adjacency table
*/
bool Edge::setDuplicate(Edge* dup)
{

	//Set duplicate pointer and return true;
	duplicate = dup;
	return true;

}//End of function setDuplicate

/*
* This function points the current edge to the next edge
*/
bool Edge::setNext(Edge* link)
{

	//Point to next node and return true
	next = link;
	return true;

}//End of function setNext

/*
* This function returns the source node of the edge
*/
int Edge::getSrc()
{

	//Return source
	return src;

}//End of function getSrc

/*
* This function returns the destination node of the edge
*/
int Edge::getDst()
{

	//Return destination
	return dst;

}//End of function getDst

/*
* This function returns the edge weight
*/
int Edge::getWeight()
{

	//Return weight
	return weight;

}//End of function getWeight

/*
* This function returns the traversal-state of the edge
*/
bool Edge::beenTraversed()
{

	//Return traversal-state
	return traversed;

}//End of function beenTraversed

/*
* This function returns the duplicate-edge pointer if one exists
*/
Edge* Edge::getDuplicate()
{

	//Return duplicate pointer
	return duplicate;

}//End of function getDuplicate

/*
* This function returns next pointer
*/
Edge* Edge::getNext()
{

	//Return next pointer
	return next;

}//End of function getNext

/*
* This constructor builds an initial linked-list
*/
LinkedList::LinkedList()
{

	//Set private data
	head = NULL;
	degree = 0;

}//End of Constructor

/*
* This destructor handles allocated memory no longer needed
*/
LinkedList::~LinkedList()
{

	//Deletion pointer
	Edge* del = head;

	//Deletion iterator
	while (head != NULL)
	{

		//Iterate and delete
		head = head->getNext();
		delete del;
		del = head;

	}//End of deletion iterator

}//End of Destructor

/*
* This function returns the degree of the list
*/
int LinkedList::getDegree()
{

	//Return degree of node
	return degree;

}//End of function getDegree

/*
* This function returns a pointer to the head of the list
*/
Edge* LinkedList::getFirst()
{

	//Return pointer to head
	return head;

}//End of function getFirst

/*
* This functionn inserts an edge into the linked list
*/
Edge* LinkedList::insertEdge(int src, int dst, int weight)
{

	//Search for edge in list
	bool exists = searchEdge(dst, weight);

	//Existent edge case
	if (exists)
	{

		//Return false for exact duplicate edge
		return NULL;

	}//End of existent edge case

	//Insertion case
	else
	{

		//Create edge to be inserted
		Edge* insert = new Edge(src, dst, weight);

		//Memory check
		if (insert == NULL)
		{

			//Return false for inadequate memory
			return insert;

		}//End of memory check

		//Head insertion case
		if (head == NULL)
		{

			//Point head to new edge
			head = insert;
			degree++;
			return insert;

		}//End of head insertion case

		//Edge iterators for insertion
		Edge* iterator = head;
		Edge* follower = NULL;

		//List iterator
		while (iterator != NULL)
		{

			//Loop break case
			if (insert->getDst() < iterator->getDst())
			{

				//Break loop and insert
				break;

			}//End of loop break case

			//Redundant edge case
			else if (insert->getDst() == iterator->getDst())
			{

				//Loop break case
				if (insert->getWeight() < iterator->getWeight())
				{

					//Break loop and insert
					break;

				}//End of loop break case

			}//End of redundant edge case

			//Iterate
			follower = iterator;
			iterator = iterator->getNext();

		}//End of list iterator

		//New head case
		if (follower == NULL)
		{

			//Insert node
			insert->setNext(iterator);
			head = insert;
			degree++;
			return insert;

		}//End of new head case

		//Body insertion
		else
		{

			//Insert node
			insert->setNext(iterator);
			follower->setNext(insert);
			degree++;
			return insert;

		}//End of body insertion

	}//End of insertion case

}//End of function insertEdge

/*
* This function searches for an already existent edge
*/
bool LinkedList::searchEdge(int dst, int weight)
{

	//Iterator pointer
	Edge* traverse = head;

	//Searching iterator
	while (traverse != NULL)
	{

		//Duplicate found case
		if (traverse->getDst() == dst && traverse->getWeight() == weight)
		{

			//Return true for found
			return true;

		}//End of duplicate found case

		//Iterate
		traverse = traverse->getNext();

	}//End of searching iterator

	//Return false for not found
	return false;

}//End of function searchEdge

/*
* This function prints the list contents
*/
void LinkedList::printList()
{

	//Iterator
	Edge* traverse = head;

	//List iterator
	while (traverse != NULL)
	{

		//Print edges
		cout << "To: " << traverse->getDst()
			<< " with weight " << traverse->getWeight()
			<< endl;

		//Iterate
		traverse = traverse->getNext();

	}//End of list iterator

	cout << endl;

}//End of function