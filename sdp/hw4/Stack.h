#pragma once
template <typename T>
class Stack
{
private:
	int size;
	struct node
	{
		T value;
		node* next;
	};
	node *head;
public:
	Stack() :size(0), head(nullptr) {};
	T& top()
	{
		if (!empty())
			return head->value;
	}
	void push(const T& v)
	{
		node*n = new node();
		n->value = v;
		n->next = head;
		++size;
		head = n;
	}
	void pop()
	{
		if (!empty())
		{
			T value = head->value;
			node*n = head->next;
			delete head;
			head = n;
			--size;
		}
	}
	bool empty() const
	{
		if (size == 0)
			return true;
		else
			return false;
	}
	int getsize()const
	{
		return size;
	}
	~Stack()
	{
		while (!empty())
			pop();
	}
	T getvalue() const
	{
		return head->value;
	}
};
