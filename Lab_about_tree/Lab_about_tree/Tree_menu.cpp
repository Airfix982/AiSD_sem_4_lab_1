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

HANDLE hStdOut1_1 = GetStdHandle(STD_OUTPUT_HANDLE);
void ConsoleCursorVisible(bool show, short size);

int Tree_menu()
{
	
	Tree oak;
	while (true)
	{
		SetConsoleTextAttribute(hStdOut1_1, DEF_COL);
		system("cls");
		
		string actions[] = { "Добавить элемент", "Удалить элемент", "Проверить наличие", "Главное меню (ESC)", "Создать новое дерево" };
		int active_menu = 0;
		char ch;
		while (1)
		{
			if (oak.get_root() == NULL)
			{
				SetConsoleTextAttribute(hStdOut1_1, RED);
				cout << "Дерево пустое" << endl << endl;
			}
			else
			{
				SetConsoleTextAttribute(hStdOut1_1, GREEN);
				cout << "Дерево: ";
				oak.print();
				cout << endl << endl;
			}
			for (int i = 0; i < size(actions); i++)
			{
				if (i == active_menu) SetConsoleTextAttribute(hStdOut1_1, ACT_COL);
				else SetConsoleTextAttribute(hStdOut1_1, DEF_COL);
				if (oak.get_root() == NULL && (i == 1 || i == 2))
				{
					if (i == active_menu) SetConsoleTextAttribute(hStdOut1_1, PAS_ACT);
					else SetConsoleTextAttribute(hStdOut1_1, PAS_COL);
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
						
						system("cls");
						cout << "Введите значение: ";

						_getch();
						break;
					case 1:
						if (oak.get_root() == NULL) break;
						system("cls");
						cout << "nice chice";
						_getch();
						break;
					case 2:
						if (oak.get_root() == NULL) break;
						system("cls");
						cout << "nice chice";
						_getch();
						break;
					case 3:

						return -1;
					case 4:

						return 1;
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