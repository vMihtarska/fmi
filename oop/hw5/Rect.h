#pragma once
#include "Point.h"
#include "Figure.h"
class Rect :public Figure
{
private:
	
	Point a;
	Point b;
public:
	Rect();
	Rect(double, double, double,double);
	Rect(Point&, Point &);

	Point & GetA();
	Point & GetB();
	void SetA(Point &);
	void SetB(Point &);
	void IsInFigure(Point &) const;
	void print()const;

};