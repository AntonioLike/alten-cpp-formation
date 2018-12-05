
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

struct Interval {
	int start, end;
};

bool comparatorInterval(Interval i1, Interval i2) {
	return i1.start < i2.start;
}

int main()
{
	static const Interval intervalArr[] = { (5,6),(2,9),(1,2),(4,5) };
	std::vector<Interval> intervalVector(intervalArr, intervalArr + sizeof(intervalArr) / sizeof(intervalArr[0]));

	std::sort(intervalVector.begin(), intervalVector.end(), comparatorInterval);

	std::cout << "my vector contains: ";
	for (std::vector<Interval>::iterator it = intervalVector.begin(); it != intervalVector.end(); ++it)
		std::cout << ' ' << (*it).start << "," << (*it).end;
	std::cout << '\n';
}
