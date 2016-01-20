#include <iostream>
using namespace std;

int printRows(int n, const int &y)
{

	 if (n != 0)
	{
		cout << y - n + 1 << " ";
    }
	else return 0;

	return printRows(n - 1, y);
}
int printNumbers(int n,const int &y,const int &z)
{
	if (n==y==z)
	{
		
		printRows(n - n + 1, y - y + 1);
		cout << endl;
	}
	else if (n!=0)
	{
		printRows(n-1 , y-1);
		cout << endl;
	}
	else return 0;
	return printNumbers(n-1,y-1,z);
}
int printNumbers2(int n, const int &y, const int &z)
{
	if (n == y == z)
	{
		printRows(n-1, y-1);
		
		cout << endl;
	}
	else if (n != 0)
	{
		printRows(z - n + 1, z - y + 1);
		cout << endl;
	}
	else return 0;
	return printNumbers2(n - 1, y - 1, z);
}
int main()
{
	int n;
	do
	{
		cout << "Enter N=";
		cin >> n;
	} while (n<0||n>=20);
	const int &y = n;
	const int &z = n;
	printNumbers2(n, y, z);
	printNumbers(n, y,z);
	return 0;
}

