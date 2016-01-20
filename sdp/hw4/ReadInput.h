#pragma once
#include <iostream>
#include "Tree.h"
#include "Stack.h"
class ReadInput
{
private:
	Tree* t;
public:
	ReadInput()
	{
		t = new Tree();
	}
	
	int MakeATree(char* input,int i=0,int father=0,int level=0)
	{
		Stack<char> help;
		int value = 0;
		for (i; i < strlen(input); i++)
		{
			
			if (input[i] == ')' || input[i] == '(' || input[i] == ' ')
			{
				continue;
			}
			else if (input[i] == '{')
			{
				help.push('{');
				if (input[i + 1] != '}')
				i = MakeATree(input,i+1,value,level+1);
				if(i==1 && help.getsize()==1)
					break;
			}
			else if (input[i] == '}')
			{
				if (help.empty())
				{
					return i-1;
				}
				help.pop();
				continue;
			}
			else
			{

				value = input[i] - '0';
				int j = i;
				while (input[j+1] >= '0' && input[j+1] <= '9')
				{
					value = value * 10 + (input[j+1] - '0');
					j++;
				}
				i = j;
				if (t->isEmpty())
					t->add(value);
				else
				{
					t->add(father, value,level);
				}
			}

		}
	}
	Tree* getTree()
	{
		return this->t;
	}
	

	~ReadInput()
	{
		t->~Tree();
	}
};
