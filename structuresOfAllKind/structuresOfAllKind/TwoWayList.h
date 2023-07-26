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
	void pop_back();
	void pop_front();



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
	std::cout << "todo destructor\n";
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
inline void TwoWayList<T>::pop_back()
{
	TwoWayNode<T>* tmp = m_end->prev;
	tmp->prev->next = m_end;
	m_end->prev = tmp->prev;
	delete tmp;

}

template<typename T>
inline void TwoWayList<T>::pop_front()
{
	TwoWayNode<T>* tmp = m_start;
	m_start = m_start->next;
	m_start->prev = nullptr;
	delete tmp;


}
