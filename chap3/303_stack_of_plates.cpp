#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;
class SetOfStacks {
	public:
		SetOfStacks(int k, int threshold);
		void push(int num);
		void pop();
		int top();
		bool isempty();//return any element
		void pop(int sta_ind);
	private:
		int sta_size;
		int sta_total;
		int cur_size;
		stack<int>* stacksets;
		};

SetOfStacks::SetOfStacks(int k, int threshold) {
	sta_size=threshold;
	sta_total=k;
	cur_size=0;
	stacksets=new stack<int>[k*threshold];
	}
void SetOfStacks::push(int num) {
	if (cur_size==sta_total*sta_size) throw std::out_of_range("No more space");
	else {
	cur_size++;
	stacksets[(cur_size-1)/sta_size].push(num);
	cout<<"Pushing "<<num<<" in stack "<<(cur_size-1)/sta_size+1<<endl;
		}
	}
void SetOfStacks::pop() {
	cout<<"Popping "<<top()<<" from stack "<<(cur_size-1)/sta_size+1<<endl;
	stacksets[(cur_size-1)/sta_size].pop();
	cur_size--;
	}
int SetOfStacks::top() {
	return stacksets[(cur_size-1)/sta_size].top();}
bool SetOfStacks::isempty() {
	return cur_size==0;
	}
void SetOfStacks::pop(int sta_ind) {
	cout<<"Popping "<<top()<<" from stack "<<sta_ind<<endl;
	stacksets[sta_ind-1].pop();}

int main() {
	SetOfStacks mysta(3,2);
	mysta.push(3);
	mysta.pop();
	mysta.push(1);
	mysta.push(4);
	mysta.push(2);
	mysta.push(5);
	mysta.push(6);
	mysta.push(7);
	mysta.push(8);
	}
	
	
	
	
	
	
	
		

