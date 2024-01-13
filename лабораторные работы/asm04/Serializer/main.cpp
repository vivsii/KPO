#include "stdafx.h"


int main()
{
	long l;
	int c;

	cout << "long: ";
	cin >> l;
	cout << "\nunsigned int: ";
	cin >> c;


	Serealizer serealizer(l, c);
	serealizer.SerealizeData();
	system("pause");
}
