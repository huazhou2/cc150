#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <cstddef>
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int value):val(value),next(NULL) {};
	};

class Graph {
	private:
		ListNode* *arr;
		int vnum;//vertex number;
		bool isPath(int v1, int v2);//if thers's path from v1 to v2
	public:
		Graph(int num);
		~Graph();
		void addEdge(int v1, int v2);//add edge by element
		void remEdge(int v1, int v2);//rem edge by element
		void printGraph();
		bool isConnect(int v1, int v2);//if there's connection between v1 and v2
	};
#endif



		

	
	
