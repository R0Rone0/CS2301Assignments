#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "etest.h"


#define OUTFILENAME "etest.txt"
#define OUTFILENAME2 "etest1.txt"



int main() {
	printf("Starting program etest.\n"); 
	
	int arrSize;
	int i, j;
	char* line;
	int numRead;
	
	
	printf("How many employees do you want to read?\n");
	scanf("%d", &arrSize);
	
	Employee1** empArr = (Employee1**)calloc(arrSize, sizeof(Employee1*));
	
	FILE *file = fopen(OUTFILENAME2, "r"); // Open file for reading
	
	numRead = 0;
	while((empArr[numRead] = read1Employee(file)) != NULL) {
		numRead++;
		if(numRead == arrSize)
			break;
	}
	
	fclose(file);
	
	if(numRead < arrSize) {
		fprintf(stderr, "WARNING: Less entries in file than requested.\n");
	} else if(numRead > arrSize) {
		fprintf(stderr, "WARNING: More entries in file than requested.\n");
	}
		
	for(i = 0; i < numRead; i++) {
		printEmployee1Verbose(empArr[i]);
	}
	
	// Output the employees to a file.
	
	
	for(j = 0; j < numRead; j++) {
		free(empArr[j]->name);
		free(empArr[j]->department);
		free(empArr[j]);
	}
	free(empArr);
	
	printf("Ending program etest.\n"); 
	return 0;
}



