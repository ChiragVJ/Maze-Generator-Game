#pragma once
#include "PlayerEnemies.h";
int timeaddCounter;
int timeremoveCounter;
mt19937 mt_rand2(time(NULL));
int player::moveUp(generation Maze[100][100], generation Level, player name) { //this function is responsible for the character moving up
	


	if (Maze[Level.playerY - 1][Level.playerX].Elements == ' ') {  //this if statement works by swapping a space with the character above it

		
		int tempY = Level.playerY; //coordinates stored in tempoary variable.
		int tempX = Level.playerX;
		Maze[Level.playerY - 1][Level.playerX].Elements = 'O';
		
		Maze[tempY][tempX].Elements = ' '; //positions swapped
		
		Level.CursorReset(); // reset cursor position  back to top left. 
		Level.Draw(Maze); //redraw the maze with new poisitions.
	
		
		return 1;
	}
	else if (Maze[Level.playerY - 1][Level.playerX].Elements == 'T') { //this if statements work by removing the T when the character hits it.
		int tempY = Level.playerY; //coordinates stored in tempoary variable.
		int tempX = Level.playerX;
		Maze[Level.playerY - 1][Level.playerX].Elements = 'O'; //position where T was is now an O
		Level.CursorReset(); // reset cursor position  back to top left. 
		Maze[tempY][tempX].Elements = ' '; 
		
		Level.Draw(Maze);//redraw the maze with new poisitions.
		timeaddCounter += 1;
		return 1;
	}
	else if (Maze[Level.playerY - 1][Level.playerX].Elements == 'E') { //this if statement works by removing the E when the character hits it
		Level.playerX = 1; //this sets the player coordinates as the top left
		Level.playerY = 1;
		int tempY = Level.playerY;
		int tempX = Level.playerX;
		Maze[Level.playerY - 1][Level.playerX].Elements = 'O'; //changes the position where the E was to an O
		Maze[tempY][tempX].Elements = ' '; 
		Level.CursorReset(); // reset cursor position  back to top left. 
		Level.Draw(Maze);//redraw the maze with new poisitions.
		return 1;
		
	}
	else if (Maze[Level.playerY - 1][Level.playerX].Elements == 'P') { //this if statements work by removing the T when the character hits it.
		int tempY = Level.playerY; //coordinates stored in tempoary variable.
		int tempX = Level.playerX;
		Maze[Level.playerY - 1][Level.playerX].Elements = 'O'; //position where T was is now an O

		Maze[tempY][tempX].Elements = ' ';
		Level.CursorReset(); // reset cursor position  back to top left. 
		
		Level.Draw(Maze);//redraw the maze with new poisitions.
		timeremoveCounter += 1;
		return 1;
	}
	
}
int player::moveDown(generation Maze[100][100],  generation Level, player name) {  //this if statement works by swapping a space with the character below it

	if (Maze[Level.playerY + 1][Level.playerX].Elements == ' ') {
		
		int tempY = Level.playerY;
		int tempX = Level.playerX;
		Maze[Level.playerY + 1][Level.playerX].Elements = 'O';
		
		Maze[tempY][tempX].Elements = ' ';
		Level.CursorReset(); // reset cursor position  back to top left. 
		Level.Draw(Maze);
		
		return 1;
	}
	else if (Maze[Level.playerY + 1][Level.playerX].Elements == 'T') {
		int tempY = Level.playerY;
		int tempX = Level.playerX;
		Maze[Level.playerY + 1][Level.playerX].Elements = 'O';

		Maze[tempY][tempX].Elements = ' ';
		//system("cls");
		Level.CursorReset();
		Level.Draw(Maze);
	//	cout << "This should print a message" << endl;
		timeaddCounter += 1;
		
		return 1;
	}
	
	else if (Maze[Level.playerY + 1][Level.playerX].Elements == 'E') {
		int tempY = Level.playerY;
		int tempX = Level.playerX;
		Maze[Level.playerY + 1][Level.playerX].Elements = 'O';
		
		Maze[tempY][tempX].Elements = ' ';
		Level.CursorReset(); // reset cursor position  back to top left. 
		
		Level.Draw(Maze);
		
		
		return 1;

	}
	else if (Maze[Level.playerY + 1][Level.playerX].Elements == 'P') { //this if statements work by removing the T when the character hits it.
		int tempY = Level.playerY; //coordinates stored in tempoary variable.
		int tempX = Level.playerX;
		Maze[Level.playerY + 1][Level.playerX].Elements = 'O'; //position where T was is now an O

		Maze[tempY][tempX].Elements = ' ';
		//system("cls");
		Level.CursorReset(); // reset cursor position  back to top left. 
		Level.Draw(Maze);//redraw the maze with new poisitions.

		timeremoveCounter += 1;


		return 1;
	}
	
}
int player::moveLeft(generation Maze[100][100],  generation Level, player name) {  //this if statement works by swapping a space with the character on the left of it
	if (Maze[Level.playerY][Level.playerX - 1].Elements == ' ') {

		int tempY = Level.playerY;
		int tempX = Level.playerX;
		Maze[Level.playerY][Level.playerX - 1].Elements = 'O';

		Maze[tempY][tempX].Elements = ' ';
		Level.CursorReset(); // reset cursor position  back to top left. 
		Level.Draw(Maze);

		return 1;
	}
	else if (Maze[Level.playerY][Level.playerX - 1].Elements == 'T') {
		int tempY = Level.playerY;
		int tempX = Level.playerX;
		Maze[Level.playerY][Level.playerX - 1].Elements = 'O';

		Maze[tempY][tempX].Elements = ' ';
		//	system("cls");
		Level.CursorReset(); // reset cursor position  back to top left. 
		Level.Draw(Maze);
	//	cout << "This should print a message" << endl;
		timeaddCounter += 1;
		
		return 1;
	}
	else if (Maze[Level.playerY][Level.playerX - 1].Elements == 'E') {
		int tempY = Level.playerY;
		int tempX = Level.playerX;
		Maze[Level.playerY][Level.playerX - 1].Elements = 'O';
		Level.CursorReset(); // reset cursor position  back to top left. 
		Maze[tempY][tempX].Elements = ' ';
		
		
		Level.Draw(Maze);
	
		return 1;
	}
	else if (Maze[Level.playerY][Level.playerX - 1].Elements == 'P') { //this if statements work by removing the T when the character hits it.
		int tempY = Level.playerY; //coordinates stored in tempoary variable.
		int tempX = Level.playerX;
		Maze[Level.playerY][Level.playerX - 1].Elements = 'O'; //position where T was is now an O

		Maze[tempY][tempX].Elements = ' ';
		//system("cls");
		Level.CursorReset(); // reset cursor position  back to top left. 
		Level.Draw(Maze);//redraw the maze with new poisitions.
		
		timeremoveCounter += 1;


		return 1;
	}
	

}
int player::moveRight(generation Maze[100][100],  generation Level, player name) {  //this if statement works by swapping a space with the character on the right of  it
	
	if (Maze[Level.playerY][Level.playerX + 1].Elements == ' ') {
		
		int tempY = Level.playerY;
		int tempX = Level.playerX;
		Maze[Level.playerY][Level.playerX + 1].Elements = 'O';
		
		Maze[tempY][tempX].Elements = ' ';
		Level.CursorReset(); // reset cursor position  back to top left. 
		Level.Draw(Maze);

		
		return 1;
	}
	else if (Maze[Level.playerY][Level.playerX + 1].Elements == 'T') {
		int tempY = Level.playerY;
		int tempX = Level.playerX;
		Maze[Level.playerY][Level.playerX + 1].Elements = 'O';

		Maze[tempY][tempX].Elements = ' ';
		Level.CursorReset(); // reset cursor position  back to top left. 
		Level.Draw(Maze);
	
		timeaddCounter += 1;
		
		return 1;
		
	}

	else if (Maze[Level.playerY][Level.playerX + 1].Elements == 'E') {
		int tempY = Level.playerY;
		int tempX = Level.playerX;
		Maze[Level.playerY][Level.playerX + 1].Elements = 'O';

		Maze[tempY][tempX].Elements = ' ';
		
		Level.CursorReset();
		Level.Draw(Maze);
		
		Level.CursorReset();
		return 1;
	}
	else if (Maze[Level.playerY][Level.playerX + 1].Elements == 'P') { //this if statements work by removing the T when the character hits it.
		int tempY = Level.playerY; //coordinates stored in tempoary variable.
		int tempX = Level.playerX;
		Maze[Level.playerY][Level.playerX + 1].Elements = 'O'; //position where T was is now an O

		Maze[tempY][tempX].Elements = ' ';
		Level.CursorReset(); // reset cursor position  back to top left. 
		
		Level.Draw(Maze);//redraw the maze with new poisitions.

		timeremoveCounter += 1;


		return 1;
	}


}

