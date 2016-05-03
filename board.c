/** This is the file: board.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "life.h"



/** Create a Board struct
 * @param[in] width Number of columns in the board 
 *    (coordinate increases to the right)
 * @param[in] height Number of rows tall (coordinate increases as you 
 *    move down the page).
 *
 */

Board* create_board(int width, int height) {

	// allocate the space for the struct
	Board* new_board = (Board*) malloc(sizeof(Board));
	new_board->width = width; // Remember width and height of the board.
	new_board->height = height;

	// Now allocate the 2-D array which forms the board.
	int x, y; // Column and row coordinates.

	// First, allocate the array of pointers to the columns
	new_board->array = (char**) (calloc(width, sizeof(char*)));
	for (x = 0; x < width; x++) {
		// Allocate each column array.
		new_board->array[x] = (char*) (calloc(height, sizeof(char)));
	}

  // We want all the counters in the array to be blank.
	for (x = 0; x < width; x++) {
		for (y = 0; y < height; y++) {
			new_board->array[y][x] = ' ';
		}
	}
	return new_board;
}


/** Retrieves the counter from a specified spot on the board.
 * @param[in] f Pointer to the Board struct
 * @param[in] x X-coordinate
 * @param[in] y Y-coordinate.
 * @return The counter at (x, y);
 */
char get_inhabitant(Board *f, int x, int y) {
	return f->array[y][x];
}

/** Stores a counter into a specified spot on the board.
 * @param[in] f Pointer to the Board struct
 * @param[in] x X-coordinate
 * @param[in] y Y-coordinate.
 * @param[out] c Counter to store (as a character)
 */
void set_inhabitant(Board* f, int x, int y, char c) {
	f->array[y][x] = c;
}



/** Prints the board to standard output
 * @param[in] f Pointer to the Board
 */

void print_board(Board* f) {
	int x, y; // Coordinates

	printf("\n-----------------------\n");
	for (y = 0; y < (f->height); y++) { // Print one complete row
		for(x = 0; x < (f->width); x++) { // Print each cell
			printf("%c", get_inhabitant(f, x, y));
		}
		printf("\n"); // End of line
	}
	printf("-----------------------\n");
}

/** Sets all the cells in the board to blank.
 * @param[in] f Pointer to the board
 */
void clear_board(Board* f) {
	int x, y; //Coordinates
  
	//Free the memory for each column
	for (y = 0; y < (f->height); y++) {
		for (x = 0; x < (f->width); x++) {
			set_inhabitant(f, x, y, ' ');
		}
	}
}

/** Plays one turn of the Game of Life
 * @param[in] current_board Pointer to the board at the beginning of the turn.
 *          This board does not get modified by this function. 
 * @param[in] updated_board Pointer to the board at the end of the turn.
 *          All cells should be empty when this function is called.
 *          The cells get filled in by this function.
 */

void play(Board* current_board, Board* updated_board) {
	int x, y; // Coordinates

	//Moves through all the cells of the board
	for (y = 0; y < (current_board->height); y++) {
		for(x = 0; x < (current_board->width); x++) {
			int a; // Holds number of neighbors
			a = adjacent(current_board,x,y); //Obtains the number of neighbors

			//Kills, creates, or leaves cell alone according to the rules
			if (a == 3)
				set_inhabitant(current_board,x,y,'X');
			if ((a < 2) || (a > 3))
				set_inhabitant(current_board,x,y,' ');
		}
	}
  
	//Copies all the cells from the current board to the updated board
	for (y = 0; y < (current_board->height); y++) {
		for(x = 0; x < (current_board->width); x++) {
			char cell = get_inhabitant(current_board,x,y);
			if(cell != ' ')
				set_inhabitant(updated_board, x, y, 'X');
		}
	}
}

/** Calculates the number of neighbors a single cell has
 * @param[in] f is the current board to be used to examine the cells
 * @param[in] x is the x position of the cell to be examined
 * @param[in] y is the y position of the cell to be examined
 * @return Number of neighbors of a particular cell
 */ 
int adjacent(Board* f, int x, int y) {
	int count = 0;

	//Check all the neighbors and increment count correspondly

	// Top Center
	if((x >= 0) && ((y - 1) >= 0)) {
		if(get_inhabitant(f, x, (y - 1)) == 'X')
			count++;
	}

	// Top Left
	if(((x - 1) >= 0) && ((y - 1) >= 0)) {
		if(get_inhabitant(f, (x - 1), (y - 1)) == 'X')
			count++;
	}

	// Top Right
	if(((x + 1) < (f->width)) && ((y - 1) >= 0)) {
		if(get_inhabitant(f, (x + 1), (y - 1)) == 'X')
			count++;
	}

	// Left
	if(((x - 1) >= 0) && (y >= 0)) {
		if(get_inhabitant(f, (x - 1), y) == 'X')
			count++;
	}

	// Right
	if(((x + 1) < (f->width)) && (y >= 0)) {
		if(get_inhabitant(f, (x + 1), y) == 'X')
			count++;
	}

	// Bottom Center
	if((x >= 0) && ((y + 1) < (f->height))) {
		if(get_inhabitant(f, x, (y + 1)) == 'X')
			count++;
	}
	
	// Bottom Left
	if(((x - 1) >= 0) && ((y + 1) < (f->height))) {
		if(get_inhabitant(f, (x - 1),(y + 1)) == 'X')
			count++;
	}

	// Bottom Right
	if(((x + 1) < (f->width)) && ((y + 1) < (f->height))) {
		if(get_inhabitant(f, (x + 1), (y + 1)) == 'X')
			count++;
	}
	
	return count;
}
