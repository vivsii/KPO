#pragma once
#include <iostream>
namespace Varparm 
{

	int ivarparm(int n, ...)
	{
		int* args = &n;
		int prod = 1;
		for (int i = 1; i <= n; ++i) 
		{
			prod *= *(args + i);
		}
		return prod;
	}
	int svarparm(short n, ...) 
	{

		int* values = (int*)(&n) + 1; // указатель на второй параметр
		int maxVal = *(values); // начинаем с первого параметра
		for (int i = 1; i < n; i++) 
		{ // начинаем считать со второго параметра
			if (*(values + i) > maxVal)
			{
				maxVal = *(values + i);
			}
		}
		return maxVal;
	}
	double fvarparm(float n, ...) 
	{
		double* pointer = (double*)(&n + 1);
		double result = n;
		for (int iter = 0; *(pointer + iter) != (double)FLT_MAX; iter++) 
			result += *(pointer + iter);
		return result;
		
	}
	double dvarparm(double n, ...) 
	{
		double* pointer = (&n + 1);
		double result = n;
		for (int iter = 0; *(pointer + iter) != DBL_MAX; iter++)
			result += *(pointer + iter);
		return result;
	}
}

