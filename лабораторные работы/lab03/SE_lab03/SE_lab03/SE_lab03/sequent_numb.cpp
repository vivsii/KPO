#include "stdafx.h"
int sequent_numb(int day, int year, int month, char yr[], int N)
{
	int count = 0;
	for (int i = 0; i < month - 1; i++)
	{
		count += yr[i];
	}
	N = count + day;

	return N;
}
