#include "Vector.h"
#include <iostream>
Vector::Vector()
{
	size = 0;
	arr = NULL;
}
Vector::Vector(size_t size)
{
	if (size < 0)
		size = -size;
	this->size = size;
	arr = new double[size];
	for (int i = 0; i < size; i++)
		arr[i] = 0;

}
Vector::Vector(const Vector & other)
{
	copy(other.arr, other.size);
}
Vector::~Vector()
{
	size = 0;
	delete[]arr;
}
void Vector::copy(double*other, size_t size)
{
	this->size = size;
	this->arr = new double[size];
	for (int i = 0; i < size; i++)
		this->arr[i] = other[i];
}
double & Vector::operator[](size_t index)
{
	static double error = 0;
	if (this->size>index)
		return this->arr[index];
	else return error;
}
void Vector::print()const
{
	std::cout << "(";
	for (int i = 0; i < this->size; i++)
	{
		std::cout << arr[i];
		if (i != this->size - 1)
			std::cout << ",";
	}
	std::cout << ")" << std::endl;
}
Vector Vector::Fill(size_t x, size_t y)const
{

	Vector nVector(x);
	for (int i = 0; i < y; i++)
		nVector.arr[i] = this->arr[i];
	for (int i = y; i < x; i++)
		nVector.arr[i] = 0;
	return nVector;

}
Vector Vector::operator+(Vector &x) const
{
	if (this->size < x.size)
	{
		Vector nVector((*this).Fill(x.size, this->size));
		for (int i = 0; i < x.size; i++)
			nVector.arr[i] += x[i];
		return nVector;
	}
	else
	{
		Vector nVector(x.Fill(this->size, x.size));
		for (int i = 0; i < this->size; i++)
			nVector.arr[i] += this->arr[i];
		return nVector;
	}


}
Vector &Vector::operator+=(Vector& x)
{
	if (this->size > x.size)
	{

		for (int i = 0; i < this->size; i++)
			this->arr[i] = this->arr[i] + x.Fill(this->size, x.size)[i];
		return *this;
	}
	else
	{
		Vector n((*this).Fill(x.size, this->size));
		(*this).copy(n.arr, n.size);
		for (int i = 0; i < x.size; i++)
			this->arr[i] = this->arr[i] + x[i];
		return *this;
	}

}
Vector Vector::operator-(Vector& x) const
{
	if (this->size < x.size)
	{
		Vector nVector((*this).Fill(x.size, this->size));
		for (int i = 0; i < x.size; i++)
			nVector.arr[i] -= x[i];
		return nVector;
	}
	else
	{
		Vector nVector(x.Fill(this->size, x.size));
		for (int i = 0; i < this->size; i++)
			nVector.arr[i] -= this->arr[i];
		return nVector;
	}
}
Vector &Vector::operator-=(Vector &x)
{
	if (this->size > x.size)
	{

		for (int i = 0; i < this->size; i++)
			this->arr[i] = this->arr[i] - x.Fill(this->size, x.size)[i];
		return *this;
	}
	else
	{
		Vector n((*this).Fill(x.size, this->size));
		(*this).copy(n.arr, n.size);
		for (int i = 0; i < x.size; i++)
			this->arr[i] = this->arr[i] - x[i];
		return *this;
	}
}
Vector Vector::operator*(double x) const
{
	Vector nVector(*this);
	for (int i = 0; i < this->size; i++)
		nVector.arr[i] *= x;

	return nVector;
}
Vector &Vector::operator*=(double x)
{
	for (int i = 0; i < this->size; i++)
		this->arr[i] = this->arr[i] * x;
	return *this;
}
Vector Vector::operator/(double x) const
{
	Vector nVector(*this);
	for (int i = 0; i < this->size; i++)
		nVector.arr[i] /= x;

	return nVector;
}
Vector &Vector::operator/=(double x)
{
	for (int i = 0; i < this->size; i++)
		this->arr[i] = this->arr[i] / x;
	return *this;
}
double &Vector::operator%(Vector &x)const
{
	double sum = 0;
	if (this->size < x.size)
	{
		Vector nVector((*this).Fill(x.size, this->size));
		for (int i = 0; i < x.size; i++)
			sum += nVector.arr[i] * x[i];
		return sum;
	}
	else
	{
		Vector nVector(x.Fill(this->size, x.size));
		for (int i = 0; i < this->size; i++)
			sum += nVector.arr[i] * this->arr[i];
		return sum;
	}
}