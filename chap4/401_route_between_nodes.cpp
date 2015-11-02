#include "graph.hpp"
#include <iostream>

using namespace std;

int main() {
	Graph mygraph(5);
	mygraph.addEdge(0,1);
	mygraph.addEdge(0,4);
	mygraph.addEdge(1,4);
	mygraph.addEdge(1,2);
	mygraph.addEdge(1,3);
	mygraph.addEdge(2,3);
	mygraph.addEdge(3,1);
	mygraph.addEdge(3,4);
	mygraph.addEdge(4,1);
	mygraph.printGraph();
	}
	


