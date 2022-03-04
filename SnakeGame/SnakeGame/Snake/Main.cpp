#include<iostream>
#include<conio.h>;
#include"GameHeader.h"

using namespace std;

int getMenuChoice()
{

	int choice;
	system("cls");
	cout << "1. PLAY GAME" << endl;
	cout << "2. SET MAP" << endl;
	cout << "3. HIGHEST SCORE";
	cout << endl << endl << "ENTER YOUR CHOICE : ";
	cin >> choice;
	return choice;
}

void menu()
{
	int mapChoice = 1, playAgain;
comeBack:   // this is goto label
	switch (getMenuChoice())
	{
	case  1: playGame(mapChoice);
		cout << endl << endl << "  ooppppss , you collided !!!" << endl<< endl << "wanna play again ? 1 for yes , 0 for no : ";
		cin >> playAgain;
		if (playAgain)
			goto comeBack;
		break;
	case 2: mapChoice = gameMap();
		goto comeBack;
		break;
	case 3: displayScoreFromFile();
		cout << endl << " ENTER ANY KEY TO RETURN TO MENU : ";
		_getch();
		goto comeBack;
		break;
	default: cout << "oops !!!! " << endl << "entered a wrong choice";
	}
}

int main()
{
	menu();
	return 0;
}
