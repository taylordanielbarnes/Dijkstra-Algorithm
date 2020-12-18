#include <iostream>
using namespace std;

#define VERTICES 8 //number of vertices in the graph
#define MAX(a, b) ((a >= b)? a : b) //determine max of two numbers
#define MIN(a, b) ((a <= b)? a : b) //determine min of two numbers
#define LEFT_CHILD(a) (a * 2) //find the left child of a node in a tree
#define RIGHT_CHILD(a) ((a * 2) + 1) //find the right child of a node in a tree
#define PARENT(a) (a / 2) //find the parent of a node in a tree
#define INF 999999999 //arbitrarily large number

#include "LLNode.cpp"
#include "Graph.cpp"
#include "Dijkstra.cpp"



int main() {
	//declare graph and dijkstra stuff
	Graph G;
	DijkstraTable D;
	
	//set up the graph's edges/weights
	G.constructGraph(1);
	
	//ask user for starting index
	int startInd;
	cout << "Enter starting vertex: ";
	cin >> startInd;
	cout << "\n";
	
	D.cost[startInd] = 0;
	
	//Dijkstra algorithm
	bool cont;
	do {
		
		cont = false;
		
		//find cheapest unknown vertex
		int target;
		for(int i = 0; i < VERTICES; i++) { //are there any unknown vertices?
			if(!D.known[i]) {
				target = i;
				cont = true;
				break;
			}
		}
		if(!cont) break;
		for(int i = 0; i < VERTICES; i++) { //find the cheapest one
			if(!D.known[i]) {
				target = (D.cost[i] < D.cost[target]) ? i : target;
			}
		}
		D.known[target] = true;
		//*/
		
		//update neighbors of target vertex
		LLNode *temp = G.adjList[target].next; //get the first neighbor
		while(temp != NULL) {
			if(D.cost[target] + temp->cost < D.cost[temp->key]) {
				D.cost[temp->key] = D.cost[target] + temp->cost;
				D.path[temp->key] = target;
			}
			
			temp = temp->next; //on to the next neightbor
		}
	} while(cont);
	
	
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
