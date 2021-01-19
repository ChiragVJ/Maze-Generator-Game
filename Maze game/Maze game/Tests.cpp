#include "PlayerEnemies.h"
#include <assert.h>

//in order to run these tests 1-9 comment out the CursorReset in line 161 of the MazeGen.cpp. Then to run 10-17 uncomment this line

/*int main() {
	cout << "Test 1: Constructor assigns a mazesize" << endl;
	generation TestLevelOne(11);
	assert(TestLevelOne.mazeSize == 11);
	cout << TestLevelOne.mazeSize << endl;

	cout << "========================================================================================================" << endl;

	cout << "Test 2: Instructions are outputted onto screen" << endl;
	player TestPlayer;
	TestPlayer.instructions();



	cout << "Test 3: CreateBlock function creates a block of '#'s of the size 'mazesize'*'mazesize' where mazesize is 11" << endl;
	generation TestMaze[100][100];
	TestLevelOne.CreateBlock(TestMaze);
	TestLevelOne.Draw(TestMaze);

	cout << endl << "========================================================================================================" << endl;

	cout << "Test 4: DFS function creates a different maze after every call. Call 6 times to check." << endl;
	TestLevelOne.DFS(TestMaze);
	cout << endl;
	TestLevelOne.CreateBlock(TestMaze);
	TestLevelOne.DFS(TestMaze);
	cout << endl;
	TestLevelOne.CreateBlock(TestMaze);
	TestLevelOne.DFS(TestMaze);
	cout << endl;
	TestLevelOne.CreateBlock(TestMaze);
	TestLevelOne.DFS(TestMaze);
	cout << endl;
	TestLevelOne.CreateBlock(TestMaze);
	TestLevelOne.DFS(TestMaze);
	cout << endl;
	TestLevelOne.CreateBlock(TestMaze);
	TestLevelOne.DFS(TestMaze);

	cout << endl << "========================================================================================================" << endl;
	cout << "Test 5: Three levels can be created" << endl;
	cout << "Test 6: The next level should always generate a larger maze than the previous" << endl;
	cout << "Test 7: Player starting position should always be the top left corner of the maze" << endl;
	cout << "Test 8: End of the maze should always be the bottom right corner of the maze" << endl;
	generation TestLevelTwo(17);
	generation TestLevelThree(25);
	TestLevelOne.CreateBlock(TestMaze);
	TestLevelOne.DFS(TestMaze);
	cout << endl;
	TestLevelTwo.CreateBlock(TestMaze);
	TestLevelTwo.DFS(TestMaze);
	cout << endl;
	TestLevelThree.CreateBlock(TestMaze);
	TestLevelThree.DFS(TestMaze);

	cout << endl << "========================================================================================================" << endl;
	
	cout << "Test 9: Once player movement is initialized, player should be able to move using wasd keys";
	TestLevelOne.CreateBlock(TestMaze);
	TestLevelOne.DFS(TestMaze);
	TestPlayer.movement(TestMaze, TestPlayer, TestLevelOne);

	cout << endl << "========================================================================================================" << endl;
	system("cls");
	cout << "Test 10: If the player element reaches the end of the maze, the next level loads.";
	TestLevelOne.CreateBlock(TestMaze);
	TestLevelOne.DFS(TestMaze);
	TestPlayer.movement(TestMaze, TestPlayer, TestLevelOne);
	TestLevelTwo.CreateBlock(TestMaze);
	TestLevelTwo.DFS(TestMaze);
	TestPlayer.movement(TestMaze, TestPlayer, TestLevelTwo); 
	TestLevelThree.CreateBlock(TestMaze);
	TestLevelThree.DFS(TestMaze);
	TestPlayer.movement(TestMaze, TestPlayer, TestLevelThree);
	
	cout << endl << "========================================================================================================" << endl;
	system("cls");

	cout << "Test 11: Player can quit the game any time by pressing the 'q' key";
	TestLevelOne.CreateBlock(TestMaze);
	TestLevelOne.DFS(TestMaze);
	TestPlayer.movement(TestMaze, TestPlayer, TestLevelOne);
	
	cout << endl << "========================================================================================================" << endl;
	system("cls");
	
	cout << "Test 12: Timer accurately records the time taken for the user to complete the game";
	TestLevelOne.CreateBlock(TestMaze);
	TestLevelOne.DFS(TestMaze);
	TestPlayer.movement(TestMaze, TestPlayer, TestLevelOne);
	TestLevelTwo.CreateBlock(TestMaze);
	TestLevelTwo.DFS(TestMaze);
	TestPlayer.movement(TestMaze, TestPlayer, TestLevelTwo);
	TestLevelThree.CreateBlock(TestMaze);
	TestLevelThree.DFS(TestMaze);
	TestPlayer.movement(TestMaze, TestPlayer, TestLevelThree);
	score(TestPlayer);
	
	cout << endl << "========================================================================================================" << endl;
	system("cls");

	cout << "Test 13: Spawn a single trap and powerup in level 1";
	ParentTrap TestTrap;
	timePowerUp TestPowerUp;
	TestLevelOne.CreateBlock(TestMaze);
	TestLevelOne.DFS(TestMaze);

	TestTrap.spawn(1, 'T', TestMaze, TestLevelOne);
	TestPowerUp.spawn(1, 'P', TestMaze, TestLevelOne);	TestPlayer.movement(TestMaze, TestPlayer, TestLevelOne);
	
	cout << endl << "========================================================================================================" << endl;
	system("cls");
	cout << "Test 14: Spawn two traps and powerups in level 2";

	TestLevelTwo.CreateBlock(TestMaze);
	TestLevelTwo.DFS(TestMaze);
	TestTrap.spawn(2, 'T', TestMaze, TestLevelTwo);
	TestPowerUp.spawn(2, 'P', TestMaze, TestLevelTwo);
    TestPlayer.movement(TestMaze, TestPlayer, TestLevelTwo);
	
	cout << endl << "========================================================================================================" << endl;
	system("cls");
	cout << "Test 15: Spawn three traps and powerups in level 3";
	TestLevelThree.CreateBlock(TestMaze);
	TestLevelThree.DFS(TestMaze);
	TestTrap.spawn(3, 'T', TestMaze, TestLevelThree);
	TestPowerUp.spawn(3, 'P', TestMaze, TestLevelThree);
	TestPlayer.movement(TestMaze, TestPlayer, TestLevelThree);
	

	cout << endl << "========================================================================================================" << endl;
	system("cls");
	cout << "Test 16 and 17: Check traps and powerups effects work as intended."
		"Score function should display number of the traps and powerups hit as well as total time taken by the user";
	
	TestLevelOne.CreateBlock(TestMaze);
	TestLevelOne.DFS(TestMaze);
	TestTrap.spawn(1, 'T', TestMaze, TestLevelOne);
	TestPowerUp.spawn(1, 'P', TestMaze, TestLevelOne);
	TestPlayer.movement(TestMaze, TestPlayer, TestLevelOne);
	TestLevelTwo.CreateBlock(TestMaze);
	TestLevelTwo.DFS(TestMaze);
	TestTrap.spawn(2, 'T', TestMaze, TestLevelTwo);
	TestPowerUp.spawn(2, 'P', TestMaze, TestLevelTwo);
	TestPlayer.movement(TestMaze, TestPlayer, TestLevelTwo);
	TestLevelThree.CreateBlock(TestMaze);
	TestLevelThree.DFS(TestMaze);
	TestTrap.spawn(3, 'T', TestMaze, TestLevelThree);
	TestPowerUp.spawn(3, 'P', TestMaze, TestLevelThree);
	TestPlayer.movement(TestMaze, TestPlayer, TestLevelThree);
	score(TestPlayer);
}

*/



