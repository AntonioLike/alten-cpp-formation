#include "pch.h"
#include "ArrayClass.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <initializer_list>

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
	for (unsigned int i = 0; i < this->size; i++) {
		array[i] = 0;
	}
}

ArrayClass::ArrayClass(const ArrayClass &array)
{
	size = array.size;
	int* newArray = new int[size];

	for (unsigned int i = 0; i < size; i++) {
		newArray[i] = array.array[i];
	}
	this->array = newArray;
}

ArrayClass::ArrayClass(std::initializer_list<int> list):size(list.size())
{
	array = new int[list.size()];
	int i = 0;
	for (auto c: list){
		array[i++] = c;
	}
}

int & ArrayClass::element(unsigned int position)
{
	if (position >= size) {
		throw std::invalid_argument("received negative index or index higher than size");
	}
	return array[position];
}

void ArrayClass::display() const
{
	for (unsigned int i = 0; i<size ; i++) {
		std::cout << array[i] << std::endl;
	}
}

unsigned int ArrayClass::getSize() const
{
	return size;
}

void ArrayClass::extend(unsigned int extra)
{
	int *arrayAux = new int[extra + size];
	unsigned int i = 0;
	for (; i < size; i++) {
		arrayAux[i] = array[i];
	}
	for (; i < size + extra; i++) {
		arrayAux[i] = 0;
	}
	delete [] array;
	array = arrayAux;
	size += extra;
}

ArrayClass ArrayClass::operator+(const ArrayClass & arr) const
{
	ArrayClass resultArray = ArrayClass(arr.getSize() + getSize());
	unsigned int i = 0;
	for (; i < getSize(); i++) {
		resultArray[i] = (*this)[i];
	}
	for (unsigned int j = 0; j < arr.getSize(); j++) {
		resultArray[i] = arr[j];
		i++;
	}
	return resultArray;
}

bool ArrayClass::operator==(const ArrayClass & arr) const
{
	if (getSize() != arr.getSize())
		return false;
	for (unsigned int i = 0; i < getSize(); i++) {
		if (this[i] != arr[i])
			return false;
	}
	return true;
}

bool ArrayClass::operator!=(const ArrayClass & arr) const
{
	return !((*this) == arr);
}

ArrayClass & ArrayClass::operator=(const ArrayClass & arr)
{	
	if (this != &arr) { // protect against invalid self-assignment
			// 1: allocate new memory and copy the elements
		int* new_array = new int[arr.size];
		std::copy(arr.array, arr.array + arr.size, new_array);

		// 2: deallocate old memory
		delete[] array;

		// 3: assign the new memory to the object
		array = new_array;
		size = arr.size;
	}
	// by convention, always return *this
	return *this;
}

ArrayClass & ArrayClass::operator=(ArrayClass && arr)
{
	std::swap(size, arr.size);
	std::swap(array, arr.array);
	return *this;
}

int & ArrayClass::operator[](unsigned int index)
{
	return array[index];
}

int & ArrayClass::operator[](unsigned int index) const
{
	return array[index];
}

ArrayClass::~ArrayClass()
{
	delete [] array;
}

std::ostream & operator<<(std::ostream & os, const ArrayClass & arr)
{
	os << "[" << arr[0];
	for (unsigned int i = 1; i < arr.getSize(); i++) {
		os << " , " << arr[i];
	}
	os << "]";
	return os;
}
