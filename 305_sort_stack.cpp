#include <iostream>
#include <stack>
using namespace std;
class myStack {
	public:
	void sort();
	void push(int num);
	void pop();
	int peak();
	bool isEmpty();
	void print();
	private:
	stack<int> sta;
	};

void myStack::sort() {
	stack<int> sta2;
	while (!sta.empty()) {
		int cur=sta2.top();
		sta2.pop();
		int count=0;
		while (!sta2.empty() && cur<sta2.top()) {
			sta.push(sta2.top());
			sta2.pop();
			count++; }
		sta2.push(cur);
		while (count) {
			sta2.push(sta.top());
			sta.pop();
			count--;}
		}
	while (!sta2.empty()) {
		sta.push(sta2.top());
		sta.pop();}
	}
void myStack::push(int num) {
	sta.push(num);}
void myStack::pop() {
	sta.pop();}
int myStack::peak() {
	return sta.top();}
bool myStack::isEmpty() {
	return sta.empty();}
void myStack::print() {
	stack<int> sta2;
	while (!sta.empty()) {
		cout<<sta.top()<<" ";
		sta2.push(sta.top());
		sta.pop();
		}
	cout<<endl;
	while (!sta2.empty()) {
		sta.push(sta2.top());
		sta2.pop();}
	}

			  
int main() {
	myStack mysta;
	mysta.push(3);
	mysta.push(5);
	mysta.push(7);
	mysta.push(6);
	mysta.print();
	}

