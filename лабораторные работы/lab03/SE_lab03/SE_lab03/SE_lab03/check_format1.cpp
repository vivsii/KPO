#include "stdafx.h"

void check_format1(int day, int year, int month)
{
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
	{
		if ((day > 31) || (day < 1))
		{
			cout << "Please, check the format of data" << endl;
			exit(0);
		}
	}

	else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
	{
		if ((day > 30) || (day < 1))
		{
			cout << "¬ведите дату корректно" << endl;
			exit(0);
		}
	}

	else if (month == 2)
	{
		if ((day > 28) || (day < 1))
		{
			cout << "¬ведите дату корректно" << endl;
			exit(0);
		}
	}

	if ((month > 12) || (month < 1))
	{
		cout << "¬ведите дату корректно" << endl;
		exit(0);
	}
}