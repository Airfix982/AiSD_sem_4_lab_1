#include<windows.h>
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

HANDLE hStdOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
void ConsoleCursorVisible(bool show, short size);

int incorect_insert(const int mistake)
{
	ConsoleCursorVisible(false, 100);
	char ch1;
	int active_adding = 0;
	string adding[] = { "Попытаться сызнова", "Отмена (ESC)" };

	while (1)
	{

		SetConsoleTextAttribute(hStdOut1, RED);
		system("cls");
		if (mistake == 1) cout << endl << endl << "\tВы ввели текст" << endl << endl;
		if (mistake == 2) cout << endl << endl << "\tВы ввели не целое число" << endl << endl;


		for (int i = 0; i < size(adding); i++)
		{
			if (i == active_adding) SetConsoleTextAttribute(hStdOut1, ACT_COL);
			else SetConsoleTextAttribute(hStdOut1, DEF_COL);
			cout << adding[i] << endl;

		}

		ch1 = _getch();
		if (ch1 == -32) ch1 = _getch();
		switch (ch1)
		{
		case ESC:
			system("cls");
			return 2;

		case UP:
			if (active_adding > 0) active_adding--;
			break;
		case DOWN:
			if (active_adding < size(adding) - 1) active_adding++;
			break;

		case ENTER:
			switch (active_adding)
			{
			case 0:
				system("cls");
				return 1;
			case 1:
				system("cls");
				return 2;
			}
		default:
			break;
		}
	}
}

void adding(Tree& oak)
{

	double value;
	while (1)
	{
		system("cls");
		ConsoleCursorVisible(true, 100);
		SetConsoleTextAttribute(hStdOut1, DEF_COL);
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
		else oak.insert(value);
		return;
	}
}

void removing(Tree& oak)
{

	double value;
	while (1)
	{
		system("cls");
		ConsoleCursorVisible(true, 100);
		SetConsoleTextAttribute(hStdOut1, DEF_COL);
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
		else oak.erase(value);
		return;
	}
}

void existing(Tree& oak)
{

	double value;
	while (1)
	{
		system("cls");
		ConsoleCursorVisible(true, 100);
		SetConsoleTextAttribute(hStdOut1, DEF_COL);
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
		else
		{
			ConsoleCursorVisible(false, 100);
			while (1)
			{
				
				system("cls");
				if (oak.contains(value))
				{
					SetConsoleTextAttribute(hStdOut1, GREEN);
					cout << "Такое число есть";
					SetConsoleTextAttribute(hStdOut1, ACT_COL);
					cout << endl << endl << "ну есть и есть";
				}
				else
				{
					SetConsoleTextAttribute(hStdOut1, RED);
					cout << "Такого числа нет";
					SetConsoleTextAttribute(hStdOut1, ACT_COL);
					cout << endl << endl << "ну нет так нет";
				}
				char ch2;
				ch2 = _getch();
				switch (ch2)
				{
					case ENTER:
						return;
					default:
						break;
				}
			}
		}
		return;
	}
}


int Tree_menu()
{
	Tree oak;
	while (true)
	{
		SetConsoleTextAttribute(hStdOut1, DEF_COL);
		system("cls");
		
		string actions[] = { "Добавить элемент", "Удалить элемент", "Проверить наличие", "Создать новое дерево", "Главное меню (ESC)"};
		int active_menu = 0;
		char ch;
		while (1)
		{
			ConsoleCursorVisible(false, 100);
			system("cls");
			if (oak.get_root() == NULL)
			{
				SetConsoleTextAttribute(hStdOut1, RED);
				cout << "Дерево пустое" << endl << endl;
			}
			else
			{
				SetConsoleTextAttribute(hStdOut1, GREEN);
				cout << "Дерево: ";
				oak.print();
				cout << endl << endl;
			}
			for (int i = 0; i < size(actions); i++)
			{
				if (i == active_menu) SetConsoleTextAttribute(hStdOut1, ACT_COL);
				else SetConsoleTextAttribute(hStdOut1, DEF_COL);
				if (oak.get_root() == NULL && (i == 1 || i == 2))
				{
					if (i == active_menu) SetConsoleTextAttribute(hStdOut1, PAS_ACT);
					else SetConsoleTextAttribute(hStdOut1, PAS_COL);
				}
				cout << actions[i] << endl;

			}

			ch = _getch();
			if (ch == -32) ch = _getch();
			switch (ch)
			{
				case ESC:
				return -1;


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
						adding(oak);
						break;
					case 1:
						if (oak.get_root() == NULL)break;
						removing(oak);
						break;
					case 2:
						if (oak.get_root() == NULL) break;
						existing(oak);
						break;
					case 3:

						return 1;
					case 4:

						return -1;
				}
				break;

			default:
				system("cls");
				break;
			}
		}
	}
	_getch();
	return 1;
}