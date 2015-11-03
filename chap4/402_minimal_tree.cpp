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
	}
TreeNode* helper(int* arr, int left,int right) {
	if (left>right) return NULL;
	int mid=(left+right)/2;
	TreeNode* head=new TreeNode(arr[mid]);
	head->left=helper(arr,left,mid-1);
	head->right=helper(arr,mid+1,right);
	return head;
	}
TreeNode* minTree(int* arr, size_t num) {
	return helper(arr,0,num-1);
	}

int main() {
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	TreeNode* head=minTree(arr,10);
	head->print(head);
	}
	
	


	
