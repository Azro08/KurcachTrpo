#pragma once
#include <iostream>
using namespace std;
void showAllTickets(vector<tickets> a); //Вывод вектора билетов
vector<tickets> showAllTicketsForUser(vector<tickets> a, string login);
//Вывод вектора пользователя
void showAllTypes(vector<typePlanes> a); //Вывод вектора типов
void showAllPlanes(vector<PlaneStruct> a); //Вывод вектора рейсов
89
void viewAccounts(vector<Account> a); //Вывод вектора аккаунтов
void showAllTickets(vector<tickets> a)
{
	for (int i = 0; i < a.size(); i++)
		cout << "№ " << i + 1 << endl
		<< "Пользователь " << a.at(i).login << endl
		<< "Номер рейса " << a.at(i).number << endl
		<< "Место наз-ия " << a.at(i).destination << endl
		<< "Дата вылета " << a.at(i).data << endl
		<< "Тип билета " << a.at(i).ticketType << endl
		<< "Количество " << a.at(i).count << endl << endl;
}
vector<tickets> showAllTicketsForUser(vector<tickets> a, string login)
{
	vector<tickets> temp;
	for (int i = 0; i < a.size(); i++)
	{
		if (login == a.at(i).login) temp.push_back(a.at(i));
	}
	for (int i = 0; i < temp.size(); i++)
		cout << "№ " << i + 1 << endl
		<< "Пользователь " << temp.at(i).login << endl
		<< "Номер рейса " << temp.at(i).number << endl
		<< "Место наз-ия " << temp.at(i).destination << endl
		<< "Дата вылета " << temp.at(i).data << endl
		<< "Тип билета " << temp.at(i).ticketType << endl
		<< "Количество " << temp.at(i).count << endl << endl;
	return temp;
}
void showAllTypes(vector<typePlanes> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << "№ " << i + 1 << endl
			<< "Тип " << a.at(i).type << endl
			<< "Вместимость " << a.at(i).capacity << endl
			<< "Кол-во билетов Б.К. " << a.at(i).buisnes << endl
			<< "Кол-во билетов Э.К. " << a.at(i).econom << endl <<
			endl;
	}
}
void showAllPlanes(vector<PlaneStruct> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << "№ " << i + 1 << endl
			<< "Номер рейса " << a.at(i).number << endl
			<< "Тип самолёта " << a.at(i).type << endl
			<< "Место назначения " << a.at(i).destination << endl
			<< "Дата вылета " << a.at(i).date << endl
			<< "Время вылета " << a.at(i).dep_time << endl
			<< "Время прилёта " << a.at(i).arrival_time << endl
			<< "Вместимость " << a.at(i).capacity << endl
			<< "Кол-во билетов б.к. " << a.at(i).buisnes << endl
			<< "Стоимость б.к. " << a.at(i).buisnes_cost << endl
			<< "Кол-во э.к. " << a.at(i).econom << endl
			<< "Стоимость э.к " << a.at(i).econom_cost << endl <<
			endl << endl;
	}
}
void viewAccounts(vector<Account> a)
{
	90
		for (int i = 0; i < a.size(); i++)
		{
			cout << "Номер " << i + 1 << endl
				<< "Логин " << a.at(i).login << endl
				<< "Роль " << a.at(i).role << endl << endl;
		}
}