void player::movement(generation Maze[100][100], player name, generation Level) {
	ParentTrap x;
	timePowerUp y;
	
	auto start = std::chrono::high_resolution_clock::now();
	while ((Level.playerX != Level.endX) || (Level.playerY != Level.endY)) { //while the position of the player 
		//is not equal to the letter E which is where the end of the level is
		
		char Choice;
		Choice = _getch();
		
		
		Choice = tolower(Choice); //so that upper case WASD works
			
		if (Choice == 'w') { //if the user enters w  run the moveUp function so the charcter moves up
			if (name.moveUp(Maze, Level, name) == 1) {
				Level.playerY--; //change the Y coordinate one up
			}

			else

				continue;

		}
		else if (Choice == 'a') { //if the user enters a  run the moveLeft function so the charcter moves left
			if (name.moveLeft(Maze, Level, name) == 1) {
				Level.playerX--; //change the x coordinate one left
			}

			else
				continue;

		}
		else if (Choice == 'd') { //if the user enters d  run the moveright function so the charcter moves right
			if (name.moveRight(Maze, Level, name) == 1) {
				Level.playerX++; //change the x coordinate one right
			}

			else
				continue;

		}
		else if (Choice == 's') { //if the user enters s  run the moveDown function so the charcter moves down
			if (name.moveDown(Maze, Level, name) == 1) {
				Level.playerY++; //change the y coordinate one down.
			}

			else
				continue;
		}
		else if (Choice == 'q') {
			system("cls");
			cout << "THANKS FOR PLAYING\nGOODBYE" << endl;
			exit(0);
		}
		else
			continue;
	}
	
	auto finish = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::seconds>(finish-start).count();
	duration += duration; //add the next level duration onto it
	duration += x.Effect(); //add the number of time from traps to duration.
	duration -= y.Effect();
}

