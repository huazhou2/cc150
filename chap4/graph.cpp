#include "graph.hpp"
#include <iostream>
Graph::Graph(int num) {
	vnum=num;
	arr=new ListNode*[vnum];
	for (int i=0;i<vnum;i++) 
		arr[i]=NULL;
		}
Graph::~Graph() {
	for (int i=0;i<vnum;i++) {
		ListNode* cur,*prev;
		cur=arr[i];
		while (cur) {
			prev=cur;
			cur=cur->next;
			delete prev;}
		}
		delete[] arr;
		std::cout<<"Clearing Graph"<<std::endl;
		}
void Graph::addEdge(int v1, int v2) {
	ListNode* newnode=new ListNode(v2);
	newnode->next=arr[v1];
	arr[v1]=newnode;
	}
void Graph::remEdge(int v1, int v2) {
	ListNode* cur=arr[v1];
	if (arr[v1]->val==v2) {
		cur=cur->next;
		delete arr[v1];
		arr[v1]=cur;
		return;} 
	ListNode* prev=NULL;
	while (cur) {
		if (cur->val==v2) {
		prev->next=cur->next;
		delete cur;
		return;}
		prev=cur;
		cur=cur->next;
		}
	}
void Graph::printGraph() {
	for (int i=0;i<vnum;i++) {
		std::cout<<"Connected to head "<<i<<std::endl;
	ListNode* cur=arr[i];
	while (cur) {
		std::cout<<cur->val<<"  ";
		cur=cur->next;
	}
	std::cout<<std::endl;
	}
	}
	
