#ifndef ETEST_H
#define ETEST_H

#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME 40
#define MAX_DEPT 40

// Define some structures
struct _employee1 {
  int salary; // Monthly salary in US dollars
  char *name; // Pointer to character string holding name of employee.
              // MUST be dynamically allocated from the heap.
  char *department;
};

struct _employee2 {
  int salary; // Monthly salary in US dollars
  char name[MAX_NAME + 1]; // Character string holding name of employee.
  char department[MAX_DEPT + 1];
};

typedef struct _employee1 Employee1; // For convenience
typedef struct _employee2 Employee2; // For convenience
typedef struct _employee1 emp;

// function prototypes
void printEmployee1Verbose(Employee1 *employee);
void outputEmployee1Verbose(FILE *stream, Employee1 *employee);
void fillinEmployee1(Employee1* emp, int salary, char* name, char* department);
void outputEmployee1Verbose2(FILE *stream, Employee1 *employee);
void writeEmployee(char* outfileName, Employee1** empArr, int arrSize);
void writeEmployee2(char* outfileName, Employee2** empArr, int arrSize);
void printEmployee2Verbose(Employee2 *employee);
Employee1* createEmployee1(int salary, char* name, char* department);
Employee1* read1Employee(FILE *file);
Employee2* createEmployee2(int salary, char* name, char* department);
Employee2* read1Employee2(int fd);

#endif
