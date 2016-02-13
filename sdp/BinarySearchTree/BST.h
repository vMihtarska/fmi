#pragma once
#include <iostream>
#include <queue>
#include <stack>

template <class T>
struct Node
{
	Node* left;
	Node* right;

	T value;

	Node(const T& value, Node* left = NULL, Node* right = NULL)
	{
		this->left = left;
		this->right = right;
		this->value = value;
	}

	~Node()
	{
		delete left;
		delete right;
	}
};

template <class T>
class BST
{
public:
	BST()
	{
		this->root = NULL;
	}

	~BST()
	{
		delete root;
	}

	void Add(const T& data);
	void Remove(const T& data);

	void bfss();
	
	void print();

private:
	void AddHelper(Node<T>*& n, const T& value);
	void RemoveHelper(Node<T>*& n, const T& value);
	Node<T>*& minNode(Node<T>*& root);
	void swapDelete(Node<T>*& toDelete, Node<T>*& New);
	void bfs(Node<T>* root);
	void printHelper(Node<T>* n);
	Node<T>* Search(Node<T>*& n, const T& data);
private:
	Node<T>* root;
};

template <class T>
void BST<T>::Add(const T& value)
{
	AddHelper(root, value);
}

template <class T>
inline void BST<T>::AddHelper(Node<T>*& n, const T& value)
{
	if (!n)
	{
		n = new Node<T>(value);
		return;
	}
	if (value <= n->value)
		AddHelper(n->left, value);
	else
		AddHelper(n->right, value);
}

template <class T>
inline void BST<T>::Remove(const T& value)
{
	RemoveHelper(root, value);
}

template <class T>
void BST<T>::RemoveHelper(Node<T>*& n, const T& value)
{
	if (!n)
	{
		return;
	}

	if (n->value == value)
	{	//if is a leaf
		if (!n->left && !n->right)
		{
			delete n;
			n = NULL;
			return;
		}
		//if doesnt have left child
		if (!n->left)
		{
			Node<T>* temp = n;
			n = n->right;

			temp->right = NULL;
			delete temp;
			temp = NULL;
			return;
		}
		//if doesnt have right child
		if (!n->right)
		{
			Node<T>* temp = n;
			n = n->left;

			temp->left = NULL;
			delete temp;
			temp = NULL;
			return; 
		}

		Node<T>* &replacement = minNode(n->right);

		swapDelete(n, replacement);

		RemoveHelper(replacement, value);
	}

	if (value <= n->value)
		RemoveHelper(n->left, value);
	else
		RemoveHelper(n->right, value);
}

template <class T>
inline void BST<T>::swapDelete(Node<T>*& toDelete, Node<T>*& New)
{
	T temp = toDelete->value;
	toDelete->value = New->value;
	New->value = temp;
}

template <class T>
Node<T>*& BST<T>::minNode(Node<T>*& root)
{
	if (!root->left) return root;

	return minNode(root->left);
}

template <class T>
inline Node<T>* BST<T>::Search(Node<T>*& n, const T& value)
{
	if (n->value == value)
		return n;

	if (value <= n->value)
		return Search(n->left, value);
	else
		return Search(n->right, value);
}

template<class T>
inline void BST<T>::bfss()
{
	 bfs(this->root);
}
template<class T>
inline void BST<T>::bfs(Node<T>* root)
{
	if (root == NULL)
		return;
	
	std::queue<Node<T>*> Q;
	Q.push(root);

	printf("bfs: ");
	while (!Q.empty())
	{
		Node<T>* curr = Q.front();
		std::cout << curr->value << " ";
		Q.pop();
		if (curr->left != NULL)
		{
			Q.push(curr->left);
		}
		if (curr->right != NULL)
		{
			Q.push(curr->right);
		}
	}
	printf("\n");
}
template <class T>
inline void BST<T>::print()
{
	printHelper(root);
}

template <class T>
inline void BST<T>::printHelper(Node<T>* n)
{
	if (!n) return;

	/*printHelper(n->left);
	std::cout << n->value <<"\n";
	printHelper(n->right);*/

	std::cout << n->value << "  ";
	printHelper(n->left);
	std::cout << "\n";
	printHelper(n->right);
}