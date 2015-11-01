#include <string>
#include <iostream>
#include "animal.hpp"
Animal::Animal() {
	name="No Name Animal";
	ord=0;
	}
Animal::Animal(std::string name) {
	this->name=name;}
int Animal::getOrder() {
	return ord;}
void Animal::setOrder(int num) {
	this->ord=num;}
void Animal::setType(typ kind) {
	type=kind;}
Animal::typ Animal::getType() {
	return type;}
std::string Animal::getName() {
	return name;}
void Animal::speak() {std::cout<<"I'm an animal with name "<<this->getName()<<std::endl;}
Dog::Dog():Animal() {Animal::setType(dog);}
Cat::Cat():Animal() {Animal::setType(cat);}
Dog::Dog(std::string name):Animal(name) {setType(dog);}
Cat::Cat(std::string name):Animal(name) {setType(cat);}
void Dog::speak() {std::cout<<"I'm a dog with name "<<this->getName()<<std::endl;}
void Cat::speak() {std::cout<<"I'm a cat with name "<<this->getName()<<std::endl;}

	
	

	
	
