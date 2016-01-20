//Василка Михтарска 1 група
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int day, month, year, lastday;
	cout << "Day Month Year:  ";
	cin >> day >> month >> year;
	bool leapYear =( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	if (year <= 0 || day <=  0)
	{
		cout << "Invalid date" << endl;
		return 1;
	}
	switch (month)
	{
	case 1:case 4: case 6: case 9: case 11: lastday = 31;
		if (day>30)
		{
			cout << "Invalid date";
			return 1;
		}
		break;
	case 5: case 7: case 8: case 10: case 12: lastday = 30;
		if (day>31)
		{
			cout << "Invalid date";
			return 1;
		}
		break;

	case 3: if (leapYear) lastday = 29;
			else lastday = 28;
	case 2: lastday = 31;
			if (leapYear&&day>29)
			{
				cout << "Invalid date";
				return 1;
			}
			if (!leapYear&&day>28)
			{
				cout << "Invalid date";
				return 1;
			}


			break;
	default: cout << "Invalid date" << endl; return 1;

	}
	if (day == 1)

	if (month == 1)
	{
		day = 31;
		month = 12;
		year--;

	}
	else
	{
		month--;
		day = lastday;
	}

	else day--;
	cout << "Previous day is: ";
	printf("%02d.%02d.%d", day, month, year);

	return 0;

}
