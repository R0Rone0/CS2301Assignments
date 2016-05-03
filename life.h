/**
 * This is the header file life.h.
 * Note that the board coordinates are x, which increases to the right,
 * and y, which increases down (Like on Web pages).
 */
#ifndef LIFE_H
#define LIFE_H

#include <string.h>

#define MAX_BOARD_WIDTH (50)
#define BOARD_WIDTH (10)
#define BOARD_HEIGHT (5)
#define RAND_DENSITY (60)

struct _board {
  int width; // How many columns wide the board is.
  int height; // How many rows tall the board is.

  /* We store the board as 2-D array of chars
   * It is actually implemented as a 1-D array of pointers.
   * Each entry is a pointer to an array of chars.
   * (each of these arrays represents one column)..
   * Each entry of THOSE arrays is a char 
   * (blank means uninhabited).
   * This way we can access the array as array[row][column].
   * Note that in this notation x is the column, y is the row.
   */

  char** array;        
};

typedef struct _board Board;

// Function prototypes:
Board* create_board(int width, int height);
char get_inhabitant(Board *f, int x, int y);
void set_inhabitant(Board* f, int x, int y, char c);
void print_board(Board* f);
void clear_board(Board* f);
void play(Board* current_board, Board* updated_board);
int adjacent(Board* f, int x, int y);

#endif
