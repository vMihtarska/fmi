#pragma once
#pragma once
#include <iostream>
#include <assert.h>
template <typename T>
struct Node {
public:
	T value;
	Node<T>* pNext;

public:

	Node(const T& value, Node* next = NULL) {
		this->value = value;
		this->pNext = next;
	}
};

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
			this->tail->pNext = n;
			this->tail = n;
		}

		++size;

	}
	void AddHead(const T &  e)
	{
		Node<T>* n = new Node<T>(e, nullptr);
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
		return this->head == NULL;
	}
	void print() const
	{
		for (Node<T>* p = this->head; p != NULL; p = p->pNext)
		{
			std::cout << p->value <<std::endl;
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
	
	void insertionSort() {

		Node<T>* current = this->head;
		Node<T>* insertion = this->head;

		current = current->pNext;

		while (current != NULL) {

			insertion = this->head;

			while (insertion != current) {

				if (insertion->value > current->value) {

					T temp = current->value;
					current->value = insertion->value;
					insertion->value = temp;

				}
				else {

					insertion = insertion->pNext;
				}
			}
			current = current->pNext;
		}

	}
};