/** file num_arrays.c
 * @author Nick Green
 *
 * Program to demonstrate arrays in C.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "at3.h"

#define SAMPLE_INT_ARRAY_SIZE (10)


/** Main program for demonstrating arrays. It fills them with random numbers,
 *  sorts them in ascending order using bubble sort, and prints them.
 * @return 0, Indicating success.
 */

int main(int argc, const char* argv[]) {
	int j;
	int a[SAMPLE_INT_ARRAY_SIZE + 1];
	int rand_max = 50;
  
	// Initialize random number generator
	srand(time(NULL)); 
  
	/*
	  Takes in array, arraySize, and max rand to populate array with
	  random numbers.
	*/
	populate_array(a, (SAMPLE_INT_ARRAY_SIZE + 1), rand_max);
    
	/*
	  Takes in array and arraySize and sorts values in ascending order.
	  Sorting algorithm = Bubble Sort
	*/
	sort_array(a, (SAMPLE_INT_ARRAY_SIZE + 1));
  
	/*
	  FOR loop cycles through values in "a" array and displays them in terminal
	  FOR loop will break out when
	  1) Input arguments reach defined limit (j < x)
	*/
	for(j = 0; j < (SAMPLE_INT_ARRAY_SIZE + 1); j++) {
		printf("Number[%d]: %d\n", j, a[j]); // print int on command line
	}
  
	return 0; // Success!
}
