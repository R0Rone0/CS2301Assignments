#include <stdio.h>
#include <string.h>
// string.h covers the C-style string functions.
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Mike Ciaraldi
 */

const int MAX_CHARS = 50; // Maximum number of characters in array

/** @struct Employee
 *  @var Employee::name
 *  Name contains name of the employee
 *  @var Employee::birthYear
 *  birthYear contains the birth year of the employee
 *  @var Employee:: startYear
 *  startYear contains the start year of the employee
 */
struct Employee {
	char *name;
	int birthYear;
	int startYear;
};

struct Employee *make_employee(char *name, int birthYear, int startYear)
{
    struct Employee *who = malloc(sizeof(struct Employee));
    

    who->name = strdup(name);
    who->birthYear = birthYear;
    who->startYear = startYear;
    
    return who;
}

struct Employee* random_employee() {
	

	char *name = rand_char_array();
	int birthYear = (rand() % 99);
	int startYear = (rand() % 99);
	struct Employee* temp = make_employee(name, birthYear, startYear);
	return temp;
}

/** Frees memory allocated to Employee struct
 * @var Employee::who
 * Input which Employee to delete
 */
void Employee_destroy(struct Employee *who)
{
    

    free(who->name);
    free(who);
}

/** Prints data stored in Employee struct
 * @var Employee::who
 * Input which Employee to print
 */
void Employee_print(struct Employee *who)
{	
    printf("Name: %s\n", who->name);
    printf("Birth Year: %d\n", who->birthYear);
    printf("Start Year: %d\n", who->startYear);
}


int main()
{
  char a1[MAX_CHARS + 1]; // Character array--initially empty
  char a2[] = "Hello"; // Character array--unsized but initialized
  char a3[MAX_CHARS + 1]; // Character array--we will underfill it
  char* p1 = "Hello"; // Pointer to constant string
  char* p2;           // Will be a pointer to dynamically-allocated string
  int copy_limit;     // Maximum characters to copy.

  mystrcpy(a3, "Hello, also"); // Initialize underfilled character array

  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
  printf("          p1 = %p p2 = %p\n", p1, p2);
  
  printf("\n");
  
  mystrcpy(a1, "Hi"); // Initialize character array

  printf("Contents of a1 = %s\n", a1);
  printf("Contents of a2 = %s\n", a2);
  printf("Contents of a3 = %s\n", a3);
  
  printf("\n");

  // Concatenate two character arrays, then print.
  printf("mystrcat TEST\n");
  mystrcat(a1, a2);
  printf("After concatenating a2 to a1, contents of a1 = %s\n", a1);
  
  printf("\n");
  
  // Concatenate two character arrays with limit, then print.
  printf("mystrncat TEST\n");
  mystrncat(a1, a2, 8);
  printf("After concatenating a2 to a1, max length 8, contents of a1 = %s\n",
         a1);
  
  printf("\n");

  // Copy with limit.
  printf("mystrncpy TEST 1\n");
  mystrncpy(a1, a2, 3);
  printf("After copying a2 to a1, max length 3, contents of a1 = %s\n", a1);
  printf("Note that copied string was not terminated.\n");
  
  printf("mystrncpy TEST 2\n");
  mystrcpy(a1,"Hi"); // reset a1
  mystrncpy(a1, a2, 10);
  printf("After copying a2 to a1, max length 10, contents of a1 = %s\n", a1);
  printf("Note that copied string was not terminated.\n");
  
  printf("\n");

  // Reset a1
  mystrcpy(a1, "Hi"); // Initialize character array
  printf("Resetting. a1 = %s\n", a1);
  
  printf("\n");

  // Concatenate two character arrays with limit, then print.
  printf("mystrncat TEST\n");
  mystrncat(a1, a2, 2);
  printf("After concatenating a2 to a1, max length 2, contents of a1 = %s\n",
         a1);
  printf("Note that copied string was terminated.\n");
  
  printf("\n");
  
  // Duplicate a string, using my function, then print
  printf("strdup TEST 1\n");
  printf("Before dup, pointer a2 = %p, contents = %s\n", a2, a2);
  p2 = strdup(a2);
  printf("After dup, pointer p2 = %p, contents = %s\n", p2, p2);
  
  printf("mystrndup TEST 2: Limit < strlen\n");
  printf("Before dup, pointer a2 = %p, contents = %s\n", a2, a2);
  p2 = mystrndup(a2, 3);
  printf("After dup, pointer p2 = %p, contents = %s\n", p2, p2);
  
  printf("mystrndup TEST 3: Limit > strlen\n");
  printf("Before dup, pointer a2 = %p, contents = %s\n", a2, a2);
  p2 = mystrndup(a2, 10);
  printf("After dup, pointer p2 = %p, contents = %s\n", p2, p2);

  printf("mystrndup TEST 4: Limit = strlen\n");
  printf("Before dup, pointer a2 = %p, contents = %s\n", a2, a2);
  p2 = mystrndup(a2, 5);
  printf("After dup, pointer p2 = %p, contents = %s\n", p2, p2);
  
  printf("\n");
  
  // Structs
  printf("Define Employee Struct with data\n");
 
  srand(time(NULL));
  
  // Create Employee1
  struct Employee *Employee1 = make_employee(
            "Nick Green", 1995, 2013);
  printf("\n");	
  printf("Employee1 Data:\n");
  
  Employee_print(Employee1);

  // Create Employee2
  struct Employee *Employee2 = random_employee();
  printf("\n");
  printf("Employee2 Data:\n");

  Employee_print(Employee2);
  
  printf("\n"); 
  
  // Shallow Copy
  printf("Original address: E1: %p; E2: %p\n", &Employee1, &Employee2);
  memcpy(Employee2,Employee1,sizeof(struct Employee)); // Copy Employee1 INTO Employee2
  printf("New address: E1: %p; E2: %p\n", &Employee1, &Employee2); 

  // Free memory used by Employee structs
  Employee_destroy(Employee1);
  Employee_destroy(Employee2);


  return 0;
}
