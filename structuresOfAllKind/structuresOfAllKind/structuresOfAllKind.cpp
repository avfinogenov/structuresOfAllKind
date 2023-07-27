//#define __CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
//#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#define new DEBUG_NEW

#include <iostream>
#include <list>
#include <stack>
#include <random>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <random>
#include <vector>
#include "MyStack.h"
#include "MyQueue.h"
#include "TwoWayList.h"
#include "MyBinaryTree.h"



//todo 
//in queue and twowaylist need to rethink constructor
// smart pointers
// перечисление в дерево
// понять, почему иногда находит ключ, 
// прокоментить формулы

void stackTest();
void queueTest();
void listTest();



int main()
{
	
	//std::cout << "stack test\n";
	//stackTest();
	//std::cout << "queue test\n";
	//queueTest();
	//std::cout << "list test\n";
	//listTest();
	MyBinaryTree t;
	//int sizeOfTree = rand() % 300 + 1500;
	int sizeOfTree = 500050;
	auto rng = std::default_random_engine{};
	std::vector<long long> cards_, cards2;
	for (int i = 0; i < sizeOfTree; ++i)
	{
		cards_.push_back(i);
	}
	/*for (int i = 0; i < sizeOfTree; ++i)
	{
		cards2.push_back(i + 50000 + (rand() % sizeOfTree));
	}*/
	std::shuffle(std::begin(cards_), std::end(cards_), rng);
	srand(time(NULL));
	//std::shuffle(std::begin(cards2), std::end(cards2), rng);
	createTree(t, cards_);
	
	std::set<long long> setOfTestValuesKeys;
	std::set<long long> setOfTestValuesV;
	for (int i = 0; i < sizeOfTree; ++i)
	{
		//int tmp = testValues.front();
		setOfTestValuesKeys.insert(cards_[i]);
		//testValues.pop_front();
		//testValues.push_back(tmp);

	}
	std::cout << sizeOfTree << " " << t.getNumberOfNodes() << " " << t.getNumberOfRepeats();
	int lossCounter = 0;
	//int numberOfInserts = setOfTestValuesKeys.size();
	int numberOfInserts = 10000;
	std::set<long long>::iterator it = setOfTestValuesKeys.begin();
	for (int i = 0; i < numberOfInserts; ++i)
	{
		int tryCOunter = 0;
		long long tmp1, tmp2;
		//tmp1 = *(it++);
		tmp1 = cards_[i];
		//testValues.pop_front();
		tmp2 = rand();
		//tmp2 = cards2[i];
		while (setOfTestValuesKeys.find(tmp2) != setOfTestValuesKeys.end())
		{
			if (tryCOunter > 10000000)
			{
				std::cout << "cant find a number to insert\n";
				return 0;
			}
			tryCOunter++;
			tmp2 = ((rand() % (LLONG_MAX - sizeOfTree)) * pow(10, rand() % 20)) + sizeOfTree;
			tmp2 = tmp2 * (((rand() % 2) * -2) + 1);
			//tmp2 = cards2[i + tryCOunter];
		}
		
		//tmp2 = tmp2 - (sizeOfTree * sizeOfTree);
		/*int tmp3 = std::max(tmp1, tmp2);
		int tmp4 = std::min(tmp1, tmp2);*/
		tryCOunter = 0;
		while (!t.insert(tmp1, tmp2))
		{
			if (tryCOunter > 10000000)
			{
				std::cout << "cant find a number to insert\n" << "index " << i;
				t.insert(tmp1, tmp2);
				return 0;
			}
			tmp2 = ((rand() % (LLONG_MAX - sizeOfTree )) * pow(10, rand() % 20)) + sizeOfTree;
			tmp2 = tmp2 * (((rand() % 2) * -2) + 1);
			//tmp2 = cards2[i + tryCOunter];
			tryCOunter++;
			tmp1 = cards_[rand() % sizeOfTree];
			//tmp2 = tmp2 - ((sizeOfTree * sizeOfTree) + tryCOunter);
		}
		
		
		
		setOfTestValuesV.insert(tmp2);

		BinaryTreeNode* node = t.find(tmp2);
		if (node != nullptr)
		{
			while (node->key != tmp1)
			{
				if (node->parent == nullptr && node->key != tmp1)
				{
					std::cout << "error\n";
					return 1;
				}


				node = node->parent;
				if (node->parent == nullptr && node->key != tmp1)
				{
					lossCounter++;
					std::cout << node << " " << tmp1 << " " << tmp2;
					break;
				}
			}

		}
		else
		{
			lossCounter++;
			std::cout << node << " " << tmp1 << " " << tmp2;
		}
		
		
		


		
	}
	
	
	
	
	/*for (;!testValues.empty(); )
	{
		if (testValues.front() != t.find(testValues.front())->key)
		{
			std::cout << "error\n";
			return 1;
		}
		testValues.pop_front();

	}*/
	std::cout << "all right\n";
	std::cout << lossCounter;

	//return _CrtDumpMemoryLeaks();
	return 0;

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


bool listTest1(TwoWayList<int>& myList, std::list<int> originList)
{
	std::cout << "test 1\n";
	int curRand;
	for (int j = 0; j < 100; ++j)
	{
		curRand = rand() % 100;
		for (int i = 0; i < curRand; ++i)
		{
			int tmp = rand() % 500;
			originList.push_back(tmp);
			myList.push_back(tmp);
			if (myList.front() != originList.front())
			{
				std::cout << "error\n";
				return true;
			}
			originList.pop_front();
			myList.pop_front();

		}
	}
	return false;
}


bool listTest2(TwoWayList<int>& myList, std::list<int> originList)
{
	std::cout << "test 2\n";
	int curRand;
	for (int j = 0; j < 100; ++j)
	{
		curRand = rand() % 100;
		for (int i = 0; i < curRand; ++i)
		{
			int tmp = rand() % 500;
			originList.push_front(tmp);
			myList.push_front(tmp);
			if (myList.front() != originList.front())
			{
				std::cout << "error\n";
				return true;
			}
			originList.pop_front();
			myList.pop_front();

		}
	}
	return false;
}


bool listTest3(TwoWayList<int>& myList, std::list<int> originList)
{
	std::cout << "test 3\n";
	int curRand;
	for (int j = 0; j < 100; ++j)
	{
		curRand = rand() % 100;
		for (int i = 0; i < curRand; ++i)
		{
			int tmp = rand() % 500;
			originList.push_front(tmp);
			myList.push_front(tmp);
			if (myList.back() != originList.back())
			{
				std::cout << "error\n";
				return true;
			}
			originList.pop_back();
			myList.pop_back();

		}
	}
	return false;
}


bool listTest4(TwoWayList<int>& myList, std::list<int> originList)
{
	std::cout << "test 4\n";
	int curRand;
	for (int j = 0; j < 100; ++j)
	{
		curRand = rand() % 100;
		for (int i = 0; i < curRand; ++i)
		{
			int tmp = rand() % 500;
			originList.push_back(tmp);
			myList.push_back(tmp);
			if (myList.back() != originList.back())
			{
				std::cout << "error\n";
				return true;
			}
			originList.pop_back();
			myList.pop_back();

		}
	}
	return false;
}


bool listTest5(TwoWayList<int>& myList, std::list<int>& originList)
{
	std::cout << "test 5\n";
	for (int j = 0; j < 100; ++j)
	{
		int curRand = rand() % 500;
		for (int i = 0; i < curRand; ++i)
		{
			int tmp = rand() % 500;
			originList.push_back(tmp);
			myList.push_back(tmp);
		}
		for (int i = 0; i < curRand; ++i)
		{
			if (myList.front() != originList.front())
			{
				std::cout << "error\n";
				return true;
			}
			originList.pop_front();
			myList.pop_front();

		}

	}
	
	return false;
}

bool listTest6(TwoWayList<int>& myList, std::list<int>& originList)
{
	std::cout << "test 6\n";
	for (int j = 0; j < 100; ++j)
	{
		int curRand = rand() % 500;
		for (int i = 0; i < curRand; ++i)
		{
			int tmp = rand() % 500;
			originList.push_front(tmp);
			myList.push_front(tmp);
		}
		for (int i = 0; i < curRand; ++i)
		{
			if (myList.back() != originList.back())
			{
				std::cout << "error\n";
				return true;
			}
			originList.pop_back();
			myList.pop_back();

		}

	}

	return false;
}

void listTest()
{
	std::cout << "matching test\n";
	TwoWayList<int> myList;
	std::list<int> originList;
	int curRand;
	
	if (listTest1(myList, originList) || listTest2(myList, originList)	|| 
		listTest3(myList, originList) || listTest4(myList, originList)	||
		listTest5(myList, originList) || listTest6(myList, originList)	)
	{
		return;
	}
	
	std::cout << "matching test succes\n";

	std::cout << "memory test 1\n";
	for (int i = 0; i < 100000; ++i)
	{
		TwoWayList<int> tmp;
		for (int j = 0; j < 1000; ++j)
		{
			tmp.push_back(1);
		}

	}
	std::cout << "memory test 2\n";
	for (int i = 0; i < 100000; ++i)
	{
		TwoWayList<int> tmp;
		for (int j = 0; j < 1000; ++j)
		{
			tmp.push_front(1);
		}

	}
	std::cout << "memory test finished\n";
}