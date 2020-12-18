#ifndef GRAPH_H
#define GRAPH_H



/*
 *	Graph
 *	adjacency list graph
 *	
 *	@constructor Graph()						initialize graph with |V| vertices
 *	@method addEdge(int u, int v, int w)		connect node u to node v with edge weight w
 *	@method constructGraph(int sel)				populate graph data with one of several cases
 *	@param adjList[]							array of linked lists representation of a graph
 *	@param i									keep up with all the nodes in the adj list
 *	@param nodeList[]							array of every node in the graph
 */
class Graph {
	public:
		Graph();
		void constructGraph(int sel);
		void addEdge(int u, int v, int w);
		LLNode adjList[VERTICES];
		int i;
		LLNode nodeList[VERTICES * VERTICES];
};

#endif
