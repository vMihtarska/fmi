#include "Circle.h"
#include <iostream>
Circle::Circle()
{
	center(0,0);
	radius = 0;
}
Circle::Circle(Point & center, double radius)
{
	this->center(center.Getx(), center.Gety());
	this->radius=radius;
}
Circle::Circle(double x, double y, double r)
{
	this->center.Setx(x);
	this->center.Sety(y);
	this->SetRadius(r);
}
Point & Circle::GetCenter() 
{
	return center;
}
double Circle::GetRadius() const
{
	return radius;
}
void Circle::SetCenter(Point & center)
{
	this->center = center;
}
void Circle::SetRadius(double radius)
{
	this->radius = radius;
}
void Circle::IsInFigure(Point & p) const
{
	bool inCircle = (p.Getx() - center.Getx())*(p.Getx() - center.Getx()) + (p.Gety() - center.Gety())*(p.Gety() - center.Gety()) <= GetRadius()*GetRadius();
	if (inCircle)
		this->print();
}
void Circle::print() const
{
	std::cout << "Circle:------------- " << std::endl <<
		"Center: (" << center.Getx() << "," << center.Gety() << ") "
		"Radius: " << radius << std::endl << "------------------" << std::endl << std::endl;
}
