#pragma once
#include <iostream>
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

	ArrayClass operator+(const ArrayClass&) const;
	bool operator==(const ArrayClass&) const;
	bool operator!=(const ArrayClass&) const;
	ArrayClass& operator=(const ArrayClass&);
	ArrayClass& operator=(ArrayClass&&);
	int& operator[](unsigned int);
	int& operator[](unsigned int) const;

	~ArrayClass();
};

std::ostream & operator<<(std::ostream&, const ArrayClass&);