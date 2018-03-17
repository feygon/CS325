#include "Graph.hpp"

// Constructor overload w/ max number of nodes
Graph::Graph(int max) {
	ctr = 0;
	vertices = new Node*[max];
}

// blank default constructor
Graph::Graph(){}

// instantiate a new node in its index place, and increment counter
void Graph::addNode(int index, int xval, int yval) {
	vertices[index] = new Node(index, xval, yval);
	ctr++;
}

/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
*																			*
*	Draw top and bottom lines of hull, as well as edge cases on each end.	*
*																			*
*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/
Node ** Graph::makeHull() {
	// code
	currentNode = getInitialNode();
	// make calls to addVertextAsNext while certain conditions apply


	currentNode = getInitialNode();
	// make calls to addVertextAsPrev while certain conditions apply
	return nullptr;
}

/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
*																			*
*	Find all distance values for unlinked vertices, to other vertices and	*
*		to edges (i,j)														*
*	Find difference in area for each possible change						*
*	Populate minheap														*
*	Pop front, and repeat relevant calculations afterwards					*
*																			*
*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/
Node ** Graph::stretchIn() {
	// code
	return nullptr;
}

// calculate all slopes
void Graph::getSlopes() {
	for (int i = 0; i < ctr; i++) {
		vertices[i]->slope = new double[ctr];
		for (int j = 0; j < ctr; j++) {
			if (i != j) {
				vertices[i]->slope[j] = getSlope(vertices[i], vertices[j]);
			}
		}
	}
}

// gets slope between current and next node (rise over run)
double Graph::getSlope(Node * current, Node * next) {
	int rise1 = current->yval;
	int rise2 = next->yval;
	int run1 = current->xval;
	int run2 = next->xval;
	double riseoverrun = (double)(rise1 - rise2) / (double)(run1 - run2);
	return riseoverrun;
}

// does not increment currentNode.
void Graph::addVertexAsNext(Node* nextNode) {
	currentNode->next = nextNode;
	nextNode->prev = currentNode;
}
void Graph::addVertexAsPrev(Node* prevNode) {
	currentNode->prev = prevNode;
	prevNode->next = currentNode;
}

// gets next node along bottom (next CCwise)
Node* Graph::getNextBottomHullNode() {
	int index = 0;
	if (currentNode->index == 0) { index = 1; }
	for (int i = 1; i < ctr; i++) {
		if (currentNode->index != i &&
			currentNode->xval <= vertices[index]->xval &&
			currentNode->slope[index] < currentNode->slope[i]) {
			index = i;
		}
	}
	return vertices[index];
}

// gets previous node along top (next CWise)
Node * Graph::getPrevTopHullNode() {
	int index = 0;
	if (currentNode->index == 0) { index = 1; }
	for (int i = 1; i < ctr; i++) {
		if (currentNode->index != i &&
			currentNode->xval <= vertices[index]->xval &&
			currentNode->slope[index] > currentNode->slope[i]) {
			index = i;
		}
	}
	return vertices[index];
}

// returns least-y of least-x vertex.
Node * Graph::getInitialNode() {
	Node* temp = vertices[0];
	for (int i = 1; i < ctr; i++) {
		if (temp->xval < vertices[i]->xval) {
			temp = vertices[i]; 
		}
		if (temp->xval == vertices[i]->xval &&
			temp->yval > vertices[i]->yval) {
			temp = vertices[i];
		}
	}
	return temp;
}
