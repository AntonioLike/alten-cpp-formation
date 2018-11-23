#pragma once
#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>

template <class T>
class ArrayClass
{
	T* array;
	unsigned int size;

public:
	ArrayClass(unsigned int);
	ArrayClass(const ArrayClass<T>&);
	ArrayClass(std::initializer_list<T>);
	T &element(unsigned int);
	void display() const;
	unsigned int getSize() const;
	void extend(unsigned int);

	ArrayClass<T> operator+(const ArrayClass<T>&) const;
	bool operator==(const ArrayClass&) const;
	bool operator!=(const ArrayClass&) const;
	ArrayClass& operator=(const ArrayClass&);
	ArrayClass& operator=(ArrayClass&&);
	T& operator[](unsigned int);
	T& operator[](unsigned int) const;

	~ArrayClass();
};

template<class T>
std::ostream & operator<<(std::ostream&, const ArrayClass<T>&);

template<class T>
void displayArr(const T& array, unsigned int n) {
	std::cout << "[" << array[0];
	for (unsigned int i = 1; i < n; i++) {
		std::cout << "," << array[i];
	}
	std::cout << "]" << std::endl;
}

template<class T>
ArrayClass<T>::ArrayClass(unsigned int size)
{
	if (size == 0) {
		std::cout << "The size of an array can't be 0. It's been initialized with 10" << std::endl;
		this->size = 10;
	}
	else {
		this->size = size;
	}
	array = new T[this->size];
	for (unsigned int i = 0; i < this->size; i++) {
		array[i] = 0;
	}
}

template<class T>
ArrayClass<T>::ArrayClass(const ArrayClass &array)
{
	size = array.size;
	T* newArray = new int[size];

	for (unsigned int i = 0; i < size; i++) {
		newArray[i] = array.array[i];
	}
	this->array = newArray;
}

template<class T>
ArrayClass<T>::ArrayClass(std::initializer_list<T> list) :size(list.size())
{
	array = new T[list.size()];
	int i = 0;
	for (auto c : list) {
		array[i++] = c;
	}
}

template<class T>
T& ArrayClass<T>::element(unsigned int position)
{
	if (position >= size) {
		throw std::invalid_argument("received negative index or index higher than size");
	}
	return array[position];
}

template<class T>
void ArrayClass<T>::display() const
{
	for (unsigned int i = 0; i < size; i++) {
		std::cout << array[i] << std::endl;
	}
}

template<class T>
unsigned int ArrayClass<T>::getSize() const
{
	return size;
}

template<class T>
void ArrayClass<T>::extend(unsigned int extra)
{
	T *arrayAux = new T[extra + size];
	unsigned int i = 0;
	for (; i < size; i++) {
		arrayAux[i] = array[i];
	}
	for (; i < size + extra; i++) {
		arrayAux[i] = 0;
	}
	delete[] array;
	array = arrayAux;
	size += extra;
}

template<class T>
ArrayClass<T> ArrayClass<T>::operator+(const ArrayClass & arr) const
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

template<class T>
bool ArrayClass<T>::operator==(const ArrayClass & arr) const
{
	if (getSize() != arr.getSize())
		return false;
	for (unsigned int i = 0; i < getSize(); i++) {
		if (this[i] != arr[i])
			return false;
	}
	return true;
}

template<class T>
bool ArrayClass<T>::operator!=(const ArrayClass<T>& arr) const
{
	return !((*this) == arr);
}

template<class T>
ArrayClass<T>& ArrayClass<T>::operator=(const ArrayClass<T>& arr)
{
	if (this != &arr) { // protect against invalid self-assignment
			// 1: allocate new memory and copy the elements
		T* new_array = new T[arr.size];
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

template<class T>
ArrayClass<T> & ArrayClass<T>::operator=(ArrayClass && arr)
{
	std::swap(size, arr.size);
	std::swap(array, arr.array);
	return *this;
}

template<class T>
T& ArrayClass<T>::operator[](unsigned int index)
{
	return array[index];
}

template<class T>
T& ArrayClass<T>::operator[](unsigned int index) const
{
	return array[index];
}

template<class T>
ArrayClass<T>::~ArrayClass()
{
	delete[] array;
}

template<class T>
std::ostream & operator<<(std::ostream & os, const ArrayClass<T>& arr)
{
	os << "[" << arr[0];
	for (unsigned int i = 1; i < arr.getSize(); i++) {
		os << " , " << arr[i];
	}
	os << "]";
	return os;
}
