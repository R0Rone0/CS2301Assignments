/** file store_array.c
 * @author Nick Green
 *
 * Program to demonstrate arrays in C.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "at2.h"


/** Function to store input from command line into array of ints
 * @param[in] argc
 * @param[in] argv[]
 * @param[in] arraySize Limit for array size (default 10)
 * @param[in] a Pointer to array a
 * @return x, Represent actual array size
 */

int store_array(int argc, const char* argv[], const int arraySize, int* a) {
  int i,j; // Loop counter
  int x; // Actual array size
  
  /* 
	  FOR loop will break out under two conditions
	  1) Run out of input arguments (i < argc)
	  2) More input arguments than defined limit (x < arraySize)
  */
  for (i = 1, x = 0; ((i < argc) && (x < arraySize)); i++, x++) {
	  a[x] = atoi(argv[i]);
  }

  return x;
  
}
