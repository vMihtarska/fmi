//#include "DepartmentManager.h"
//
//char* DManager::GetDinfo()const
//{
//	return Dinfo;
//}
//Employee** DManager::GetEmpl()const
//{
//	return empl;
//}
//int DManager::GetCntofemp()const
//{
//	return cntofemp;
//}
//void DManager::SetDinfo(char*Dinfo)
//{
//	if (this->Dinfo != NULL)
//	{
//		delete[] this->Dinfo;
//		this->Dinfo = NULL;
//	}
//	int length = strlen(Dinfo);
//	this->Dinfo = new (std::nothrow) char[length + 1];
//	strcpy(this->Dinfo, Dinfo);
//}
//
//void SetEmpl(Employee**)
//{
//
//}
//void DManager::SetCntofemp(int Cntofemp)
//{
//	this->cntofemp = Cntofemp;
//}