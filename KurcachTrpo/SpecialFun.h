#pragma once
#include <iostream>
#include <ctime>
using namespace std;
int generateInt(); //Проверка на числовой ввод
string cinData(); //Проверка на ввод даты
string cinTime();//Проверка на ввод времени 
string cinDestination();//Проверка на ввод места прибытия 
void getData(int& day, int& month, int& year); //Получение текущей даты
string cinAccountData(); //Ввод логина
string cinAccountData_1(); //Ввод пароля
char YesNoQuestion(); //Выбор да или нет
string cinType(); //Ввод типа самолёта
const int YearRange = 5;
string cinAccountData()
{
	int ch;
	string result;
	while (true)
	{
		ch = _getch();
		if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >=
			48 && ch <= 57) || ch == 13 || ch == 8)
		{
			if (ch == 13)
			{
				break;
			}
			else
				if (ch == 8)
				{
					cout << (char)8 << ' ' << char(8);
					if (!result.empty())
						result.erase(result.length() - 1);
				}
				else
				{
					cout << (char)ch;
					result += (char)ch;
				}
		}
	}
	cout << endl;
	return result;
}
52
string cinAccountData_1()
{
	int ch;
	string result;
	while (true)
	{
		ch = _getch();
		if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >=
			48 && ch <= 57) || ch == 13 || ch == 8)
		{
			if (ch == 13)
			{
				break;
			}
			if (ch == 8)
			{
				cout << (char)8 << ' ' << char(8);
				if (!result.empty())
					result.erase(result.length() - 1);
			}
			else
			{
				cout << '*';
				result += (char)ch;
			}
		}
	}
	cout << endl;
	return result;
}
int generateInt()
{
	int a;
	cin >> a;
	while (cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка, введите целое число!" << endl;
		cin >> a;
	}
	return a;
}
string cinData()
{
	string result;
	int tempYear, tempMonth, tempDay, month, year, day;
	bool flag;
	getData(day, month, year);
	do
	{
		cout << "Введите год" << endl;
		tempYear = generateInt();
		system("cls");
		if (tempYear<year || tempYear>year + YearRange) cout << "Неверный
			ввод!Можно вводить в промежутке от " << year << " до " << year + YearRange 
			<< endl;
	} while (tempYear<year || tempYear>year + YearRange);
	do
	{
		cout << "Введите месяц" << endl;
		53
			tempMonth = generateInt();
		system("cls");
		if (tempYear == year && tempMonth < month) cout << "Неверный
			ввод!Нельзя указть прошедшее время!" << endl;
			if (tempMonth > 12 || tempMonth < 1) cout << "Неверный ввод! Та-
				кого месяца нет!" << endl;
	} while ((tempYear == year && tempMonth < month) || tempMonth > 12 ||
		tempMonth < 1);
		do
		{
			flag = false;
			cout << "Введите день" << endl;
			tempDay = generateInt();
			system("cls");
			switch (tempMonth)
			{
			case 1: if (tempDay > 31) { flag = true; break; }
			case 2: if ((tempDay > 29 && tempYear % 4 == 0) || (tempYear % 4
				!= 0 && tempDay > 28)) {
				flag = true; break;
			}
			case 3: if (tempDay > 31) { flag = true; break; }
			case 4: if (tempDay > 30) { flag = true; break; }
			case 5: if (tempDay > 31) { flag = true; break; }
			case 6: if (tempDay > 30) { flag = true; break; }
			case 7: if (tempDay > 31) { flag = true; break; }
			case 8: if (tempDay > 31) { flag = true; break; }
			case 9: if (tempDay > 30) { flag = true; break; }
			case 10: if (tempDay > 31) { flag = true; break; }
			case 11: if (tempDay > 30) { flag = true; break; }
			case 12: if (tempDay > 31) { flag = true; break; }
			}
			if (tempYear == year && tempMonth == month && tempDay < day)cout
				<< "Неверный ввод! Нельзя указть прошедшее время!" << endl;
			if (flag || tempDay < 0) cout << "Такого дня нет!" << endl;
		} while ((tempYear == year && tempMonth == month && tempDay < day) ||
			flag || tempDay < 0);
		if (tempDay < 10) result += '0' + to_string(tempDay) + '.';
		else result += to_string(tempDay) + '.';
		if (tempMonth < 10) result += '0' + to_string(tempMonth) + '.';
		else result += to_string(tempMonth) + '.';
		result += to_string(tempYear);
		return result;
}
string cinTime()
{
	string result;
	int minutes, hours;
	do
	{
		cout << "Введите часы" << endl;
		hours = generateInt();
		system("cls");
		if (hours > 23 || hours < 0) cout << "Неверный ввод!" << endl;
	} while (hours > 23 || hours < 0);
	do
	{
		cout << "Введите минуты" << endl;
		minutes = generateInt();
		system("cls");
		if (minutes > 59 || minutes < 0) cout << "Неверный ввод!" <<
			endl;
	} while (minutes > 59 || minutes < 0);
	if (hours < 10) result += '0';
	result += to_string(hours) + ':';
	54
		if (minutes < 10) result += '0';
	result += to_string(minutes);
	return result;
}
string cinDestination()
{
	string temp, result;
	int ch;
	while (true)
	{
		ch = _getch();
		if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || ch == 13
			|| ch == 8)
		{
			if (ch == 13)
			{
				break;
			}
			if (ch == 8)
			{
				cout << (char)8 << ' ' << char(8);
				if (!temp.empty())
					temp.erase(temp.length() - 1);
			}
			else
			{
				cout << (char)ch;
				temp += (char)ch;
			}
		}
	}
	return temp;
}
void getData(int& day, int& month, int& year)
{
	int now = time(NULL) - (((time(NULL) / 31536000) - 2) / 4) * 86400;
	year = now / 31536000 + 1970;
	int day1 = (now - (year - 1970) * 31536000) / 86400 + 1;
	if (day1 <= 31) { day = day1; month = 1; }
	else
	{
		day1 -= 31;
		if (year % 4 == 0 && day1 <= 29) { day = day1; month = 2; }
		else if (day1 <= 28) { day = day1; month = 2; }
		else
		{
			if (year % 4 == 0) day1 -= 29;
			else day1 -= 28;
			if (day1 <= 31) { day = day1; month = 3; }
			else if (day1 <= 61) { day = day1 - 31; month = 4; }
			else if (day1 <= 91) { day = day1 - 61; month = 5; }
			else if (day1 <= 121) { day = day1 - 91; month = 6; }
			else if (day1 <= 152) { day = day1 - 121; month = 7; }
			else if (day1 <= 183) { day = day1 - 152; month = 8; }
			else if (day1 <= 213) { day = day1 - 183; month = 9; }
			else if (day1 <= 244) { day = day1 - 213; month = 10; }
			else if (day1 <= 274) { day = day1 - 244; month = 11; }
			else { day = day1 - 274; month = 12; }
		}
	}
	55
}
char YesNoQuestion()
{
	char a;
	while (true)
	{
		a = _getch();
		if (a == '1' || a == '2') return a;
	}
}
string cinType()
{
	int ch;
	string result;
	while (true)
	{
		ch = _getch();
		if (ch != 32)
		{
			if (ch == 13)
			{
				break;
			}
			if (ch == 8)
			{
				cout << (char)8 << ' ' << char(8);
				if (!result.empty())
					result.erase(result.length() - 1);
			}
			else
			{
				cout << (char)ch;
				result += (char)ch;
			}
		}
	}
	cout << endl;
	return result;
}