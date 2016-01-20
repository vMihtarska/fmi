#include "Employee.h"
#include "Specialist.h"
Specialist::Specialist(const Specialist& p) :Employee(p)
{
	this->description = NULL;
	SetDescription(p.GetDescription());
}
char* Specialist::GetDescription() const
{
	return description;
}

void Specialist::SetDescription(const char* description)
{
	if (this->description != NULL)
	{
		delete[] this->description;
		this->description = NULL;
	}
	int length = strlen(description);
	this->description = new (std::nothrow) char[length + 1];
	strcpy(this->description, description);
}
Specialist& Specialist::operator=(const Specialist& p)
{
	Employee::operator=(p);
	if (this->description!= p.GetDescription())
	{
		SetDescription(p.GetDescription());
	}
	return *this;
}
void Specialist::Print()const
{

	std::cout << "Specialist: " << std::endl
		<< "Name:" << this->GetName() << std::endl
		<< "Address:" << this->GetAddress() << std::endl
		<< "EGN:" << this->GetEGN() << std::endl
		<< "Department:" << this->GetDepartment() << std::endl
		<< "Salary:" << this->GetSalary() << std::endl
		<< "Description:" << this->description << std::endl;

	std::cout << std::endl;
}