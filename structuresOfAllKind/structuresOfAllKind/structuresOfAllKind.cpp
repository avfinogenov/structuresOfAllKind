//#define __CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
//#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#define new DEBUG_NEW

#include <iostream>
#include <list>
#include <stack>
#include <random>
#include "MyStack.h"
#include "MyQueue.h"





//todo 
//proper testing
// stack +
// queue
// twlist
//in queue and twowaylist need to rethink constructor
// smart pointers




void stackTest();


int main()
{
	srand(time(NULL));
	stackTest();
	/*MyStack<int> test(1);
	test.pop();
	std::cout << test.last() << "\n";
	test.pop();
	std::cout << test.last() << "\n";*/
	/*MyQueue<int> test2;
	test2.add(1);
	test2.add(2);
	do
	{
		std::cout << test2.front();
	} while (test2.pop_front());*/
	
	

	return _CrtDumpMemoryLeaks();

}


void stackTest()
{
	std::cout << "matching test\n";
	MyStack<int> myStack;
	std::stack<int> originStack;
	int curRand = rand() % 100;
	for (int i = 0; i < curRand; ++i)
	{
		int tmp = rand() % 500;
		originStack.push(tmp);
		myStack.append(tmp);
		if (myStack.last() != originStack.top())
		{
			std::cout << "error\n";
			return;
		}
		originStack.pop();
		myStack.pop();
		
	}
	curRand = rand() % 500;
	for (int i = 0; i < curRand; ++i)
	{
		int tmp = rand() % 500;
		originStack.push(tmp);
		myStack.append(tmp);
	}
	for (int i = 0; i < curRand; ++i)
	{
		if (myStack.last() != originStack.top())
		{
			std::cout << "error\n";
			return;
		}
		originStack.pop();
		myStack.pop();
		
	}
	std::cout << "matching test succes\n";
	
	std::cout << "memory test\n";
	for (int i = 0; i < 100000; ++i)
	{
		MyStack<int> tmp;
		for (int j = 0; j < 1000; ++j)
		{
			tmp.append(1);
		}

	}
	std::cout << "memory test finished\n";
}