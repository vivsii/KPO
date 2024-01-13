// в заголовочном файле все наши библиотеки и ссылки на наши функции
#include "stdafx.h"

using namespace std;

int day1, month1, year1, months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, leapmonths[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int counting;

int main()
{
start:

	setlocale(LC_ALL, "Ru");
	string date, day, month, year, Birth, BirthDay, BirthMonth, BirthYear;
	extern int day1, month1, year1, counting, months[12], leapmonths[12];
	int BirthDay1, BirthMonth1, BirthYear1, counting1, counting2, N(0), i(0);

	cout << "Введите дату: ";
	cin >> date;

	if (size(date) != 8)
	{
		cout << "\tВведите дату корректно" << endl;
		goto start;

	}
	else
	{
		goto exit;
	}
exit:

	day = date.substr(0, 2);
	day1 = stoi(day);
	cout << day << ".";
	month = date.substr(2, 2);
	month1 = stoi(month);
	cout << month << ".";
	year = date.substr(4, 8);
	year1 = stoi(year);
	cout << year << endl;

	LeapYear();
	CountDay();

	cout << "Введите когда у вас день рождения ";
	cin >> Birth;

	BirthDay = Birth.substr(0, 2);
	BirthDay1 = stoi(BirthDay);
	cout << BirthDay << ".";
	BirthMonth = Birth.substr(2, 2);
	BirthMonth1 = stoi(BirthMonth);
	cout << BirthMonth << ".";
	BirthYear = Birth.substr(4, 8);
	BirthYear1 = stoi(BirthYear);
	cout << BirthYear << endl;

	if (year1 % 4 == 0)
	{
		while (i != BirthMonth1 - 1)
		{
			N += leapmonths[i];
			i++;
		}
	}
	else
	{
		while (i != BirthMonth1 - 1)
		{
			N += months[i];
			i++;
		}
	}
	counting1 = N + BirthDay1;
	cout << "\tПорядковый новер дня в году : " << counting1 << endl;
	
	if (year1 % 4 == 0)
	{
		if (BirthMonth1 > month1)
		{
			counting2 = counting1 - counting;
			cout << "Дней до вашего дня рождения осталось: " << counting2 << endl;
		}
		else if (BirthMonth1 < month1)
		{
			counting2 = 366 + counting1 - counting;
			cout << "Дней до вашего дня рождения осталось: " << counting2 << endl;
		}
		else if (BirthMonth1 = month1)
		{
			counting2 = 366 + counting1 - counting;
			cout << "Дней до вашего дня рождения осталось: " << counting2 << endl;
		}
	}
	else
	{
		if (BirthMonth1 > month1)
		{
			counting2 = counting1 - counting;
			cout << "Дней до вашего дня рождения осталось: " << counting2 << endl;
		}
		else if (BirthMonth1 < month1)
		{
			counting2 = 365 + counting1 - counting;
			cout << "Дней до вашего дня рождения осталось: " << counting2 << endl;
		}
		else if(BirthMonth1 = month1)
		{
			counting2 = 365 + counting1 - counting;
			cout << "Дней до вашего дня рождения осталось: " << counting2 << endl;
		}
	}
	system("pause");
	return 0;
}