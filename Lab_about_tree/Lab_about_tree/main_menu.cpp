#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
#define ESC 27
#define UP 72
#define DOWN 80
#define ENTER 13
#define ACT_COL 11
#define DEF_COL 15
using namespace std;
void Menu_1();
void Speed_test_menu();
int Tree_menu();
void Task_menu();
//Menu_2();
//Menu_3();
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

void main_menu()
{
	string main_menu[] = { "Создать новое дерево", "Провести тесты", "Выполнить задачу", "Закончить (ESC)" };
	int active_menu = 0;
	ConsoleCursorVisible(false, 100);


	char ch;
	while (true)
	{
		system("cls");
		for (int i = 0; i < size(main_menu); i++)
		{
			if (i == active_menu) SetConsoleTextAttribute(hStdOut, ACT_COL);
			else SetConsoleTextAttribute(hStdOut, DEF_COL);
			cout << main_menu[i] << endl;
		}




		ch = _getch();
		if (ch == -32) ch = _getch();

		switch (ch)
		{


			case ESC:
				exit(0);


			case UP:
				if (active_menu > 0) active_menu--;
				system("cls");
				break;
			case DOWN:
				if (active_menu < size(main_menu) - 1) active_menu++;
				system("cls");
				break;


			case ENTER:
				switch (active_menu)
				{
					case 0:
						while (true)
						{
							if (Tree_menu() == -1) break;
						}
						break;
					case 1:
						Speed_test_menu();
						break;
					case 2:
						Task_menu();
						break;
					case 3:
						SetConsoleTextAttribute(hStdOut, DEF_COL);
						exit(0);
				}
				break;
			default:
				system("cls");
				break;


		}
	}


}
