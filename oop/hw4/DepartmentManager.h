#pragma once
#include "Specialist.h"
class DManager:public Specialist
{
private:
	int cntofemp;
	Employee** empl;
	char *  Dinfo;
public:
	DManager() :Specialist()
	{
		cntofemp = 0;
		empl = NULL;
		Dinfo = NULL;
	}
	~DManager()
	{

	}
	DManager(const DManager&);
	DManager & operator=(const DManager&);

	char* GetDinfo()const;
	Employee** GetEmpl()const;
	int GetCntofemp()const;

	void SetDinfo(char*);
	void SetEmpl(Employee**);
	void SetCntofemp(int);

};