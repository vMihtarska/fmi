#include <iostream>
#include "BST.h"

int main()
{
	BST<int> a;

	a.Add(10);
	a.Add(8);
	a.Add(2);
	a.Add(9);
	a.Add(11);
	a.Add(15);
	a.Add(13);
	a.Add(12);
	a.Add(17);
	a.Add(16);
	/*
	a.print();
	a.Remove(12);
	a.print();
	*/
	//a.Remove(8);
	a.bfss();

	//a.print();
	system("pause");
}