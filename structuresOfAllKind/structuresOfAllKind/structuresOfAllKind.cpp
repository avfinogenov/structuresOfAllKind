//#define __CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
//#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#define new DEBUG_NEW

#include <iostream>
#include <list>
#include <stack>
#include <random>
#include <queue>
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
void queueTest();

int main()
{
	srand(time(NULL));
	std::cout << "stack test\n";
	stackTest();
	std::cout << "queue test\n";
	queueTest();

	
	

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

void queueTest()
{
	std::cout << "matching test\n";
	MyQueue<int> myQueue;
	std::queue<int> originQueue;
	int curRand = rand() % 100;
	for (int i = 0; i < curRand; ++i)
	{
		int tmp = rand() % 500;
		originQueue.push(tmp);
		myQueue.add(tmp);
		if (myQueue.front() != originQueue.front())
		{
			std::cout << "error\n";
			return;
		}
		originQueue.pop();
		myQueue.pop_front();

	}
	curRand = rand() % 500;
	for (int i = 0; i < curRand; ++i)
	{
		int tmp = rand() % 500;
		originQueue.push(tmp);
		myQueue.add(tmp);
	}
	for (int i = 0; i < curRand; ++i)
	{
		if (myQueue.front() != originQueue.front())
		{
			std::cout << "error\n";
			return;
		}
		originQueue.pop();
		myQueue.pop_front();

	}
	std::cout << "matching test succes\n";

	std::cout << "memory test\n";
	for (int i = 0; i < 100000; ++i)
	{
		MyQueue<int> tmp;
		for (int j = 0; j < 1000; ++j)
		{
			tmp.add(1);
		}

	}
	std::cout << "memory test finished\n";
}