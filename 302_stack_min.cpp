#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class myStack {
	public:
		void push(int num);
		void pop();
		int min();
		int top();
	private:
		stack<int> mysta;//stack to store actual data
		vector<int> min_ind;//vector to store the min value
	};

void myStack::push(int num) {
	mysta.push(num);
	if (min_ind.empty())
		min_ind.push_back(num);
	else if (min_ind.back()>num) 
		min_ind.push_back(num);
	else min_ind.push_back(min_ind.back());
	cout<<"Pushing "<<num<<endl;}
void myStack::pop() {
	cout<<"Poping "<<mysta.top()<<endl;
	mysta.pop();
	min_ind.pop_back();}
int myStack::min() {
	return min_ind.back();
	}
int myStack::top() {
	return mysta.top();}
 
int main() {
	//test code
	myStack test_sta;
	test_sta.push(3);
	cout<<"Min "<<test_sta.min()<<endl;
	test_sta.push(1);
	cout<<"Min "<<test_sta.min()<<endl;
	test_sta.pop();
	cout<<"Min "<<test_sta.min()<<endl;
	test_sta.push(2);
	cout<<"Min "<<test_sta.min()<<endl;
	test_sta.push(4);
	cout<<"Min "<<test_sta.min()<<endl;
	test_sta.push(3);
	cout<<"Min "<<test_sta.min()<<endl;
	}

	
		
