
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "n=";
	do
	{   
		cin >> n;
	} while (n <= 0);
	

	if (n % 2 == 0)
	{
		for (int row = 1; row <= n; row++)
		{
			for (int i = 1; i <= n; i++)
			{
				if (row - 1 <= n / 2)
				{

					if (i < (n / 2 - row + 1) || i >(n / 2 + row))
					{
						cout << " ";
					}
					else cout << i ;
				}
				else
				{


					if (i < (n / 2 - (n - row)) || i >(n / 2 + n - row + 1))
					{
						cout << " ";
					}
					else cout << i ;

				}

			}
			cout << endl;
		}
	}
	else
	{
		for (int row = 1; row <= n; row++)
		{
			for (int i = 1; i <= n; i++)
			{
				if (row <= n / 2)
				{

					if (i < (n / 2 - row + 2) || i >(n / 2 + row))
					{
						cout << " ";
					}
					else cout << i ;
				}
				else
				{


					if (i < (n / 2 - (n - row)+1) || i >(n / 2 + n - row + 1))
					{
						cout << " ";
					}
					else cout << i ;

				}

			}
			cout << endl;

		}

	}

}
