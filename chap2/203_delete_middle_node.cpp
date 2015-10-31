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
void del_Mid(Node* mid);
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
	cout<<"Before deletion:"<<endl;
	print(head);
	Node* mid=head->next->next; //delte node with value 4
	del_Mid(mid);
	cout<<"after deletion:"<<endl;
	print(head);
	}

void del_Mid(Node* mid) {
	//Basically doing value refill
	mid->val=mid->next->val;
	mid->next=mid->next->next;
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
		
	

