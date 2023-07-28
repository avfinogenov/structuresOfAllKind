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
	
	std::cout << "stack test\n";
	stackTest();
	std::cout << "queue test\n";
	queueTest();
	std::cout << "list test\n";
	listTest();
	treeTest();
	
	//return _CrtDumpMemoryLeaks();
	return 0;

}

