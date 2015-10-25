#include <iostream>
#include <unordered_set>
using namespace std;
//structure for Linked List Node
struct Node {
	int val;
	Node* next;
	Node(int num) {
	val=num;
	next=NULL;
	}
	};
Node* loop_Detection(Node*);
void print_Circular(Node* head);

int main() {
	//test cases;
	Node* head=new Node(3);
	Node* cur=head;
	cur->next=new Node(2);
	cur=cur->next;
	cur->next=new Node(4);
	cur=cur->next;
	cur->next=new Node(5);
	cur=cur->next;
	cur->next=new Node(1);
	cur=cur->next;
	cur->next=new Node(6);
	cur=cur->next;
	cur->next=new Node(7);
	cur=cur->next;
	cur->next=head->next->next;//point back to 3rd node(4)
	cout<<"List:"<<endl;
	print_Circular(head);
	cout<<"Circular List:"<<endl;
	print_Circular(loop_Detection(head));
	}

Node* loop_Detection(Node* head) {
	if (!head || !head->next) return NULL;
	//find collision point
	Node* fast=head, *slow=head;
	do {
		fast=fast->next->next;
		slow=slow->next;}
	while (fast!=slow);
	slow=head;
	//find the start point
	while (fast!=slow) {
		fast=fast->next;
		slow=slow->next;}
	return fast;}
void print_Circular(Node* head) {
	if (!head) return;
	Node* cur=head;
	//store nodes in case there's duplicate(circular)
	unordered_set<Node*> set; 
	while (cur) {
		if (set.find(cur)==set.end()) {
			cout<<cur->val<<" -> ";
			set.insert(cur);
			cur=cur->next;}
		else {
		     cout<<"back to "<<cur->val<<endl;
		    break;}
	}
	}
