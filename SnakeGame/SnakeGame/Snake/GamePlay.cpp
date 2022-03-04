#include <iostream>
#include<conio.h>
#include<time.h>
#include"GameHeader.h"

using namespace std;



class Snake {
	int points;
	bool gameOver;               // for definining game is over or not
	int snakeSize;               // for size of snake
	int headPosX, headPosY;      // for head position of snake 
	   // for area of wall
	int fruitPosX, fruitPosY;    // for fruit position 
		  // to store chararacters for wall
	int tailX[200], tailY[200];
	enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
	direction dir;
public:
	Snake(int);
	~Snake();
	bool checkGameOver();
	bool checkWall();
	bool checkSnakeByte();
	void checkWallMap0();
	int getPoints();
	void checkBoundaryLimits(int);
	void makeFruitPos(int);
	void upgradeSnakePos();
	void upgradeSnake();
	/// [void setGameVariables()] This function is there to show why we need constructer
	void drawGameMap(int);
	void input();
	void gameLogic(int);
	void mapInAll(int, int, int);
	void makeFruitPosAll();

	void playMap1();
	void playMap2();

};



Snake::Snake(int choice)
{
	srand(time(NULL));
	gameOver = false;
	dir = STOP;
	points = 0;
	snakeSize = 0;
	headPosX = mapWidthX / 2;
	headPosY = mapWidthY / 2;
	makeFruitPos(choice);
}

Snake::~Snake()
{
	updateScoreInFile(points);
}

bool Snake::checkGameOver()
{
	return gameOver;
}

bool Snake::checkWall()
{
	if (headPosX == 0 || headPosX == mapWidthX - 1 || headPosY == 0 || headPosY == mapWidthY - 1)
		return true;
	return false;
}

bool Snake::checkSnakeByte() 
{
	for (int i = snakeSize; i > 0; --i)
	{
		if (headPosX == tailX[i] && headPosY == tailY[i])
			return true;
	}
	return false;
}

void Snake::checkWallMap0() 
{
		if (headPosX == 0)
			headPosX = mapWidthX - 2;
		else if (headPosX == mapWidthX - 1)
			headPosX = 1;
		else if (headPosY == 0)
			headPosY = mapWidthY - 2;
		else if (headPosY == mapWidthY - 1)
			headPosY = 1;
}

void Snake::checkBoundaryLimits(int mapChoice) {
	switch (mapChoice)
	{
	case 1: {
		if (checkSnakeByte())
			gameOver = true;
		else checkWallMap0();
		break; 
	}
	case 2: {
		if (checkWall()||checkSnakeByte())
			gameOver = true;
		break;
	}
	case 3: {
		if (checkWall() || checkSnakeByte() || gameWall2Block(headPosY, headPosX))
			gameOver = true;
		break;
	}
	default:
		break;
	}

};

void Snake::makeFruitPosAll()
{
	do {                 /// this do while loop is so , to make differnt position for fruit n snake            
		fruitPosX = rand() % (mapWidthX - 2) + 1;
		fruitPosY = rand() % (mapWidthY - 2) + 1;
	} while (fruitPosX != headPosX && fruitPosY != headPosY); /// update needed,because fruit can come under snake except head
}

void Snake::makeFruitPos(int choice)
{

	switch (choice)
	{
	case 1:
	case 2: 
	{
		makeFruitPosAll();
		break;
	}
	case 3: {
		do {
			makeFruitPosAll();
		} while (gameWall2Block(fruitPosY, fruitPosX));

		break;
	}
	default:
		break;
	}

}

void Snake::upgradeSnakePos()
{
	for (int i = snakeSize; i > 0; --i)
	{
		tailX[i] = tailX[i - 1];
		tailY[i] = tailY[i - 1];
	}
	tailX[0] = headPosX;
	tailY[0] = headPosY;
}

//void Snake::setGameVariables() 
//{
//	srand(time(NULL));
//	gameOver = false;
//	dir = STOP;
//	points = 0;
//	snakeSize = 0;
//	charMapX = '-';
//	charMapY = '-';
//	mapWidthX = 30;
//	mapWidthY = 25;
//	headPosX = mapWidthX / 2;
//	headPosY = mapWidthY / 2;
//	makeFruitPos();   
//	
//};7

void Snake::mapInAll(int i, int j, int n)
{
	if (i == fruitPosY && j == fruitPosX)
	{
		cout << "*";
		n = 1;
	}
	else if (i == headPosY && j == headPosX)
	{
		cout << "o";
		n = 1;
	}
	for (int k = 1; k <= snakeSize; ++k)
	{
		if (i == tailY[k] && j == tailX[k])
		{
			cout << ".";
			n = 1;
			break;
		}
	}
	if (!n)
		cout << " ";
}



void Snake::playMap1()
{
	topMap();
	for (int i = 1; i < mapWidthY - 1; ++i)
	{
		for (int j = 0; j < mapWidthX; ++j)
		{
			int n = 0;

			if (j == 0 || j == mapWidthX - 1)
				cout << charMapY;
			else {
				mapInAll(i, j, n);
			}

		}
		cout << endl;
	}
	bottomMap();
	cout << endl << "           POINTS : " << points;
}

void Snake::playMap2()
{
	topMap();
	for (int i = 1; i < mapWidthY - 1; ++i)
	{
		for (int j = 0; j < mapWidthX; ++j)
		{
			int n = 0;

			if (j == 0 || j == mapWidthX - 1)
				cout << charMapY;
			else if (gameWall2(i, j)) {}
			else {
				mapInAll(i, j, n);
			}


		}
		cout << endl;

	}
	bottomMap();
	cout << endl << "           POINTS : " << points;
}

void Snake::drawGameMap(int mapChoice)
{

	system("cls");
	switch (mapChoice)
	{
	case 1: 
	case 2: playMap1();
		break;
	case 3:playMap2();
		break;
	defaul: cout << "wrong map";
	}
};

void Snake::input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
		case 'A':
				dir = LEFT;
			break;
		case 's':
		case 'S':
			dir = DOWN;
			break;
		case 'w':
		case 'W':
			dir = UP;
			break;
		case 'd':
		case 'D':
			dir = RIGHT;
			break;
		default:
			break;
		}
	}


}

void Snake::gameLogic(int mapChoice)
{
	checkBoundaryLimits(mapChoice); // checks wether the snake hits the wall or not

	if (headPosX == fruitPosX && headPosY == fruitPosY)  //if snakes eats fruit , change the pos of fruit
	{
		makeFruitPos(mapChoice);
		++snakeSize;
		points += 5;
	}

	switch (dir)
	{
	case Snake::LEFT: --headPosX;
		break;
	case Snake::RIGHT: ++headPosX;
		break;
	case Snake::UP: --headPosY;
		break;
	case Snake::DOWN: ++headPosY;
		break;
	default:
		break;
	}
	upgradeSnakePos();
};


void playGame(int mapChoice) {

	Snake s(mapChoice);
	//s.setGameVariables();
	while (!(s.checkGameOver()))
	{
		s.drawGameMap(mapChoice);
		s.input();
		s.gameLogic(mapChoice);
	}

}