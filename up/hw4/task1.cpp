
#include <iostream>
using namespace std;
int const size = 1000;
bool LeftToRight(char Table[][size], char words[17], int NumCol, int NumRow, int x, int y)
{
	int count = 0;
	int size = strlen(words);
	bool bul = false;
	for (int i = y, count = 0; i < NumCol&&count < size&&Table[x][i] == words[count]; i++, count++)
	{
		if (count == size-1 ) 
			bul = true;
	}
	return bul;
}
bool RightToLeft(char Table[][size], char words[17], int NumCol, int NumRow, int x, int y)
{
	int count = 0;
	int size = strlen(words);
	bool bul = false;
	for (int i = y, count = 0; i < NumCol&&count < size&&Table[x][i] == words[count]; i--, count++)
	{
		if (count == size - 1)
			bul = true;
	}
	return bul;
}
bool DownToUp(char Table[][size], char words[17], int NumCol, int NumRow, int x, int y)
{
	int count = 0;
	int size = strlen(words);
	bool bul = false;
	for (int i = x, count = 0; i < NumCol&&count < size&&Table[i][y] == words[count]; i++, count++)
	{
		if (count == size - 1)
			bul = true;
	}
	return bul;
}
bool UptoDown(char Table[][size], char words[17], int NumCol, int NumRow, int x, int y)
{
	int count = 0;
	int size = strlen(words);
	bool bul = false;
	for (int i = x, count = 0; i < NumCol&&count < size&&Table[i][y] == words[count]; i--, count++)
	{
		if (count == size - 1)
			bul = true;
	}
	return bul;
}
void FindWords(char Table[][size], char words[17], int NumCol, int NumRow)
{
	
	
	bool isLeftToRight = false;
	bool isRightToLeft = false;
	bool isUptoDown = false;
		bool isDownToUp = false;
		for (int i = 0; i < NumRow; i++)
		{
			for (int j = 0; j < NumCol; j++)
			{
				if (Table[i][j] == words[0])
				{
					if (!isLeftToRight)
						isLeftToRight = LeftToRight(Table, words, NumCol, NumRow, i, j);
					if (!isRightToLeft)
						isRightToLeft = RightToLeft(Table, words, NumCol, NumRow, i, j);
					if (!isUptoDown)
						isUptoDown = UptoDown(Table, words, NumCol, NumRow, i, j);
					if (!isDownToUp)
						isDownToUp = DownToUp(Table, words, NumCol, NumRow, i, j);
				}
			}
		}
		if (isLeftToRight)
			cout << "Yes"<<endl;
		else if (isRightToLeft)
			cout << "Yes"<<endl;
		else
		if (isUptoDown)
			cout << "Yes" << endl;
		else if (isDownToUp)
			cout << "Yes" << endl;
		else cout << "NO" << endl;
}
int main()
{
	char Table[size][size];
	int n, m;
	cout << "n,m="<<endl;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter a word:";
		for (int j = 0; j < m; j++)
			cin >> Table[i][j];
	}
	int t;
	cout << "t=";
	cin >> t;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << Table[i][j] << " ";
		cout << endl;
	}
	
	char words[17];
	cin.clear();
	cin.sync();
	
	for (int i = 0; i < t; i++){

		{
			cin.clear();
			cin.getline(words, 17);
			FindWords(Table, words, m, n);
		}
	}
	
	
}
