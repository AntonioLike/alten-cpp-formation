#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.h"

using namespace std;

void counterTest() {
	Point p2 = Point(2, 3);

	cout << "The counter value after creating another point is: " << Point::numberOfPointers() << endl;
}

int main()
{
	Point p1 = Point(1, 2);
	
	p1.display();

	p1.move(2, 4);

	p1.display();

	cout << "The counter value is: " << Point::numberOfPointers() << endl;

	counterTest();

	cout << "The counter value is after destroying a point by leaving scope: " << Point::numberOfPointers() << endl;

	cout << "Point created by the no arguments constructor" << endl;
	Point p_empty = Point();
	p_empty.display();

	cout << "Point created by the constructor with one argument" << endl;
	Point p_oneArg = Point(2);
	p_oneArg.display();

	cout << "Point created by the copy constructor" << endl;
	Point p_copy = p1;
	p_copy.display();

	cout << "The point P1 is " << compareValueToString(p_copy.compare(p1)) << " the point p_copy" << endl;
	
	cout << "The maximum of the points p1 and p_empty is " << endl;
	p1.maximum(p_empty).display();

	Point p_move = std::move(p1);
}
