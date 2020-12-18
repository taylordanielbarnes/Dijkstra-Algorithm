/*
 *	QueueEvent
 *	node to be placed into a heap-based priority queue
 *	
 *	@constructor QueueEvent()	construct a node with max cost
 *	@param vertex				key value for the node
 *	@param cost					value by which the heap is sorted
 */
class QueueEvent {
	public:
		QueueEvent();
		int vertex;
		int cost;
};

QueueEvent::QueueEvent() {
	cost = INF; //max out everything in the heap
}
