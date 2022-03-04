#include<iostream>
#include<conio.h>
#include"GameHeader.h"
using namespace std;

static int mapCounter;

void topMap()
{
	for (int i = 0; i < mapWidthX; ++i)
		cout << charMapX;
	cout << endl;
}

void bottomMap()
{
	for (int i = 0; i < mapWidthX; ++i)
		cout << charMapX;
}

int gameWall2Block(int i, int j)
{
	if ((((i == 4 || i == 7 || i == 18 || i == 21) && (j >= 10 && j <= 20)) ||
		(((i >= 8 && i <= 10) || (i >= 15 && i <= 17)) && (j == 10 || j == 20)))
		)
		return 1;
	return 0;
}

int gameWall2(int i, int j)
{
	if (gameWall2Block(i, j))
	{
		cout << "=";
		return 1;
	}
	return 0;
}

void map0() 
{
	++mapCounter;
	topMap();
	for (int i = 1; i < mapWidthY - 1; ++i)
	{
		for (int j = 0; j < mapWidthX; ++j)
		{


			if (j == 0 || j == mapWidthX - 1)
				cout << charMapY;
			else {
				cout << " ";
			}

		}
		cout << endl;
	}
	bottomMap();
	cout << endl;
}

void map1()
{
	++mapCounter;
	topMap();
	for (int i = 1; i < mapWidthY - 1; ++i)
	{
		for (int j = 0; j < mapWidthX; ++j)
		{


			if (j == 0 || j == mapWidthX - 1)
				cout << charMapY;
			else {
				cout << " ";
			}

		}
		cout << endl;
	}
	bottomMap();
	cout << endl;
}

void map2()
{
	++mapCounter;
	topMap();
	for (int i = 1; i < mapWidthY - 1; ++i)
	{
		for (int j = 0; j < mapWidthX; ++j)
		{


			if (j == 0 || j == mapWidthX - 1)
				cout << charMapY;
			else if (gameWall2(i, j)) {}
			else {
				cout << " ";
			}

		}
		cout << endl;

	}
	bottomMap();
}


int gameMap()
{
	int mapChoice;
	mapCounter = 1;
	system("cls");
	cout << "choose your map " << endl;
	cout << mapCounter << " : " << "TRANSPARENT MAP" << endl;
	map0();
	cout << endl;
	cout << mapCounter << " : " << "BLOCKING MAP" << endl;
	map1();
	cout << endl;
	cout << mapCounter << " : " << "EXTRA BLOCKING MAP" << endl;
	map2();
	cout << endl;
	cout << "ENTER YOUR CHOICE NUMBER : ";
	cin >> mapChoice;
	return mapChoice;
}

//void aa() { cout << "sa"; }