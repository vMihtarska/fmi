//Василка Михтарска фн:45053 1 група
#include <iostream>
using namespace std;
const int Max_Size = 100;
bool isAlpha(char c)
{
	return  c > 'a'&& c <= 'z' ||
		c >= 'A'&&  c <= 'Z'  ||
		c == '_';

}
bool islower(char c)
{
	return c >= 'a'&& c <= 'z';
}
char toupper(char *str,int count)
{
	
	if (!islower(str[count])) return *str;
	return str[count] - 'a' + 'A';
}
void IdentificatorsToUpper(char* str)
{
	bool ds = true;
	int size = strlen(str);
	for (int i = 0; i <= size; i++)
	{
		
		if (str[i] == ' ' || !isAlpha(str[0]))
		{
			cout << "Nevaliden Identifikator!" << endl;
			ds = false;
			break;
		}
		else 
		{
			*str=toupper(str,0);
				
		}
	}
	if (ds)
	{
		cout << str << endl;
	}
}


int main()
{
	char str[Max_Size];
	cin.getline(str, Max_Size);
	IdentificatorsToUpper(str);


}