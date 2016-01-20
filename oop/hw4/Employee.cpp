#include "Employee.h"
#include <iostream>

char* Employee::GetName()const
{
	return name;
}
char* Employee::GetAddress()const
{
	return address;
}
char* Employee::GetEGN()const
{
	return EGN;
}
char* Employee::GetDepartment()const
{
	return department;
}
int Employee::GetSalary()const
{
	return salary;
}
void Employee::SetName(const char*name)
{
	if (this->name != NULL)
	{
		delete[] this->name;
		this->name = NULL;
	}
	int length = strlen(name);
	this->name = new (std::nothrow) char[length + 1];
	strcpy(this->name, name);
}
void Employee::SetAddress(const char* address)
{
	if (this->address != NULL)
	{
		delete[] this->address;
		this->address = NULL;
	}
	int length = strlen(address);
	this->address = new (std::nothrow) char[length + 1];
	strcpy(this->address, address);
}
void Employee::SetEGN(const char* EGN)
{
	if (this->EGN != NULL)
	{
		delete[] this->EGN;
		this->EGN = NULL;
	}
	int length = strlen(EGN);
	this->EGN = new (std::nothrow) char[length + 1];
	if (!this->EGN)
	{
		std::cout << "Couldn't allocate memory!\n";
		return;
	}
	strcpy(this->EGN,EGN);
}
void Employee::SetDepartment(const char* department)
{
	if (this->department != NULL)
	{
		delete[] this->department;
		this->department = NULL;
	}
	int length = strlen(department);
	this->department = new (std::nothrow) char[length + 1];
	strcpy(this->department, department);
}
void Employee::SetSalary(int salary)
{
	this->salary = salary;
}
Employee::Employee(const Employee& p)
{
	this->name = NULL;
	SetName(p.GetName());
	this->address = NULL;
	SetAddress(p.GetAddress());
	this->EGN = NULL;
	SetEGN(p.GetEGN());
	this->department = NULL;
	SetDepartment(p.GetDepartment());
	SetSalary(p.GetSalary());
}
Employee& Employee::operator=(const Employee& p)
{
	if (this->name != p.GetName())
	{
		SetName(p.GetName());
	}

	if (this->address != p.GetAddress())
	{
		SetAddress(p.GetAddress());
	}

	if (this->EGN != p.GetEGN())
	{
		SetEGN(p.GetEGN());
	}

	if (this->department != p.GetDepartment())
	{
		SetDepartment(p.GetDepartment());
	}
	SetSalary(p.GetSalary());
	return *this;
}
void Employee::Print()const
{
	std::cout << "Employee: " << std::endl
		<< "Name:" << this->name << std::endl
		<< "Address:" << this->address << std::endl
		<< "EGN:" << this->EGN << std::endl
		<< "Department:" << this->department << std::endl
		<< "Salary:" << this->salary << std::endl;
	std::cout << std::endl;
}