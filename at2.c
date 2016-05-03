/** file num_arrays.c
 * @author Nick Green
 *
 * Program to demonstrate arrays in C.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "at2.h"

#define SAMPLE_INT_ARRAY_SIZE (10)


/** Main program for demonstrating arrays. It fills them, sorts them, and prints them
 *  from user input.
 * @return 0, Indicating success.
 */

int main(int argc, const char* argv[]) {
	int j,x;	// loop variables
	int a[x]; 	// Sample array for demonstration

	/*
	  Takes in values of argc, argv, arraySize, and pointer to array to store values.
	  Returns number of elements in new array.
	*/
	x = store_array(argc, argv, SAMPLE_INT_ARRAY_SIZE, a);
  
	/*
	  Takes in array and arraySize and sorts values in ascending order.
	  Sorting algorithm = Bubble Sort
	*/
	sort_array(a, x);

	/*
	  FOR loop cycles through values in "a" array and displays them in terminal
	  FOR loop will break out when
	  1) Input arguments reach defined limit (j < x)
	*/
	for(j = 0; j < x ; j++) {
		printf("Number[%d]: %d\n", j, a[j]); // print int on command line
	}

	/*
	  IF statement which print WARNING message if number of input arguments
	  is lower than user defined limit (SAMPLE_INT_ARRAY_SIZE - x)
	*/	
	if(x < SAMPLE_INT_ARRAY_SIZE) {
		printf("WARNING: Can still input %d more number(s).\n", SAMPLE_INT_ARRAY_SIZE - x);
	}
  
	/*
	  IF statement which prints ERROR message if number of input arguments
	  exceeds user defined limit (argc - 1 > SAMPLE_INT_ARRAY_SIZE)
	*/
	if((argc - 1) > SAMPLE_INT_ARRAY_SIZE) {
		printf("ERROR: Too many numbers specified in input (%d > %d).\n", argc - 1, SAMPLE_INT_ARRAY_SIZE);
	}
  
  
  
	return 0; // Success!
}
