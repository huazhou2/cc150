#include <iostream>
using namespace std;
//Structure for Linked List Node
struct Node {
	int val;
	Node* next;
	Node(int num) {
	val=num;
	next=NULL;
	}
	};
bool is_Palindrome(Node* mid);
void print(Node* head);
Node* rev_List(Node*);

int main() {
	//test cases;
	Node* head=new Node(3);
	Node* cur=head;
	cur->next=new Node(2);
	cur=cur->next;
	cur->next=new Node(4);
	cur=cur->next;
	cur->next=new Node(2);
	cur=cur->next;
	cur->next=new Node(5);
	cout<<"List:"<<endl;
	print(head);
	cout<<(is_Palindrome(head)?"Yes":"No")<<endl;
	}

bool is_Palindrome(Node* head) {
	//basically check if reversed list is the same as original
	Node* rev_head=rev_List(head);
	while (head) {
		if (head->val==rev_head->val) {
			head=head->next;
			rev_head=rev_head->next;}
		else return false;
		}
	return true;
	}
Node* rev_List(Node* head) {
	if (!head || !head->next) return head;
	Node* prev=NULL, *cur=head;
	while (cur) {
		Node* temp=cur->next;
		cur->next=prev;
		prev=cur;
		cur=temp;
		}
	return prev;
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
		
	

