#include "stdafx.h"

bool check_format01(string date, bool tip)
{
	int counter = 0;
	for (int i = 0; i < date.length(); i++)
	{
		if (isalpha(date[i]))
		{
			tip = false;
			break;
		}

	}

	return tip;

}