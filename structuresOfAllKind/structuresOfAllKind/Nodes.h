#pragma once

#ifndef __CRTDBG_MAP_ALLOC
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif // !__CRTDBG_MAP_ALLOC


#include <iostream>
template <typename T>
struct StackNode
{
	StackNode<T>* prev = nullptr;
	T data = T();
};


template <typename T>
struct QueueNode
{

	QueueNode<T>* next = nullptr;
	T data = T();
};

template <typename T>
struct TwoWayNode
{

	TwoWayNode<T>* next = nullptr;
	TwoWayNode<T>* prev = nullptr;
	T data = T();
};

struct BinaryTreeNode
{
	long long key = 0;
	//�� ������
	long long notLesser = LLONG_MIN;
	//�� ������
	long long notGreater = LLONG_MAX;
	BinaryTreeNode* greater = nullptr;
	BinaryTreeNode* lesser = nullptr;
	BinaryTreeNode* parent = nullptr;
};