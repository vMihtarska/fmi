//Василка Михтарска Фак.номер:45053 1група
#include <iostream>
#include <fstream>
#include <cstring>

const int sizeOfcar = 4;
const int sizeOfname = 23;
struct Person
{
	char name[sizeOfname];
	short IdentNumber;
	unsigned int RegNumber;
};
struct Car
{
	char* name;
	int power;
};
int IsRepeatReg(int n);
void Add(const char * p)
{
	std::fstream file(p, std::ios::out | std::ios::binary | std::ios::app);
	if (!file)
	{
		std::cout << "File cannot open for writing";
		return;
	}
	int numberOfpeople;
	std::cout << "Add a new report." << std::endl;
	do{
		std::cin.clear();
		std::cin.sync();
		std::cout << "Number of people(positive number):";
		std::cin >> numberOfpeople;

	} while (numberOfpeople <= 0);
	Person *arr1 = new Person[numberOfpeople];

	for (int i = 0; i < numberOfpeople; i++)
	{
		std::cout << "Person:" << i+1 << std::endl;
		std::cout << "Name: ";
		std::cin.clear();
		std::cin.sync();
		std::cin.getline(arr1[i].name, sizeOfname);
		do
		{
			std::cin.clear();
			std::cin.sync();
			std::cout << "0-Lambordgini Murcielago" << std::endl;
			std::cout << "1-Mercedes-AMG" << std::endl;
			std::cout << "2-Pagani Zonda R" << std::endl;
			std::cout << "3-Bugatti Veyron" << std::endl;
			std::cout << "Identification number: (0,1,2,3) ";
			std::cin >> arr1[i].IdentNumber;
		} while (arr1[i].IdentNumber<0 || arr1[i].IdentNumber>3);
		do
		{
			std::cin.clear();
			std::cin.sync();
			std::cout << "Registration number:(xxxx) ";
			std::cin >> arr1[i].RegNumber;
		} while (arr1[i].RegNumber > 10000 || arr1[i].RegNumber < 0);
		for (int j = 0; j < i; j++)
		{
			if ((arr1[i].RegNumber == arr1[j].RegNumber) || IsRepeatReg(arr1[i].RegNumber))
			{
				arr1[i].RegNumber = 0;
				std::cout <<std::endl<< "This registration number exist!" << std::endl;
			}
		}
	}

	for (int k = 0; k < numberOfpeople; k++)
	{
		if (arr1[k].RegNumber != 0)
			file.write((const char*)&arr1[k], sizeof(Person));
		if (!file)
		{
			std::cout << "Cannot write in this file bin" << std::endl;
		}
	}
	file.close();
	delete[] arr1;
}
int IsRepeatReg(int n)
{
	std::fstream infile("db-save.dat", std::ios::in | std::ios::binary);
	if (!infile)
	{
		std::cout << "Cannot read this file";
		return 1;
	}
	Person buff1;
	int i = 0;
	infile.seekg(0, std::ios::end);
	int size = infile.tellg() / sizeof(Person);
	int *regNum = new int[size];
	infile.seekg(0, std::ios::beg);
	while (infile)
	{
		infile.read((char*)&buff1, sizeof(Person));
		if (!infile)
			break;
		regNum[i] = buff1.RegNumber;
		if (regNum[i] == n)
			return 1;
		i++;
	}
	infile.close();
	return 0;
}
void ClearFile(const char * binfile,const char* textfile)
{
	std::fstream file(binfile, std::ios::out | std::ios::binary | std::ios::trunc);
	if (!file)
	{
		return;
	}
	file.seekp(0, std::ios::beg);
	std::ofstream file2(textfile, std::ios::out | std::ios::trunc);
	if (!file2)
	{
		return;
	}
	file2.seekp(0,std::ios::beg);
	file.close();
	file2.close();
	std::cout << "Reports are deleted." << std::endl;
	std::cout << std::endl;
}
void FamousCar(const char * in, Car cars[sizeOfcar])
{
	std::fstream infile(in, std::ios::in | std::ios::binary);
	if (!infile)
	{
		std::cout << "Cannot read this file";
		return;
	}
	std::ofstream outfile("car-report.txt", std::ios::out | std::ios::trunc);
	if (!outfile)
	{
		std::cout << "Cannot write in this file";
		return;
	}

	infile.seekg(0, std::ios::end);
	int size = infile.tellg() / sizeof(Person);
	int *IdNum = new int[size];
	char **Names = new char*[size];
	int *Powers = new int[size];
	
	for (int j = 0; j < size; j++)
	{
		Names[j] = new char[sizeOfname];
		if (!Names)
		{
			std::cout << "no memory";
			return;
		}
	}
	
	Person buff;
	bool bff = false;
	infile.seekg(0, std::ios::beg);
	int i = 0;
	int m = 0;
	bool isRepeat = false;
	while (infile)
	{
		infile.read((char*)&buff, sizeof(Person));

		if (!infile)
			break;
		bff = true;
		isRepeat = false;
		IdNum[i] = buff.IdentNumber;
		for (int j = 0; j < m; j++)
		{
			if (!strcmp(buff.name, Names[j]))
			{
				Powers[j] += cars[buff.IdentNumber].power;
				isRepeat = true;
			}
			
		}
		if (!isRepeat)
		{
			strcpy(Names[m], buff.name);
			Powers[m] = cars[buff.IdentNumber].power;
			m++;
		}
		i++;
	} 
	if (bff)
	{
		std::cout << std::endl;
		int count = 0;
		int maxcount = 0;
		int index = 0;
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < i; k++)
			{
				if (IdNum[k] == j)
				{
					count++;
				}
			}
			if (maxcount < count)
			{
				maxcount = count;
				index = j;
			}
			count = 0;
		}
		int sum = 0;
		for (int k = 0; k < i; k++)
		{
			sum += cars[IdNum[k]].power;

		}
		sum /= i;
		outfile << "---------------------------------------------------------------" << std::endl;
		outfile << "The most famous car is: " << cars[index].name << std::endl;
		outfile << "-------------------------------------------" << std::endl;
		outfile << "Average power of all cars is : " << sum << std::endl;

		for (int i = 0; i < m; i++)
		{
			outfile << "-------------------------------------------" << std::endl;
			outfile << "Name: " << Names[i] << std::endl << "Power of his cars: " << Powers[i] << std::endl;
		}
		outfile << "---------------------------------------------------------------" << std::endl;


		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "The most famous car is: " << cars[index].name << std::endl;

		std::cout << "Average power of all cars is : " << sum << std::endl;

		for (int i = 0; i < m; i++)
		{
			std::cout << "Name: " << Names[i] << std::endl << "Power of his/her cars: " << Powers[i] << std::endl;
		}
		std::cout << "-----------------------------------------------" << std::endl;
	}
	infile.close();
	outfile.close();
	delete[] Powers;
	delete[] IdNum;
	for (int j = 0; j < size; j++)
		delete[] Names[j];
	delete[] Names;
}



int main()
{


	Car arr[sizeOfcar];
	arr[0] = { "Lambordgini Murcielago", 670 };
	arr[1] = { "Mercedes-AMG", 503 };
	arr[2] = { "Pagani Zonda R", 740 };
	arr[3] = { "Bugatti Veyron", 1020 };
	
	
	

	int n;
	do{
		std::cout << "Select an option:" << std::endl
			<< "1.Add a new report." << std::endl
			<< "2.Delete reports." << std::endl
			<< "3.The most famous car and people's cars power." << std::endl
			<< "4.Exit." << std::endl;
		std::cin >> n;
		switch (n)
		{
		case 1: Add("db-save.dat"); break;
		case 2: ClearFile("db-save.dat", "car-report.txt"); break;
		case 3: FamousCar("db-save.dat", arr); break;
		}
	} while (n != 4);
	return 0;
}