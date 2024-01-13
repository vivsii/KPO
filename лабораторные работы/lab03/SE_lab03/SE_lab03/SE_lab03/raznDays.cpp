#include "stdafx.h"

int razndays()
{
	string date1;
	int datearr1[3];
	char yr1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cout << "Введите первую дату";
	cin >> date1;

	bool format_check1 = true;
	format_check1 = check_format01(date1, format_check1);

	if (format_check1 == false)
	{
		cout << "Введите дату корректно" << endl;
		exit(0);
	}

	find_substr(date1, datearr1);
	int yearnow1 = datearr1[0];
	int monthnow1 = datearr1[1];
	int daynow1 = datearr1[2];
	check_format1(daynow1, yearnow1, monthnow1);

	cout << "Название месяца: " << month_define(monthnow1) << endl;


	bool is_leap = if_leap_year(yearnow1);

	if (is_leap == true)
	{
		cout << "Високосный год" << endl;
		yr1[1] += 1;
	}

	else
	{
		cout << "Не високосный год" << endl;
	}
	int sequent_number1 = 0;
	sequent_number1 = sequent_numb(daynow1, yearnow1, monthnow1, yr1, sequent_number1);

	cout << "Порядковый номер:  " << sequent_number1 << endl;



	string date2;
	int datearr2[3];
	char yr2[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cout << "Введите вторую дату ";
	cin >> date2;

	bool format_check2 = true;
	format_check2 = check_format01(date2, format_check2);

	if (format_check2 == false)
	{
		cout << "Введите дату корректно" << endl;
		exit(0);
	}

	find_substr(date2, datearr2);
	int yearnow2 = datearr2[0];
	int monthnow2 = datearr2[1];
	int daynow2 = datearr2[2];
	check_format1(daynow2, yearnow2, monthnow2);

	cout << "Название месяца " << month_define(monthnow2) << endl;


	bool is_leap2 = if_leap_year(yearnow2);

	if (is_leap2 == true)
	{
		cout << "Високосный год" << endl;
		yr2[1] += 1;
	}

	else
	{
		cout << "Не високосный год" << endl;
	}
	int sequent_number2 = 0;
	sequent_number2 = sequent_numb(daynow2, yearnow2, monthnow2, yr2, sequent_number2);

	cout << "Порядковый номер " << sequent_number2 << endl;


	int razn = 0;
	if (yearnow1 == yearnow2)
	{
		razn = abs(sequent_number2 - sequent_number1);
	}
	else
	{
		int razn1 = abs(yearnow1 - yearnow2) * 365;
		razn = abs(sequent_number2 - sequent_number1) + razn1;

	}

	return razn;
}