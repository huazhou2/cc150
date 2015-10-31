#ifndef _ARRAY_STACK_H
#define _ARRAY_STACK_H
template <class Type>
class arraystack {
	public:
		arraystack(int k=3, int n=100);
		arraystack<Type>& operator=(const arraystack<Type>& rhs);
		arraystack(const arraystack<Type>& rhs);
		~arraystack();
		Type top(int sta_num);
		Type pop(int sta_num);
		void push(Type ele, int sta_num=0);
		bool isFull();//check if array has space left
		bool isEmpty(int sta_num);//check if stack is empty
	private:
		int _k;
		int _n;
		int* _arr;
		int* _top;//size k 
		int* _next;//store next free index
		int free;//store first free index of free space
	};
#include "arraystack.cpp"
#endif
		
		
		
		
		
