#include "pch.h"
#include "Stack.h"
#include <sstream>
#include <string>

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

bool Stack::isFull() const
{
	return currentSize >= array.getSize();
}

void Stack::push(int value)
{
	if (isFull())
		throw FullStack("Error in push()", __LINE__);
		
	array[currentSize] = value;
	currentSize++;
}

int Stack::pop()
{
	return isEmpty() ? (throw EmptyStack("Error in pop()",__LINE__)):array[--currentSize];
}

int Stack::peek()
{
	return isEmpty() ? (throw EmptyStack("Error in peek()",__LINE__)):array[currentSize - 1];
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

EmptyStack::EmptyStack(const char * msg, unsigned int line)
{
	std::ostringstream oss;
	oss << "Error line " << line << " : " << "Empty Stack-> " << msg << std::endl;
	message = oss.str();
}

const char * EmptyStack::what() const
{
	return message.c_str();
}

FullStack::FullStack(const char * msg, unsigned int line)
{
	std::ostringstream oss;
	oss << "Error line " << line << " : " << "Full Stack-> " << msg << std::endl;
	message = oss.str();
}

const char * FullStack::what() const
{
	return message.c_str();
}


