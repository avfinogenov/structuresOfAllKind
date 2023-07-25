#pragma once
#include <iostream>

#include "Nodes.h"

//
//// Use (void) to silence unused warnings.
//#define assertm(exp, msg) assert(((void)msg, exp))

template <typename T>
class MyQueue
{
public:
	MyQueue();
	~MyQueue();
	void add(T data);
	T front();
	bool pop_front();


private:
	QueueNode<T>* m_start = nullptr;
	QueueNode<T>* m_end = nullptr;



};

template<typename T>
inline MyQueue<T>::MyQueue()
{
	m_start = new QueueNode<T>();
	m_end = m_start;
}

template<typename T>
inline MyQueue<T>::~MyQueue()
{
	if (m_start->next != nullptr)
	{


		while (pop_front())
		{
			continue;

		}
	}
}

template<typename T>
inline void MyQueue<T>::add(T data)
{
	QueueNode<T>* tmp = new QueueNode<T>();
	m_end->data = data;
	m_end->next = tmp;
	tmp->prev = m_end;
	m_end = tmp;


}

template<typename T>
inline T MyQueue<T>::front()
{
	
	return m_start->data;
}

template<typename T>
inline bool MyQueue<T>::pop_front()
{
	if (m_start == m_end)
	{
		return false;
	}
	QueueNode<T>* tmp = m_start;
	
	
	m_start = m_start->next;
	delete tmp;
	return m_start != m_end;
}
