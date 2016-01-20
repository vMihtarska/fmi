//Василка Михтарска фн:45053 1 група
#include <iostream> 
#include <cstring>
using namespace std;
const int Max_Size_words = 16;
const int Max_Size_Char = 60;

int main()
{


	int n;
	cout << "N=";
	do
	{
		cin >> n;
	} while (n < 1);
	char arr[100][16];
	for (int i = 0; i < n; i++){

		{
			cin.clear();
			cin.sync();
			cout << "Enter word:" << endl;
			cin.getline(arr[i], 17);
		}
	}
	
	char arr2[100];
	cout << "Enter a sentence:"<<endl;
	cin.getline(arr2, 100);
	
	int count3 = 0;
	char arr3[100];
	int size = strlen(arr2);
	arr2[size + 1] = ' ';
	arr2[size + 2] = '\0';
	cout << "The oposite words are:";
	for (int count2 = 0; count2 <= size+1;)
	{
		
		if (arr2[count2] != ' '&&arr[count2]!='\0')
		{
			arr3[count3] = arr2[count2];
			count2++;
			count3++;
		}
		else
		{
			arr3[count3] = '\0';

			
			for (int i = 0; i <= n; i++)
			{
				if (strcmp(arr3, arr[i]) == 0)
				{
					

					int length = strlen(arr3);

					//cout << length << endl;
					char* word_opposite = new char[length+1];
					count3 = 0;
					for (int j = length-1; j >= 0; j--)
					{
						
						word_opposite[count3] = arr3[j];
						count3++; 
					}
					word_opposite[count3] = '\0';
					cout << word_opposite << endl;
					delete[] word_opposite;
				}
			}
			count2++;
			arr3[0] = '\0';
			count3 = 0;
		}
	} 
	


	return 0;

}