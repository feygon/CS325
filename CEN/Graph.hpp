#pragma once
#include <cstdlib>
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, 
#include <vector>       // std::vector
#include <iterator>
#include <cstring>
using namespace std;

struct Node {
	int index;
	int xval;
	int yval;
	int dist;
	double* slope;
	Node* next; // next edge in cycle
	Node* prev; // previous edge in cycle
	Node(int i, int x, int y) {
		index = i;
		xval = x;
		yval = y;
	}
};

class Graph
{
public:
	Node** vertices;
	Node* currentNode;
	int ctr;
	void addNode(int index, int xval, int yval);
	Node** makeHull();
	Node** stretchIn();
	Graph(int max);
	Graph();
private:
	void getSlopes();
	double getSlope(Node* current, Node* next);
	void addVertexAsNext(Node*);
	void addVertexAsPrev(Node*);
	Node* getNextBottomHullNode();	// get next counter-clockwise vertex of the outer convex hull
	Node* getPrevTopHullNode();		// get next clockwise vertex of the outer convex hull
	Node* getInitialNode();			// get least-y of least-x vertex
};

