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

	BinaryTreeNode* greater = nullptr;
	BinaryTreeNode* lesser = nullptr;
	BinaryTreeNode* parent = nullptr;
};

struct BinaryTreeNodeWithRules 
{
	
	//не меньше
	long long notLesser = LLONG_MIN;
	//не больше
	long long notGreater = LLONG_MAX;
	BinaryTreeNode* node = nullptr;
	
};

struct RedNBlackBinaryTreeNode
{
	long long key = 0;
	bool flag = false; // false - black, true - red
	RedNBlackBinaryTreeNode* greater = nullptr;
	RedNBlackBinaryTreeNode* lesser = nullptr;
	RedNBlackBinaryTreeNode* parent = nullptr;
};