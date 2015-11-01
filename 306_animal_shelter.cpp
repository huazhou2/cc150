#include <iostream>
#include "animal.hpp"
#include "animalque.hpp"
using namespace std;
int main() {
	animalQueue myqueue;
	myqueue.enqueue(new Dog("dog1"));
	myqueue.enqueue(new Dog("dog2"));
	myqueue.enqueue(new Cat("cat1"));
	myqueue.enqueue(new Cat("cat2"));
	myqueue.dequeueAny()->speak();
	myqueue.dequeCat()->speak();
	myqueue.dequeDog()->speak();
	myqueue.dequeCat()->speak();
	myqueue.dequeDog()->speak();
	}
