#include "stdafx.h"
string month_define(int month)
{
	string monthes[12] = { "������", "�������", "����", "������", "���", "����", "����", "������","��������", "�������", "������", "�������", };
	return monthes[month - 1];
}