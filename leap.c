#include <stdio.h>
#include <stdlib.h>

/**
 *	Program Name: leap.c
 *	Programmer: Nick Green
 *
 *	Program determines whether the year input by the user is a
 *	leap year or not.
 */

int main(int argc, const char* argv[]) {
	int n; // Converted year input from char to int
	
	// Error for no year entered
	if(argc < 2) {
		printf("Must enter a year on the command line!\n");
		return 1;
	}
	
	n = atoi(argv[1]); // Convert entered year from char to int
	
	// Error for year before 1752 entered
	if(n < 1752) {
		printf("Cannot test year %d. Year must be after 1752\n", n);
		return 1;
	}
	
	// Display entered year
	printf("The year you entered was: %d\n", n);
	
	// Determine if entered year is a leap year
	if((n % 4) == 0) { // Test if year is divisible by 4
		if(((n % 100) == 0) && ((n % 400) != 0)) { // Test if year is divisible by 400 if it is divisible by 100
			printf("The year %d is NOT a leap year.\n", n);
			return 1; // Return year = NOT leap year
		}
		printf("The year %d is a leap year.\n", n);
		return 0; // Return year = leap year
	} else { // If prevous conditions are not met, year is NOT a leap year
		printf("The year %d is NOT a leap year.\n", n);
		return 1; // Return year = NOT leap year
	}
	
	
	
}