void player::instructions() {
	cout << "\nWelcome to the Maze game!!!!!\n"
		"\nAttempt to traverse the maze in the fastest speed possible\n"
		"\nYour player is represented by an 'O' and the end goal is represented by an 'E'\n"
		"\nTo move your player use the 'w' (up) 's'(down) 'a'(left) 'd' (right) keys\n"
		"\nIf you wish to quit, press the 'q' key at any time\n"
		"\nOnce you reach the 'E' the next level will load\n"
		"\nBe aware Traps represented by a 'T' will add 5 seconds onto your final time\n"
		"\nOn the other hand PowerUps represented by a 'P' will remove 2 seconds from your final time\n"
		"There are a total 3 levels\nGOOD LUCK!!!!" << endl; //print instructions

	char play;
	cout << "\nPress any key to begin" << endl;
	play = _getch(); //so the user can read through the instructions
	system("cls");
}

	
	
		
	
		
		


int score(player name) {
	system("cls"); //clear screen
	int quotient = name.duration / 60;
	cout << "You got a time of " << quotient << " minutes and " << fmod(name.duration, 60) << " seconds" << endl;
	cout << "A total of " << 5 * timeaddCounter << " seconds were added to your score because you hit " 
		<< timeaddCounter << " traps" << endl;// print time of completion
	cout << "A total of " << 2 * timeremoveCounter << " seconds were removed to your score because you hit " 
		<< timeremoveCounter << " power ups" << endl;//
	return 0;
}


void ParentTrap::spawn(int number, char letter, generation Maze[100][100], generation Level) {
	
	

	for (int i = 0; i < number; i++) {
		int spawnX = ((10 * mt_rand2()) + 1) % (Level.mazeSize - 1); //for the number that i want of traps 
		int spawnY = ((10 * mt_rand2()) + 1) % (Level.mazeSize - 1); //i spawn them randomly and make sur they are within the mazeSize;

		if (Maze[spawnY][spawnX].Elements == ' ') { //if the position that is callated is a space
			Maze[spawnY][spawnX].Elements = letter; // assign a trap to that position

		}
		else
			continue;

	}
	Level.CursorReset(); //reset back to top left
	Level.Draw(Maze); //redraw maze

}


int ParentTrap::Effect() {
	int add = timeaddCounter * 5; // calculate time added from traps
	return add; //return extra time to function
}


int timePowerUp::Effect() {
	int reduce = timeremoveCounter * 2;
	return reduce;
}


