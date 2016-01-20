#include "Rect.h"
#include <iostream>
Rect::Rect()
{
	a(0, 0);
	b(0, 0);
}
Rect::Rect(double ax, double ay, double bx, double by)
{
	this->a(ax,ay);
	this->b(bx, by);
}
Rect::Rect(Point& a, Point & b)
{
	this->SetA(a);
	this->SetB(b);
}
Point & Rect::GetA()
{
	return a;
}
Point & Rect::GetB()
{
	return b;
}
void Rect::SetA(Point &other)
{
	this->a.Setx (other.Getx());
	this->a.Sety (other.Gety());

}
void Rect::SetB(Point & other)
{
	this->b.Setx (other.Getx());
	this->b.Sety (other.Gety());
}
void Rect::IsInFigure(Point & p) const
{
	if (p.Getx() >= a.Getx() && p.Getx() <= b.Getx() && p.Gety()<=b.Gety() && p.Gety()>=a.Gety())
		this->print();
}
void Rect::print()const
{
	std::cout << "Rectangle:-------- " << std::endl <<
		"A: (" << a.Getx() <<","<< a.Gety() << ") "<<
		"B: (" << b.Getx() <<","<< b.Gety() << ")" <<
		std::endl<<"------------"<<std::endl<<std::endl;
}