/*
 *	LLNode
 *	node of a linked list
 *	each node refers to a vertex in the graph
 *	an array of such linked lists forms an adj list, representing a graph
 *
 *	@constructor LLNode()							set up each node to have infinite cost by default
 *	@constructor LLNode(int k, int c, LLNode *n)	set up a node with information from the graph
 *	@param key										the value by which nodes in the graph are arranged
 *	@param cost										the cost to get from this node to its parent
 *	@param next										the child of this node
 */
class LLNode {
	public:
		LLNode();
		LLNode(int k, int c, LLNode *n);
		int key;
		int cost;
		LLNode *next;
};

//default constructor
LLNode::LLNode() {
	cost = INF;
}

//better constructor
LLNode::LLNode(int k, int c, LLNode *n) {
	key = k;
	cost = c;
	next = n;
}
