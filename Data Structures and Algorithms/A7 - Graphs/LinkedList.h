// Assignment #7
// Name: Vincent Latona
// Description: This header file is responsible for
//				the creation of linkedlist and edge
//				objects and their operations

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
	Edge* duplicate;
	Edge* next;

public:
	Edge(int, int, int);
	void setTraversed();
	bool setDuplicate(Edge*);
	bool setNext(Edge*);
	int getSrc();
	int getDst();
	int getWeight();
	bool beenTraversed();
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
	Edge* insertEdge(int, int, int);
	bool searchEdge(int, int);
	void printList();

};//End of class LinkedList

#endif /*LINKEDLIST_H*/