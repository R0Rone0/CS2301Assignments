#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "etest.h"


#define OUTFILENAME "etest.txt"
#define OUTFILENAME2 "etest6.bin"



int main() {
	printf("Starting program etest.\n"); 
	
	#ifdef TESTMODE
	printf("When the program runs: TESTMODE = %d\n", TESTMODE);
	#endif
	
	
	int arrSize;
	int i = 0, j = 0;
	char* line;
	
	printf("How many employees are you inputting?\n");
	scanf("%d", &arrSize);
	
	int newSalary;
	char newName[MAX_NAME + 1], newDepartment[MAX_DEPT + 1];
	Employee2** empArr = (Employee2**)calloc(arrSize, sizeof(Employee2*));
	
	
	while(i < arrSize) {
		
		
		printf("Enter Employee Name: ");
		scanf("%s", newName);
		do{
			line = readline("Enter Employee Salary: ");
		} while (sscanf(line, "%d", &newSalary) <= 0);
		printf("Enter Employee Department: ");
		scanf("%s", newDepartment);
		
		
		Employee2* employee = createEmployee2(newSalary, newName, newDepartment);
		empArr[i] = employee;
		i++;
	}
	
	// Output the employees to a file.
	writeEmployee2(OUTFILENAME2, empArr, arrSize);
	
	for(j = 0; j < arrSize; j++) {
		free(empArr[j]);
	}
	free(empArr);
	
	printf("Ending program etest.\n"); 
	return 0;
}



