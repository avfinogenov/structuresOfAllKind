#pragma once
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#include <iostream>

#include "Nodes.h"


//
//// Use (void) to silence unused warnings.
//#define assertm(exp, msg) assert(((void)msg, exp))
template <typename T>
class MyStack
{
public:
	MyStack();
	~MyStack();
	void append(T data);
	void pop();
	T last();


private:
	
	StackNode<T>* m_current = nullptr;

};


template<typename T>
MyStack<T>::MyStack()
{
	m_current = new StackNode<T>;

	
}

template<typename T>
MyStack<T>::~MyStack()
{
	while (m_current != nullptr)
	{
		pop();
	}
}

template<typename T>
void MyStack<T>::append(T data)
{
	StackNode<T>* next = new StackNode<T>;
	next->prev = m_current;
	next->data = data;
	m_current = next;
}

template<typename T>
void MyStack<T>::pop()
{
	
	
		if (m_current != nullptr)
		{
			StackNode<T>* current = m_current;
			m_current = m_current->prev;
			delete current;
			return;
		}
		
		

	


}

template<typename T>
inline T MyStack<T>::last()
{

	if (m_current != nullptr)
	{

		return m_current->data;
	}
}
