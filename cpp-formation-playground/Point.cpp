#include "pch.h"
#include "Point.h"
#include <iostream>
#include <string>

unsigned int Point::counter = 0;


std::string compareValueToString(CompareValue enumValue) {
	switch (enumValue)
	{
	case 1:
		return "greater than";
	case -1:
		return "lesser than";
	default:
		return "equal to";
	}
}

Point::Point() : Point(0, 0)
{
}

Point::Point(float x) : Point(x,0)
{
}

Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
	Point::counter++;
}

Point::Point(const Point & point)
{
	x = point.x;
	y = point.y;
	Point::counter++;
}

Point::Point(Point && p):x(0),y(0)
{
	std::swap(x, p.x);
	std::swap(y, p.y);
}

void Point::move(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Point::display() const
{
	std::cout << "The coordinates of the point are x: " << x << " and y: " << y << std::endl;
}

unsigned int Point::numberOfPointers()
{
	return counter;
}

CompareValue Point::compare(const Point &p)
{
	if (x + y < p.x + p.y)
		return Bigger;
	else if (x + y > p.x + p.y)
		return Smaller;
	return Equal;
}

Point Point::maximum(const Point &p)
{
	CompareValue compareValue = compare(p);
	if (compareValue == 1)
		return p;
	else
		return *this;
}

Point::~Point()
{
	Point::counter--;
}
