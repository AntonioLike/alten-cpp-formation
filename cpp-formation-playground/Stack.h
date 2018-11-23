#pragma once
#include "ArrayClass.h"
#include <exception>


class Stack {
	ArrayClass<int> array;// = ArrayClass(0);
	unsigned int currentSize;
public:
	Stack(unsigned int);
	~Stack();
	
	bool isEmpty() const;
	bool isFull() const;
	void push(int);
	int pop();
	int peek();
	unsigned int getCurrentSize();
	

	bool operator==(const Stack&) const;
};

class EmptyStack : public std::exception {
	std::string message;
public:
	EmptyStack(const char*, unsigned int);
	virtual const char* what() const;
};

class FullStack : public std::exception {
	std::string message;
public:
	FullStack(const char*, unsigned int);
	virtual const char* what() const;
};



