#pragma once
class Vector
{
private:
	size_t size;
	double *arr;
	void copy(double*arr, size_t size);
public:
	Vector();
	Vector(size_t size);
	Vector(const Vector &);
	~Vector();
public:
	Vector Fill(size_t x, size_t y)const;
	double & operator[](size_t size);
	void print()const;
	Vector operator+(Vector& x)const;
	Vector& operator+=(Vector& x);
	Vector operator-(Vector& x)const;
	Vector& operator-=(Vector& x);
	Vector operator*(double x)const;
	Vector& operator*=(double x);
	Vector operator/(double x)const;
	Vector& operator/=(double x);
	double & operator%(Vector& x)const;

};