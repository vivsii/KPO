#include "stdafx.h"// подключаем библиотеки и std

void CountDay()
{
	extern int year1, month1, day1, months[12], leapmonths[12], counting;
	int N(0), i(0);

	if (year1 % 4 == 0)
	{
		while (i != month1 - 1)
		{
			N += leapmonths[i];
			i++;
		}
	}
	else
	{
		while (i != month1 - 1)
		{
			N += months[i];
			i++;
		}
	}
	counting = N + day1;
	cout << "\tПорядковый новер дня в году: " << counting << endl;
}