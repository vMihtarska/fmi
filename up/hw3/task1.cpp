#include <iostream>
using namespace std;
int const size = 1024;
void ReadArray(double a[], int n)
{
	cout << "Array=";
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

int main()
{
	int n;
	double Average=0;
	double Sum = 0;
	double Arr[size];
	cout << "n=";
	do
	{
		cin >> n;
	} while (n < 2);


	ReadArray(Arr, n);
	for (int i = 0; i < n; i++)
		Sum += Arr[i];
	Average =Sum /n;
	
	for (int i = 0; i < n; i++)
	{
		if (Arr[i]>Average)
			cout << Arr[i] << " ";
	}

	return 0;

}