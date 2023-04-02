#include<windows.h>
#include<time.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
#include"Tree.hpp"
#define ESC 27
#define UP 72
#define DOWN 80
#define ENTER 13
#define ACT_COL 11
#define DEF_COL 15
#define PAS_COL 8
#define GREEN 10
#define RED 12
#define PAS_ACT 3
using namespace std;

HANDLE hStdOut3 = GetStdHandle(STD_OUTPUT_HANDLE);
void ConsoleCursorVisible(bool show, short size);
int incorect_insert(const int mistake);

void Add_element(int *el)
{
	double value;
	while (1)
	{
		system("cls");
		ConsoleCursorVisible(true, 100);
		SetConsoleTextAttribute(hStdOut3, DEF_COL);
		cout << "Введите значение: ";
		int choice = 0;
		while (!(cin >> value) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');

			choice = incorect_insert(1);

			break;
		}
		if (double(int(value)) != value) choice = incorect_insert(2);
		if (choice == 1) continue;
		else if (choice == 2) return;
		*el = int(value);
		return;
	}


}


void Task_menu()
{
	SetConsoleTextAttribute(hStdOut3, DEF_COL);
	system("cls");
	Tree oak;
	vector<int> vec;
	string actions[] = { "Добавить элемент", "Удалить элемент", "Главное меню (ESC)" };
	int active_menu = 0;
	char ch;
	while (1)
	{
		ConsoleCursorVisible(false, 100);
		system("cls");

		if (vec.begin() == vec.end())
		{
			SetConsoleTextAttribute(hStdOut3, RED);
			cout << "Вектор пуст" << endl << endl;

		}
		else
		{
			SetConsoleTextAttribute(hStdOut3, GREEN);
			cout << "Вектор:";
			for (auto i : vec)
			{
				cout << " " << i;
			}
			cout << endl << endl;
			if (oak.get_root() == NULL)
			{
				SetConsoleTextAttribute(hStdOut3, RED);
				cout << "Неповторяющихся элементов нет";
			}
			else
			{
				cout << "Неповторяющиеся элементы: ";
				oak.print();
			}
			cout << endl << endl;
		}

		for (int i = 0; i < size(actions); i++)
		{
			if(vec.begin() == vec.end() && i == 1)
			{
				if (i == active_menu) SetConsoleTextAttribute(hStdOut3, PAS_ACT);
				else SetConsoleTextAttribute(hStdOut3, PAS_COL);
			}
			else
			{
				if (i == active_menu) SetConsoleTextAttribute(hStdOut3, ACT_COL);
				else SetConsoleTextAttribute(hStdOut3, DEF_COL);
			}
			cout << actions[i] << endl;

		}

		ch = _getch();
		if (ch == -32) ch = _getch();
		switch (ch)
		{
		case ESC:
			return;


		case UP:
			if (active_menu > 0) active_menu--;
			system("cls");
			break;
		case DOWN:
			if (active_menu < size(actions) - 1) active_menu++;
			system("cls");
			break;

		case ENTER:
			switch (active_menu)
			{
			case 0:
			{
				int el;
				Add_element(&el);
				vec.push_back(el);
				bool repeat;
				if (vec.begin() != vec.end())
				{
					repeat = false;
					for (auto i = vec.begin(); i != (vec.end() - 1); i++)
					{
						if (*i == el) repeat = true;
					}

				}
				if (repeat == true) oak.erase(el);
				else oak.insert(el);
				break;
			}
			case 1:
			{
				if (vec.begin() == vec.end()) break;
				int el;
				Add_element(&el);
				auto it = find(vec.begin(), vec.end(), el);
				if (it != vec.end()) 
				{
					vec.erase(it);
				}
				else
				{
					break;
				}
				//================================================
				it = find(vec.begin(), vec.end(), el);
				if (it == vec.end())
				{
					oak.erase(el);
					break;
				}
				else
				{
					auto it1 = find(it + 1, vec.end(), el);
					if (it1 == vec.end())
					{
						oak.insert(el);
						break;
					}
					else
					{
						break;
					}
				}
			}
			case 2:
				return;

			default:
				system("cls");
				break;
			}
		}
	}

	_getch();


}