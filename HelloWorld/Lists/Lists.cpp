
#include "pch.h"
#include <list>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//template <typename T>
void showList(list <int> myList) {
	for (list<int> ::iterator it = myList.begin(); it != myList.end(); it++) {
		cout << *it << "\n";
	}
}

int main()
{
	list<int> intListBack;
	list<int> intListFront;
	for (int i = 0; i < 10; i++) {
		intListBack.push_back(i * 2);
		intListFront.push_front(i * 3);
	}
    std::cout << "List front:\n";
	showList(intListFront);
	std::cout << "List back:\n";
	showList(intListBack);

	return 0;
}

