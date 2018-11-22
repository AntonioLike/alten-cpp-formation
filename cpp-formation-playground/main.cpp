#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "ArrayClass.h"
#include "Stack.h"

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


	//**************************************Operators*********************************

	ArrayClass t_sum = t_list + t_list;
	cout << "Sum array: " << t_sum << endl;
	
	cout << "The result of comparing sum array and list array is " << (t_sum == t_list) << endl;

	cout << "The result of comparing sum array and list array is " << (t_sum != t_list) << endl;

	ArrayClass t_assign{ 10 };
	t_assign = t_sum;
	cout << "copy assigned array: " << t_assign << endl;

	t_assign = ArrayClass(5);
	cout << "move assigned array: " << t_assign << endl;

	//**********************************Stack************************************

	int stackSize = 10;

	Stack stack0(stackSize);

	for (int i = 0; i < 10; i++) {
		stack0.push(i*i);
	}

	//cout << "The stack looks like this: \n" << stack0 << endl;
	cout << "The top element of the stack is " << stack0.peek() << endl;
	cout << "I remove the top element that is " << stack0.pop();
	cout << " and can see that the new top element is " << stack0.peek() << " if I add the element 15 " << endl;
	stack0.push(15);

	cout << "The new top element will be " << stack0.peek() << endl;

	return 0;
}
