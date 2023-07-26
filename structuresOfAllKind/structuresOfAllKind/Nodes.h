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