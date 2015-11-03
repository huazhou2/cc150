#include <iostream>
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

int height(TreeNode* head) {
	if (!head) return 0;
	return 1+max(height(head->left),height(head->right));
	}

bool isBalanced(TreeNode* head) {
	if (!head) return true;
	int dif=height(head->left)-height(head->right);
	dif=dif>=0?dif:-dif;
	if (dif>1) return false;
	else return isBalanced(head->left) && isBalanced(head->right);
	}
int main() {
	TreeNode* head=new TreeNode(5);
	TreeNode* l1=new TreeNode(3);
	TreeNode* r1=new TreeNode(8);
	head->left=l1;
	//head->right=r1;
	l1->left=new TreeNode(1);
	l1->right=new TreeNode(4);
	//r1->right=new TreeNode(9);
	cout<<"This Tree is balanced? "<<(isBalanced(head)?"Yes":"No")<<endl;
	}
	
