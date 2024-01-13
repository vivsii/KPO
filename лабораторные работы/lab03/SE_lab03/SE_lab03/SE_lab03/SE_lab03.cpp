#include "stdafx.h"
int main()
{
	setlocale(LC_ALL, "ru");
	string date;
	int datearr[3];
	char yr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char yrbirth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cout << "Введите дату " << endl;
	cin >> date;

	bool format_check = true;
	format_check = check_format01(date, format_check);

	if (format_check == false)
	{
		cout << "Введите дату корректно" << endl;
		exit(0);
	}

	find_substr(date, datearr);
	int yearnow = datearr[0];
	int monthnow = datearr[1];
	int daynow = datearr[2];
	//check_format1(daynow, yearnow, monthnow);

	cout << "Название месяца: " << month_define(monthnow) << endl;

	bool is_leap = if_leap_year(yearnow);

	if (is_leap == true)
	{
		cout << "Високосный год" << endl;
		yr[1] += 1;
	}

	else
	{
		cout << "Не високосный год" << endl;
	}
	int sequent_number = 0;
	sequent_number = sequent_numb(daynow, yearnow, monthnow, yr, sequent_number);

	cout << "Порядковый номер:  " << sequent_number << endl;
	GetHolidayDate(yr);

	string brthday;
	int brtd[3];

	cout << "Введите дату рождения: " << endl;
	cin >> brthday;

	bool tip1 = true;
	format_check = check_format01(brthday, tip1);

	if (tip1 == false)
	{
		cout << "Введите дату корректно" << endl;
		exit(0);
	}

	find_substr(brthday, brtd);
	int yearbirth = brtd[0];
	int monthbirth = brtd[1];
	int daybirth = brtd[2];
	//check_format1(daybirth, yearbirth, monthbirth);

	int dif = 0;

	dif = get_birthday(monthnow, daynow, monthbirth, daybirth, yearbirth, yr);

	cout << "До вашего дня рождения осталось " << dif << " дней" << endl;


	int razn = 0;
	razn = razndays();



	cout << "Разница между днями " << razn << endl;


	return 0;
}