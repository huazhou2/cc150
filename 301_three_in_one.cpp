#include <iostream>
#include "arraystack.hpp"
//#include "arraystack.cpp"
using namespace std;

int main() {
	arraystack<int>* mystack=new arraystack<int>(3,100); //3 stacks in size 100 array
	mystack->push(2,1);
	
	cout<<mystack->top(1)<<endl;
	cout<<mystack->top(0)<<endl;
	}
