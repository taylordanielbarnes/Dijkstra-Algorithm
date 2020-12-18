#include <iostream>
using namespace std;

#define VERTICES 8 //number of vertices in the graph
#define MAX(a, b) ((a >= b)? a : b) //determine max of two numbers
#define MIN(a, b) ((a <= b)? a : b) //determine min of two numbers
#define LEFT_CHILD(a) (a * 2) //find the left child of a node in a tree
#define RIGHT_CHILD(a) ((a * 2) + 1) //find the right child of a node in a tree
#define PARENT(a) (a / 2) //find the parent of a node in a tree
#define INF 999999999 //arbitrarily large number

#include "QueueEvent.cpp"
#include "MinHeap.cpp"
#include "LLNode.cpp"
#include "Graph.cpp"
#include "Dijkstra.cpp"



int main() {
	//declare graph and dijkstra stuff
	Graph G;
	DijkstraTable D;
	MinHeap M;
	
	//set up the graph's edges/weights
	G.constructGraph(1);
	
	//ask user for starting index
	int startInd;
	cout << "Enter starting vertex: ";
	cin >> startInd;
	cout << "\n";
	
	D.cost[startInd] = 0;
	M.decreaseKey(startInd, 0);
	
	//Dijkstra algorithm
	while(true) {
		
		//find cheapest unknown vertex
		QueueEvent current = M.extractMin();
		if(current.vertex == -1)
			break;
		D.known[current.vertex] = true;
		
		//update neighbors of target vertex
		LLNode *temp = G.adjList[current.vertex].next; //get the first neighbor
		while(temp != NULL) {
			if(D.cost[current.vertex] + temp->cost < D.cost[temp->key]) {
				D.cost[temp->key] = D.cost[current.vertex] + temp->cost;
				D.path[temp->key] = current.vertex;
				M.decreaseKey(temp->key, D.cost[temp->key]);
			}
			
			temp = temp->next; //on to the next neightbor
		}
	}
	
	
	//print adjacency list of the graph
	cout << "Graph:\n";
	for(int i = 0; i < VERTICES; i++) {
		cout << G.adjList[i].key;
		LLNode *temp = G.adjList[i].next;
		while(temp != NULL) {
			cout << " -> " << temp->key;
			temp = temp->next;
		}
		cout << "\n";
	}
	cout << "\n\n\n";
	
	//print dijkstra info
	cout << "Dijkstra Paths:\nVertex\t";
	cout << "Cost\t";
	cout << "Parent\n";
	for(int i = 0; i < VERTICES; i++) {
		cout << D.vertex[i] << "\t";
		if(D.cost[i] < INF) {
			cout << D.cost[i] << "\t";
			cout << D.path[i] << "\n";
		}
		else {
			cout << "INF\t";
			cout << "NULL\n";
		}
	}
	//*/
	
	return 0;
}
