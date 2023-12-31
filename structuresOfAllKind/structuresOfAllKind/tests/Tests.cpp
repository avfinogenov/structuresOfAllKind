#include "Tests.h"


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

	if (listTest1(myList, originList) || listTest2(myList, originList) ||
		listTest3(myList, originList) || listTest4(myList, originList) ||
		listTest5(myList, originList) || listTest6(myList, originList))
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


void traversTest()
{
	MyBinaryTree t;
	int sizeOfTree = 50;
	auto rng = std::default_random_engine{};
	std::vector<long long> cards_, cards2;
	for (int i = 0; i < sizeOfTree; ++i)
	{
		cards_.push_back(i);
	}

	std::shuffle(std::begin(cards_), std::end(cards_), rng);
	srand(time(NULL));

	createTree(t, cards_);
	Travers_t travers_t = &(print);

	t.traverseNLR(travers_t);
	std::cout << "\n";
	t.traverseGreaterToLess(travers_t);
	std::cout << "\n";
	t.traverseLRN(travers_t);
	std::cout << "\n";
	t.traverseLessToGreater(travers_t);
	std::cout << "\n";
}

void treeTest()
{
	MyBinaryTree t;
	//int sizeOfTree = rand() % 300 + 1500;
	int sizeOfTree = 500050;
	auto rng = std::default_random_engine{};
	std::vector<long long> cards_, cards2;
	for (int i = 0; i < sizeOfTree; ++i)
	{
		cards_.push_back(i);
	}

	std::shuffle(std::begin(cards_), std::end(cards_), rng);
	srand(time(NULL));

	createTree(t, cards_);





	std::cout << sizeOfTree << " " << t.getNumberOfInserts() << " " << t.getNumberOfRepeats();
	int lossCounter = 0;

	int numberOfInserts = 500000;

	int haha = 0;
	for (int i = 0; i < numberOfInserts; ++i)
	{
		if (i / 1000 == haha)
		{
			haha++;
			std::cout << i << "\n";
		}



		int tryCOunter = 0;
		long long tmp1, tmp2;

		tmp1 = cards_[i];

		tmp2 = rand();

		tryCOunter = 0;
		while (!t.insertSpecial(tmp1, tmp2))
		{



			if (tryCOunter > 10000000)
			{
				std::cout << "cant find a number to insert\n" << "index " << i;
				t.insertSpecial(tmp1, tmp2);
				return;
			}
			// ���� � ���, ����� �������� ��������, ������� � ������� ������������ ����� ����� �������� � ������
			// ������ ��� ������� ��������� ��������� ����� ������� ����� ���� ��������, ������� �� �������� � ������� ������
			tmp2 = ((rand() % (LLONG_MAX - sizeOfTree)) * pow(10, rand() % 20)) + sizeOfTree;
			tmp2 = tmp2 * (((rand() % 2) * -2) + 1);

			tryCOunter++;
			tmp1 = cards_[tryCOunter % sizeOfTree];

		}



		BinaryTreeNode* node = t.find(tmp2);
		if (node != nullptr)
		{
			while (node->key != tmp1)
			{
				if (node->parent == nullptr && node->key != tmp1)
				{
					std::cout << "error\n";
					return;
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

	BinaryTreeNode* root = t.find(cards_[0]);
	while (root->greater != nullptr)
	{
		//std::cout << root.greater->key << "\n";
		//std::cout << LLONG_MAX << "\n";
		t.remove(root->greater->key);
	}
	while (root->lesser != nullptr)
	{
		t.remove(root->lesser->key);
	}


	std::cout << "all right\n";
	std::cout << lossCounter;
	std::cout << " " << t.getNumberOfInserts() << " ";
	std::cout << t.getNumberOfDeletes();
}


void print(long long data)
{
	std::cout << data << " ";
}