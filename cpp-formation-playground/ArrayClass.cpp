#include "pch.h"
#include "ArrayClass.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

ArrayClass::ArrayClass(unsigned int size)
{
	if (size == 0) {
		cout << "The size of an array can't be 0. It's been initialized with 10" << endl;
		this->size = 10;
	}
	else {
		this->size = size;
	}
	array = new int[this->size];
	for (int i = 0; i < this->size; i++) {
		array[i] = 0;
	}
}

int & ArrayClass::element(unsigned int position)
{
	if (position >= size) {
		throw std::invalid_argument("received negative index or index higher than size");
	}
	return array[position];
}

void ArrayClass::display()
{
	for (int i = 0; i<size ; i++) {
		std::cout << array[i] << std::endl;
	}
}

unsigned int ArrayClass::getSize()
{
	return size;
}

void ArrayClass::extend(unsigned int extra)
{
	int *arrayAux = new int[extra + size];
	int i = 0;
	for (; i < size; i++) {
		arrayAux[i] = array[i];
	}
	for (i++; i < size + extra; i++) {
		arrayAux[i] = 0;
	}
	delete [] array;
	array = arrayAux;
	size += extra;
}

ArrayClass::~ArrayClass()
{
	delete [] array;
}
