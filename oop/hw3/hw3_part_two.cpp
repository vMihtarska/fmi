#include "BoolVector.h"
#include <iostream>
int main()
{
	BoolVector p;
	BoolVector c(17);
	p.set(3);
	p.print();
	p.clear(5);
	p.print();
	c.set(3);
	c.print();
	c.clear(0);
	c.print();
	std::cout << p[0] << std::endl << c[4] << std::endl;
}