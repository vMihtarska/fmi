#include "Group.h"
#include <iostream>
Group::Group()
{
	cnt = 0;
	figures = NULL;
}
Group::~Group()
{
	for (int i = 0; i < cnt; i++)
		delete figures[i];
	delete[]figures;
}

void Group::AddFigure(Figure* newFigure)
{

	if (figures == NULL)
	{
		figures = new Figure*[1];
		figures[0] = newFigure;
		cnt++;
	}
	else
	{
		Figure** buffer = new Figure*[cnt + 1];
		for (int i = 0; i < cnt; i++)
		{
			buffer[i] = figures[i];
		}
		buffer[cnt] = newFigure;
		delete[]figures;
		figures = buffer;
		cnt++;
	}
}
void Group::print()const
{
	std::cout << "Group of-----------------:"<< std::endl;
	for (int i = 0; i < cnt; i++)
		figures[i]->print();
	std::cout <<"-------------------"<< std::endl;
}
int Group::GetCnt()const
{
	return cnt;
}
void Group::IsInFigure(Point & p)const
{
	for (int i = 0; i < cnt; i++)
	{
		figures[i]->IsInFigure(p);
	}
}
Group::Group(Group &other)
{
	this->figures = NULL;
	
	this->cnt = other.cnt;
	this->figures = new Figure*[cnt];
	for (int i = 0; i < cnt; i++)
		this->figures[i] = other.figures[i];

}
Figure* Group::GetFigures()const
{
	return *figures;
}