#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "etest.h"

/** Outputs one Employee1 structure in verbose form, to an open file stream
 * @param stream The output stream to write to (must already be open).
 * @param employee Pointer to the structure to print
*/

void outputEmployee1Verbose(FILE *stream, Employee1 *employee) {
	fprintf(stream, "Employee1: Name = %s, Salary = %d, Department = %s\n",
		employee->name, employee->salary, employee->department);
}

/** Outputs one Employee1 structure in verbose form, to an open file stream without extra text
 * @param stream The output stream to write to (must already be open).
 * @param employee Pointer to the structure to print
*/
void outputEmployee1Verbose2(FILE *stream, Employee1 *employee) {
	fprintf(stream, "%s\n%d\n%s\n", employee->name, employee->salary, employee->department);
}

/** Outputs one Employee2 structure in verbose form, to an open binary file
 * @param fd File descriptor of file to write to
 * @param employee Pointer to the structure to print
 */
void outputEmployee2Verbose2(int fd, Employee2 *employee) {
	write(fd, employee->name, MAX_NAME);
	write(fd, &employee->salary, sizeof(int));
	write(fd, employee->department, MAX_DEPT);
}

/** Prints one Employee1 structure in verbose form
 * @param employee Pointer to the structure to print
 */

void printEmployee1Verbose(Employee1 *employee) {
	// Save effort -- make use of other function already written!
	outputEmployee1Verbose(stdout, employee);
}

/** Prints one Employee2 structure in verbose form
 * @param employee Pointer to the structure to print
 */
void printEmployee2Verbose(Employee2 *employee) {
	printf("Employee1: Name = %s, Salary = %d, Department = %s\n", 
			employee->name, employee->salary, employee->department);
}

/** Fills in the fields of an Employee1 structure
 * @param emp Pointer to the struct. MUST ALREADY EXIST!
 * @param salary Annual salary in dollars
 * @param name Character string holding the name. Gets duplicated,
 *    and the pointer to the duplicate is put into struct.
 */
void fillinEmployee1(Employee1* emp, int salary, char* name, char* department) {
	emp->salary = salary;
	emp->name = strdup(name);
	emp->department = strdup(department);
}

/** Allocates an Employee1 struct and fills in its fields. 
 * @param salary Annual salary in dollars
 * @param name Character string holding the name. Gets duplicated,
 *    and the pointer to the duplicate is put into struct.
 * @param department Character string holding the department. Gets duplicated,
 *    and the pointer to the duplicate is put into struct.
 * @return Pointer to the newly-allocated struct.
 */
Employee1* createEmployee1(int salary, char* name, char* department) {
	Employee1* emp = (Employee1*) malloc(sizeof(Employee1));
	
	emp->salary = salary;
	emp->name = strdup(name);
	emp->department = strdup(department);
	
	return emp;
}

/** Allocates an Employee1 struct and fills in its fields. 
 * @param salary Annual salary in dollars
 * @param name Character string holding the name. Gets duplicated,
 *    and the pointer to the duplicate is put into struct.
 * @param department Character string holding the department. Gets duplicated,
 *    and the pointer to the duplicate is put into struct.
 * @return Pointer to the newly-allocated struct.
 */
Employee2* createEmployee2(int salary, char* name, char* department) {
	Employee2* emp = (Employee2*) malloc(sizeof(Employee2));
	
	emp->salary = salary;
	strncpy(emp->name, name, MAX_NAME);
	strncpy(emp->department, department, MAX_DEPT);
	
	return emp;
}

/** Writes an Employee1 struct to specified file
 * @param outfileName Pointer to file to write Employee1 struct to
 * @param empArr Pointer to array of Employee1 pointers
 * @param arrSize Number of total Employee1 structs in array
 */
 void writeEmployee(char* outfileName, Employee1** empArr, int arrSize) {
	// Output the employees to a file.
	printf("About to write to file %s.\n", outfileName);
	FILE *outfile = fopen(outfileName, "w+"); // Open or create file for writing
	
	int j;
	
	if(outfile == NULL) {
		printf("Uh-oh! Error number: %d\n", errno);
		return;
	}
	
	for(j = 0; j < arrSize; j++) {
		outputEmployee1Verbose2(outfile, empArr[j]);
	}
	
	fclose(outfile); // Close the file
}

/** Writes an Employee2 struct to specified binary file
 * @param outfileName Pointer to file to write Employee1 struct to
 * @param empArr Pointer to array of Employee1 pointers
 * @param arrSize Number of total Employee1 structs in array
 */
void writeEmployee2(char* outfileName, Employee2** empArr, int arrSize) {
	// Output the employees to a file.
	printf("About to write to file %s.\n", outfileName);
	int fd = open(outfileName, O_WRONLY | O_CREAT | O_TRUNC, 0666); // Open or create file for writing
	
	int j;
	
	if(fd == -1) {
		printf("Uh-oh! Error number: %d\n", errno);
		return;
	}
	
	for(j = 0; j < arrSize; j++) {
		outputEmployee2Verbose2(fd, empArr[j]);
	}
	
	close(fd); // Close the file
}

/** Trims a C-style string by one character at the end, and replaces it with the NULL character
 * @param line Pointer to string to trim
 * @param line
 */
char* trim(char* line) {
	size_t len = strlen(line);
  if (len > 0 && line[len-1] == '\n') {
    line[--len] = '\0';
  }
  
  return line;
}

/** Reads Employee1 data structure from txt file
 * @param file Pointer to txt file to read Employee1 data from
 * @return Employee1
 */
Employee1* read1Employee(FILE *file) {
	char line1[MAX_NAME + 1], line2[50], line3[MAX_DEPT + 1];
	
	if(fgets(line1, sizeof line1, file) == NULL)
		return NULL;
	if(fgets(line2, sizeof line2, file) == NULL)
		return NULL;
	if(fgets(line3, sizeof line3, file) == NULL)
		return NULL;
	
	return createEmployee1(atoi(line2), trim(line1), trim(line3));
}

/** Reads Employee1 data structure from txt file
 * @param fd Pointer to bin file to read Employee2 data from
 * @return Employee2
 */
Employee2* read1Employee2(int fd) {
	char line1[MAX_NAME + 1], line3[MAX_DEPT + 1];
	int salary;
	
	if(read(fd, line1, MAX_NAME) == -1)
		return NULL;
	if(read(fd, &salary, sizeof(int)) == -1)
		return NULL;
	if(read(fd, line3, MAX_DEPT) == -1)
		return NULL;
	
	return createEmployee2(salary, trim(line1), trim(line3));
}

