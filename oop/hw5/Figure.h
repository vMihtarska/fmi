#pragma once
#include "Point.h"
class Figure
{
public:
		Figure();
		virtual ~Figure();
		friend void AddFigure(Figure*);
		virtual void IsInFigure(Point &) const = 0;
		virtual void print() const = 0;
	
};