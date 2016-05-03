/** file sort_array.c
 * @author Nick Green
 *
 * Program to demonstrate arrays in C.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "sort_array.h"

/** Bubble sort function. Takes in array and arraySize and sorts in ascending order.
 * @param[in] array Array to be sorted
 * @param[in] arraySize Size of array to be sorted
 */

void sort_array(int array[], int arraySize) {
	int j,k; 	// Loop counter
	int temp;	// Temp location on array
		
	/*
	  Bubble sort algorithm. j loop is the iteration number
	  As j increases, the high element will be put at the end of the array
	*/
	for(j = 0; j < (arraySize - 1); j++) {
		/*
		  FOR loop which determines which value is the max value and puts
		  it at the end of the array. Loop then finds next highest by shortening
		  array size to not consider total max value.
		*/
		for(k = 1; k < (arraySize - j); k++) {
			if(array[k - 1] > array[k]) {
				temp = array[k - 1];
				array[k - 1] = array[k];
				array[k] = temp;
			}
		}
	}
}

/** Random number generator function. Takes in MAX rand and returns rand number.
 * @param[in] randMax Random number generator maximum value, inclusive
 * @return number, Random number
 */
int rand_gen(int randMax) {
	int number;	// variable to store random number

	number = rand() % (randMax + 1);
	
	return number;
	
}


/** Populate random array function. Populates given array with random numbers.
 * @param[in] a Pointer to array to be populated
 * @param[in] arraySize Size of array to be populated
 * @param[in] randMax Random number generator maximum value, inclusive
 */
void populate_array(int* a, int arraySize, int randMax) {
	int i;
	
	/*
	  FOR loop to populate array with random numbers
	  FOR loop will break out when:
	  1) number of elements in array equals specified arraySize (i < arraySize)
	*/
	for(i = 0; i < arraySize; i++) {
		a[i] = rand_gen(randMax);
	}
}

