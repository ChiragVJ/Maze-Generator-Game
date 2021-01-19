#include "MazeGen.h";
mt19937 mt_rand(time(NULL));

void generation::CursorReset(){  // cursor reset function
	COORD CursorPos; //set coordinates where i want the cursor to reset, this is so i can redraw different levels in the same area
	CursorPos.X = 0;
	CursorPos.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPos); //sets console cursor point to the coordinate 0,0

}

void generation::CreateBlock(generation Maze[100][100]) { //used to create a block and filled out with #
	for (int i = 0; i < mazeSize; i++) {
		for (int j = 0; j < mazeSize; j++) {

			Maze[i][j].Elements = '#'; // block will be filled with this elkement. it will later become the elements to represent the walls in the maze
			Maze[i][j].marked = false; //make sure that when creating the block all the points are not marked so they can be deletedlater.
		}
	}
	
}


void generation::Draw(generation Maze[100][100]){ //this function basically updates the changes made the DFS and then outputs to the console. 
	for (int i = 0; i < mazeSize; i++) { 
		cout << endl;
		for (int j = 0; j < mazeSize; j++)
			cout << " " << Maze[i][j].Elements;
	}
}


void generation::DFS(generation Maze[100][100]) { //Depth first search member function
	 
	
	int direction = 0; //declare direction integer 

	int startX = ((10 * mt_rand()) + 1) % (mazeSize - 1); //this basically ensures that a odd number is generated as a starting X coordinate
	int startY = ((10 * mt_rand()) + 1) % (mazeSize - 1); //this basically ensures that a odd number is generated as a starting Y coordinate
	int markedElementCounter = 1; // this is used to count how much elements have been marked
	playerX = 1;
	playerY = 1;
	
	Maze[startY][startX].Elements = ' ';

	int insideElements = ((mazeSize - 1) / 2)*((mazeSize - 1) / 2); // this counts the  number of elments inside the border and then devided it by 2.
	//This is bescuase when we check the element using DFS we check around it in 4 directions, so if we didn't divide by 2, some elements would overlap during DFS checking

	deque<int>reverseX, reverseY; //create  a deque of reverseX and reverseY. This is so we can use the back tracking in DFS
	 // this is were we start searching

	Maze[startY][startX].marked = true; // state that the startingpoint has been marked

	while (markedElementCounter < insideElements)  // run the DFS algorithm up until the all the elements inside the border/2 have been marked.
	{
		if ((Maze[startY - 2][startX].marked == false) && (Maze[startY - 1][startX].Elements == '#') || // check if two elements above the current element is not marked. ,and that the current element has the top member as true
			(Maze[startY + 2][startX].marked == false) && (Maze[startY + 1][startX].Elements == '#') || //check if two elements below the current element is not marked. ,and that the current element has the bot member as true
			(Maze[startY][startX - 2].marked == false) && (Maze[startY][startX - 1].Elements == '#') || // check if two elements on the left the current element is not marked. ,and that the current element has the left member as true
			(Maze[startY][startX + 2].marked == false) && (Maze[startY][startX + 1].Elements == '#'))  // check if two elements on the right the current element is not marked. ,and that the current element has the right member as true
		{
			direction = (mt_rand() % 4) + 1; //generates a random number between 1 and 4


			// GO UP
			if ((direction == 1) && (startY > 1)) {
				if (Maze[startY - 2][startX].marked == false) {        // if the element which is two elments above the current position is marked
					Maze[startY - 1][startX].Elements = ' ';        // Delete Elements
					    

					reverseX.push_front(startX);                      // Push X for back track
					reverseY.push_front(startY);                      // Push Y for back track

					startY -= 2;                                   // Move to next cell
					Maze[startY][startX].marked = true;         // Mark cell moved to as marked
					Maze[startY][startX].Elements = ' ';          // Update path

					markedElementCounter++;                                // Increase marked counter
				}
				else
					continue;
			}

			// GO DOWN
			else if ((direction == 2) && (startY < mazeSize - 2)) {
				if (Maze[startY + 2][startX].marked == false) {        // If not marked
					Maze[startY + 1][startX].Elements = ' ';        // Delete Elements


					reverseX.push_front(startX);                      // Push X for back track
					reverseY.push_front(startY);                      // Push Y for back track

					startY += 2;                                   // Move to next cell
					Maze[startY][startX].marked = true;         // Mark cell moved to as marked
					Maze[startY][startX].Elements = ' ';          // Update path

					markedElementCounter++;                             // Increase marked counter
				}
				else
					continue;
			}

			// GO LEFT
			else if ((direction == 3) && (startX > 1)) {
				if (Maze[startY][startX - 2].marked == false) {        // If not marked
					Maze[startY][startX - 1].Elements = ' ';        // Delete Elements
					


					reverseX.push_front(startX);                      // Push X for back track
					reverseY.push_front(startY);                      // Push Y for back track

					startX -= 2;                                   // Move to next cell
					Maze[startY][startX].marked = true;         // Mark cell moved to as marked
					Maze[startY][startX].Elements = ' ';          // Update path

					markedElementCounter++;                         // Increase marked counter
				}
				else
					continue;
			}

			// GO RIGHT
			else if ((direction == 4) && (startX < mazeSize - 2)) { // the size -2 is the edge without the border
				if (Maze[startY][startX + 2].marked == false) {        // If not marked
					Maze[startY][startX + 1].Elements = ' ';        // Delete Elements
					


					reverseX.push_front(startX);                      // Push X for back track
					reverseY.push_front(startY);                      // Push Y for back track

					startX += 2;                                   // Move to next cell
					Maze[startY][startX].marked = true;         // Mark cell moved to as marked
					Maze[startY][startX].Elements = ' ';          // Update path

					markedElementCounter++;                                 // Increase marked counter
				}
				else
					continue;
			}
		}
		else {
			startX = reverseX.front(); //set the startX coordinate to the x element at the front of the deque
			reverseX.pop_front(); // then pop off the front element in the deque

			startY = reverseY.front(); //set the startY coordinate to the y elemenbt at the front of the deque
			reverseY.pop_front(); //then pop off the front element in the deque
		}





	}
	endX = mazeSize - 2;
	endY = mazeSize - 2;
	
	Maze[1][1].Elements = 'O';
	Maze[mazeSize-2][mazeSize-2].Elements = 'E';
	 //this is the end point of the DFS which is set as the target for the user to reach during the maze gane
	CursorReset();
	Draw(Maze); //print the maze onto the console once the DFS has finished.
	


}



