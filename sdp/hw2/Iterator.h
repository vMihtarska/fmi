#pragma once
#include "Node.h"

template <class T>
class Iterator
{
private:

	Node<T> *pStart;
	Node<T> *pCurrent;
public:
	Iterator(Node<T> *pStart);

	T & GetCurrent() const;
	void SetCurrent(T const &);
	void MoveNext();
	void Rewind();
	bool EndReached() const;
};
template <class T>
Iterator<T>::Iterator(Node<T> *pStart)
{
	this->pStart = this->pCurrent = pStart;
}
template <class T>
T & Iterator<T>::GetCurrent() const
{
	assert(!this->EndReached());

	return this->pCurrent->value;
}
template <class T>
void Iterator<T>::SetCurrent(T const & Value)
{
	assert(!this->EndReached());

	this->pCurrent->value = Value;
}
template <class T>
void Iterator<T>::MoveNext()
{
	if (this->pCurrent)
	{
		this->pCurrent = this->pCurrent->pNext;
	}
}
template <class T>
void Iterator<T>::Rewind()
{
	this->pCurrent = this->pStart;
}
template <class T>
bool Iterator<T>::EndReached() const
{
	return this->pCurrent == NULL;
}