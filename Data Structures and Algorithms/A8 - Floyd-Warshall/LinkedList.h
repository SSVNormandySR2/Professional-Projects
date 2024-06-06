// Assignment #8
// Name: Vincent Latona
// Description: This header file is responsible for the creation
//				of linked-list and edge objects and defining their operations.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>

using namespace std;

//Edge class to be linked
class Edge
{

private:
	int src;
	int dst;
	int weight;
	bool traversed;
	bool virtualEdge;
	Edge* duplicate;
	Edge* next;

public:
	Edge();
	Edge(int, int, int);
	void setTraversed();
	bool setDuplicate(Edge*);
	bool setNext(Edge*);
	int getSrc();
	int getDst();
	int getWeight();
	void setWeight(int);
	void setVirtual();
	bool beenTraversed();
	bool isVirtual();
	Edge* getDuplicate();
	Edge* getNext();

};//End of class Edge

//LinkedList class to link edges
class LinkedList
{

private:
	Edge* head;
	int degree;

public:
	LinkedList();
	~LinkedList();
	int getDegree();
	Edge* getFirst();
	Edge* insertEdge(int, int, int, bool);
	bool searchEdge(int, int);
	void printList();

};//End of class LinkedList

#endif /*LINKEDLIST_H*/
