#include "pch.h"
#include <iostream>     // std::cout
#include <algorithm>    // std::find_if
#include <vector>       // std::vector

int main() {
	int myarray[4]{ 1,2,3,4 };

	auto isOdd = [](int i) { return ((i % 2) == 1); };

	int* it = std::find_if(myarray, myarray+4, isOdd);
	std::cout << "The first odd value is " << *it << '\n';

	return 0;
}