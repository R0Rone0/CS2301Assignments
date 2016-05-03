/** file print_arrays.c
 * @author Mike Ciaraldi
 *
 * Functions for printing arrays.
 */

#include <stdio.h>
#include "print_arrays.h"

/** Print an array of ints, one per line.
    @param[in] a Array of ints to print
    @param[in] num_elements Number of elements in the array
*/

void print_int_array(int a[], int num_elements) {
	int i; // Loop counter

	/*
	  FOR Loop that prints array elements (int) on command line.
	  Loop breaks when number of elements have all been printed (i <= num_elements)
	*/
	for (i = 0; i <= num_elements; i++) {
		printf("%d\n", a[i]);
	}
}

/** Print an array of doubles, one per line.
    @param[in] a Array of doubles to print
    @param[in] num_elements Number of elements in the array
*/
void print_double_array(double a[], int num_elements) {
	int i; // Loop counter

	/*
	  FOR Loop that prints array elements(double) on command line.
	  Loop breaks when number of elements have all been printed (i <= num_elements)
	*/
	for (i = 0; i <= num_elements; i++) {
		printf("%d\n", a[i]);
	}
}

