#include <iostream>
#include <list>

#include "MyStack.h"



int main()
{

	
	MyStack<int> test(1);
	test.pop();
	std::cout << test.last() << "\n";
	test.pop();
	std::cout << test.last() << "\n";






}
