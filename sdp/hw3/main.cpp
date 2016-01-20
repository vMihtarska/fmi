
#include <iostream>
#include "StringArray.h"

const int MaxSize_Of_Op = 5 ;
void Merge(char** pA, size_t sizeA, char** pB, size_t sizeB, char** pResult);
void MergeSort(char** pArr, size_t Size)
{
	if (Size <= 1)
		return;
	size_t middle = Size / 2;
	char** left = new char*[middle];
	char** right = new char*[Size - middle];
	for (int i = 0; i < middle; i++)
		left[i] = pArr[i];

	for (int i = middle; i < Size; i++)
		right[i-middle] = pArr[i];

	MergeSort(left, middle);

	MergeSort(right, Size - middle);

	Merge(left, middle, right, Size - middle, pArr);
	delete[] left;
	delete[] right;

}
void Merge(char** left, size_t sizeL, char** right, size_t sizeR, char** res)
{
	size_t i, j, k;
	i = j = k = 0;
	while (i < sizeL && j < sizeR)
	{
		if (strcmp(left[i],right[j])<=0)
		{
			res[k++] = left[i++];
		}
		else {
			res[k++] = right[j++];
		}
	}
	while (i < sizeL)
		res[k++] = left[i++];

	while (j < sizeR)
		res[k++] = right[j++];
}

int main()
{
	int num;
	std::cout << "Enter the number of string arrays: ";
	std::cin >> num;
	int numOfwords, numOfoperation;
	int left, right;

	for (int i = 0; i < num; i++)
	{
		std::cout << "Enter the number of words and operation: ";
		std::cin >> numOfwords >> numOfoperation;
		StringArray str(numOfwords);

		std::cout << "Enter the words: ";
		for (int j = 0; j < numOfwords; j++)
		{
			char words[MaxSize_Of_Word + 1];
			std::cin >> words;
			str.Add(words);
		}

		MergeSort(str.getArr(), numOfwords);

		std::cout << "Enter the operations: "<<std::endl;
		char* Operation = new char[MaxSize_Of_Op + 1];
		for (int k = 0; k < numOfoperation; k++)
		{
			std::cin >> Operation;
			if (!strcmp(Operation, "ENTER"))
			{
				std::cin >> left >> right;
				str.SetInterval(left, right);
			}
			else if(!strcmp(Operation, "QUERY"))
			{
				char searchWord[MaxSize_Of_Word+1];
				std::cin >> searchWord;
				str.QUERY(searchWord);
			}
			
		}
		delete[] Operation;
	}
}
