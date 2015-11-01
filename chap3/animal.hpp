#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include <string>
class Animal {
public:
	typedef enum {dog,cat} typ;
	Animal();
	~Animal();
	Animal(std::string);
	int getOrder();
	void setOrder(int);
	void setType(typ);
	typ getType();
	std::string getName();
	virtual void speak();
private:
	int ord;
	std::string name;
	typ type;
	};
class Dog:public Animal {
	public:
	Dog();
	Dog(std::string);
	~Dog();
	virtual void speak();
	};
class Cat:public Animal {
	public:
	Cat();
	Cat(std::string);
	~Cat();
	virtual void speak();
	};
#endif
