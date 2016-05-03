#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* Program which reads numbers from the command line,
 * outputs them, sorts them in descending order, and outputs the sorted list.
 *
 * Usage:
 *         ./sorttest some_number another_number ...
 * Example:
 *         ./sorttest 2014 15 7000
 *
 */

/** Main program
 * @param argc Number of words on the command line
 * @param argv[] Array of character strings, the words from the command line.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

int main (int argc, const char* argv[]) {

	int *nums; // space to store numbers entered from the command line.

	int next_num; // Integer read from the command line goes here.
	int i; // array index 
	int num_nums;
	
	num_nums = argc - 1;
	
	// Allocate an array big enough to hold the numbers
	nums = (int*) calloc(num_nums, sizeof(int));
	if (nums == NULL) {
		fprintf(stderr, "Unable to allocate enougn memory to hold the numbers.\n");
	}

	/* Read all the numbers from the command line and put them into the array */
	for (i = 0; i < num_nums; i++) {
		next_num = atoi(argv[i+1]); // Get string from command line; convert to int
		nums[i] = next_num; // store into the array
	}
	
	int arraySize = nums[0];
	int sortType = nums[1];
	
	if(arraySize <= 1) { // check array size
		printf("ERROR: Array Size must be greater than 1. EXITING...\n");
		return 1;
	} else if(sortType > 1) { // check sort type
		printf("ERROR: Sort Type must be 0 or 1. EXITING...\n");
		return 1;
	} else if(nums[2] != 0) { // check input arguments
		printf("ERROR: Too many input arguments. EXITING...\n");
		return 1;
	}
	
	int a[arraySize];

	// Initialize random number generator. TURN OFF FOR SAME NUMBERS.
	srand(time(NULL)); 
	
	// Check that there are at least two numbers
	if (arraySize == 0) { 
		printf("Must enter at least 1 number on the command line! Exiting.\n");
		return 1; // Indicate failure
	}

	/*
	  Takes in array and arraySize to populate array with
	  random numbers.
	*/
	populate_array(a, arraySize);
	
	// Now print, sort, and print the array, and time how long the sorting took.
	timesort(a, arraySize, sortType);

	return 0; // Indicate success!
}
