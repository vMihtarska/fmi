#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List<int> a;
	a.AddHead(3);
	a.AddHead(1);
	a.AddHead(30);
	a.AddHead(32);
	a.AddHead(14);
	a.AddHead(9);
	a.AddHead(40);
	a.AddHead(2);
	a.AddHead(17);
	a.AddHead(9);
	a.AddHead(50);
	a.AddHead(200);
	a.insertionSort();
	a.print();

	return 0;
}