#pragma once
#include <initializer_list>

class ArrayClass
{
	int* array;
	unsigned int size;

public:
	ArrayClass(unsigned int);
	ArrayClass(const ArrayClass &);
	ArrayClass(std::initializer_list<int>);
	int &element(unsigned int);
	void display() const;
	unsigned int getSize() const;
	void extend(unsigned int);

	~ArrayClass();
};

