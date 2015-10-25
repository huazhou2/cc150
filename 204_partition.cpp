#include <iostream>
using namespace std;
//defind Linked list Node
struct Node {
	int val;
	Node* next;
	Node(int num) {
	val=num;
	next=NULL;
	}
	};
void Partition(Node* head, int num);
void print(Node* head);

int main() {
	//test cases;
	Node* head=new Node(3);
	Node* cur=head;
	cur->next=new Node(5);
	cur=cur->next;
	cur->next=new Node(8);
	cur=cur->next;
	cur->next=new Node(5);
	cur=cur->next;
	cur->next=new Node(10);
	cur=cur->next;
	cur->next=new Node(2);
	cur=cur->next;
	cur->next=new Node(1);
	cout<<"Before deletion:"<<endl;
	print(head);
	cout<<"after deletion:"<<endl;
	Partition(head,5);
	print(head);
	}

void Partition(Node* head, int num) {
	//find the first >= element
	Node* cur=head;
	while (cur){
		if (cur->val>=num) break;
		else cur=cur->next;}
	if (!cur) return;
	Node* right=cur; 	
	Node* dummy=new Node(-1);
	dummy->next=head;
	Node* slow=dummy;
	cur=dummy;
	//cur records our progress
	//slow records the <num list
	//right records the >=num list
	while (cur->next) {
	if (cur->next->val<num) {
		slow->next=cur->next;
		slow=slow->next; 
		cur->next=cur->next->next;}
	else 
	cur=cur->next;
	}
	slow->next=right;
	return;
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
		
	

