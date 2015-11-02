#include "graph.hpp"
#include <iostream>

using namespace std;

int main() {
	Graph mygraph(5);
	mygraph.addEdge(0,1);
	mygraph.addEdge(1,2);
	mygraph.addEdge(4,0);
	mygraph.addEdge(3,0);
	mygraph.printGraph();
	cout<<"Node 0 and 2 Connected?  "<<(mygraph.isConnect(0,2)?"Yes":"No")<<endl;
	cout<<"Node 2 and 0 Connected?  "<<(mygraph.isConnect(2,0)?"Yes":"No")<<endl;
	cout<<"Node 3 and 4 Connected?  "<<(mygraph.isConnect(3,4)?"Yes":"No")<<endl;
	
	
	}
	


