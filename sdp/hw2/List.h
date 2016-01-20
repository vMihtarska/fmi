#pragma once
#include <iostream>
#include <assert.h>
#include "Iterator.h"
#include "Node.h"

template <typename T>
class List
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	List() :head(nullptr), tail(nullptr), size(0) {};
	List(const List & o) :head(nullptr), tail(nullptr), size(0)
	{
		Node<T>* n = o.head;
		while (n != NULL)
		{
			AddTail(n->value);
			n = n->pNext;
		}

	}
	List& operator=(const List & o)
	{
		if (this != &o)
		{
			Node<T>* n = o.head;
			while (n != NULL)
			{
				AddTail(n->value);
				n = n->pNext;
			}
		}
		return *this;
	}
	~List()
	{
		while (!isEmpty())
		{
			RemoveHead();
		}
	}
	void AddTail(const T & e)
	{

		Node<T>* n = new Node<T>(e, nullptr);
		if (isEmpty())
		{
			this->tail = n;
			this->head = n;
		}
		else
		{
			this->tail->pNext= n;
			this->tail = n;
		}

		++size;
		
		
	}
	void AddHead(const T &  e)
	{
		Node<T>* n = new Node<T>(e,nullptr);
		if (isEmpty())
		{
			this->tail = n;
			this->head = n;
		}
		else
		{
			n->pNext = this->head;
			this->head = n;
		}

		++size;
	}
	
	void InsertAfter(const T &  e, const T &  r)
	{
		Node<T>* b = new Node<T>(r, nullptr);
		Node<T>* n = this->head;
		while (n)
		{
			if (n->value == e)
			{
				b->pNext = n->pNext;
				n->pNext = b;
				++size;
				break;
			}
			n = n->pNext;
		}
		
	}
	bool isEmpty() const
	{
		return this->head==NULL;
	}
	void print() const
	{
		for (Node<T>* p = this->head; p != NULL; p = p->pNext)
		{
			p->value.print();
		}
		std::cout << std::endl;
	}
	T & GetHead()
	{
		assert(!this->isEmpty());

		return this->head->value;
	}
	T & GetTail()
	{
		assert(!this->isEmpty());

		return this->tail->value;
	}
	void RemoveHead()
	{

		if (!this->isEmpty())
		{
			assert(this->head != NULL);

			Node<T> *n = this->head;
			this->head = this->head->pNext;

			if (this->head == NULL)
			{
				this->tail = NULL;
			}

			this->size--;
			delete n;
		}
	}

	void RemoveTail()
	{
		if (!this->isEmpty())
		{
			assert(this->head != NULL);

			Node<T> *b = this->tail;
			Node<T> *n = this->head;

			while (n && n->pNext != this->tail)
			{
				n = n->pNext;
			}
			n->pNext = NULL;
			this->tail = n;

		
			--size;
			delete b;
		}
	}
	int GetSize() const
	{
		return this->size;
	}
	Iterator<T> GetIterator() const
	{
		return Iterator<T>(this->head);
	}

	bool operator==(const List& other) const
	{
		if (this->GetSize() != other.GetSize())
		{
			return false;
		}
		else
		{
			Iterator<T> iterator = this->GetIterator();
			Iterator<T> iterator2 = other.GetIterator();
			while (!iterator.EndReached())
			{
				if (!(iterator.GetCurrent() == iterator2.GetCurrent()))
					return false;
				iterator.MoveNext();
				iterator2.MoveNext();
			}
		}
		return true;
	}
};