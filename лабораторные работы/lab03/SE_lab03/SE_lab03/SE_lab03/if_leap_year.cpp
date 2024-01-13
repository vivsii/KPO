#include "stdafx.h"
bool if_leap_year(int year)
{
	return ((year % 4) == 0 && (year % 100 != 0) || (year % 400 == 0));
}
