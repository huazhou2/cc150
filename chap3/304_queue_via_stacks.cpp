#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
	void push(int num);
	void pop();
	int front();
	bool isempty();
private:
	stack<int> sta1;
	stack<int> sta2;
	};
void MyQueue::push(int num) {
	while (!sta1.empty()) {
		sta2.push(sta1.top());
		sta1.pop();}
	sta1.push(num);
	while (!sta2.empty()) {
		sta1.push(sta2.top());
		sta2.pop();}
	cout<<"Pushing "<<num<<endl;
	}
void MyQueue::pop() {
	cout<<"Popping "<<sta1.top()<<endl;
	sta1.pop();}
int MyQueue::front() {
	return sta1.top();
	}
bool MyQueue::isempty() {
	return sta1.empty();}
int main() {
	MyQueue myq;
	myq.push(1);
	cout<<"Front: "<<myq.front()<<endl;
	myq.push(2);
	cout<<"Front: "<<myq.front()<<endl;
	myq.push(3);
	cout<<"Front: "<<myq.front()<<endl;
	myq.pop();
	cout<<"Front: "<<myq.front()<<endl;
	myq.pop();
	cout<<"Front: "<<myq.front()<<endl;
	cout<<"Empty: "<<(myq.isempty()?"Yes":"No")<<endl;
	myq.pop();
	cout<<"Empty: "<<(myq.isempty()?"Yes":"No")<<endl;
	}
	

	
	
	
