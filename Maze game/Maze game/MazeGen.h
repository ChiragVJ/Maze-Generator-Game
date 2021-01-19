#pragma once


//create a 2d array greater than expected and then empty it down to needed size
#include <deque>
#include <iostream>
#include <random>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <chrono>



 
using namespace std;


class generation{
public:
	
	generation() {}; //default constructor to create maze
	generation(int size) {
		mazeSize = size; //this constructor is used to define maze size so levels can be created.
	}
	int endX; //ending coordinates of the MAZE
	int endY;
	int playerX; //the players current coordinates
	int playerY;
	bool marked; //if the position has been marked by when generating
	char Elements; // this is what the maze will be made up of and edited. eg, # ' ' 'O' 'E'
	
	int mazeSize; //this is the size of the maze which has to be odd for the depth first search algorithm to work 
	
	void CreateBlock(generation Maze[100][100]); //. this generates a block depending on the mazesize
	void DFS(generation Maze[100][100]); //this performs the depth first search to generate a random maze
	void Draw(generation Maze[100][100]); // this is responsible for drawingf and updating the maze once changes are made to it
	void CursorReset();// this resets the console cursor to the top left so when re drawing the maze it can overlap and not draw it constantly below every time.
	 
};





