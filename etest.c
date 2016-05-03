#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "etest.h"

#define OUTFILENAME "etest.txt"

int main() {
	printf("Starting program etest.\n"); 
	
	#ifdef TESTMODE
	printf("When the program runs: TESTMODE = %d\n", TESTMODE);
	#endif
	
	
	
	// Anybody recognize these names?
	Employee1* harry;
	harry = createEmployee1(50000, "Harry Palmer", "Ministry of Defence"); // Declare a local variable (a struct).
	

	Employee1* bluejay; // Declare a local variable (a struct).
	bluejay = createEmployee1(60000, "Erik Grantby", "Criminal");
	
	Employee1* nick;
	nick = createEmployee1(10000000, "Nick Green", "Student");
	
	Employee1* john;
	john = createEmployee1(40000, "John Doe", "Unemployed");

	// Output the employees to a file.
	printf("About to write to file %s.\n", OUTFILENAME);
	FILE *outfile = fopen(OUTFILENAME, "w+"); // Open or create file for writing
	if(outfile == NULL) {
		printf("Uh-oh! Error number: %d\n", errno);
		return 1;
	}
	outputEmployee1Verbose(outfile, harry);
	outputEmployee1Verbose(outfile, bluejay);
	outputEmployee1Verbose(outfile, nick);
	outputEmployee1Verbose(outfile, john);
	fclose(outfile); // Close the file

	// Output the employees to stdout.
	printEmployee1Verbose(harry);
	printEmployee1Verbose(bluejay);
	printEmployee1Verbose(nick);
	printEmployee1Verbose(john);

	printf("Ending program etest.\n"); 
	return 0;
}



