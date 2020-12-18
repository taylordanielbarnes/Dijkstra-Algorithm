/*
 *	Dijkstra Table
 *	contains all of the info to be used in the Dijkstra algorithm
 *
 *	@constructor DijkstraTable()	initialize every node in the graph with its path to the source vertex and cost of travel
 *	@param vertex[]					the key of the node at a given index
 *	@param known[]					whether the node at a given index has already been processed
 *	@param cost[]					the cost to get from the source node to the node at a given index
 *	@param path[]					the parent of the node at a given index
 */
class DijkstraTable {
	public:
		DijkstraTable();
		int vertex[VERTICES];
		bool known[VERTICES];
		int cost[VERTICES];
		int path[VERTICES];
};

DijkstraTable::DijkstraTable() {
	for(int i = 0; i < VERTICES; i++) {
		vertex[i] = i;
		known[i] = false;
		cost[i] = INF;
		path[i] = -1;
	}
}
