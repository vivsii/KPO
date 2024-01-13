#include "stdafx.h" // подключаем библиотеки и std

void LeapYear()
{
	extern int year1;
	if (year1 % 4 == 0)
		cout << "\tГод високосный" << endl;
	else
		cout << "\tГод не високосный" << endl;
}