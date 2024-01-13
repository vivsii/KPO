#include <iostream>
#include <locale>
#include "Windows.h"
#include "D:\уник\кпо\лабораторные работы\lab6\SE_Lab07L\SE_Lab07L\Dictionary.h"
#pragma comment(lib, "D:\\уник\\кпо\\лабораторные работы\\lab6\\SE_Lab07L\\Debug\\SE_Lab07L.lib")

using namespace Dictionary;
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		Instance d11 = Create("Преподаватели", 7);
		Entry e11 = { 1,"Шиман" }, //элементы словаря
			e12 = { 2,"Белодед" },
			e13 = { 3,"Смелов" },
			e14 = { 4,"Наркевич" },
			e15 = { 5,"Пацей" },
			e16 = { 6,"Чайковский" },
			e17 = { 7,"Жиляк" };
		addEntry(d11, e11);
		addEntry(d11, e12);
		addEntry(d11, e13);
		addEntry(d11, e14);
		addEntry(d11, e15);
		addEntry(d11, e16);
		addEntry(d11, e17);
		Print(d11);
		//-------------------------------------------
		Instance d22 = Create("Студенты", 7);
		Entry e01 = { 1,"Пузырева" },
			e02 = { 2,"Труханович" },
			e03 = { 3,"Глушко" },
			e04 = { 4,"Евсеенко" },
			e05 = { 5,"Кантарович" },
			e06 = { 6,"Кивлинас" },
			e07 = { 7,"Сосновец" };
		addEntry(d22, e01);
		addEntry(d22, e02);
		addEntry(d22, e03);
		addEntry(d22, e04);
		addEntry(d22, e05);
		addEntry(d22, e06);
		addEntry(d22, e07);
		Print(d22);
		Delete(d11);
		Delete(d22);
	}


	catch (const char* e)
	{
		cout << e << endl;
	}

}
