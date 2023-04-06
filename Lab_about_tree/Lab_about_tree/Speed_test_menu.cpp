#include<windows.h>
#include<time.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
#include<fstream>
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

HANDLE hStdOut2 = GetStdHandle(STD_OUTPUT_HANDLE);
void ConsoleCursorVisible(bool show, short size);

size_t Rand_val() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}

int How_many()
{

	string actions[] = { "1000 случайных чисел", "10000 случайных чисел", "100000 случайных чисел", "Назад (ESC)" };
	int active_menu = 0;
	char ch;
	while (1)
	{

		SetConsoleTextAttribute(hStdOut2, DEF_COL);
		system("cls");
		for (int i = 0; i < size(actions); i++)
		{
			if (i == active_menu) SetConsoleTextAttribute(hStdOut2, ACT_COL);
			else SetConsoleTextAttribute(hStdOut2, DEF_COL);
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
				return 1000;
			case 1:
				return 10000;
			case 2:
				return 100000;
			case 3:
				return -1;
			}
			break;
		default:
			system("cls");
			break;
		}
	}
}

void Speed_filling_to_txt()
{
	ofstream outfile("filling_speed.csv");
	clock_t start, end;
	for (int i = 1000; i < 100001; i+=1000)
	{
		vector<int> vec;
		start = clock();
		for (int j = 0; j < i; j++)
		{
			vec.push_back((int)(Rand_val()));

		}
		end = clock();
		double vec_time = (double)(end - start) / CLOCKS_PER_SEC;

		double tree_time = 0;
		for (int j = 0; j < 100; j++)
		{
			Tree oak;
			start = clock();
			for (int k = 0; k < i; k++)
			{
				oak.insert((int)(Rand_val()));
			}
			end = clock();
			tree_time += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tree_time /= 100;

		outfile << i << "," << vec_time << "," << tree_time << "\n";
		cout << i << " write" << endl;

	}

	outfile.close();
}

void Speed_finding_to_txt()
{
	ofstream outfile("finding_speed.csv");
	clock_t start, end;
	vector<int> vec;
	Tree oak;
	for (int i = 1000; i < 100001; i += 1000)
	{
		for (int j = 0; j < 1000; j++)
		{
			vec.push_back((int)(Rand_val()));

		}
		int pres;
		start = clock();
		auto place = find(vec.begin(), vec.end(), (int)(Rand_val()));
		end = clock();
		double vec_time = (double)(end - start) / CLOCKS_PER_SEC;

		double tree_time = 0;
		for (int j = 0; j < 1000; j++)
		{
				oak.insert((int)(Rand_val()));
		}
		
		for (int j = 0; j < 1000; j++)
		{
			start = clock();
			pres = oak.contains((int)(Rand_val()));
			end = clock();
			tree_time += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tree_time /= 1000;

		outfile << i << "," << vec_time << "," << tree_time << "\n";
		cout << i << " write" << endl;

	}

	outfile.close();
}

void Speed_adding_deleting_to_txt()
{
	ofstream outfile("adding_deleting_speed.csv");
	clock_t start, end;
	vector<int> vec;
	Tree oak;
	for (int i = 1000; i < 100001; i += 1000)
	{
		for (int j = 0; j < 1000; j++)
		{
			vec.push_back((int)(Rand_val()));

		}
		int rand_val = (int)Rand_val();
		start = clock();
		vec.push_back(rand_val);
		vec.erase(remove(vec.begin(), vec.end(), rand_val), vec.end());
		end = clock();
		double vec_time = (double)(end - start) / CLOCKS_PER_SEC;

		double tree_time = 0;
		for (int j = 0; j < 1000; j++)
		{
			oak.insert((int)(Rand_val()));
		}

		for (int j = 0; j < 1000; j++)
		{
			rand_val = Rand_val();
			start = clock();
			oak.insert(rand_val);
			oak.erase(rand_val);
			end = clock();
			tree_time += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tree_time /= 1000;

		outfile << i << "," << vec_time << "," << tree_time << "\n";
		cout << i << " write" << endl;

	}

	outfile.close();
}

void Speed_filling()
{
	int amount = How_many();
	if(amount == -1) return;
	system("cls");

	clock_t start, end;
	vector<int> vec;
	start = clock();
	for (int i = 0; i < amount; i++)
	{
		vec.push_back((int)(Rand_val()));
	}
	end = clock();
	double vector_time = (double)(end - start) / CLOCKS_PER_SEC;

	double tree_time = 0;
	for (int j = 0; j < 100; j++)
	{
		Tree oak;
		start = clock();
		for (int i = 0; i < amount; i++)
		{
			oak.insert((int)(Rand_val()));
		}
		end = clock();
		tree_time += (double)(end - start) / CLOCKS_PER_SEC;
	}
	tree_time /= 100;

	while (1)
	{
		system("cls");
		SetConsoleTextAttribute(hStdOut2, GREEN);
		cout << "Время заполнения std::vector<int> - " << vector_time << " секунд." << endl;
		cout << "Время заполнения бинарного дерева поиска - " << tree_time << " секунд." << endl << endl;

		SetConsoleTextAttribute(hStdOut2, ACT_COL);
		cout << "Назад (ESC)";
		char ch;
		ch = _getch();
		switch (ch)
		{
		case(ESC):
		case ENTER:
			return;
		default:
			break;
		}
	}
}

void Speed_finding()
{
	system("cls");
	int amount = How_many();
	if (amount == -1) return;

	clock_t start, end;
	vector<int> vec;
	for (int i = 0; i < amount; i++)
	{
		vec.push_back((int)(Rand_val()));
	}
	Tree oak;
	for (int i = 0; i < amount; i++)
	{
		oak.insert((int)(Rand_val()));
	}
	bool pres;
	start = clock();
	find(vec.begin(), vec.end(), (int)(Rand_val()));
	end = clock();
	double vector_time = (double)(end - start) / CLOCKS_PER_SEC;
	double tree_time = 0;
	for (int i = 0; i < 1000; i++)
	{
		start = clock();
		pres = oak.contains((int)(Rand_val()));
		end = clock();
		tree_time += (double)(end - start) / CLOCKS_PER_SEC;
	}
	tree_time /= 1000;

	while (1)
	{
		system("cls");
		SetConsoleTextAttribute(hStdOut2, GREEN);
		cout << "Время поиска значения в std::vector<int> - " << vector_time << " секунд." << endl;
		cout << "Время поиска значения в бинарном дереве поиска - " << tree_time << " секунд." << endl << endl;

		SetConsoleTextAttribute(hStdOut2, ACT_COL);
		cout << "Назад (ESC)";
		char ch;
		ch = _getch();
		switch (ch)
		{
		case(ESC):
		case ENTER:
			return;
		default:
			break;
		}
	}
}

void Add_and_delete()
{
	system("cls");
	int amount = How_many();
	if (amount == -1) return;

	clock_t start, end;
	vector<int> vec;
	for (int i = 0; i < amount; i++)
	{
		vec.push_back((int)(Rand_val()));
	}
	Tree oak;
	start = clock();
	for (int i = 0; i < amount; i++)
	{
		oak.insert((int)(Rand_val()));
	}
	int val = int(Rand_val());
	start = clock();
	vec.push_back(val);
	vec.erase(remove(vec.begin(), vec.end(), val), vec.end());
	end = clock();
	double vector_time = (double)(end - start) / CLOCKS_PER_SEC;

	double tree_time = 0;
	for (int i = 0; i < 1000; i++)
	{
		val = int(Rand_val());
		start = clock();
		oak.insert(val);
		oak.erase(val);
		end = clock();
		tree_time += (double)(end - start) / CLOCKS_PER_SEC;
	}
	tree_time /= 1000;

	while (1)
	{
		system("cls");
		SetConsoleTextAttribute(hStdOut2, GREEN);
		cout << "Время добавления и удаления значения в std::vector<int> - " << vector_time << " секунд." << endl;
		cout << "Время добавления и удаления значения в бинарном дереве поиска - " << tree_time << " секунд." << endl << endl;

		SetConsoleTextAttribute(hStdOut2, ACT_COL);
		cout << "Назад (ESC)";
		char ch;
		ch = _getch();
		switch (ch)
		{
		case(ESC):
		case ENTER:
			return;
		default:
			break;
		}
	}
}

void Speed_test_menu()
{
	SetConsoleTextAttribute(hStdOut2, DEF_COL);
	system("cls");

	string actions[] = { "Тест на время заполнения", "Тест на время поиска", "Тест на время добавления и удаления", "Главное меню (ESC)" };
	int active_menu = 0;
	char ch;
	while (1)
	{
		ConsoleCursorVisible(false, 100);
		system("cls");
			
		for (int i = 0; i < size(actions); i++)
		{
			if (i == active_menu) SetConsoleTextAttribute(hStdOut2, ACT_COL);
			else SetConsoleTextAttribute(hStdOut2, DEF_COL);
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
				Speed_filling_to_txt();
				//Speed_filling();
				break;
			case 1:
				Speed_finding_to_txt();
				/*Speed_finding();*/
				break;
			case 2:
				Speed_adding_deleting_to_txt();
				//Add_and_delete();
				break;
			case 3:

				return;
			}
			break;

		default:
			system("cls");
			break;
		}
	}
	
_getch();


}