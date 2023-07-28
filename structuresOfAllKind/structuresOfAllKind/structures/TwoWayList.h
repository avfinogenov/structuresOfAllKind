#pragma once
#include <iostream>
#include "Nodes.h"

template <typename T>
class TwoWayList
{
public:
	TwoWayList();
	~TwoWayList();
	void push_back(T data);
	void push_front(T data);
	T back();
	T front();
	bool pop_back();
	bool pop_front();



private:
	TwoWayNode<T>* m_start = nullptr;
	TwoWayNode<T>* m_end = nullptr;



};

template<typename T>
inline TwoWayList<T>::TwoWayList()
{
	m_start = new TwoWayNode<T>();
	m_end = m_start;
}

template<typename T>
inline TwoWayList<T>::~TwoWayList()
{
	if (m_start->next != nullptr)
	{


		while (pop_front())
		{
			continue;

		}

	}
	delete m_start;
}

template<typename T>
inline void TwoWayList<T>::push_back(T data)
{
	m_end->data = data;
	TwoWayNode<T>* tmp = new TwoWayNode<T>();
	m_end->next = tmp;
	tmp->prev = m_end;
	m_end = tmp;
}

template<typename T>
inline void TwoWayList<T>::push_front(T data)
{
	TwoWayNode<T>* tmp = new TwoWayNode<T>();
	tmp->data = data;
	m_start->prev = tmp;
	tmp->next = m_start;
	m_start = tmp;
}

template<typename T>
inline T TwoWayList<T>::back()
{
	return m_end->prev->data;
}

template<typename T>
inline T TwoWayList<T>::front()
{
	return m_start->data;
}

template<typename T>
inline bool TwoWayList<T>::pop_back()
{
	if (m_start == m_end)
	{
		return false;
	}
	TwoWayNode<T>* tmp = m_end->prev;
	if (tmp->prev != nullptr)
	{
		
		tmp->prev->next = m_end;
		m_end->prev = tmp->prev;
		delete tmp;
	}
	else
	{
		m_start = m_end;
		m_start->prev = nullptr;
		m_start->next = nullptr;
		delete tmp;
	}
	
	return m_end->prev != nullptr;
}

template<typename T>
inline bool TwoWayList<T>::pop_front()
{
	if (m_start == m_end)
	{
		return false;
	}
	TwoWayNode<T>* tmp = m_start;
	if (m_start != m_end)
	{
		if (m_start->next != nullptr)
		{
			m_start = m_start->next;
			m_start->prev = nullptr;
			delete tmp;
		}
	}
	
	
	
	return m_start->next != nullptr;

}
