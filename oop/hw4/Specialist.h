#pragma once
// INFEFDGdfd
#include "Employee.h"
class Specialist : public Employee
{
private:
	char* description;
public:
	Specialist() :Employee()
	{
		description = NULL;
	}
	~Specialist()
	{
		delete[]description;
		description = NULL;
	};
	Specialist(const Specialist& p);
	Specialist& Specialist::operator=(const Specialist& p); 

	char* GetDescription() const;
	void SetDescription(const char* description);

	void Print()const;
};