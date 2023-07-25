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
	QueueNode<T>* prev = nullptr;
	QueueNode<T>* next = nullptr;
	T data;
};