#include <iostream>
#include "Vector.h"

int main()
{
	
	Vector c(3);			//Създава нулев вектор с 3 координати
	c[0] = 1;				//Задаване на стойности
	std::cout << c[1]		//Принтиране на дадена координата
		<<std::endl; 
	Vector p(c);			//Копиране от един в др вектор
	p[2] = 3;
	std::cout << "c ";
	c.print();	
	std::cout << "p ";
	p.print();
	Vector z(3);
	std::cout << "z ";
	z.print();
	z += c;
	std::cout << "z+=c ";
	z.print();
	std::cout << "p+z ";
	(p+z).print();
	std::cout << "p-c ";
	(p - c).print();
	z -= c;
	std::cout << "z-=c";
	z.print();
	Vector x = p +c +c;
	std::cout << "x ";
	x.print();
	std::cout << "x*=2 ";
	x *= 2;
	x.print();
	std::cout << "x*5 ";
	(x * 5).print();
	std::cout << "z/5 ";
	(z / 5).print();
	std::cout << "p%c=";
	std::cout << p%c<<std::endl;

	Vector m(4);
	for (int i = 0; i < 4; i++)
		m[i] = i;
	std::cout << "m ";
	m.print();
	Vector b(2);
	for (int i = 0; i < 2; i++)
		b[i] = i;
	std::cout << "b ";
	b.print();
	//При различни размерности 
	std::cout << "m+b ";			
	(m+b).print();
	std::cout << "b+m ";
	(b + m).print();
	b += m; 
	m += b;
	std::cout << "b+=m ";
	b.print();
	std::cout << "m+=b ";
	m.print();
	Vector w(4);
	w[1] = 3;
	std::cout << "w  ";
	w.print();
	std::cout << "c-=w ";
	c -= w;
	c.print();
	std::cout << "c-m ";
	(c - w).print();
	std::cout << "m%c=";
	std::cout << m%c<<std::endl;

	return 0;
}