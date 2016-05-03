#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include "life.h"

/** Simulates Conway's Game of Life
 *@ If -t is included a hard-coded game of life will run
 *@ If -r is included the program will generate a random board
 *@ If {filename}.txt is inlcuded the program will run that board in the txt file
 *@ If nothing the program will prompt the user for the size of the board and
 *@ to fill in the board manually
*/
int main(int argc, char **argv) {
  
	srand(time(NULL));

	Board* current_board; 		// Holds a pointer to the current board struct
	Board* updated_board; 		// Updated board at the end of the turn
	Board* temp_board; 			// Used during swapping
	int turn; 					// Turn counter
	int done; 					// Flag to indicate user is done playing
	char* input; 				// String entered by user

	char test[2] = "-t"; 		//To see if testmode
	char random[2] = "-r"; 		//To see if random mode


	// Process any user input:
		
		// Parameter Mode
		if(argv[1]) {
			// Testmode (-t)
			if((strcmp(test,argv[1])) == 0) {
				printf("Testmode activated\n");
				current_board = create_board(BOARD_WIDTH, BOARD_HEIGHT); //Create a constant board
				updated_board = create_board(BOARD_WIDTH, BOARD_HEIGHT);
				
				// Hard-coded test board
				set_inhabitant(current_board, 4, 4, 'X');
				set_inhabitant(current_board, 3, 2, 'X');
				set_inhabitant(current_board, 3, 4, 'X');
				set_inhabitant(current_board, 5, 3, 'X');
				set_inhabitant(current_board, 2, 1, 'X');
				printf("exiting testmode\n");
			}
			// Random mode (-r)
			else if((strcmp(random,argv[1])) == 0) {
				printf("Random mode activated\n");\
				current_board = create_board(BOARD_WIDTH, BOARD_HEIGHT); //Create a 
																	   //a const board
				updated_board = create_board(BOARD_WIDTH, BOARD_HEIGHT);

				int x, y;
			  
				// Run through each cell of the board and fill with a 'X' randomly
				for (y = 0; y < BOARD_HEIGHT; y++) {
					for (x = 0; x < BOARD_WIDTH; x++) {
						int ran = rand() % 100;

						//The higher tha RAND_DENSITY the more likely there will be 'X'
						if(ran < RAND_DENSITY)
							set_inhabitant(current_board, x, y, 'X');
					}
				}
			}
			// File mode ({filename}.txt)
			else if((strcmp(random,argv[1]) != 0) && (strcmp(test, argv[1]) != 0)) {
				printf("Filemode Activated\n");

				// See if you can open the file
				FILE *infile = fopen(argv[1], "r");
				if(infile == NULL) {
					printf("%s\n", strerror(errno));
					printf("\n");
					return 1;
				}
				int txtHeight, txtWidth;		// Height & Width from *.txt file
				char s1[MAX_BOARD_WIDTH];
				char* returnedVal;

				// Get the height and width from the first line of the *.txt file
				returnedVal = fgets(s1, MAX_BOARD_WIDTH, infile);
				sscanf(returnedVal, "%d %d", &txtHeight, &txtWidth);
				current_board = create_board(txtWidth, txtHeight);
				updated_board = create_board(txtWidth, txtHeight);
				printf("Board created\n");

				int i, j;

				// Read the 'X' from the *.txt file
				for(j = 0; j < txtHeight; j++) {			
					char s2[MAX_BOARD_WIDTH + 1];
					char *line;
					line = fgets(s2, MAX_BOARD_WIDTH, infile); // Get line from file
					for(i = 0; (i < txtWidth) && (i < strlen(line)); i++) {
						if(line[i] == 'X') // If it finds an X it puts an X on the board
							set_inhabitant(current_board, i, j, 'X');
						else
							set_inhabitant(current_board, i, j, ' ');
					}
				}
				fclose(infile); // Close the file
			}
		}

		// No Parameter Mode (Only call executable)
		else {
			char* board;				// Temp board to get height & width
			int height, width;			// User defined on command line
			
			//Obtain the height and width from the user
			board = readline("Enter the height and width of of the board\n");
			sscanf(board, "%d %d", &height, &width);
			free(board);
			current_board = create_board(width, height);
			updated_board = create_board(width, height);
			
			int i, j;

			//Prompts the user type out each line
			for(j = 0; j < height; j++) {
				char *line; //No need to free because inside for-loop
				printf("Enter the info for row: %d\n", j);
				line = readline("");
			  
				//Reads the line and puts X from the user on the board
				for(i = 0; (i < width) && (i < strlen(line)); i++) {
					if(line[i] == 'X')
						set_inhabitant(current_board, i, j, 'X');
					else
						set_inhabitant(current_board, i, j, ' ');
				}
			}
		}
  
	//Plays the game
	printf("Playing the game of life.\n");

	printf("Initial board:\n"); 
	print_board(current_board);

	turn = 1;
	done = 0; // Not done yet
 
	while(!done) {
		play(current_board, updated_board); 	// Do one turn
		printf("After turn %d:\n", turn);
		print_board(updated_board); 			// display results on new board

		temp_board = current_board; 			// Remember pointer to the old board
		current_board = updated_board; 			// Updated board becomes current 
												// board for next turn
		updated_board = temp_board; 			// Reuse old board as updated board
		clear_board(updated_board); 			// Clear out
		turn++; 								// Ready for next turn

		input = readline("Enter 'Q' to quit. Anything else to continue> ");
		if (input[0] == 'Q' || input[0] == 'q')
			done = 1;

		free(input); 							// release alocated memory
	}

  return 0;
}
