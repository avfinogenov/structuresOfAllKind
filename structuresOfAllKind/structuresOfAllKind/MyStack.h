#pragma once
#include <iostream>
#include "Node.h"


template <typename T>
class MyStack
{
public:
	MyStack(T data);
	~MyStack();
	void append(T data);
	T pop();


private:
	
	Node<T>* m_current = nullptr;

};


template<typename T>
MyStack<T>::MyStack(T data)
{
	m_current = new Node<T>;
	m_current->data = data;
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
T MyStack<T>::pop()
{
	try 
	{
		if (m_current != nullptr)
		{
			Node<T>* current = m_current;
			T data = m_current->data;
			m_current = m_current->prev;
			delete current;
			return data;
		}
		throw 1;
	}
	catch (int)
	{
		
		std::cout << "MyStack out of range, next value is garbadge";
		return T();
	}
	
	


}
