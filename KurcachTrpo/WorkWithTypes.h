#pragma once
#include "iostream"
#include "show.h"
using namespace std;
vector<Account> changeAccount(vector<Account> a, int& user); //Изменить дан-
ные об аккаунтах
vector<Account> createNewAccount(vector<Account> a); //Создать аккаунт
int inAccount(vector<Account> a); //Вход в аккаунт
vector <Account> changePassowrd(vector<Account> a, int user); //Изменить па-
роль
vector<Account> changeRole(vector<Account> a);//Выбор индекса аккаунта для
изменения роли
vector<Account> changeRole_1(vector<Account> a, int i); //Изменение роли ак-
каунта
vector<Account> deleteAccount_1(vector<Account> a, int i, int& user);
//Удаление выбранного аккаунта
56
vector<Account> deleteAccount(vector<Account> a, int& user);//Выбор аккаунта
для удаления
vector<Account> addBalance(vector<Account> a, int user);//Пополнение баланса
vector<Account> changeAccount(vector<Account> a, int& user)
{
	char question;
	while (true)
	{
		cout << "1) Изменить роль" << endl
			<< "2) Удалить аккаунт" << endl
			<< "3) Показать все аккаунты" << endl
			<< "0) Выйти" << endl;
		question = _getch();
		system("cls");
		switch (question)
		{
		case '1':
		{
			a = changeRole(a);
			break;
		}
		case '2':
		{
			a = deleteAccount(a, user);
			break;
		}
		case '3':
		{
			viewAccounts(a);
			system("pause");
			break;
		}
		case '0': return a;
		default: cout << "Invalid input!" << endl;
		}
		system("cls");
	}
}
int inAccount(vector<Account> a)
{
	char question, ch;
	int i;
	while (true)
	{
		cout << "Добро пожаловать!" << endl
			<< "1) Войти в аккаунт" << endl
			<< "2) Создать новый аккаунт" << endl
			<< "3) Выйти" << endl;
		question = _getch();
		system("cls");
		if (question == '1')
		{
			string login, password;
			bool flag = false;
			do
			{
				system("cls");
				cout << "Введите логин." << endl;
				login = cinAccountData();
				system("cls");
				57
					cout << "Введите пароль" << endl;
				password = cinAccountData_1();
				system("cls");
				password = sha1(password);
				for (i = 0; i < a.size(); i++)
					if (login == a.at(i).login && password ==
						a.at(i).password)
					{
						flag = true;
						return i;
					}
				if (!flag)
				{
					cout << "Неверный логин или пароль!" << endl
						<< "Повторить воод?" << endl
						<< "1) Повторить" << endl << "2) Выйти"
						<< endl;
					question = YesNoQuestion();
					system("cls");
					if (question == '2') exit(0);
				}
			} while (!flag);
		}
		else
			if (question == '2') return -2;
			else if (question == '3') exit(0);
			else
			{
				system("cls");
				cout << "Invalid input!" << endl;
			}
	}
}
vector<Account> createNewAccount(vector<Account> a)
{
	Account newUser;
	bool flag;
	do
	{
		flag = false;
		cout << "Введите логин!" << endl;
		newUser.login = cinAccountData();
		for (int t = 0; t < a.size(); t++)
		{
			if (newUser.login == a.at(t).login)
			{
				flag = true;
				system("cls");
				cout << endl << "Такой аккаунт уже существует, вве-
					дите другой!" << endl;
					break;
			}
		}
	} while (flag);
	cout << endl << "Введите пароль!" << endl;
	newUser.password = cinAccountData();
	newUser.password = sha1(newUser.password);
	char quest;
	cout << endl;
	cout << "Вы действительно хотите создать аккаунт?" << endl
		<< "1) да" << endl
		58
		<< "2) нет" << endl;
	quest = YesNoQuestion();
	if (quest == '2') return a;
	newUser.money = 0;
	newUser.role = 0;
	a.push_back(newUser);
	saveAccounts(a);
	return a;
}
vector<Account> changeRole(vector<Account> a)
{
	char question;
	int i;
	viewAccounts(a);
	cout << "Желаете изменить роль?" << endl
		<< "1) Да" << endl << "2) Нет" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '2') return a;
	while (true)
	{
		viewAccounts(a);
		cout << "Введите номер изменяемого аккаунта." << endl;
		i = generateInt() - 1;
		system("cls");
		if (i < 0 || i >= a.size()) cout << "Invalid input!" << endl;
		else if (a.at(i).role == 2) cout << "Вы не можете изменить роль 
			этого аккаунта!" << endl;
		else
		{
			a = changeRole_1(a, i);
			return a;
		}
	}
}
vector<Account> changeRole_1(vector<Account> a, int i)
{
	char question;
	if (a.at(i).role == 0)
	{
		cout << "Изменить роль " << a.at(i).login << " на админа?" <<
			endl
			<< "1) Да" << endl << "2) Нет" << endl;
		question = YesNoQuestion();
		system("cls");
		if (question == '1')
		{
			a.at(i).role = 1;
			saveAccounts(a);
			return a;
		}
		else return a;
	}
	else
	{
		cout << "Изменить роль " << a.at(i).login << " на пользователя?"
			<< endl
			<< "1) Да" << endl << "2) Нет" << endl;
		question = YesNoQuestion();
		system("cls");
		if (question == '1')
		{
			a.at(i).role = 0;
			59
				saveAccounts(a);
			return a;
		}
		else return a;
	}
}
vector <Account> changePassowrd(vector<Account> a, int user)
{
	char question;
	string password;
	cout << "Вы хотите изменить пароль?" << endl <<
		"1) Да" << endl << "2) Нет" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '2') return a;
	while (true)
	{
		cout << "Введите старый пароль" << endl;
		password = cinAccountData_1();
		password = sha1(password);
		system("cls");
		if (password == a.at(user).password) break;
		else
		{
			cout << "Пароль неверный! Повторить ввод?" << endl
				<< "1) Да" << endl << "2) Нет" << endl;
			question = YesNoQuestion();
			system("cls");
			if (question == '2') return a;
		}
	}
	cout << "Введите новый пароль" << endl;
	password = cinAccountData();
	password = sha1(password);
	cout << "Изменить пароль?" << endl
		<< "1) Да" << endl << "2) Нет" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '1')
	{
		a.at(user).password = password;
		saveAccounts(a);
		return a;
	}
	else return a;
}
vector<Account> deleteAccount(vector<Account> a, int& user)
{
	char question;
	int i;
	viewAccounts(a);
	cout << "Желаете удалить аккаунт?" << endl
		<< "1) Да" << endl << "2) Нет" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '2')return a;
	while (true)
	{
		viewAccounts(a);
		cout << "Какой аккаунт удалить?" << endl;
		i = generateInt() - 1;
		system("cls");
		if (i < 0 || i >= a.size())
			60
		{
			cout << "Invalid input!" << endl;
		}
		else if (a.at(i).role == 2) cout << "Вы не можете удалить этот 
			аккаунт!" << endl;
		else
		{
			a = deleteAccount_1(a, i, user);
			return a;
		}
	}
}
vector<Account> deleteAccount_1(vector<Account> a, int i, int& user)
{
	char question;
	cout << "Номер " << i + 1 << endl
		<< "Логин " << a.at(i).login << endl
		<< "Роль " << a.at(i).role << endl
		<< "Удалить?" << endl
		<< "1) Да" << endl << "2) Нет" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '2') return a;
	string temp = a.at(user).login;
	for (i; i + 1 < a.size(); i++) a.at(i) = a.at(i + 1);
	a.pop_back();
	saveAccounts(a);
	for (i = 0; i < a.size(); i++) if (a.at(i).login == temp) break;
	user = i;
	return a;
}
vector<Account> addBalance(vector<Account> a, int user)
{
	char question;
	int balance;
	cout << "Ваш баланс: " << a.at(user).money << endl
		<< "Желаете пополнить баланс?" << endl
		<< "1) Да" << endl << "2) Нет" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '2') return a;
	while (true)
	{
		cout << "На какую сумму пополнить баланс?" << endl;
		balance = generateInt();
		system("cls");
		if (balance < 0) cout << "Invalid input!" << endl;
		else break;
	}
	cout << "Пополнить баланс на " << balance << " рублей?" << endl
		<< "1) Да" << endl << "2) Нет" << endl;
	question = YesNoQuestion();
	system("cls");
	if (question == '1')
	{
		a.at(user).money += balance;
		saveAccounts(a);
		return a;
	}
	else return a;
}