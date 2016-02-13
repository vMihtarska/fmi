
#include <iostream>
using namespace std;
int const MAX_SIZE = 50;
int  q = 0;
void ReadArray(int a[][MAX_SIZE], int n)
{
	int Numbers = 1;
	for (int row = 0; row < n; row++)
		for (int colm = 0; colm < n; colm++)
			{
				a[row][colm] = Numbers;
				Numbers++;
			}
}
void LeftToRight(int a[][MAX_SIZE], int row, int colm, int n)
{

	for (row, colm; colm < n - 1; colm++)
		cout << a[row][colm] << " ";

}
void UptoDown(int a[][MAX_SIZE], int row, int colm, int n)
{
	for (row; row < n; row++)
		for (colm = n - 1; colm< n; colm++)
			cout << a[row][colm] << " ";

}


void RightToLeft(int a[][MAX_SIZE], int row, int colm, int n)
{
	
	for (row = n - 1, colm = n - 2; colm >= q; colm--)
		cout << a[row][colm] << " ";
	q++;
}
void DownToUp(int a[][MAX_SIZE], int row, int colm, int n)
{


	for (colm, row = n - 2; row >= q; row--)
		cout << a[row][colm] << " ";


}

int main()
{
	int a[MAX_SIZE][MAX_SIZE];
	int n;
	do
	{

		cout << "n>1=";
		cin >> n;

	} while (n < 1);

	ReadArray(a, n);

	int k=0, p = 0;   // Çàìåñòèòåë íà row è colm
	
	while (k <= n - 1 && p <=n - 1)
	{
		LeftToRight(a, k, p, n);
		UptoDown(a, k, p, n);
		RightToLeft(a, k, p, n);
		DownToUp(a, k, p, n);
		
		n--;      // Îáõîæäàìå ìàòðèöàòà n-1  è òí.. 
		k++; 
		p++;
	}

	
	return 0;

}
