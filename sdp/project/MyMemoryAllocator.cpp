#pragma once
#include "MyMemoryAllocator.h"
#include <iostream>
const int Max_Size = 40000000;
/**
* Constructor that allocate the size what we want in out memory manager.
* The size is alighment by eight.
*
* @param size size of bytes in our memory manager
* 
*/

MyMemoryManager::MyMemoryManager(int size)
{
	if (size > 0 && size < Max_Size)
	{
		size = AlighmentSize(size);
		this->size = size / alignment;
		buffer = new long long int[this->size];
		for (int i = 0; i < this->size; i++)
			buffer[i] = 0;
		buffer[0] = buffer[this->size - 1] = size - 2 * alignment;
	}
	else
	{
		this->size = 0;
		this->buffer = nullptr;
	}
}
/**
* Function MyMalloc give to the user allocated memory to use.
* We search the best place (we try to have minimal fragmentation)
* to allocate the bytes which the user want. We looking for the 
* right place as jump on headers. We have two headers for every 
* memory which we give (before and after) which is the size of bytes
* and mark the last bit to one.And fix other headers.
* If the size is bigger than out free memory we return 
* nullptr and print a message "No free memory" .
*
*  @param size Size of bytes which the user want to allocate.
*  The size is alighment by eight.
*
*  @see #MyMemoryManager::AlighmentSize(size_t size)
*/
long long int* MyMemoryManager::MyMalloc(size_t size)
{
	if (size <= 0 || this->size == 0)
	{
		std::cout << "Wrong size" <<std::endl;
		return nullptr;
	}

	int maskcheck = 1;
	int  mask = 1;
	int oldsize = 0;

	long long int* pAdress = nullptr;
	long long int * start = buffer;

	size = AlighmentSize(size);

	bool SearchPlace = true;
	bool IsNoteEnd = true;

	while (SearchPlace)
	{
		maskcheck = 1;
		if(buffer < (start + this->size) && IsNoteEnd)
			maskcheck = *buffer & maskcheck;
		else 
		{
			maskcheck = 0;
			IsNoteEnd = false;
		}

		if (maskcheck == 0 && IsNoteEnd && *buffer >= size && ((*buffer < oldsize) || (oldsize == 0)))
		{
			oldsize = *buffer;
			pAdress = buffer + 1;
			buffer = buffer + (*buffer / alignment + 2);
		}
		else if (!IsNoteEnd && pAdress)
		{

			int newSize = 0;
			if (oldsize > size + alignment)
			{
				newSize = oldsize - size - 2 * alignment;
			}
			else 
			{
				buffer = pAdress - 1;
				*buffer = oldsize;
				*buffer = *buffer | mask;

				*(buffer + oldsize / alignment + 1) = oldsize | mask;
				buffer = start;
				
				return pAdress;
			}
		
			buffer = pAdress - 1;
			*buffer = size;
			*buffer = *buffer | mask; 

			*(buffer + size / alignment + 1) = size | mask;

			*(buffer + size / alignment + 2) = newSize;

			if ((buffer + oldsize / alignment + 1) != (buffer + this->size))
			{
				*(buffer + oldsize / alignment + 1) = newSize;
			}

			if ((buffer + size / alignment + 2) == (buffer + this->size))
			{
				buffer = start;
				buffer[this->size - 1] = newSize;
			}
			else
			{
				buffer = start;
			}

			return pAdress;
		}
		else
		{
			buffer = buffer + (*buffer / alignment + 2);

			if (buffer > start + this->size && !pAdress)
			{
				buffer = start;
				std::cout << "No free memory." << std::endl;
				return nullptr;
			}
		}
	}


}
/**
* Function MyFree that set free the the memory where
* is pBlock and merge around it if its free.
* And fix the headers.
* And then set pBlock to nullptr.
* If the pointer is not allocate with our metod 
* myMalloc or is free we print a message "Wrong pointer"
* and return.
* We search the pointer from the begining to the end.
* We jump on headers(move the pointer).
*
*  @param pBlock Pointer to memory that we want to set free.
*
*  @see #MyMemoryManager::MergeAfterBlock(long long int * buffer)
*  @see #MyMemoryManager::MergeBeforeBlock(long long int * buffer)
*  @see #MyMemoryManager::MergeBeforeAfterBlock(long long int * buffer)
*/
void MyMemoryManager::MyFree(int*& pBlock)
{
	if (pBlock == nullptr)
	{
		std::cout << "Wrong pointer." << std::endl;
		return;
	}

	bool isFined = true;
	long long int* start = buffer;
	int maskCheckBefore = 1;
	int maskCheckAfter = 1;
	int mask = 1;

	while (isFined)
	{
		if (buffer + 1 == (long long int*)pBlock)
		{
			if (buffer != start)
			{
				if (*(buffer - 1) >= 0)
					maskCheckBefore = *(buffer - 1) & maskCheckBefore;
				else
					maskCheckBefore = 1;
			}

			if (*(buffer + (*buffer / alignment + 2)) >= 0)
				maskCheckAfter = *(buffer + (*buffer / alignment + 2)) & maskCheckAfter;
			else
				maskCheckBefore = 1;

			if (maskCheckBefore && maskCheckAfter)
			{

				*buffer &= ~mask;
				*(buffer + *buffer / alignment + 1) &= ~mask;

				buffer = start;
			}
			else if (!maskCheckBefore && !maskCheckAfter)
			{
				MergeBeforeAfterBlock(buffer);
				buffer = start;
			}
			else if (!maskCheckBefore)
			{
				MergeBeforeBlock(buffer);
				buffer = start;
			}
			else if (!maskCheckAfter)
			{
				MergeAfterBlock(buffer);
				buffer = start;
			}

			pBlock = NULL;
			isFined = false;
		}
		else
		{
			buffer = buffer + (*buffer / alignment + 2);
			if (buffer >= (start + this->size))
			{
				buffer = start;
				std::cout << "Wrong pointer." << std::endl;
				pBlock = nullptr;
				return;
			}
		}
	}


}
/**
* Function AlighmentSize that alighment the size we given.
*
* @param size Òhe size that the user has submitted.
*     
*/
size_t MyMemoryManager::AlighmentSize(size_t size)
{
	if (size % 8 != 0)
	{
		size += alignment - (size % 8);
	}
	return size;
}
/**
* Function MergeAfterBlock which merge and set free two part
* of memory (current and after which is free) which no longer needed.
*
* @param buffer Pointer to memory that we want to set free
*
*/
void MyMemoryManager::MergeAfterBlock(long long int * buffer)
{
	int temp = *(buffer + *buffer / alignment + 1);
	int temp2 = *(buffer + *buffer / alignment + 2);

	*(buffer + *buffer / alignment + 1) = 0;
	*(buffer + *buffer / alignment + 2) = 0;
	*buffer += temp2 + 2 * alignment - 1;
	*(buffer + *buffer / alignment + 1) = *buffer;
}

