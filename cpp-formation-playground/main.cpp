#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "ArrayClass.h"

using namespace std;

int main()
{
	ArrayClass t(10);
	t.element(2) = 10;
	t.element(4) = 25;
	t.display();
	cout << "Elements: " << t.element(0) << " " << t.element(1);
	t.extend(10);
	t.display();
	return 0;
}
