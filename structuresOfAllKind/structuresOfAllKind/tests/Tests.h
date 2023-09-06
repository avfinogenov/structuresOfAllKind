#pragma once
#ifndef __CRTDBG_MAP_ALLOC
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif // !__CRTDBG_MAP_ALLOC


// �� ����� ������� �������, ����� ��� ������ ��� ������� ������� ����� ��� ������� ��������
//todo
// ���������� ������
//����� ������
//���������� ��������
#include <iostream>

#include <list>

#include <stack>


#include <queue>
#include <list>
#include <algorithm>
#include <random>
#include <vector>
#include "../structures/MyStack.h"
#include "../structures/MyQueue.h"
#include "../structures/TwoWayList.h"
#include "../structures/MyBinaryTree.h"


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
void print(long long data);

void traversTest();