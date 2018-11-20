#pragma once
class ArrayClass
{
	int* array;
	unsigned int size;

public:
	ArrayClass(unsigned int);
	int &element(unsigned int);
	void display();
	unsigned int getSize();
	void extend(unsigned int);

	~ArrayClass();
};

