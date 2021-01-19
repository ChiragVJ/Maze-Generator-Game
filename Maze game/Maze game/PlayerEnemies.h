#pragma once

#include "MazeGen.h"

class player{
public:
	float duration;
	int moveUp(generation Maze[100][100],  generation Level, player name);
	int moveDown(generation Maze[100][100],  generation Level, player name);
	int moveLeft(generation Maze[100][100],  generation Level, player name);
	int moveRight(generation Maze[100][100], generation Level, player name);
	void movement(generation Maze[100][100], player name, generation Level);
	void instructions();
	
};

class ParentTrap{
public:
	void spawn(int number, char letter, generation Maze[100][100], generation Level);
	virtual int Effect();



};

class timePowerUp : public ParentTrap {
public:
	int Effect();
};

int score(player name);

