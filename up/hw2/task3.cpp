//Василка Михтарска 1 група Фак.номер 45053
#include <iostream>
#include <iomanip>
using namespace std;

long fact(long n)
{
	long fact = 1;
	for (int i = 2; i <= n; i++)
		fact *= i;
	return fact;
}

int binomial(int n, int k)
{
	if ((k == 0) || (k == n)) return 1;
	return fact(n) / (fact(n - k)*fact(k));
}

int main()
{
	int iNADk=0;
	int nNADi=0;
	int n;
	do
	{
		cout << "Enter positive integer:"<<endl;
			cin >> n;
	} while (n <= 0);

	int maxNumWidth;
	
	if (n < 4)
	{
		maxNumWidth = 1;
	}
	else if (n < 8)
	{
		maxNumWidth = 2;
	}
	else if (n < 12)
	{
		maxNumWidth = 3;
	}
	else if (n < 15)
	{
		maxNumWidth = 4;
	}
	else
	{
		maxNumWidth = 5;
	}

	for (int i = 0; i <= n; i++)
	{

		cout << setw((n - i + 1) * maxNumWidth);
		for (int k = 0; k <= i; k++)
		{
			
			iNADk = binomial(i, k);
			
			nNADi = binomial(n - 1, i);
			
			if (iNADk*nNADi != 0)
			{
				
				cout << iNADk*nNADi << setw(2 * maxNumWidth);
			}
		
		} cout << endl;
	}
	
return 0;
}