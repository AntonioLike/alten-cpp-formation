#include <string>
#pragma once

enum CompareValue
{
	Bigger = 1,
	Equal = 0,
	Smaller = -1
};

std::string compareValueToString(CompareValue);
void printPointer(const Point&);

class Point
{
	friend void printPointer(const Point&);
	float x;
	float y;
	static unsigned int counter;
public:
	Point();
	Point(float);
	Point(float,float);
	Point(const Point&);
	Point(Point&&);
	void move(float, float);
	void display() const;
	static unsigned int numberOfPointers();
	CompareValue compare(const Point&);
	Point maximum(const Point&);
	~Point();
};

