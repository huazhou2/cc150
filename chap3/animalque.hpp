#ifndef _ANIMAL_QUEUQ_H_
#define _ANIMAL_QUEUQ_H_
#include "animal.hpp"
#include <list>
class animalQueue {
	private:
		std::list<Animal*>* doglist;
		std::list<Animal*>* catlist;
		int order;
	public:
		animalQueue();
		~animalQueue();
		void enqueue(Animal*);
		Animal* dequeueAny();	
		Animal* dequeDog();
		Animal* dequeCat();
	};
#endif
		
