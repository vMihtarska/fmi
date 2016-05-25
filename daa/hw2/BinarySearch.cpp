#include <iostream>
#include <vector>
#include <algorithm>

bool canPutCows(std::vector<int>& v, int k, int curr, bool& hasLength);

int BinarySearch(std::vector<int>& v, int l, int r, int k,int& num)
{
	bool t = false;

	if (l >= r)
	{
		return num;
	}
	
	int m = (r + l) / 2;

	if (canPutCows(v, k, m, t))
	{
		num = m;
		return BinarySearch(v, m + 1, r, k,num);
	}
	else
	{
		return BinarySearch(v, l, m, k,num);
	}
}
int BinarySearch1(std::vector<int>& v, int l, int r, int num)
{
	if (num > v[v.size() - 1])
		return -1;
	if (l >= r)
	{
		return l;
	}

	int m = (r + l) / 2;

	if (num > v[m])
	{
		return BinarySearch1(v, m + 1, r, num);
	}
	else
	{
		return BinarySearch1(v, l, m, num);
	}
}
bool canPutCows(std::vector<int>& v, int k, int curr, bool& hasLength)
{
	int lastIndex = 0;
	int nextIndex = -1; 

	while (k > 1)
	{
		nextIndex = BinarySearch1(v, lastIndex, v.size() - 1, v[lastIndex] + curr);

		if (nextIndex == -1)
			return false;
		else {

			k--;

			if (!hasLength && nextIndex != 0 && v[nextIndex] - v[lastIndex] == curr)
			{
				hasLength = true;
			}

			lastIndex = nextIndex;
		}
	}
	return true;
}

int main()
{

	std::cin.sync_with_stdio(0);
	int n, k;

	std::cin >> n >> k;


	int num;
	std::vector<int> v;
	for (int i = 0; i < n; i++)
	{
		std::cin >> num;
		v.push_back(num);
	}

	std::sort(v.begin(), v.end());

	if (k == 2)
	{
		std::cout << v[n - 1] - v[0];
	}
	else
	{
		
		long long int av = v[v.size() - 1] - v[0];

		int max = 0;
		int num= 0;
		max = BinarySearch(v, 1, av,k,num);

		std::cout << max;
	}
}