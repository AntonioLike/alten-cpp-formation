#include "pch.h"
#include "Stack.h"


Stack::Stack(unsigned int size):array(size)
{
	//array = ArrayClass(size);
	currentSize = 0;
}

Stack::~Stack()
{
}

bool Stack::isEmpty() const
{
	return currentSize == 0;
}

void Stack::push(int value)
{
	if (currentSize < array.getSize()) {
		array[currentSize] = value;
		currentSize++;
	}
}

int Stack::pop()
{
	//int result = (*this)[currentSize-1];
	//(*this)[currentSize - 1] = 0;
	return isEmpty() ? 0:array[--currentSize];
}

int Stack::peek()
{
	return isEmpty() ? 0:array[currentSize - 1];
}

unsigned int Stack::getCurrentSize()
{
	return currentSize;
}

bool Stack::operator==(const Stack & s) const
{
	if (s.currentSize != currentSize)
		return false;
	return array==s.array;
}
