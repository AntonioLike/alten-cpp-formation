#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int* nullPointer(nullptr);
    cout << "The adress from nullptr is " << nullPointer << endl;
	nullPointer = NULL;
	cout << "The adress from nullptr is " << nullPointer << endl;

	vector<int> v{ 23, 24, 25 };

	int arr[]{ 1,2,3,4,5 };
	for (auto& e : arr)
	{
		e = e * e;
	}
	cout << "The array using references in the for each:" << endl;
	for (const auto& elt : arr)
	{
		cout << elt << endl;
	}

	cout << "The array not using references in the for each:" << endl;
	int arr2[]{ 1,2,3,4,5 };
	for (auto e : arr2)
	{
		e = e * e;
	}
	for (const auto& elt : arr2)
	{
		std::cout << elt << std::endl;
	}

	//Lambda Expressions
	vector<int> numbers{ 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
	for_each(numbers.begin(), numbers.end(),
		[](int z) -> void {cout << z * 2 << ";"; });

	return 0;
}
