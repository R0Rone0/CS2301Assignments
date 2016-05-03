#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processGrades.h"

#define MAX_GRADES (20)

/** 
 *	Program Name: num.c
 *	Programmer: Nick Green
 *	
 *	Program runs in UNIX terminal and takes inputs and displays them upon
 *	execution. Program also calls outside function processGrades, which takes
 *	the input values from main and determines the maximum, minimum, and average
 *	values of the user defined inputs.
 */
int main(int argc, const char* argv[]) {
	int grades[MAX_GRADES]; // Define and allocate the array
	int j,k,x; // FOR loop counter
	
	/* check if command line input is empty. If true, return 1 */
	if(argc < 2) {
		printf("Must enter a number on the command line!\n");
		return 1; // indicate fail
	}
	
	/* 
		FOR loop will break out under two conditions
		1) Run out of input arguments (k < argc)
		2) More input arguments than defined limit (x < MAX_GRADES)
	*/
	for(k = 1, x = 0; (k < argc) && (x < MAX_GRADES); k++, x++) {
		grades[x] = atoi(argv[k]); // convert string to int
		
	}
	
	/*
		FOR loop cycles through values in grades array and displays them in terminal
		FOR loop will break out when
		1) Input arguments reach defined limit (j < x)
	*/
	for(j = 0; j < x ; j++) {
		printf("Grade[%d]: %d\n", j, grades[j]); // print int on command line
	}
	
	/*
		IF statement which print WARNING message if number of input arguments
		is lower than user defined limit (MAX_GRADES - x)
	*/	
	if(k == argc) {
		printf("WARNING: Can still input %d more grade(s).\n", MAX_GRADES - x);
	}
	
	/*
		IF statement which prints ERROR message if number of input arguments
		exceeds user defined limit (argc - 1 > MAX_GRADES)
	*/
	if((argc - 1) > MAX_GRADES) {
		printf("ERROR: Too many numbers specified in input (%d > %d).\n", argc - 1, MAX_GRADES);
	}
	
	/*
		Call function processGrades which takes in grades array and integer
		value of input arguments.
		
		WARNING: Will not take grades outside of user defined limit when
		calculating max, min, and average values of grades.
	*/
	processGrades(grades, x);
	
	return 0;// indicate success
}
