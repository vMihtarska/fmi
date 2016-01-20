#include "BoolVector.h"
#include <iostream>
BoolVector::BoolVector()
{
	x = 0;
}
BoolVector::BoolVector(unsigned int x)
{
	this->x = x;
}
BoolVector::~BoolVector()
{

}
bool BoolVector::set(const int x)
{
	if (x >= 0 && x <= 31)
	{

		int mask = (1 << x);
		this->x |= mask;
		return 1;
	}
	else return 0;
}
bool BoolVector::clear(const int x)
{
	if (x >= 0 && x <= 31)
	{

		int mask = ~(1 << x);
		this->x &= mask;
		return 1;
	}
	else return 0;
}
int BoolVector::operator[](const int x)const
{
	if (x >= 0 && x <= 31)
	{
		int mask = (1 << x);
		if (mask&this->x)
			return 1;
		else return 0;
	}
	else return -1;
}
void BoolVector::print()const
{
	std::cout << x << std::endl;
}