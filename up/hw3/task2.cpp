#include <iostream>
using namespace std;
int const size = 1024;
void ReadArray(int a[], int n)
{
	cout << "Array=";
	for (int i = 0; i < n; i++)
		cin >> a[i];
}


int main()
{
	int n;
	int Counter =1;
	int Index = 0;
	int IndexMax = 0;
	int Arr[size];
	int MaxCounter=0;
	int StartIndex = 0;
	cout << "n=";
	do
	{
		cin >> n;
	} while (n < 2);
	ReadArray(Arr, n);
	
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] == Arr[i + 1])
		{

			Counter++;
		}
		else
		{
			Index = i;
			if (MaxCounter < Counter)
			{
				IndexMax = Index;
				MaxCounter = Counter;
			}
			Counter = 1;
		}

	}
	StartIndex = IndexMax - MaxCounter + 1;
	cout << "Start Index = " << StartIndex<<endl;
	cout <<"Max Counter is:"<< MaxCounter<<endl;
}