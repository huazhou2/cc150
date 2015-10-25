#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int num) {
	val=num;
	next=NULL;
	}
	};
void remove_Dups(Node* head);
void print(Node* head);

int main() {
	//test cases;
	Node* head=new Node(3);
	Node* cur=head;
	cur->next=new Node(2);
	cur=cur->next;
	cur->next=new Node(3);
	cur=cur->next;
	cur->next=new Node(1);
	cur=cur->next;
	cur->next=new Node(1);
	cur=cur->next;
	cout<<"Before:"<<endl;
	print(head);
	remove_Dups(head);
	cout<<"After:"<<endl;
	print(head);
	}

void remove_Dups(Node* head) {
	if (!head || !head->next) return;
	unordered_map<int,int> map;
	Node* cur=head;
	map[cur->val]=1;
	while (cur->next) {
		unordered_map<int,int>::iterator it=map.find(cur->next->val);
		if (it!=map.end()) 
			cur->next=cur->next->next;
		else {
			map[cur->next->val]=1;
			cur=cur->next;
			}
		}
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
		
	

