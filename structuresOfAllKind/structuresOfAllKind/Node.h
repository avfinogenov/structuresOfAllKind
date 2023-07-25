#pragma once
#include <iostream>
template <typename T>
struct Node
{
	Node<T>* prev;
	T data;
};