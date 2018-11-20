#include "pch.h"
#include "Point.h"
#include <iostream>

Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Point::move(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Point::display()
{
	std::cout << "The coordinates of the point are x: " << x << " and y: " << y << std::endl;
}

Point::~Point()
{
}
