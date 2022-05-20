#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

void arrayInit(char *array, int size){
	// initializes a character array
	// parameters:
	//	char *array: a character array of size int size

	for (int i = 0; i < size; i++){
		// loop that initalizes every value in the array to an * 
		array[i] = '*';
	}
}


void printArr(char *array, int size){
	// prints every character in the array array
	// parameters:
	//	char *array: a character array of size int size
	for (int i = 0; i < size; i++){
		char p = array[i];
		printw("%c", p);
	}
}





int main(){
	// array data
	int sizee = 20; 	// size of the array
	char arr[sizee];	// the array itself
	int times = 10;	// the number of times it is printed AKA the number of ROWS
	
	
	// player data
	int row = 3;		// initial player spawn position (row)
	int col = 5;		// initial player spawn position (column)
	
	// goal data
	int rowg = 6;		// initial goal spawn position (row)
	int colg = 2;		// initial goal spawn position (column)
	
	
	initscr();		// creat an ncurses window
	
	int done = 0;		// setup the infinite loop
	int score = 0;		// start the score counter
	
	
	while (done != 1){
		
		int count = 0;								// basically keeps track of number of rows printed
	
		while (count < times){
			arrayInit(arr, sizee);						// start the array
			
			if (row != rowg){						// check if player and goal are not on the same row
				if (count == row){					// check if we are desired row location the print the row with the palyer only
					arr[col] = '#';
					printArr(arr, sizee);	
				}
				
				if (count == rowg){					// do the same for the goal, print it alone
					arr[colg] = '@';
					printArr(arr, sizee);	
				}
			}
			
			if (count == row && count == row && row == rowg){		// check if the rows overlap for player and goal
				arr[col] = '#';					// print both on the same line
				arr[colg] = '@';
				printArr(arr, sizee);	
			}
			
			if (count != rowg && count != row){				// the else statement basically 
				arrayInit(arr, sizee);
				printArr(arr, sizee);	
			}
			
			printw("\n");							// new line to print next row
			count++;							// increment the row number
			
			
			if (colg == col && row == rowg){				// check if the player has reached the goal
				score++;						// add to the score 
				rowg = rand() % times;					// randomize the location of the next goal
				colg = rand() % sizee;
			}
		}
		refresh();								// refresh the screeen
		
		
		printw("Your score is: %d\n", score);					// score diplay
		refresh();
		
		char act = getch();							// get/wait for player input
		
		
		// input checks
		
		// quit
		if (act == 'q'){
			done = 1;
		}
		
		// left
		if (act == 'a'){
			col = col - 1;
		}
		
		// right
		if (act == 'd'){
			col = col + 1;
		}
		
		// down
		if (act == 's'){
			row = row + 1;
		}
		
		// up
		if (act == 'w'){
			row = row - 1;
		}
		
		
		// clear the screen and refresh
		clear();
		refresh();
	}
	
	// close the ncurses window
	endwin();
	// print the final score
	printf("Your Score Was: %d\n", score);
		
	return 0;
}
