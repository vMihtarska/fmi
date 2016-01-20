#include <iostream>
#include "Employee.h"
#include "Specialist.h"

int main()
{
	Employee g;
	g.SetName("VASI");
	g.SetAddress("JK ZAPAD");
	g.SetEGN("9508110056");
	g.SetDepartment("IT");
	g.SetSalary(100);
	g.Print();
	Employee c(g);
	c.Print();
	Employee m;
	m = g;
	m.Print();
	Specialist x;
	x.SetName("VASI");
	x.SetAddress("JK ZAPAD");
	x.SetEGN("9508110056");
	x.SetDepartment("IT");
	x.SetSalary(100);
	x.SetDescription("PENCHO");
	x.Print();

	Specialist l(x);
	l.Print();
	Specialist y;
	y = l;
	y.Print();


}