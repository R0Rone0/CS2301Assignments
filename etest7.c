#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "etest.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define OUTFILENAME "etest.txt"
#define OUTFILENAME2 "etest6.bin"



int main() {
	printf("Starting program etest.\n"); 
	
	int arrSize;
	int i, j;
	char* line;
	int numRead;
	
	
	printf("How many employees do you want to read?\n");
	scanf("%d", &arrSize);
	
	Employee2** empArr = (Employee2**)calloc(arrSize, sizeof(Employee2*));
	
	int fd = open(OUTFILENAME2, O_RDONLY); // Open file for reading
	
	numRead = 0;
	while((empArr[numRead] = read1Employee2(fd)) != NULL) {
		numRead++;
		if(numRead == arrSize)
			break;
	}
	
	close(fd);
	
	if(numRead < arrSize) {
		fprintf(stderr, "WARNING: Less entries in file than requested.\n");
	}
		
	for(i = 0; i < numRead; i++) {
		printEmployee2Verbose(empArr[i]);
	}
	
	// Output the employees to a file.
	
	
	for(j = 0; j < numRead; j++) {
		free(empArr[j]);
	}
	free(empArr);
	
	printf("Ending program etest.\n"); 
	return 0;
}



