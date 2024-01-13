#include <iostream>
//параметры_квартиры: метраж, количество жилых комнат, год постройки, этаж,
// наличие(да / нет) : кухни, ванны, туалета, подвала, балкона

using namespace std;

typedef unsigned int metr;
typedef unsigned int kolvo;
typedef unsigned int year;
typedef unsigned int floar;
typedef unsigned int kitchen;
typedef unsigned int bath;
typedef unsigned int toilet;
typedef unsigned int celler;
typedef unsigned int porch;

struct flat
{
	metr m;
	kolvo k;
	year y;
	floar f;
	kitchen ki;
	bath b;
	toilet t;
	celler c;
	porch p;
};

bool operator ==(flat f1, flat f2)
{
	return (f1.k == f2.k);
}

bool operator >(flat f1, flat f2)
{
	return (f1.m > f2.m);
}

int main()
{
	setlocale(LC_ALL, "rus");

	flat f1 = { 66, 3, 2010, 3, 1, 1, 1, 0, 1 };
	flat f2 = { 87, 3, 2022, 14, 1, 1, 1, 1, 1 };

	if (f1 == f2)
	{
		cout << "f1 и f2 равны, тк имеют одинаковое кол-во комнат\n";
	}
	else
	{
		cout << "f1 и f2 разное кол-во комнат\n";
	}
	if (f1 > f2)
	{
		cout << "метраж f1 больше f2\n";
	}
	else
	{
		cout << "метраж f1 не больше f2\n";
	}

	return 0;
}