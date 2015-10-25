#include <iostream>
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
Node* Intersection(Node* head1,Node* head2);
void print(Node* head);

int main() {
	//test cases;
	Node* head1=new Node(3);
	Node* cur=head1;
	cur->next=new Node(2);
	cur=cur->next;
	cur->next=new Node(4);
	cur=cur->next;
	cur->next=new Node(5);
	cur=cur->next;
	cur->next=new Node(1);
	cout<<"List1"<<endl;
	print(head1);
	Node* head2=new Node(7);
	head2->next=head1->next->next;	
	cout<<"List2"<<endl;
	print(head2);
	cout<<"Intersection List"<<endl;
	print(Intersection(head1,head2));
	}

Node* Intersection(Node* head1, Node* head2) {
	//get length difference of 2 lists
	if (!head1 || !head2) return NULL;
	Node* cur1=head1, *cur2=head2;
	while (cur1 && cur2) {
		cur1=cur1->next;
		cur2=cur2->next;
		}
	//get the long list
	Node* longlist=cur1?head1:head2;
	Node* shortlist=cur1?head2:head1;
	Node* cur=cur1?cur1:cur2;
	//move the long list first
	while(cur) {
		longlist=longlist->next;
		cur=cur->next;	
		}
	while (longlist) {
		if (longlist==shortlist) return longlist;
		else {
			longlist=longlist->next;
			shortlist=shortlist->next;
			}
		}
	return NULL;
	}
void print(Node* head) {
	if (!head) return;
	Node* cur=head;
	while (cur) {
		cout<<cur->val;
		if (cur->next)
			cout<<" -> ";
		cur=cur->next;}
	cout<<endl;
	}
		
	

