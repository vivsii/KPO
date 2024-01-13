#include"stdafx.h"
string month_define(int month);

void GetHolidayDate(char yr[])
{
    int holidayNumber = 256;
    int holiMounth = 1;
    for (int i = 0; holidayNumber > yr[i]; i++)
    {
        holidayNumber = holidayNumber - yr[i];
        holiMounth++;
    }

    cout << "День программиста: " << holidayNumber << " " << month_define(holiMounth) << endl;

}