#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	TreeNode(int num): val(num),left(NULL),right(NULL),parent(NULL) {};
	void print(TreeNode*);
	};
void TreeNode::print(TreeNode* head) {
	if (!head) return;
	cout<<head->val<<" ";
	print(head->left);
	print(head->right);
	}
TreeNode* successor(TreeNode* head) {
	if (!head) return NULL;
	if (head->right) {
		TreeNode* cur=head->right;
		while (cur->left) 
			cur=cur->left;
		return cur;}
	else {
		TreeNode* cur=head->parent;
		while (cur && cur->right==head) {
			head=cur;
			cur=head->parent;}
		return cur;}
	}
	
int main() {
	TreeNode* head=new TreeNode(5);
	TreeNode* l1=new TreeNode(3);
	TreeNode* r1=new TreeNode(8);
	head->left=l1;
	head->right=r1;
	l1->parent=head;
	r1->parent=head;
	l1->left=new TreeNode(1);
	l1->right=new TreeNode(4);
	l1->left->parent=l1;
	l1->right->parent=l1;
	r1->right=new TreeNode(9);
	r1->right->parent=r1;
	TreeNode* next=successor(r1);
	cout<<r1->val<<" next is "<<next->val<<endl;
	}		
			
