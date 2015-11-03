#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int num): val(num),left(NULL),right(NULL) {};
	};
void print(TreeNode* head) {
	if (!head) return;
	cout<<head->val<<" ";
	print(head->left);
	print(head->right);
	}
//I intended to use a lot of pointers here:P
vector<list<TreeNode*>* > listDepth(TreeNode* head) { //vector of pointer to list of pointers to TreeNode
	vector<list<TreeNode*>* > result;
	if (!head) return result;
	deque<TreeNode*> myq;
	myq.push_back(head);
	while (!myq.empty()) {
		list<TreeNode*>* cur=new list<TreeNode*>();
		while (!myq.empty()){ 
		cur->push_back(myq.front());
		myq.pop_front();}
		result.push_back(cur);
		for (list<TreeNode*>::iterator it=cur->begin();it!=cur->end();it++) {
			if ((*it)->left)
			myq.push_back((*it)->left);
			if ((*it)->right)
			myq.push_back((*it)->right);
		}
		}
	return result;
	}
void print(vector<list<TreeNode*>* >& result) {
	if (result.empty()) return;
	int level=0;
	for (vector<list<TreeNode*>* >::iterator it=result.begin();it!=result.end();it++) {
	cout<<"Level "<<++level<<": ";
	for (list<TreeNode*>::iterator it2=(*it)->begin();it2!=(*it)->end();it2++) 
		cout<<(*it2)->val<<" ";
	cout<<endl;
	}
	}

int main() {
	TreeNode* head=new TreeNode(5);
	TreeNode* l1=new TreeNode(3);
	TreeNode* r1=new TreeNode(8);
	head->left=l1;
	head->right=r1;
	l1->left=new TreeNode(1);
	l1->right=new TreeNode(4);
	r1->right=new TreeNode(9);
	vector<list<TreeNode*>* > result=listDepth(head);
	print(result);
	}		
