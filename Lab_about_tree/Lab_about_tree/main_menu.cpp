#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
#include"Tree.hpp"
#define ESC 27
#define UP 72
#define DOWN 80
#define ENTER 13
#define ACT_COL 11
#define DEF_COL 15

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
	string Menu_1[] = { "������� ����� ������", "�������� �����", "��������� ������", "��������� (ESC)" };
	int active_menu = 0;
	ConsoleCursorVisible(false, 100);


	char ch;
	while (true)
	{

		for (int i = 0; i < size(Menu_1); i++)
		{
			if (i == active_menu) SetConsoleTextAttribute(hStdOut, ACT_COL);
			else SetConsoleTextAttribute(hStdOut, DEF_COL);
			cout << Menu_1[i] << endl;
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
				if (active_menu < size(Menu_1) - 1) active_menu++;
				system("cls");
				break;


			case ENTER:
				switch (active_menu)
				{
					case 0:
					case 1:
					case 2:
						/*system("cls");
						SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN |

							FOREGROUND_INTENSITY);

						cout << "������������ ������ " << Menu_1[active_menu] << endl;
						_getch();
						system("cls");
						break;*/
						system("cls");
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
