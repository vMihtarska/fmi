#pragma once
/**
* @file
* @author  Vasilka Mihtarska
* @version 1.0
*
* 
* @section DESCRIPTION
*
* Memory management is to provide ways to dynamically allocate 
* portions of memory to programs at their request,
* and free it for reuse when no longer needed. 
*/
class MyMemoryManager
{
private:

	long long int* buffer;
	int alignment = sizeof(long long int);
	int size;

	size_t AlighmentSize(size_t size);

	void MergeAfterBlock(long long int* p);
	void MergeBeforeBlock(long long int* p);
	void MergeBeforeAfterBlock(long long int* p);

public:

	MyMemoryManager(int size);

public:

	long long int* MyMalloc(size_t size);
	void MyFree(int*& pBlock);

public:

	void print()const;

	~MyMemoryManager();
};