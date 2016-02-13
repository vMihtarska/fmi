#include "stdafx.h"
#include "CppUnitTest.h"
#include "MyMemoryAllocator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
TEST_MODULE_INITIALIZE(ModuleInitialize)
{
	Logger::WriteMessage("Entered ModuleInitialize");
}

TEST_MODULE_CLEANUP(ModuleCleanup)
{
	Logger::WriteMessage("Entering ModuleCleanup");
}
namespace MyMemoryAllocatorUnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		
		TEST_METHOD(TestForAllocateAndFree)
		{
			MyMemoryManager test2(64);
			int* pArr2 = (int*)test2.MyMalloc(8);
			unsigned long long int * dArr2 = (unsigned long long int *)pArr2;
			dArr2--;
			test2.MyFree(pArr2);

			Assert::IsTrue(*dArr2 == 48);
			
		}
		TEST_METHOD(CheckNullIfTheMemoryIsFree)
		{
			MyMemoryManager test3(64);
			int* pArr3 = (int*)test3.MyMalloc(8);
			test3.MyFree(pArr3);

			Assert::IsNull(pArr3);

		}
		TEST_METHOD(TestForTheSizeOfTheNextHeader)
		{
			MyMemoryManager test1(64);
			int* pArr1 = (int*)test1.MyMalloc(8);
			unsigned long long int * dArr1 = (unsigned long long int *)pArr1;
			dArr1--;
			dArr1 += (*dArr1 - 1) / 8 + 2;

			Assert::IsTrue(*dArr1 == 24);
		}
		TEST_METHOD(BiggerSizeThanExpected)
		{
			wchar_t message[28];
			try 
			{
				MyMemoryManager test4(1000000000);
			}
			catch (...)
			{
				swprintf_s(message, L"Bigger size then the memory");
				Assert::Fail(message, LINE_INFO());
			}
		}
		TEST_METHOD(NegativeSizeOfMemoryAllocator)
		{
			wchar_t message[28];
			try
			{
				MyMemoryManager test5(-100);
			}
			catch (...)
			{
				swprintf_s(message, L"Negative size");
				Assert::Fail(message, LINE_INFO());
			}
		}
		TEST_METHOD(CheckNullifThePointerDoesntExist)
		{
			MyMemoryManager test6(100);
			int* pArr6;
			test6.MyFree(pArr6);
			Assert::IsNull(pArr6);
		}
		TEST_METHOD(ReuseTheMemory)
		{
			MyMemoryManager test7(24);
			int FreeSize = 8;
			int* pArr7 = (int*)test7.MyMalloc(FreeSize);
			//There is no free memory
			test7.MyFree(pArr7);

			//Now we have  memory and we try to reuse it
			int* pArr8 = (int*)test7.MyMalloc(FreeSize);
			unsigned long long int *dArr8 =(unsigned long long int *) pArr8;
			dArr8--;
			
			Assert::IsTrue(*dArr8 - 1 == FreeSize);
		}
		TEST_METHOD(MergetwoBlocks)
		{
			MyMemoryManager test8(104);
			int* pArr9 = (int*)test8.MyMalloc(8);
			int* pArr10 = (int*)test8.MyMalloc(5);
			int* pArr11 = (int*)test8.MyMalloc(6);

			unsigned long long int *dArr9 = (unsigned long long int *) pArr9;
			dArr9--;

			test8.MyFree(pArr10);
			test8.MyFree(pArr9);

			
			Assert::IsTrue(*dArr9 == 32);

		}
		TEST_METHOD(MergethreeBlocks)
		{
			MyMemoryManager test9(104);
			int* pArr12 = (int*)test9.MyMalloc(8);
			int* pArr13 = (int*)test9.MyMalloc(5);
			int* pArr14 = (int*)test9.MyMalloc(6);

			unsigned long long int *dArr10 = (unsigned long long int *) pArr12;
			dArr10--;
			//first and third are free and when we set free the second
			//we have to merge all trees
			test9.MyFree(pArr12);
			test9.MyFree(pArr14);

			test9.MyFree(pArr13);


			Assert::IsTrue(*dArr10 == 88);

		}
	};
}