#include "pch.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
void printVector(vector<T> myVector) {
	for_each(myVector.begin(), myVector.end(), [](const T& n) {cout << n << "\n"; });
}

int main()
{
	vector<int> myVector{ 1,2,3,4,5 };	
	printVector(myVector);

	vector<string> myStringVector{ "computer", "science", "object" };
	printVector(myStringVector);

	return 0;
}
