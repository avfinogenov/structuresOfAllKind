#include <iostream>
#include <list>

#include "MyStack.h"
#include "MyQueue.h"

//todo 
//proper testing
//in queue and twowaylist need to rethink constructor
int main()
{

	
	/*MyStack<int> test(1);
	test.pop();
	std::cout << test.last() << "\n";
	test.pop();
	std::cout << test.last() << "\n";*/
	MyQueue<int> test2;
	test2.add(1);
	test2.add(2);
	do
	{
		std::cout << test2.front();
	} while (test2.pop_front());
	
	



}
