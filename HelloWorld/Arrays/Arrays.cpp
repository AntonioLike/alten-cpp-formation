
#include "pch.h"
#include <iostream>
#include <array>

using namespace std;

template<typename T, std::size_t N>
void showArrays(const std::array<T, N>& arr)
{
	for (const auto& e : arr)
		std::cout << e << "\n";
}

int main()
{
	array<int,6> myArray = { 1,2,3,4,5,6 };
	cout << "The array is \n";
	showArrays(myArray);

	return 0;
}