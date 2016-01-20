#pragma once
#include "Point.h"
#include  "Figure.h"
class Triangle :public Figure
{
private:
	Point a, b, c;
public:
	Triangle();
	Triangle(Point&, Point&, Point&);
	Triangle(double, double, double, double, double, double);

	Point & GetA();
	Point & GetB();
	Point & GetC();
	void SetA(Point &);
	void SetB(Point &);
	void SetC(Point &);
	void IsInFigure(Point &) const;
	void print()const;
};