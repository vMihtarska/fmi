
#include <iostream>
using namespace std;
int const Max_Size = 1000;
int const Max_Size_Numers = 9000;

bool IsEvenNumber(int arr[], int n)
{
	if (arr[n-1] % 2 == 0) return true;
	else return false;
}

int HowEvenNumbers(int arr[], int n,int count)
{
	
	if (n!=0)
	{
		if (IsEvenNumber(arr, n))
			count++;
			return HowEvenNumbers(arr, n - 1,count);
		
	}
	else return count;
}
int CopyNumbers(int  arr[], int n,int arr2[],int i)
{
	if (n != 0)
	{
		if (IsEvenNumber(arr, n))
		{
			arr2[i] = arr[n - 1];
			i++;
		}
	}
	else return 0;
	return CopyNumbers(arr, n - 1, arr2,i);

}

int main()
{
	
	int n;
	int count = 0;
	do{
		cout << "Enter how much number u want:";
		cin >> n;
	} while (n<0 && n>1000);
	int *arr = new (std::nothrow)int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int sizeOfarr2 = HowEvenNumbers(arr, n, count);
	cout << "There... are: "<< sizeOfarr2<<endl;
	int *arr2 = new (std::nothrow) int[sizeOfarr2];
	int i = 0;
	 CopyNumbers(arr, n, arr2,i);
	 cout << "Numbers are:" << endl;
	 for (int i = sizeOfarr2-1; i >= 0; i--)
	 {
		 cout<< arr2[i]<<endl;
	 }
	 system("pause");
	
	 return 0;
}
