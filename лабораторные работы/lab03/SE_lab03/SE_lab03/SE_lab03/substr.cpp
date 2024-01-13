#include "stdafx.h"
int* find_substr(string date, int datearr[])
{
	string year, month, day;
	year = date.substr(4, 4);
	datearr[0] = stoi(year);
	month = date.substr(2, 2);
	datearr[1] = stoi(month);
	day = date.substr(0, 2);
	datearr[2] = stoi(day);

	return datearr;
}