#pragma once
#include <iostream>
template <typename T>
struct StackNode
{
	StackNode<T>* prev = nullptr;
	T data;
};


template <typename T>
struct QueueNode
{

	QueueNode<T>* next = nullptr;
	T data;
};

template <typename T>
struct TwoWayNode
{

	TwoWayNode<T>* next = nullptr;
	TwoWayNode<T>* prev = nullptr;
	T data;
};

struct BinaryTreeNode
{
	int key;
	//не меньше
	int notLesser = INT_MIN;
	//не больше
	int notGreater = INT_MAX;
	BinaryTreeNode* greater = nullptr;
	BinaryTreeNode* lesser = nullptr;
	BinaryTreeNode* parent = nullptr;
};