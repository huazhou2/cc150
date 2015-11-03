#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int num): val(num),left(NULL),right(NULL) {};
	void print(TreeNode*);
	};
void TreeNode::print(TreeNode* head) {
	if (!head) return;
	cout<<head->val<<" ";
	print(head->left);
	print(head->right);
	cout<<endl;
	}

void helper(TreeNode* head, vector<int>& result) {
	if (!head) return;
	helper(head->left,result);
	result.push_back(head->val);
	helper(head->right,result);
	}
bool isBST(TreeNode* head) {
	vector<int> result;
	helper(head,result);
	for (int i=0;i<result.size()-1;i++)
		if (result[i]>=result[i+1]) return false;
	return true;
	}
int main() {
	TreeNode* head=new TreeNode(3);
	TreeNode* l1=new TreeNode(1);
	TreeNode* r1=new TreeNode(5);
	head->left=l1;
	head->right=r1;
	l1->left=new TreeNode(0);
	l1->right=new TreeNode(2);
	r1->left=new TreeNode(4);
	r1->right=new TreeNode(6);
	l1->right->right=new TreeNode(3);
	cout<<"This Tree is BST? "<<(isBST(head)?"Yes":"No")<<endl;
	}
			   
			
