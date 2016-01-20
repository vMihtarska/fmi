#pragma once
template <typename T>
class CompressedString
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
	CompressedString() :size(0), head(nullptr){};
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
	node* getNext()const
	{
		return head->next;
	}
	node* getHead()const
	{
		return head;
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
	~CompressedString()
	{
		while (!empty())
			pop();
	}
	void ReversePrint() const
	{
		node *n = head;
		while (n)
		{
			std::cout << n->value;
			n = n->next;
		}
	}
	T getvalue() const
	{
		return head->value;
	}
	static bool isAlpha(char ch)
	{
		return (ch >= 'A'&& ch <= 'Z');
	}
	static bool isBrace(char ch)
	{
		return (ch == '(' || ch == ')');
	}
	static bool isNum(char num)
	{
		return (num >= '1' && num <= '9');
	}
	static int ToInt(char n)
	{
		return n - '0';
	}
};