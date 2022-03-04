#pragma once

void playGame(int);
int gameMap();
void topMap();
void bottomMap();
int gameWall2(int, int);
int gameWall2Block(int, int);

static int mapWidthX = 30, mapWidthY = 25;
static char charMapX = '-', charMapY = '-';

void updateScoreInFile(int);
void displayScoreFromFile();


class Snake;
