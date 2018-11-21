#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "ArrayClass.h"

using namespace std;

int main()
{
	
	ArrayClass t(5);
	t.element(2) = 10;
	t.element(4) = 25;
	cout << "The t object" << endl;
	t.display();
	cout << "Elements: " << t.element(0) << " " << t.element(1) << endl;
	t.extend(5);
	cout << "The t object after extending by 5" << endl;
	t.display();

	cout << "The t object created by the initialized_list constructor" << endl;
	ArrayClass t_list{ 1,2,3,4,5};
	t_list.display();

	cout << "The t object constructed by the copy constructor" << endl;
	ArrayClass t_copy(t);
	t_copy.display();

	const ArrayClass t_const(t);
	cout << "The getSize and display methods are const and can be used by const Objects. The size of t_const is: " << t_const.getSize() << endl;
	t_const.display();

	return 0;
}
