#ifndef __CRTDBG_MAP_ALLOC
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif // !__CRTDBG_MAP_ALLOC


#include "Tests.h"




//todo 
//in queue and twowaylist need to rethink constructor
// smart pointers
// перечисление в дерево






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

	std::shuffle(std::begin(cards_), std::end(cards_), rng);
	srand(time(NULL));

	createTree(t, cards_);
	


	

	std::cout << sizeOfTree << " " << t.getNumberOfNodes() << " " << t.getNumberOfRepeats();
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
		while (!t.insert(tmp1, tmp2))
		{
			

		
			if (tryCOunter > 10000000)
			{
				std::cout << "cant find a number to insert\n" << "index " << i;
				t.insert(tmp1, tmp2);
				return 0;
			}
			// идея в том, чтобы получать значения, которые с большей вероятностью можно будет добавить в дерево
			// потому что простая генерация случайных чисел слишком часто дает значения, которые не встроить в большое дерево
			tmp2 = ((rand() % (LLONG_MAX - sizeOfTree )) * pow(10, rand() % 20)) + sizeOfTree;
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
	
	
	
	

	std::cout << "all right\n";
	std::cout << lossCounter;

	//return _CrtDumpMemoryLeaks();
	return 0;

}
