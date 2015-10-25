#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int num) {
	val=num;
	next=NULL;
	}
	};
int kth_Last(Node* head, int k);
void print(Node* head);

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
	cout<<"List:";
	print(head);
	int k=2;
	cout<<k<<"th to last is "<<kth_Last(head,k)<<endl;
	}

int kth_Last(Node* head, int k) {
	if (!head || k<0) return -1;
	Node* slow=head, *fast=head;
	int step=0;
	while (step<k) {
		fast=fast->next;	
		step++;
		if (!fast) return -1;
		}
	while (fast->next) {
		slow=slow->next;
		fast=fast->next;}
	return slow->val;}
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
		
	

