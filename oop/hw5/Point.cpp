#include "Point.h"
Point::Point()
{
	x, y = 0;
}
double Point::Getx() const
{
	return x;
}
double Point::Gety() const
{
	return y;
}

void Point::Setx(double x)
{
	this->x = x;
}
void Point::Sety(double y)
{
	this->y = y;
}

Point::Point(const Point& other)
{
	Setx(other.x);
	Sety(other.y);
}
Point & Point::operator=(const Point &other)
{
	if (this == &other)
		return *this;
	else
	{
		Setx(other.x);
		Sety(other.y);
		return *this;
	}
}
void Point::operator()(double x, double y)
{
	Setx(x);
	Sety(y);
}