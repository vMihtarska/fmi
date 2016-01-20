#pragma once
#include "Vector.h"
#include <iostream>
struct Node
{
	int value;
	int level;
	int index = 0;
	Vector<Node*> children;
	Node()
	{
		index = 0;
		value = 0;
		level = 0;
	}
	Node(int value,int level)
	{
		this->value = value;
		this->level = level;
	}
	~Node()
	{
		this->children.clear();
	}
};
class Tree
{
private:
	Node* root;
	int size;
public:
	Tree()
	{
		size = 0;
		root = nullptr;
	}
	Node* helpSearch(int key, Node* n,int level)
	{
		if (!n)
			return n;
		if (n->value == key)
			return n;
		for (int i = 0; i < n->children.getSize(); i++)
		{
			Node * temp = helpSearch(key, n->children.getAt(i),level);
			if (temp)
			{
				return temp;
			}
		}
		return NULL;
	}
	Node* search(int key,int level)
	{
		if (root->value == key && root->level==level)
			return root;
		for (int i = 0; i < root->children.getSize(); i++)
		{

			Node * temp = helpSearch(key, root->children.getAt(i), level);
			if (temp)
				return temp;
		}
	}
	void add(int key, int value,int level)
	{
		Node* n = search(key,level-1);
		if (!n)
		{
			throw "No key";
		}
		Node* child = new Node(value,n->level + 1);
		n->children.add(child);
		size++;

	}

	void add(int value)
	{
		root = new Node(value,0);
		size++;
	}

	int getSizeofChild(Node* n) const
	{
		return n->children.getSize();
	}
	bool isItLeaf(Node* n)
	{
		return n->children.isEmpty();
	}
	int getSizeofNode() const
	{
		return this->size;
	}
	
	int Indexing(Node* n)
	{

		for (int i = 0; i < n->children.getSize(); i++)
		{
			if (isItLeaf(n->children.getAt(i)))
				 n->index += 1;
			else
				n->index += Indexing(n->children.getAt(i)) + 1;
		}
		return n->index;
	}
	bool isEmpty()const
	{
		return size == 0;
	}
	Vector<Node*> getChildren(Node* o) const
	{
		return o->children;
	}
	bool IsEquals(Vector<Node*> t, Vector<Node*> t2)
	{
		for (int i = 0; i < t.getSize(); i++)
		{
			for (int j = 0; j < t.getSize(); j++)
			{
				if (t.getAt(i)->index == t2.getAt(j)->index)
				{
					t2.getAt(j)->index = -1;
					break;
				}
				else if ((t.getAt(i)->index != t2.getAt(j)->index) && j == t.getSize() - 1)
					return false;
			}
		}
		return true;
	}

	bool isIsomorphism(Tree& other)
	{
		this->Indexing(this->root);
		other.Indexing(other.root);

		if (this->root->index != other.root->index)
		{
			return false;
		}
		else
		{
			Vector<Node*> t;
			Vector<Node*> t2;
			for (int i = 0; i < root->children.getSize(); i++)
			{
				t.add(root->children.getAt(i));
				t2.add(other.getChildren(other.root).getAt(i));
			}
			if (IsEquals(t, t2))
			{

				return IsoByLevels(t, t2);
			}
			else
			{
				return false;
			}
		}
	}
	
	bool IsoByLevels(Vector<Node*> r, Vector<Node*> r2)
	{
		if (r.isEmpty() || r2.isEmpty())
			return true;
		if (r.getSize() == r2.getSize())
		{
			Vector<Node*> t;
			Vector<Node*> t2;
			for (int i = 0; i < r.getSize(); i++)
			{

				for (int j = 0; j < r.getAt(i)->children.getSize(); j++)
					t.add(r.getAt(i)->children.getAt(j));

				for (int j = 0; j < r2.getAt(i)->children.getSize(); j++)
					t2.add(r2.getAt(i)->children.getAt(j));
			}
			if (IsEquals(t, t2))
				return IsoByLevels(t, t2);
			else
			{
				return false;
			}
		}
		else return false;
	}
	void clear(Node* n)
	{
	for (int i = 0; i < n->children.getSize(); i++)
	{
	if (n->children.getAt(i) != NULL)
	clear(n->children.getAt(i));
	delete n;
	n = NULL;
	size--;

	}

	}
	~Tree()
	{
	clear(root);
	}
};