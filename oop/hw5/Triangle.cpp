#include "Triangle.h"
#include <iostream>
Triangle::Triangle()
{
	a(0, 0);
	b(0, 0);
	c(0, 0);
}
Triangle::Triangle(Point& a, Point& b, Point& c)
{
	SetA(a);
	SetB(b);
	SetC(c);
}
Triangle::Triangle(double a1, double a2, double b1, double b2, double c1, double c2)
{
	this->a(a1, a2);
	this->b(b1, b2);
	this->c(c1, c2);
}
Point & Triangle::GetA()
{
	return this->a;
}
Point & Triangle::GetB()
{
	return this->b;
}
Point & Triangle::GetC()
{
	return this->c;
}
void Triangle::SetA(Point & a)
{
	this->a = a;
}
void Triangle::SetB(Point & b)
{
	this->b = b;
}
void Triangle::SetC(Point & c)
{
	this->c = c;
}
void Triangle::IsInFigure(Point & q) const
{
	double AB = (q.Gety() - a.Gety())*(b.Getx() - a.Getx()) - (q.Getx() - a.Getx())*(b.Gety() - a.Gety());
	double CA = (q.Gety() - c.Gety())*(a.Getx() - c.Getx()) - (q.Getx() - c.Getx())*(a.Gety() - c.Gety());
	double BC = (q.Gety() - b.Gety())*(c.Getx() - b.Getx()) - (q.Getx() - b.Getx())*(c.Gety() - b.Gety());
	if (AB*BC > 0 && BC*CA > 0)
		this->print();
}
void Triangle::print()const
{
	std::cout << "Triangle:------------ " << std::endl <<
		"A: (" << a.Getx() << "," << a.Gety() << ") " 
		"B: (" << b.Getx() <<","<< b.Gety() << ") "
		"C: (" << c.Getx() << "," << c.Gety() << ")" << std::endl 
		<< "-------------------" << std::endl << std::endl;
}