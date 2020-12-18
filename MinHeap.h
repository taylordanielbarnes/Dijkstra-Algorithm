#ifndef MINHEAP_H
#define MINHEAP_H



/*
 *	MinHeap
 *	minheap to implement priority queue for dijkstra algorithm
 *	
 *	@constructor MinHeap()							initialize heap
 *	@method extractMin() 							return the highest priority event, reheapify the heap
 *	@method decreaseKey(int vertex, int newCost) 	find a node in the heap, decrease its cost value, reheapify
 *	@method heapify() 								satisfy the heap property (only use once at beginning)
 *	@method sink(int i) 							swap a node down the heap until minheap property is satisfied
 *	@method floatUp(int i) 							swap a node UP the heap until minheap property is satisfied
 *	@method printHeap() 							visualize the heap
 *	@param heapArr[] 								the array which contains the heap
 *	@param positionArr[] 							keep indices of where every node is within the heap array
 *	@param lastEvent 								how many events are left in the queue
 */
class MinHeap {
	public:
		MinHeap();
		QueueEvent extractMin();
		void decreaseKey(int vertex, int newCost);
		void printHeap();
	private:
		void heapify();
		void sink(int i);
		void floatUp(int i);
		QueueEvent heapArr[VERTICES];
		int positionArr[VERTICES];
		int lastEvent;
};

#endif
