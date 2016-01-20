#pragma once
#include <iostream>
template <typename T>
class Queue
{
private:
	struct Node
	{
		T value;
		Node* next;
		Node(const T&v, Node* n) :value(v), next(n) {};
		~Node()
		{
			delete next;
		}
	};
	Node* head,* tail;
	int size;
public:
	Queue() :head(nullptr), tail(nullptr), size(0)
	{};
	void push(const T&v)
	{
		
		Node* n = new Node(v, nullptr);
		if (isEmpty())
		{
			tail = n;
			head = n;
		}
		else
		{
			tail->next = n;
			tail = n;
		}

		++size;
	}
	bool operator==(T& o)
	{
		Node *n = head;
		while (n)
		{
			if (n->value==o)
				return true;
			n = n->next;
		}
		return false;
	}
	void pop()
	{
		Node* n = head;
		head = n->next;
		n->next = nullptr;
		delete n;
		--size;
	}
	bool isEmpty()
	{
		return !size;
	}
	T& top()
	{
		return head->value;
	}
	~Queue()
	{
		delete head;
	}
};
