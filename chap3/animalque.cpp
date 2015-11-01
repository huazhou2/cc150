#include <list>
#include "animalque.hpp"
using std::list;
animalQueue::animalQueue() {
	order=0;
	doglist=new list<Animal*>;
	catlist=new list<Animal*>;}
animalQueue::~animalQueue() {
	order=0;
	delete doglist;
	delete catlist;}
void animalQueue::enqueue(Animal* rhs) {
	order++;
	rhs->setOrder(order);
	if (rhs->getType()==Animal::dog) 
		doglist->push_back(rhs);
	else if (rhs->getType()==Animal::cat) 
	catlist->push_back(rhs);
	}
Animal* animalQueue::dequeueAny() {
	Animal* result;
	if (doglist->empty() && catlist->empty()) return NULL;
	if (doglist->empty()) {
		result=catlist->front();	
		catlist->pop_front();
		return result;}	
	else if (catlist->empty()) {
		result=doglist->front();
		doglist->pop_front();	
		return result;}	
	if (catlist->front()->getOrder() > doglist->front()->getOrder()){
		result=doglist->front();
		doglist->pop_front();	
		return result;}
	else {
		result=catlist->front();
		catlist->pop_front();	
		return result;}
	}
Animal* animalQueue::dequeDog() {
	if (doglist->empty()) return NULL;
	Animal* result=doglist->front();
	doglist->pop_front();
	return result;}
Animal* animalQueue::dequeCat() {
	if (catlist->empty()) return NULL;
	Animal* result=catlist->front();
	catlist->pop_front();
	return result;}
		
