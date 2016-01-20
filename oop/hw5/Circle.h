#pragma once
#include "Point.h"
#include "Figure.h"
class Circle:public Figure
{
private: 
	Point center;
	double radius;
public:
	Circle();
	Circle(double, double, double);
	Circle(Point&, double);

	Point & GetCenter();
	double GetRadius() const;
	void SetCenter(Point &);
	void SetRadius(double);
	void IsInFigure(Point &) const;
	void print()const;

};