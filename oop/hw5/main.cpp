#include <iostream>
#include <fstream>
#include "Circle.h"
#include "Figure.h"
#include "Triangle.h"
#include "Rect.h"
#include "Group.h"
using namespace std;
const int Max_Size = 100;

Figure ** CreateFigures(const char* filename)
{
	Figure **figures = NULL;
	figures = new Figure *[Max_Size];
	ifstream file(filename, ios::in);
	if (!file)
	{
		cerr << "Cannot read file \n";
	
	}
	char  name[20];
	Group *gr=new Group;
	Point q, r, p;
	int i = 0;
	
	while (!file.eof())
	{
		double x1, x2, x3, y1, y2, y3, z;
		file >>name;
		if (name[0] == 'c')
		{
			file >> x1 >> y1 >> z;
			q(x1, y1);
			figures[i]=new Circle(q, z);
			i++;
		}


		if (name[0] == 't')
		{
			file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
			q(x1, y1);
			p(x2, y2);
			r(x3, y3);
			figures[i] = new Triangle(q,p,r);
			i++; 
		}
		if (name[0] == 'r')
		{
			file >> x1 >> y1 >> x2 >> y2;
			q(x1, y1);
			p(x2, y2);
			figures[i] = new Rect(q, p);
			i++;
		}
		if (name[0] == 'g')
		{
			while (name[0] == 'g' || name[0] == 'c' || name[0] == 'r' || name[0] == 't')
			{
				Point a, b, c;
				double x1, x2, x3, y1, y2, y3, z, b1, b2;

				if (name[0] == 'g')
				{
					file >> name;
					if (name[0] == 'o')
						break;
					file >> b1 >> b2;
				}
				file >> name;
				if (name[0] == 'c')
				{
					file >> x1 >> y1 >> z;
					a(x1 + b1, y1 + b2);
					Figure *circle = new Circle(a, z);
					gr->AddFigure(circle);
				}


				if (name[0] == 't')
				{
					file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
					a(x1 + b1, y1 + b2);
					b(x2 + b1, y2 + b2);
					c(x3 + b1, y3 + b2);
					Figure *triangle = new Triangle(a, b, c);
					gr->AddFigure(triangle);
				}
				if (name[0] == 'r')
				{
					file >> x1 >> y1 >> x2 >> y2;
					a(x1+b1, y1+b2);
					b(x2 + b1, y2 + b2);
					Figure *rect = new Rect(a, b);
					gr->AddFigure(rect);
				}
			}
			
			figures[i] = new Group(*gr);
			i++;
		}
	}
	return figures;
}
int main()
{
	Figure ** pc = CreateFigures("1.txt");
	pc[0]->print();
	pc[1]->print();
	
	pc[2]->print();
	pc[3]->print();
	Point c;
	c(0, 0);
	Point b;
	b(12,9);
	pc[0]->IsInFigure(c);
	pc[2]->IsInFigure(b);
	
	
}