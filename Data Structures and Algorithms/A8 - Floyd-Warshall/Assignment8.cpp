// Assignment #8
// Name: Vincent Latona
// Description: This driver program demonstrates the use of graphs by
//				reading a graph from a file and performing operations,
//				including Floyd-Warshall, Perfect Matching, and DFS.

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
	
	//Build and display Odds
	graph->buildOdds();

	//Perform Floyd-Warshall Algorithm and print graph
	graph->Floyd_Warshall();
	graph->printGraph();

	//Sort odds and perform perfect match
	graph->sortEdges();
	graph->perfectMatching();

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
			string src, dst;

			//Read edge info
			reader >> src;
			reader >> dst;

			//Integer conversion
			int s = stoi(src);
			int d = stoi(dst);
			int w = 1;

			//Insert parsed edge into graph
			g->insertEdge(s, d, w, false);

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