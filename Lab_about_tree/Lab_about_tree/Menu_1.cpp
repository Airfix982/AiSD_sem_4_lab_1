//#include<windows.h>
//#include<stdio.h>
//#include<iostream>
//#include<conio.h>
//#include<vector>
//#include<string>
//#include"Tree.hpp"
//#define ESC 27
//#define UP 72
//#define DOWN 80
//#define ENTER 13
//#define ACT_COL 11
//#define DEF_COL 15
//void ConsoleCursorVisible(bool show, short size);
//HANDLE hStdOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
//
//int Tree_menu();
//
//void Menu_1()
//{
//	string main_menu[] = { "Создать дерево", "Назад (ESC)"};
//	int active_menu = 0;
//	char ch;
//	while (true)
//	{
//		system("cls");
//		for (int i = 0; i < size(main_menu); i++)
//		{
//			if (i == active_menu) SetConsoleTextAttribute(hStdOut1, ACT_COL);
//			else SetConsoleTextAttribute(hStdOut1, DEF_COL);
//			cout << main_menu[i] << endl;
//		}
//
//
//
//
//		ch = _getch();
//		if (ch == -32) ch = _getch();
//
//		switch (ch)
//		{
//
//
//			case ESC:
//				return;
//
//
//			case UP:
//				if (active_menu > 0) active_menu--;
//				system("cls");
//				break;
//			case DOWN:
//				if (active_menu < size(main_menu) - 1) active_menu++;
//				system("cls");
//				break;
//
//
//			case ENTER:
//				switch (active_menu)
//				{
//					case 0:
//						while (true) 
//						{
//							if (Tree_menu() == -1) return;
//						}
//						system("cls");
//						break;
//
//					case 1:
//						return;
//				}
//				break;
//
//
//			default:
//				system("cls");
//				break;
//
//
//		}
//	}
//}