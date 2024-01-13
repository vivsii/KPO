#include <iostream>
#include <string>

using namespace std;

//прототипы функций
void LeapYear();
void CountDay();

//глобальные переменные
int day1, month1, year1, months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, leapmonths[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int counting;

int main()
{
	//вот старт
start:

	setlocale(LC_ALL, "Ru");
	string date, day, month, year, Birth, BirthDay, BirthMonth, BirthYear;
	//инициализируем глобальные переменные
	extern int day1, month1, year1, counting, months[12], leapmonths[12];
	int BirthDay1, BirthMonth1, BirthYear1, counting1, counting2, N(0), i(0);

	cout << "Введите дату: ";
	cin >> date;

	if (size(date) != 8)
	{
		cout << "\tВведите дату корректно" << endl;
		//если количество цифр неправильно то переходим на старт он выше
		goto start;

	}
	else
	{
		//если все правильно то переходим на exit
		goto exit;
	}
	//вот exit
exit:
	//присваиваем переменной две первые цифры
	day = date.substr(0, 2);
	//присваиваем эти цифры только уже приобразованные в целочисленное значение
	day1 = stoi(day);
	cout << day << ".";
	month = date.substr(2, 2); // вторые дфе цифры
	month1 = stoi(month);
	cout << month << ".";
	year = date.substr(4, 8); // последние четыре цифры
	year1 = stoi(year);
	cout << year << endl;

	//объявляем функции
	LeapYear();
	CountDay();

	cout << "Введите когда у вас день рождения ";
	cin >> Birth;

	// то же самое что и с предыдущей датой только дата др
	BirthDay = Birth.substr(0, 2);
	BirthDay1 = stoi(BirthDay);
	cout << BirthDay << ".";
	BirthMonth = Birth.substr(2, 2);
	BirthMonth1 = stoi(BirthMonth);
	cout << BirthMonth << ".";
	BirthYear = Birth.substr(4, 8);
	BirthYear1 = stoi(BirthYear);
	cout << BirthYear << endl;

	//проверяем високосный или не високосный 
	if (year1 % 4 == 0)
	{
		// пока номер месяца не будет равен числу счетчика будет работать цикл
		while (i != BirthMonth1 - 1)
		{
			// плюсуются дни, что в массиве до нашего месяца
			N += leapmonths[i];
			i++;
		}
	}
	else
	{
		// то же самое только с не високосным годом
		while (i != BirthMonth1 - 1)
		{
			N += months[i];
			i++;
		}
	}
	// порядковый номер это сумма дней что было дальше + дни в нашем месяце
	counting1 = N + BirthDay1;
	cout << "\tПорядковый новер дня в году : " << counting1 << endl;
	
	// снова високосный или нет
	if (year1 % 4 == 0)
	{
		// если др еще не было 
		if (BirthMonth1 > month1)
		{
			// порядковый номер др минус порядковый номер нашего дня
			counting2 = counting1 - counting;
			cout << "Дней до вашего дня рождения осталось: " << counting2 << endl;
		}
		// если др уже был
		else if (BirthMonth1 < month1)
		{
			//колво дней в году + разница между порядковыми номерами
			counting2 = 366 + counting1 - counting;
			cout << "Дней до вашего дня рождения осталось: " << counting2 << endl;
		}
		else if (BirthMonth1 = month1)
		{
			//колво дней в году + разница между порядковыми номерами
			counting2 = 366 + counting1 - counting;
			cout << "Дней до вашего дня рождения осталось: " << counting2 << endl;
		}
	}
	// не високосный год
	else
	{
		// если др еще не было 
		if (BirthMonth1 > month1)
		{
			// порядковый номер др минус порядковый номер нашего дня
			counting2 = counting1 - counting;
			cout << "Дней до вашего дня рождения осталось: " << counting2 << endl;
		}
		// если др уже был
		else if (BirthMonth1 < month1)
		{
			//колво дней в году + разница между порядковыми номерами
			counting2 = 365 + counting1 - counting;
			cout << "Дней до вашего дня рождения осталось: " << counting2 << endl;
		}
		else if(BirthMonth1 = month1)
		{
			//колво дней в году + разница между порядковыми номерами
			counting2 = 365 + counting1 - counting;
			cout << "Дней до вашего дня рождения осталось: " << counting2 << endl;
		}
	}
	system("pause");
	return 0;
}

//функция проверяет високосный у нас год или нет
void LeapYear()
{
	extern int year1;
	if (year1 % 4 == 0) //целочисленную переменную делим на 4
		cout << "\tГод високосный" << endl;
	else
		cout << "\tГод не високосный" << endl;
}

// функция считает порядковый номер дня в году
void CountDay()
{
	// инициализируем глобальные переменные
	extern int year1, month1, day1, months[12], leapmonths[12], counting;
	// объявляем счетчики
	int N(0), i(0);

	// високосный
	if (year1 % 4 == 0)
	{
		while (i != month1 - 1)
		{
			// плюсуются дни, что в массиве до нашего месяца
			N += leapmonths[i];
			i++;
		}
	}
	//не високосный
	else
	{
		while (i != month1 - 1)
		{
			// плюсуются дни, что в массиве до нашего месяца
			N += months[i];
			i++;
		}
	}
	// порядковый номер это сумма дней что было дальше + дни в нашем месяце
	counting = N + day1;
	cout << "\tПорядковый новер дня в году: " << counting << endl;
}