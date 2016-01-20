#pragma once
const int MaxSize_Of_Word = 9;
class StringArray
{
private:
	char** words;
	int left, right;
	int size;
public:
	StringArray() :words(nullptr), size(0), left(0), right(0) {};
	StringArray(int n)
	{
		words = new char*[n];
		for (int i = 0; i < n; i++)
			words[i] = new char[MaxSize_Of_Word];
		size = 0;
		left = 0;
		right = n - 1;
	}

	char** getArr()
	{
		return this->words;
	}
	void SetInterval(int left, int right)
	{
		if (left < 0)
			this->left = 0;
		else 
			this->left = left;
		if (right > getSize() - 1)
			this->right = getSize() - 1;
		else
			this->right = right;
		if (this->left > this->right)
		{
			int x = this->left;
			this->left = this->right;
			this->right = x;
		}
	}
	void Add(char* buffer)
	{
		strcpy(words[this->size++], buffer);
	}
	void print() const
	{
		for (int i = 0; i < size; i++)
			std::cout << words[i] << " ";
		std::cout << std::endl;
	}
	int getSize() const
	{
		return this->size;
	}
	int getleft()const
	{
		return left;
	}
	int getright()const
	{
		return right;
	}

	char* getElementAt(int i) const
	{
		return words[i];
	}
	static int sizeOfbuffer(char* buff)
	{
		int count = 0;
		int i = 0;
		while (buff[i] >= 'a'&& buff[i] <= 'z')
		{
			count++;
			i++;
		}
		return count;
	}
	static bool Find(char* word, char* buff)
	{
		for (int i = 0; i < sizeOfbuffer(buff); i++)
			if (word[i] != buff[i])
				return false;

		return true;
	}
	void QUERY(char* buff) const
	{
		if (getSize() == 0)
		{
			std::cout << "There is no words." << std::endl;
			return;
		}

		int count = 0;
		int l = getleft();
		int r = getright();
		int middle = (r - l) / 2;
		
		while (strcmp(getElementAt(l + middle), buff) != 0 && !Find(getElementAt(l + middle), buff) && r!=l)
		{
			if (strcmp(words[l + middle], buff) > 0)
			{
				r = l + middle;
			}
			else
			{
				l += middle;
			}
			middle = (r-l) / 2;
			if (l == r-1)
				break;
		}
	
		for (int i = l; i <= r; i++)
			if (Find(getElementAt(i), buff))
				count++;
		if (count == 0)
			std::cout << "No match!" << std::endl;
		else std::cout<<count<<std::endl;

	}

	~StringArray()
	{
		for (int i = 0; i<size; i++)
			delete[] this->words[i];
		delete[] this->words;
		words = NULL;
	}
};
