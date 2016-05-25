#include<iostream>
#include<algorithm>
#include<string>


int main()
{
	std::cin.sync_with_stdio(0);

	int n;
	std::cin >> n;

	std::string* strs = new std::string[n];

	char w[51];

	for (int i = 0; i < n; i++)
	{
		std::cin >> w;
		strs[i] = w;
	}

	
	int minsize = 0;
	bool b = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			b = true;
			if (strs[i].size() != strs[j].size())
			{
				minsize = strs[i].size() < strs[j].size() ? strs[i].size() + 1 : strs[j].size() + 1;
				for (int k = 0; k < minsize - 1; k++)
				{
					if (strs[i].at(k) > strs[j].at(k))
					{
						std::swap(strs[i], strs[j]);
						b = false;
						break;
					}
					else if (strs[i].at(k) < strs[j].at(k))
					{
						b = false;
						break;
					}
					
				}
				if (b)
				{
					int m = 0;
					int m1 = minsize - 1;
					if (strs[i].size() == minsize - 1)
					{
						m = strs[j].size() - minsize + 1;
						for (int x = 0,y=0; x < m && y<m1; x++,y++)
						{
							if (strs[j].at(minsize - 1 + x) < strs[i].at(y))
							{
								std::swap(strs[i], strs[j]);
								break;
							}
							else if (strs[j].at(minsize - 1 + x) == strs[i].at(y))
							{
								if (x == m - 1)
								{
									std::swap(strs[i], strs[j]);
									break;
								}
								continue;
							}
							else
							{
								break;
							}
						}
					}
					else
					{
						int m1 = minsize - 1;
						m = strs[i].size() - minsize + 1;
						for (int x = 0,y=0; x < m && y<m1; x++,y++)
							if (strs[i].at(minsize - 1 + x) > strs[j].at(y))
							{
								std::swap(strs[i], strs[j]);
								break;
							}
							else if (strs[i].at(minsize - 1 + x) == strs[j].at(y))
							{
								if (x == m - 1)
								{
									std::swap(strs[i], strs[j]);
									break;
								}
								continue;
							}
							else
							{
								break;
							}
					}
				}
			}
			else
			{
				if (strs[i] > strs[j])
				{
					std::swap(strs[i], strs[j]);
				}

			}
		}
	}
	
	for (int i = 0; i < n; i++)
		std::cout << strs[i];

	std::cout << "\n";
}