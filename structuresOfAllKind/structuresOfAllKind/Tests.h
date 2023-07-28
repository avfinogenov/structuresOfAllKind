#pragma once
#ifndef __CRTDBG_MAP_ALLOC
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif // !__CRTDBG_MAP_ALLOC


#include <iostream>

#include <list>

#include <stack>


#include <queue>
#include <list>
#include <algorithm>
#include <random>
#include <vector>
#include "MyStack.h"
#include "MyQueue.h"
#include "TwoWayList.h"
#include "MyBinaryTree.h"


void stackTest();
void queueTest();
void listTest();
void treeTest();
bool listTest1(TwoWayList<int>& myList, std::list<int> originList);
bool listTest2(TwoWayList<int>& myList, std::list<int> originList);
bool listTest3(TwoWayList<int>& myList, std::list<int> originList);
bool listTest4(TwoWayList<int>& myList, std::list<int> originList);
bool listTest5(TwoWayList<int>& myList, std::list<int>& originList);
bool listTest6(TwoWayList<int>& myList, std::list<int>& originList);