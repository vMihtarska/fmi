#include <iostream>
#include <fstream>

class Cookie
{
private:
	char* str[2];
public:
	Cookie ();
	Cookie( char * n[]);
	~Cookie ();

	void setStr(char*p[]);
	const char* getStr1()const;
	const char* getStr2()const;
	void print() const;
	Cookie & operator = (const Cookie&);
	
};
class Jar
{
	Cookie* list;
	size_t numberofcookies;
	size_t capacity;
public:
	Jar();
	Jar(const Jar&);
	~Jar();

	void print() const;
	void AddCookie(const Cookie&);
	void EatCookie();
	
};
Cookie::Cookie()
{
	
	str[0] = NULL;
	str[1] = NULL;
}
Cookie::Cookie( char * n[])
{
	setStr(n);

}
void Cookie::setStr( char* n[])
{
	
	for (int i = 0; i < 2; i++)
	{
	
		int size = strlen(n[i]) + 1;
		str[i] = new char[size];
		strcpy_s(str[i], size, n[i]);
	}
	
	
}
const char* Cookie::getStr1()const
{
	return str[0];
}
const char* Cookie::getStr2()const
{
	return str[1];
}
void Cookie::print() const
{
	for (int i = 0; i < 2; i++)
	{
		std::cout<<str[i];
	}
}
Cookie::~Cookie()
{
	for (int i = 0; i < 2;i++)
	delete[] str[i];

}
Cookie& Cookie::operator=(const Cookie& other)
{
	if (this != &other)
	{
		delete[] str[0];
		str[0] = new char[strlen(other.getStr1()) + 1];
		strcpy(str[0], other.getStr1());

		delete[] str[1];
		str[1] = new char[strlen(other.getStr2()) + 1];
		strcpy(str[1], other.getStr2());
	}
		return *this;
}


Jar::Jar()
{
	capacity = 20;
	numberofcookies = 0;
	list = new Cookie[20];

}

Jar::Jar(const Jar& newDoc):capacity(newDoc.capacity), numberofcookies(newDoc.numberofcookies)
{
        
		this->list = new Cookie[this->capacity];
        for(size_t i = 0; i < numberofcookies; ++i)
        {
                this->list[i] = newDoc.list[i];
        }
}
 
 
Jar::~Jar()
{
        
        delete [] list;
}
 
 
void Jar::AddCookie(const Cookie& p)
{
        if(numberofcookies >= capacity)
        {
                Cookie* buffer = new Cookie[2*capacity];
                for(size_t i = 0; i < numberofcookies; ++i)
                {
                        buffer[i] = list[i];
                }
 
                delete [] list;
                list = buffer;
        }
 
        list[numberofcookies] = p;
        ++numberofcookies;
		std::cout << "You eat a cookie." << std::endl;
		std::cout << "There are " << numberofcookies << " cookies." << std::endl;
}
 
void Jar::EatCookie()
{
	if (numberofcookies == 0)
	{
		std::cout << "Jar is empty!";
		return ;
	}
	else --numberofcookies;

	if (numberofcookies * 2 < capacity)
	{
		
		Cookie*buffer = new Cookie[capacity / 2];
		for (size_t i = 0; i < numberofcookies; ++i)
		{
			buffer[i] = list[i];
		}
		delete[] list;
		list = buffer;
	}
	std::cout << "You put a cookie." << std::endl;
	std::cout << "There are " << numberofcookies << "cookies" << std::endl;
	
} 
void Jar::print()const
{
	for (int i = 0; i < numberofcookies; i++)
		list[i].print();
}






int main()
{
	
	int option;
	Jar cookies;
	do
	{
		std::cout << "Choose an option:" << std::endl
			<< "1.Eat a cookie." << std::endl
			<< "2.Put a cookie." << std::endl
			<< "3.Exit." << std::endl;
		std::cin >> option;
		switch (option)
		{
		case 1:
		{
		
			cookies.EatCookie();
			break;
		}
		case 2:
		{
				  char* string1[2];
				  string1[0] = new char[20];
				  string1[1] = new char[20];
				  std::cin.clear();
				  std::cin.sync();
				  std::cout << "Cookie wiht: (milk,chocolate,...)";
				  std::cin.getline(string1[0], 20);
				  std::cout << "Size of cookie:(small,normal,large)";
				  std::cin.getline(string1[1], 20);
				  Cookie one(string1);

				  cookies.AddCookie(one);
				  break;
		}
			
		}
	} while (option != 3);
	
	return 0;
}
