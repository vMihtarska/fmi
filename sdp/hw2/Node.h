#pragma once
#include <iostream>
template <typename T>
class Node {
public:
	T value;
	Node<T>* pNext;

public:

	Node(const T& value, Node* next = NULL) {
		this->value = value;
		this->pNext = next;
	}
	Node(Node* next = NULL)
	{
		this->pNext = next;
	}
};