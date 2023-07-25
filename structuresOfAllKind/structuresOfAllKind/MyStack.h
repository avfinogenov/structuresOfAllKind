#pragma once
#include <iostream>
#include <cassert>
#include "Node.h"



// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))
template <typename T>
class MyStack
{
public:
	MyStack(T data);
	~MyStack();
	void append(T data);
	void pop();
	T last();


private:
	bool m_isStuffed = false;
	Node<T>* m_current = nullptr;

};


template<typename T>
MyStack<T>::MyStack(T data)
{
	m_current = new Node<T>;
	m_current->data = data;
	m_isStuffed = true;
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
	Node<T>* next = new Node<T>;
	next->prev = m_current;
	next->data = data;
	m_current = next;
}

template<typename T>
void MyStack<T>::pop()
{
	assert("MyStack is empty" && m_current == nullptr);
	
		if (m_current != nullptr)
		{
			Node<T>* current = m_current;
			m_current = m_current->prev;
			delete current;
			return;
		}
		m_isStuffed = false;
		

	


}

template<typename T>
inline T MyStack<T>::last()
{
	assert("MyStack is empty" && m_current == nullptr);
	if (m_current != nullptr)
	{

		return m_current->data;
	}
}
