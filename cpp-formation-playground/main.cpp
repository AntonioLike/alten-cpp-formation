#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.h"

using namespace std;

int main()
{
	Point p1 = Point(1, 2);
	
	p1.display();

	p1.move(2, 4);

	p1.display();
}
