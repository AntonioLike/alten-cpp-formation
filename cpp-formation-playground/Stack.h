#pragma once
#include "ArrayClass.h"
class Stack {
	ArrayClass array;// = ArrayClass(0);
	unsigned int currentSize;
public:
	Stack(unsigned int);
	~Stack();
	
	bool isEmpty() const;
	void push(int);
	int pop();
	int peek();
	unsigned int getCurrentSize();
	

	bool operator==(const Stack&) const;
};


