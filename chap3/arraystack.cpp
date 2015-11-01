//#include "arraystack.hpp"
#ifdef _ARRAY_STACK_H
#include <stdexcept>
#include <iostream>
using namespace std;
template <class T>
arraystack<T>::arraystack(int k,int n) {
	_k=k;
	_n=n;
	_arr=new T[n];
	_top=new int[k];
	for (int i=0;i<k;i++) 
		_top[i]=-1;
	_next=new T[n];
	for (int i=0;i<n;i++) 
		_next[i]=i+1;
	free=0;
	}
template <class T>
arraystack<T>& arraystack<T>::operator=(const arraystack<T>& rhs) {
		if (this=&rhs) return *this;
		_k=rhs._k;
		_n=rhs._n;
		_arr=new T[rhs._n];
		for (int i=0;i<rhs._n;i++)
			_arr[i]=rhs._arr[i];
		_top=new int[rhs._k];
		for (int i=0;i<rhs._k;i++)
			_top[i]=rhs._top[i];
		_next=new T[rhs._n];
		for (int i=0;i<rhs._n;i++)
			_next[i]=rhs._next[i];
		return *this;
		}
		
template <class T>
arraystack<T>::arraystack(const arraystack<T>& rhs) {
	_k=rhs._k;
	_n=rhs._n;
	_arr=new T[rhs._n];
	for (int i=0;i<rhs._n;i++)
		_arr[i]=rhs._arr[i];
	_top=new int[rhs._k];
	for (int i=0;i<rhs._k;i++)
		_top[i]=rhs._top[i];
	_next=new T[rhs._n];
	for (int i=0;i<rhs._n;i++)
		_next[i]=rhs._next[i];
	}
template <class T>
arraystack<T>::~arraystack<T>(){
	for (int i=0;i<_n;i++) 
		delete _arr[i];
	delete[] _arr;
	delete[] _top;
	delete[] _next;
	}
template <class T>
T arraystack<T>::top(int sta_num) {
	if (_top[sta_num]==-1) {
		cout<<"Stack "<<sta_num<<" is empty"<<endl;
		throw std::out_of_range("stack empty");
		}
	else return _arr[_top[sta_num]];
	}
	
template <class T>
T arraystack<T>::pop(int sta_num) {
	if (_top[sta_num]==-1) {
		cout<<"Stack "<<sta_num<<" is empty"<<endl;
		return;}
	else {
	_next[_top[sta_num]]=free;
	free=_top[sta_num];	
	return _arr[_top[sta_num]];
	}
}
template <class T>
void arraystack<T>::push(T ele, int sta_num) {
	if (free==_n) { 
		cout<<"No space left"<<endl;
		return;}
	else {
	_arr[free]=ele;
	_top[sta_num]=free;
	free=_next[free];
	}
	}
template <class T>
bool arraystack<T>::isFull() {
	return free==_n;}
template <class T>
bool arraystack<T>::isEmpty(int sta_num) {
	return _top[sta_num]==-1; }
#endif
