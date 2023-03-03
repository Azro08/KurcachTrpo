#pragma once
#include <iostream>
using namespace std;
vector<PlaneStruct> sortPlanes(vector<PlaneStruct> a); //Сортировка рейсов
vector<PlaneStruct> sortPlanesByNumber(vector < PlaneStruct> a); //Сортировка
по номеру
vector<PlaneStruct> sortPlanesByDestination(vector<PlaneStruct> a);
//Сортировка по месту прибытия
vector<PlaneStruct> sortPlanesByDate(vector<PlaneStruct>a); //Сортировка по
дате вылета
vector<PlaneStruct> sortPlaneByEconomCost(vector<PlaneStruct>a); //Сортировка
по стоимости эконом класса
vector<PlaneStruct> sortPlaneByBuisnes(vector<PlaneStruct>a); //Сортировка по
кол - ву билетов бизнесс класса
vector<PlaneStruct> sortPlaneByBuisnesCost(vector<PlaneStruct>a);
//Сортировка по стоимости бизнесс класса
vector<PlaneStruct> sortPlaneByEconom(vector<PlaneStruct>a); //Сортировка по
кол - ву билетов эконом класса
vector<PlaneStruct> sortPlanes(vector<PlaneStruct> a)
{
	char question;
	77
		while (true)
		{
			showAllPlanes(a);
			cout << "1) Сортировать по номеру рейса" << endl
				<< "2) Сортировать по месту прибытия" << endl
				<< "3) Сортировать по дате вылета" << endl
				<< "4) Сортировать по кол-ву билетов эконом-класса" << endl
				<< "5) Сортировать по кол-ву билетов бизнес-класса" << endl
				<< "6) Сортировать по цене билетов эконом класса" << endl
				<< "7) Сортировать по цене билетов бизнес-класса" << endl
				<< "0) Завершить" << endl;
			question = _getch();
			system("cls");
			switch (question)
			{
			case '0':
			{
				saveFile(a);
				return a;
			}
			case '1':
			{
				a = sortPlanesByNumber(a);
				break;
			}
			case '2':
			{
				a = sortPlanesByDestination(a);
				break;
			}
			case '3':
			{
				a = sortPlanesByDate(a);
				break;
			}
			case '4':
			{
				a = sortPlaneByEconom(a);
				break;
			}
			case '5':
			{
				a = sortPlaneByBuisnes(a);
				break;
			}
			case '6':
			{
				a = sortPlaneByEconomCost(a);
				break;
			}
			case '7':
			{
				a = sortPlaneByBuisnesCost(a);
				break;
			}
			}
		}
}
vector<PlaneStruct> sortPlanesByNumber(vector < PlaneStruct> a)
{
	int min;
	for (int i = 0; i < a.size() - 1; i++)
	{
		78
			min = i;
		for (int g = i + 1; g < a.size(); g++)
			if (a.at(g).number < a.at(min).number) min = g;
		if (min != i) swap(a.at(i), a.at(min));
	}
	return a;
}
vector<PlaneStruct> sortPlanesByDestination(vector<PlaneStruct> a)
{
	int min;
	for (int i = 0; i < a.size() - 1; i++)
	{
		min = i;
		for (int g = i + 1; g < a.size(); g++)
		{
			if ((int)a.at(g).destination.at(0) < (int)a.at(min).desti￾nation.at(0)) min = g;
			else if ((int)a.at(g).destination.at(0) ==
				(int)a.at(min).destination.at(0) && (int)a.at(g).destination.at(1) <
				(int)a.at(min).destination.at(1)) min = g;
		}
		if (min != i) swap(a.at(i), a.at(min));
	}
	return a;
}
vector<PlaneStruct> sortPlanesByDate(vector<PlaneStruct>a)
{
	int min;
	for (int i = 0; i < a.size() - 1; i++)
	{
		min = i;
		for (int g = i + 1; g < a.size(); g++)
		{
			if (a.at(g).date.at(8) > a.at(min).date.at(8));
			else
			{
				if (a.at(g).date.at(8) == a.at(min).date.at(8))
				{
					if (a.at(g).date.at(9) > a.at(min).date.at(9));
					else
					{
						if (a.at(g).date.at(9) ==
							a.at(min).date.at(9))
						{
							if (a.at(g).date.at(3) >
								a.at(min).date.at(3));
							else
							{
								if (a.at(g).date.at(3) ==
									a.at(min).date.at(3))
								{
									if (a.at(g).date.at(4)
			> a.at(min).date.at(4));
									else
									{
										if
											(a.at(g).date.at(4) == a.at(min).date.at(4))
										{
											if
												(a.at(g).date.at(0) > a.at(min).date.at(0));
											else
											{
												79
													if
														(a.at(g).date.at(0) == a.at(min).date.at(0))
													{
														if (a.at(g).date.at(1) < a.at(min).date.at(1)) min = g;
													}
													else
														min = g;
											}
										}
										else min = g;
									}
								}
								else min = g;
							}
						}
						else min = g;
					}
				}
				else min = g;
			}
		}
		if (min != i) swap(a.at(i), a.at(min));
	}
	return a;
}
vector<PlaneStruct> sortPlaneByEconom(vector<PlaneStruct>a)
{
	int min;
	for (int i = 0; i < a.size() - 1; i++)
	{
		min = i;
		for (int g = i + 1; g < a.size(); g++)
			if (a.at(g).econom < a.at(min).econom) min = g;
		if (min != i) swap(a.at(i), a.at(min));
	}
	return a;
}
vector<PlaneStruct> sortPlaneByBuisnes(vector<PlaneStruct>a)
{
	int min;
	for (int i = 0; i < a.size() - 1; i++)
	{
		min = i;
		for (int g = i + 1; g < a.size(); g++)
			if (a.at(g).buisnes < a.at(min).buisnes) min = g;
		if (min != i) swap(a.at(i), a.at(min));
	}
	return a;
}
vector<PlaneStruct> sortPlaneByBuisnesCost(vector<PlaneStruct>a)
{
	int min;
	for (int i = 0; i < a.size() - 1; i++)
	{
		min = i;
		for (int g = i + 1; g < a.size(); g++)
			if (a.at(g).buisnes_cost < a.at(min).buisnes_cost) min = g;
		if (min != i) swap(a.at(i), a.at(min));
	}
	return a;
}
80
vector<PlaneStruct> sortPlaneByEconomCost(vector<PlaneStruct>a)
{
	int min;
	for (int i = 0; i < a.size() - 1; i++)
	{
		min = i;
		for (int g = i + 1; g < a.size(); g++)
			if (a.at(g).econom_cost < a.at(min).econom_cost) min = g;
		if (min != i) swap(a.at(i), a.at(min));
	}
	return a;
}