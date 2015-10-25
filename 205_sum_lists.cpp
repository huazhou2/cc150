#include <iostream>
using namespace std;
//structre for Linked List Node
struct Node {
	int val;
	Node* next;
	Node(int num) {
	val=num;
	next=NULL;
	}
	};
//do the forward one, cuz it's more difficult
Node* sum_List(Node* head1, Node* head2);
void print(Node* head);
Node* rev_List(Node* head);

int main() {
	//test cases;
	Node* head1=new Node(6);
	Node* cur=head1;
	cur->next=new Node(1);
	cur=cur->next;
	cur->next=new Node(7);
	Node* head2=new Node(3);
	cur=head2;
	cur->next=new Node(9);
	cur=cur->next;
	cur->next=new Node(5);
	cout<<"List1: "<<endl;
	print(head1);
	cout<<"List2: "<<endl;
	print(head2);
	Node* head=sum_List(head1,head2);
	cout<<"Sum of List1 and List 2:"<<endl;
	print(head);
	}

Node* sum_List(Node* head1, Node* head2) {
	//if either list is null, simply return
	if (!head1) return head2;
	else if (!head2) return head1;
	//reverse both lists so we can sum list from head to tail
	head1=rev_List(head1);
	head2=rev_List(head2);
	int carry=0;
	Node* cur1=head1, *cur2=head2;
	Node* dummy=new Node(-1);
	Node* cur=dummy;
	while (cur1 || cur2 || carry) {
		int val1,val2;
		val1=cur1?cur1->val:0;
		val2=cur2?cur2->val:0;
		int temp=val1+val2+carry;
		cur->next=new Node(temp%10);
		carry=temp/10;
		//check cur pos to make sure cur->next exists!!
		if (cur1)
			cur1=cur1->next;
		if (cur2)
			cur2=cur2->next;
		cur=cur->next;
		}
	//reverse summed list again to get the correct order
	cur=dummy->next;
	delete dummy;
	return rev_List(cur);
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
		
	

