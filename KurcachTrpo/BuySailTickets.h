#pragma once
#include <iostream>
#include "show.h"
#include "SortPlanes.h"
using namespace std;
//Закупка билета
vector<tickets> buyTicket_1(vector<tickets> a, vector<PlaneStruct>& b, string
	login, int& balance, int i);
//Присваивание купленых билетов
vector<tickets> buyTickets_2(vector<tickets> a, tickets econom, tickets
	buisnes);
//Продажа конкретного билета
vector<tickets> sailTicket_1(vector<tickets> a, vector<PlaneStruct>& b, vec￾tor<Account>& c, int i);
//Продать все билеты на выбранный рейс
vector<tickets> sailAll(vector<tickets> a, vector<Account>& b, PlaneStruct
	temp, PlaneStruct newtemp);
//Выбор продаваемого билета
int sailTicket(vector<tickets> a, string login);
//Выбор покупаемого билета
int buyTicket(vector<PlaneStruct>& b);
int sailTicket(vector<tickets> a, string login)
{
	char question;
	int i;
	vector<tickets> temp;
	temp = showAllTicketsForUser(a, login);
	if (temp.size() == 0)
	{
		cout << "На данный момент у вас нет билетов!" << endl;
		system("pause");
		return-1;
	}
	cout << "Желаете продать билет?" << endl
		<< "1) Да" << endl << "2) Нет" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '2') return -1;
	do
	{
		showAllTickets(temp);
		cout << "Выберите номер продааемого билета" << endl;
		i = generateInt() - 1;
		system("cls");
		if (i >= temp.size() || i < 0) cout << "Invalid input!" << endl;
	} while (i >= temp.size() || i < 0);
	81
		for (int g = 0; g < a.size(); g++)
			if (temp.at(i).login == a.at(g).login && temp.at(i).number ==
				a.at(g).number && temp.at(i).ticketType == a.at(g).ticketType)
			{
				i = g;
				break;
			}
	return i;
}
vector<tickets> sailTicket_1(vector<tickets> a, vector<PlaneStruct>& b, vec￾tor<Account>& c, int i)
{
	int count;
	int money;
	bool type;
	do
	{
		cout << "Сколько билетов хотите продать? (У вас в наличии " <<
			a.at(i).count << " билетов)" << endl;
		count = generateInt();
		system("cls");
		if (count > a.at(i).count) cout << "У вас нет столки билетов!" <<
			endl;
		if (count < 0) cout << "Invalid input!" << endl;
	} while (count > a.at(i).count || count < 0);
	cout << "Вы уверены, что хотите продать " << count << " билетов?" <<
		endl
		<< "1) Да" << endl << "2) Нет" << endl;
	if (YesNoQuestion() == '2') return a;
	if (a.at(i).ticketType == "эконом-класс") type = true;
	else type = false;
	for (int g = 0; g < b.size(); g++)
	{
		if (b.at(g).number == a.at(i).number)
		{
			if (type)
			{
				money = count * b.at(g).econom_cost;
				b.at(g).econom += count;
			}
			else
			{
				money = count * b.at(g).buisnes_cost;
				b.at(g).buisnes += count;
			}
			break;
		}
	}
	a.at(i).count -= count;
	for (int g = 0; g < c.size(); g++)
		if (a.at(i).login == c.at(g).login)
		{
			c.at(g).money += money;
			break;
		}
	if (a.at(i).count == 0)
	{
		for (i; i < a.size() - 1; i++) a.at(i) = a.at(i + 1);
		a.pop_back();
	}
	saveAccounts(c);
	82
		saveFile(b);
	saveVectorTickets(a);
	return a;
}
vector<tickets> sailAll(vector<tickets> a, vector<Account>& b, PlaneStruct
	temp, PlaneStruct newtemp)
{
	if (temp.buisnes != newtemp.buisnes || temp.econom != newtemp.econom)
		for (int i = 0; i < a.size(); i++)
		{
			if (a.at(i).number == temp.number)
			{
				for (int g = 0; g < b.size(); g++)
				{
					if (b.at(g).login == a.at(i).login)
					{
						if (a.at(i).ticketType == "эконом-класс")
							b.at(g).money += a.at(i).count * temp.econom_cost;
						else b.at(g).money += a.at(i).count *
							temp.buisnes_cost;
						break;
					}
				}
				for (int t = i; t < a.size() - 1; t++) a.at(t) =
					a.at(t + 1);
				i--;
				a.pop_back();
			}
		}
	else
	{
		for (int i = 0; i < a.size(); i++)
		{
			a.at(i).data = newtemp.date;
			a.at(i).number = newtemp.number;
			a.at(i).destination = newtemp.destination;
		}
	}
	saveAccounts(b);
	saveVectorTickets(a);
	return a;
}
vector<tickets> buyTicket_1(vector<tickets> a, vector<PlaneStruct>& b, string
	login, int& balance, int i)
{
	bool flag = true;
	char question;
	PlaneStruct temp = b.at(i);
	tickets temp_buisnes, temp_econom;
	int temp_balance = balance;
	temp_buisnes.data = temp_econom.data = temp.date;
	temp_buisnes.destination = temp_econom.destination = temp.destination;
	temp_buisnes.login = temp_econom.login = login;
	temp_buisnes.number = temp_econom.number = temp.number;
	temp_buisnes.ticketType = "бизнес-класс";
	temp_econom.ticketType = "эконом-класс";
	temp_buisnes.count = temp_econom.count = 0;
	while (flag)
	{
		cout << "Ваш баланс: " << temp_balance << endl << endl
			<< "Эконом-класс - Стоимость билета: " << temp.econom_cost
			<< " рублей Осталось билетов:" << temp.econom << endl
			83
			<< "Бизнес-класс - Стоимость билета: " << temp.buisnes_cost
			<< " рублей Осталось билетов:" << temp.buisnes << endl << endl
			<< "Вы купили: " << temp_econom.count << " билетов эконом-
			класса" << endl
			<< "Вы купили: " << temp_buisnes.count << " билетов биз-
			нес - класса" << endl << endl;
			if (temp.econom == 0) cout << "1) Нет билетов!" << endl;
			else if (temp_balance < temp.econom_cost) cout << "1) Недоста-
				точно средств!" << endl;
			else cout << "1) Купить билет эконом-класса" << endl;
		if (temp.buisnes == 0) cout << "2) Нет билетов!" << endl;
		else if (temp_balance < temp.buisnes_cost) cout << "2) Недоста-
			точно средств!" << endl;
		else cout << "2) Купить билет бизнес-класса" << endl;
		if (temp_econom.count == 0) cout << "3) У вас нет билетов эконом-
			класса!" << endl;
		else cout << "3) Продать билет эконом-класса" << endl;
		if (temp_buisnes.count == 0) cout << "4) У вас нет билетов биз-
			нес - класса!" << endl;
		else cout << "4) Продать билет бизнес-класса" << endl;
		cout << "5) Завершить покупку" << endl;
		question = _getch();
		system("cls");
		switch (question)
		{
		case '1':
		{
			if (temp.econom == 0 || temp_balance < temp.econom_cost)
				break;
			else
			{
				temp_balance -= temp.econom_cost;
				temp.econom -= 1;
				temp_econom.count += 1;
				break;
			}
		}
		case '2':
		{
			if (temp.buisnes == 0 || temp_balance < temp.buisnes_cost)
				break;
			else
			{
				temp_balance -= temp.buisnes_cost;
				temp.buisnes -= 1;
				temp_buisnes.count += 1;
				break;
			}
		}
		case '3':
		{
			if (temp_econom.count == 0) break;
			else
			{
				temp_balance += temp.econom_cost;
				temp.econom += 1;
				temp_econom.count -= 1;
				break;
			}
		}
		84
		case '4':
		{
			if (temp_buisnes.count == 0) break;
			else
			{
				temp_balance += temp.buisnes_cost;
				temp.buisnes += 1;
				temp_buisnes.count -= 1;
				break;
			}
		}
		case '5':
		{
			flag = false;
			break;
		}
		}
	}
	cout << "Совершить покупку?" << endl
		<< "1) Да" << endl << "2) Нет" << endl;
	question = YesNoQuestion();
	if (question == '1')
	{
		a = buyTickets_2(a, temp_econom, temp_buisnes);
		balance = temp_balance;
		b.at(i) = temp;
		saveFile(b);
		return a;
	}
	else return a;
}
vector<tickets> buyTickets_2(vector<tickets> a, tickets econom, tickets
	buisnes)
{
	bool flag1, flag2;
	flag1 = flag2 = true;
	for (int i = 0; i < a.size(); i++)
	{
		if (a.at(i).login == econom.login && a.at(i).ticketType ==
			econom.ticketType && a.at(i).number == econom.number && flag1)
		{
			a.at(i).count += econom.count;
			flag1 = false;
		}
		if (a.at(i).login == buisnes.login && a.at(i).ticketType ==
			buisnes.ticketType && a.at(i).number == buisnes.number && flag2)
		{
			a.at(i).count += buisnes.count;
			flag2 = false;
		}
		if (!flag1 && !flag2) break;
	}
	if (flag1 && econom.count != 0) a.push_back(econom);
	if (flag2 && buisnes.count != 0) a.push_back(buisnes);
	saveVectorTickets(a);
	return a;
}
int buyTicket(vector<PlaneStruct>& b)
{
	char question;
	int i;
	b = sortPlanes(b);
	cout << "Желаете купить билет?" << endl
		85
		<< "1) Да" << endl << "2) Нет" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '2') return -1;
	while (true)
	{
		showAllPlanes(b);
		cout << "Выберите желаемый билет" << endl;
		i = generateInt() - 1;
		system("cls");
		if (i < 0 || i >= b.size()) cout << "Invalid input!" << endl;
		else return i;
	}
}