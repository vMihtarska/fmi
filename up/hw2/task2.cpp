
#include <iostream>
using namespace std;
bool Prosto(int k)
{
	if (k == 1) return 0;
	if ((k == 2) || (k == 3)) return 1;
	else if (k % 2 == 0) return 0;
	if (k % 3 == 0)return 0;
	int d = 3;
	while (d*d <= k)
	{
		if (k%d == 0)
			return 0;
		d += 2;
	}
	 return 1;
}
int main()
{    
	
	
	int n, m;
	int sum = 1;
	int count=0;
	cout << "[n,m]=" << endl<<"n<m"<<endl;
	
	do
	{   
		cin >> n >> m;
	} while (n >= m && n < 0);
	
	for (int i = n; i <= m; i++)
	{
		for (int j = 2; j <= i - 1; j++)
		{
			if (i%j == 0)
			{
				sum += j;
			}

		}
		
		if (Prosto(sum))
		{  
			count++;
			cout << i << endl;
		}
		sum = 1;
	}
	cout << "Count=" << count << endl;

	return 0;
}
