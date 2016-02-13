#include <iostream>
#include "MyMemoryAllocator.h"


int main()
{
	MyMemoryManager obj(1024);
	int* pArr1 = (int*)obj.MyMalloc(200);
	int* pArr2 = (int*)obj.MyMalloc(88);
	int* pArr3 = (int*)obj.MyMalloc(300);
	
	pArr1[0] = pArr2[0] = pArr3[0] = 10;
	
	obj.MyFree(pArr1);
	obj.MyFree(pArr2);

	obj.MyFree(pArr3);
		//obj.print();		return 0;
}