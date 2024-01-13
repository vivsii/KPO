#include "stdafx.h"
int get_birthday(int  monthnow, int daynow, int monthbirth, int daybirth, int yearbirth, char yr[])
{
	int count1 = 0, count2 = 0;

	for (int i = 0; i < monthnow - 1; i++)
	{
		count1 += yr[i];
	}

	int c1 = count1 + daynow;
	for (int k = 0; k < monthbirth - 1; k++)
	{
		count2 += yr[k];
	}

	int c2 = count2 + daybirth;
	int dif = c2 - c1;

	if (dif > 0)
	{
		return dif;
	}

	if (dif < 0)
	{

		return 365 - abs(dif);
	}

}