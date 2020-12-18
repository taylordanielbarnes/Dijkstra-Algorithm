#include "Graph.h"



Graph::Graph() {
	for(int j = 0; j < VERTICES; j++) {
		this->adjList[j].key = j;
		this->adjList[j].cost = 0;
		this->adjList[j].next = NULL;
	}
	this->i = 0;
}

void Graph::addEdge(int u, int v, int w) {
	LLNode temp(v, w, this->adjList[u].next);
	this->nodeList[i] = temp;
	this->adjList[u].next = &nodeList[i++];
}

void Graph::constructGraph(int sel) {
	switch(sel) {		
		case 1: {
			this->addEdge(1, 6, 7);
			this->addEdge(2, 5, 6);
			this->addEdge(2, 4, 5);
			this->addEdge(4, 6, 1);
			this->addEdge(4, 2, 9);
			this->addEdge(5, 7, 6);
			this->addEdge(6, 7, 8);
			this->addEdge(7, 5, 4); //8 vertices
			break;
		}
		case 2: {
			this->addEdge(0, 2, 3);
			this->addEdge(0, 1, 9);
			this->addEdge(1, 5, 9);
			this->addEdge(1, 2, 4);
			this->addEdge(2, 6, 7);
			this->addEdge(2, 4, 2);
			this->addEdge(2, 1, 8);
			this->addEdge(2, 0, 6);
			this->addEdge(3, 7, 3);
			this->addEdge(3, 1, 3);
			this->addEdge(4, 7, 4);
			this->addEdge(4, 2, 6);
			this->addEdge(5, 7, 2);
			this->addEdge(5, 3, 5);
			this->addEdge(5, 1, 6);
			this->addEdge(6, 5, 7); //8 vertices
			break;
		}
		case 3: {
			this->addEdge(0, 2, 1);
			this->addEdge(0, 3, 4);
			this->addEdge(1, 0, 2);
			this->addEdge(1, 3, 9);
			this->addEdge(3, 2, 12);
			this->addEdge(3, 4, 8); //5 vertices
			break;
		}
		case 4: {
			this->addEdge(0, 1, 5);
			this->addEdge(0, 14, 1);
			this->addEdge(3, 10, 6);
			this->addEdge(4, 5, 9);
			this->addEdge(4, 7, 3);
			this->addEdge(5, 6, 7);
			this->addEdge(5, 8, 3);
			this->addEdge(6, 2, 1);
			this->addEdge(7, 0, 7);
			this->addEdge(9, 6, 1);
			this->addEdge(10, 9, 1);
			this->addEdge(10, 13, 8);
			this->addEdge(11, 12, 3);
			this->addEdge(12, 11, 9);
			this->addEdge(12, 13, 9);
			this->addEdge(12, 16, 8);
			this->addEdge(13, 9, 9);
			this->addEdge(13, 17, 3);
			this->addEdge(14, 15, 2);
			this->addEdge(17, 13, 5); //18 vertices
			break;
		}
		case 5: {
			this->addEdge(0, 2, 3);
			this->addEdge(0, 7, 6);
			this->addEdge(1, 5, 9);
			this->addEdge(2, 3, 6);
			this->addEdge(3, 2, 9);
			this->addEdge(3, 6, 8);
			this->addEdge(3, 10, 6);
			this->addEdge(3, 17, 2);
			this->addEdge(5, 9, 2);
			this->addEdge(6, 2, 9);
			this->addEdge(6, 9, 8);
			this->addEdge(6, 10, 8);
			this->addEdge(7, 0, 7);
			this->addEdge(7, 14, 1);
			this->addEdge(8, 4, 2);
			this->addEdge(9, 6, 9);
			this->addEdge(9, 10, 4);
			this->addEdge(10, 13, 6);
			this->addEdge(11, 8, 9);
			this->addEdge(12, 9, 1);
			this->addEdge(13, 16, 7);
			this->addEdge(14, 7, 9);
			this->addEdge(15, 17, 6);
			this->addEdge(16, 13, 6);
			this->addEdge(16, 17, 4);
			this->addEdge(17, 13, 6);
			this->addEdge(17, 16, 7); //18 vertices
			break;
		}
		default:
			break;
	}
	return;
}
