#pragma once
#include "Figure.h"
#include "Point.h"
class Group:public Figure
{
private:
	Figure ** figures;
	int cnt;
public:
	Group();
	Group(Group &);
	~Group();

	int GetCnt()const;
	Figure* GetFigures()const;
	void AddFigure(Figure*);
	void IsInFigure(Point &)const;
	void print()const;


};