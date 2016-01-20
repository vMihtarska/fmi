#pragma once
class Point
{
private:
	double x, y;
	void copyPoint();
public:
	Point();
	Point(const Point&);
	void operator()(double,double);
	Point & operator=(const Point &);
	

	double Getx() const;
	double Gety() const;
	void Setx(double);
	void Sety(double);
	

};