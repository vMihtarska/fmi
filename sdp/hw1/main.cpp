//Василка Михтарска 45053

#include <iostream>
#include <string>
#include "CompressedString.h"
void Reduce(CompressedString<std::string> &, int*,int,bool);
void Read()
{

	CompressedString<std::string> str;
	char* temp = new char[100];
	std::cout << "Write a compressed string:" << std::endl;
	std::cin.getline(temp, 100);
	std::cin.clear();
	std::cin.sync();
	int size = strlen(temp);
	int*numbers = new int[100];
	numbers[0] = 0;
	int j = 0;
	int i = 0;
	bool nulls = false;
	while (i<size)
	{
		char* ch = new char[100];
		int k = 0;
		if (CompressedString<std::string>::isAlpha(temp[i]))
		{
			while (CompressedString<std::string>::isAlpha(temp[i]))
			{
				ch[k++] = temp[i++];
			}
			ch[k] = '\0';
			str.push(ch);
			delete[] ch;
		}
		else
		{
			delete[] ch;
		}
		if (CompressedString<std::string>::isNum(temp[i]))
		{
			if (i>0&&temp[i - 1]==')'&& temp[i + 1]=='(')
			{
				numbers[j++] = 0;
				nulls = true;
				numbers[j++] = CompressedString<std::string>::ToInt(temp[i++]);
			}
			else if (CompressedString<std::string>::isNum(temp[i + 1]))
			{
				while (CompressedString<std::string>::isNum(temp[i]))
				{
					ch[k++] = temp[i++];
				}
				ch[k] = '\0';
				std::cout << ch;
				numbers[j++] = std::atoi(ch);
			}
			else
			{
				numbers[j++] = CompressedString<std::string>::ToInt(temp[i++]);
			}
		}
		if (CompressedString<std::string>::isBrace(temp[i]))
		{
			i++;
		}
	}
	
	Reduce(str, numbers,j,nulls);
}
void Reduce(CompressedString<std::string> & str, int* num,int size,bool nulls)
{
	std::cout << "The decompressed string is:" << std::endl;
	std::string b;
	if (num[0] == 0) str.ReversePrint();
	else if (num[0] != 0 && str.getsize() == 1)
	{
		for (int i = 1; i < size; i++)
			num[0] *= num[i];
		std::string temp = str.top();
		for (int i = 0; i < num[0]-1; i++)
			str.top() = str.top() + temp;
		str.ReversePrint();
	}
	else 
	{
		for (int i = size-1; i >= 0; i--)
		{
			
			if (num[i] != 0)
			{
				int k = 0;
				std::string temp = str.top();
				while (k < num[i] - 1)
				{
					str.top() = str.top() + temp;
					k++;
				}
				std::string temp1 = str.top()+b;
				if (str.getsize() == 1 && !nulls)
				{
					str.top() = str.top() + b;
					break;
				}
				else 
				if (str.getsize() == 1 && num[i + 1] == 0 && nulls&&i==0)
				{
					str.top() = str.top() + b;
					break;
				}
				else if (str.getsize() == 1 && nulls)
				{
					std::string temp = b;
					for (int i = 0; i < num[0] - 1; i++)
						str.top() = str.top() + temp;
					str.ReversePrint();
					break;
				}
				else if (num[i - 1] != 0)
				{
					str.pop();
					str.top() = str.top() + temp1;
				}
				else
				{
					b = str.top() + b;
					str.pop();
				}
			}
		}
		str.ReversePrint();
	}
	
}
int main()
{

	Read();
	std::cout<<std::endl;
	return 0;
}