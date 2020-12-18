#include "MinHeap.h"



MinHeap::MinHeap() {
	lastEvent = VERTICES - 1; //the queue has VERTICES events, so the last event is held at index VERTICES - 1
	
	//set each event in the queue in order of vertex #
	for(int i = 0; i < VERTICES; i++) {
		heapArr[i].vertex = i;
		positionArr[i] = i;
	}
	heapify(); //satisfy the minheap property
}

QueueEvent MinHeap::extractMin() {
	//if the queue is empty, send out a sentinel
	if(lastEvent < 0) {
		QueueEvent temp;
		temp.vertex = -1;
		return temp;
	}
	
	QueueEvent temp = heapArr[0]; //save the min (return this later)
	positionArr[heapArr[0].vertex] = -1; //note the changing positions
	
	heapArr[0] = heapArr[lastEvent]; //bring the bottom event up to the top
	positionArr[heapArr[0].vertex] = 0; //note the changing positions
	lastEvent--; //remove one event from the queue
	
	sink(0); //reheapify
	
	return temp; //return the minimum cost vertex
}

void MinHeap::decreaseKey(int vertex, int newCost) {
	heapArr[positionArr[vertex]].cost = newCost; //change the key
	floatUp(positionArr[vertex]); //reheapify
}

void MinHeap::heapify() {
	int i = PARENT(lastEvent); //start at the last parent
	for(int j = i; j >= 0; j--) { //move up all the way to the root
		sink(j);
	}
}

void MinHeap::sink(int i) {
	//move a node downward through the heap until it is a minheap
	while(RIGHT_CHILD(i) <= lastEvent) { //stop when there's no more children with whom to swap
		if(heapArr[i].cost > heapArr[LEFT_CHILD(i)].cost) { //if we need to swap with the left child
			//swap parent with child
			QueueEvent temp1 = heapArr[i];
			heapArr[i] = heapArr[LEFT_CHILD(i)];
			heapArr[LEFT_CHILD(i)] = temp1;
			
			//note the changing positions
			int temp2 = positionArr[heapArr[i].vertex];
			positionArr[heapArr[i].vertex] = positionArr[heapArr[LEFT_CHILD(i)].vertex];
			positionArr[heapArr[LEFT_CHILD(i)].vertex] = temp2;
			
			i = LEFT_CHILD(i);
		}
		else if(heapArr[i].cost > heapArr[RIGHT_CHILD(i)].cost) { //if we need to swap with the right child
			//swap parent with child
			QueueEvent temp3 = heapArr[i];
			heapArr[i] = heapArr[RIGHT_CHILD(i)];
			heapArr[RIGHT_CHILD(i)] = temp3;
			
			//note the changing positions
			int temp4 = positionArr[heapArr[i].vertex];
			positionArr[heapArr[i].vertex] = positionArr[heapArr[RIGHT_CHILD(i)].vertex];
			positionArr[heapArr[RIGHT_CHILD(i)].vertex] = temp4;
			
			i = RIGHT_CHILD(i);
		}
		else break;
	}
	if(LEFT_CHILD(i) == lastEvent) { //fringe case
		if(heapArr[i].cost > heapArr[LEFT_CHILD(i)].cost) { //if we need to swap with the left child
			//swap parent with child
			QueueEvent temp5 = heapArr[i];
			heapArr[i] = heapArr[LEFT_CHILD(i)];
			heapArr[LEFT_CHILD(i)] = temp5;
			
			//note the changing positions
			int temp6 = positionArr[heapArr[i].vertex];
			positionArr[heapArr[i].vertex] = positionArr[heapArr[LEFT_CHILD(i)].vertex];
			positionArr[heapArr[LEFT_CHILD(i)].vertex] = temp6;
			
			i = LEFT_CHILD(i);
		}
	}
}

void MinHeap::floatUp(int i) {
	//move a node upward through the heap until it is a minheap
	while(i > 0) { //go all the way to the top
		if(heapArr[PARENT(i)].cost > heapArr[i].cost) { //if we need to swap with the parent
			//swap parent with child
			QueueEvent temp1 = heapArr[i];
			heapArr[i] = heapArr[PARENT(i)];
			heapArr[PARENT(i)] = temp1;
			
			//note the changing positions
			int temp2 = positionArr[heapArr[i].vertex];
			positionArr[heapArr[i].vertex] = positionArr[heapArr[PARENT(i)].vertex];
			positionArr[heapArr[PARENT(i)].vertex] = temp2;
			
			i = PARENT(i);
		}
		else break;
	}
}

void MinHeap::printHeap() {
	int i = 0;
	int j = 2;
	while(i <= lastEvent) {
		cout << heapArr[i].cost << " ";
		
		//math
		if(i + 2 == j) {
			cout << "\n";
			j *= 2;
		}
		i++;
	}
	
	cout << "\n\n\n";
}
