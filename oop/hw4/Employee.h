#include <iostream>
#pragma once
class Employee
{
private:
	char* name;
	char* address;
	char* EGN;
	char* department;
	int salary;
public:
	Employee::Employee()
	{
		name = NULL;
		address = NULL;
		EGN = NULL;
		department = NULL;
		salary = 0;
	};
	~Employee()
	{
		delete[]name;
		name = NULL;
		delete[]address;
		address = NULL;
		delete[]EGN;
		EGN = NULL;
		delete[]department;
		department = NULL;
	};
	Employee(const Employee&);
	Employee& operator=(const Employee&);
	char* GetName()const;
	char* GetAddress()const;
	char* GetEGN()const;
	char* GetDepartment()const;
	int GetSalary()const;

	void SetName(const char*name);
	void SetAddress(const char*address);
	void SetEGN(const char*EGN);
	void SetDepartment(const char*department);
	void SetSalary(int salary);

	void Print()const;



};