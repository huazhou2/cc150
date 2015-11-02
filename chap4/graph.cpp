#include "graph.hpp"
#include <iostream>
#include <deque>
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
bool Graph::isPath (int v1, int v2) {
	if (arr[v1]==NULL) return false;
	std::deque<int> myq;
	myq.push_back(arr[v1]->val);
	while (!myq.empty()) {
		int cur=myq.front();
		if (cur==v2) return true;
		ListNode* head=arr[cur];
		while (head) {
			myq.push_back(head->val);
			head=head->next;}
		myq.pop_front();
		}
	return false;
	}
bool Graph::isConnect(int v1,int v2) {
	return isPath(v1,v2) || isPath(v2,v1);
	}
	
	
	
