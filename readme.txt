Name: Nick Green
Username: negreen
CS 2301 Assignment 7

Doxygen Comments: http://users.wpi.edu/~negreen/cs2301assig7/index.html
NOTE: To run Doxygen, type "make docs" into command line
	Purposely done, so you don't make docs each time you compile the program
	
Source Files:
life.c:
	Main source file that contains the main() function for program to play
	Conway's Game of Life. When	compiled and run, program will generate board 
	containing both 'X' and ' '	values, indicating active and inactive squares.
	
	Game Modes:
		-t: Testmode -> play a hard-coded board for testing
		-r: Random -> play a randomally generated board
		*.txt: Text File -> play from a text file in same folder as source file
		NULL: User Input -> play by following commands on command line
	
board.c:
	Contains functions used in life.c. See Doxygen comments by following above
	URL. Also read more about functions by accessing source file.
	
	Functions:
		create_board()
		get_inhabitant()
		set_inhabitant()
		print_board()
		clear_board()
		play()
		adjacent()
	
life.h:
	Header file containing variable definitions, as well as the board struct.
	Contains function prototypes for every function included in both life.c
	and board.c.
	
