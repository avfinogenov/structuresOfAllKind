


#ifndef __CRTDBG_MAP_ALLOC
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif // !__CRTDBG_MAP_ALLOC

#include "tests/Tests.h"





//todo 
//in queue and twowaylist need to rethink constructor
// smart pointers
// перечисление в дерево
// обход дерева
// балансировка дерева
// красно черное дерево 
// avl дерево
// слияние деревьев
// посчитать глубину дерева
// посчитать количество ветвей (фактически посчтит ноды с двумя нуллпоинтерами)
// посчитать количество элементов с 1 нуллпоинтером





int main()
{
	
	/*std::cout << "stack test\n";
	stackTest();
	std::cout << "queue test\n";
	queueTest();
	std::cout << "list test\n";
	listTest();
	treeTest();*/
	
	traversTest();


	return _CrtDumpMemoryLeaks();
	//return 0;

}