/**
* Function MergeBeforeBlock which merge and set free two part
* of memory (current and before which is free) which no longer needed.
*
* @param buffer Pointer to memory that we want to set free
*
*/

void MyMemoryManager::MergeBeforeBlock(long long int * buffer)
{
	*(buffer + (*buffer / alignment + 1)) = *buffer - 1 + *(buffer - 1) + 2 * alignment;
	*(buffer - *(buffer - 1) / alignment - 2) = *buffer - 1 + *(buffer - 1) + 2 * alignment;
	*buffer = 0;
	*(buffer - 1) = 0;
}
/**
* Function MergeBeforeAfterBlock which merge and set free two part of
* memory (current and after and before which is free) which no longer needed.
*
* @param buffer Pointer to memory that we want to set free
*
*/	

void MyMemoryManager::MergeBeforeAfterBlock(long long int * buffer)
{
	int middle = *buffer - 1;
	int before = *(buffer - 1);
	int after = *(buffer + *buffer / alignment + 2);

	*(buffer - before / alignment - 2) = before + middle + after + 4 * alignment;
	*(buffer + *buffer / alignment + 2 + after / alignment + 1) = before + middle + after + 4 * alignment;
	*(buffer + *buffer / alignment + 1) = 0;
	*(buffer - 1) = 0;
	*(buffer + *buffer / alignment + 2) = 0;
	*buffer = 0;
}
/**
* Function print - print the array,help us to see
* is everything okey.
*/
void MyMemoryManager::print()const
{
	for (int i = 0; i < this->size; i++)
		std::cout << "[" << i << "]= " << buffer[i] << std::endl;
}
/**
* Destructor which is automatically invoked when the object is destroyed.
*/
MyMemoryManager::~MyMemoryManager()
{
	delete[] buffer;
	buffer = nullptr;
}