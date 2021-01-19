#include "PlayerEnemies.h"



int main() {
	ParentTrap Trap;
	timePowerUp PowerUp;
	player Chirag; // create a player object named Chirag
	Chirag.instructions(); // run instructions
	generation Levelone(13);// initalise level one of the maze using a overloaded constructor 
	generation Maze[100][100]; //initalise the maze array itself
	Levelone.CreateBlock(Maze); //create block of # using the maze size defined in the overloaded constructor
	Levelone.DFS(Maze); //use the depth first search algorithm to generate the maze
	Trap.spawn(1, 'T', Maze, Levelone); //spawn 1 Trap in level one
	PowerUp.spawn(1, 'P', Maze, Levelone); //spawn 1 powerup in level one
	Chirag.movement(Maze, Chirag, Levelone); // initialize movement of the player
	generation Leveltwo(21);// initalise level two  of the maze of size 21 using a overloaded constructor 
	Leveltwo.CreateBlock(Maze);  //create block of # using the maze size defined in the overloaded constructor
	Leveltwo.DFS(Maze);  //use the depth first search algorithm to generate the maze
	Trap.spawn(2, 'T', Maze, Leveltwo);
	PowerUp.spawn(2, 'P', Maze, Leveltwo);
	Chirag.movement(Maze, Chirag, Leveltwo); //allow movement to occur in level two
	generation Levelthree(27); // initalise level three of the maze using a overloaded constructor
	Levelthree.CreateBlock(Maze); //createof # using the maze size defined in the overloaded constructor
	Levelthree.DFS(Maze);  //use the depth first search algorithm to generate the maze
	Trap.spawn(3, 'T', Maze, Levelthree);
	PowerUp.spawn(3, 'P', Maze, Levelthree);
	Chirag.movement(Maze, Chirag, Levelthree); //allow movement to occur in level three
	score(Chirag);
}
