// Assignment #7
// Name: Vincent Latona
// Description: This program demonstrates the use
//				of graphs by reading an input file
//				and performing graph operations.

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"

using namespace std;

//Forward declaration
Graph* buildGraph();

/*
* This function is to drive the main program execution
*/
int main()
{

	//Build graph
	Graph* graph = buildGraph();

	//Print graph contents
	graph->printGraph();

	//Perform DFS
	graph->DFS();

}//End of function main

/*
* This function builds the graph contained within a file
*/
Graph* buildGraph()
{

	//Create ifstream reader and open input file
	ifstream reader;
	reader.open("graph.txt");

	//Read file
	if (reader.is_open())
	{

		//Variables for input parsing
		string firstLine, n, m;

		//Read nodes and edges
		reader >> n;
		reader >> m;

		//Convert to integers
		int nodes = stoi(n);
		int edges = stoi(m);

		//Create graph
		Graph* g = new Graph(nodes, edges);

		//Iterator
		int i = 0;

		//Edge-reading iterator
		while (i < edges)
		{

			//Strings for edge info
			string src, dst, weight;

			//Read edge info
			reader >> src;
			reader >> dst;
			reader >> weight;

			//Integer conversion
			int s = stoi(src);
			int d = stoi(dst);
			int w = stoi(weight);

			//Insert parsed edge into graph
			g->insertEdge(s, d, w);

			//Iterate to next edge
			i++;

		}//End of edge-reading iterator

		//Close file
		reader.close();

		//Return created graph
		return g;

	}//End of read file

	//Input file error
	else
	{

		//Print error message
		cout << "Input file error, unable to read input file\n";
		return NULL;

	}//End of input file error

}//End of function buildGraph