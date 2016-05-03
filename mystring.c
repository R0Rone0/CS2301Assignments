/** mystring.c
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/
#include <string.h>
#include <stdlib.h>
// stdlib.h is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/

char* mystrdup(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  mystrcpy(newstr, src);
  return newstr;
}

/** Counts length of C-style string.
 * @param str Pointer to string to be counted
 * @return Number of elements in given src char array or null if no
 * 		   memory available
 */

size_t mystrlen(const char* str) {
	size_t len = 0; // Initialize len
	while(*str != '\0') { // If str index value is not NULL, then:
		str++; // Move to next index value in str array
		len++; // Increase value of string length
	}
	
	return len;
}

/** Copies C-style string to an array using pointers
 * @param array Pointer to target array string will be copied
 * @param src Pointer to char array to be copied
 * @return Target array with input char array value
 */

char* mystrcpy(char* array, const char* src) {
	char* new;
	
	while(*src) {
		*array++ = *src++;
	}
	
	*array = 0;
	
	return array;
}

/** Concatenates a src array to the end of a target array
 * @param src 
 * @param target
 * @return New combined array with target and src arrays together
 */
 
char* mystrcat(char* target, const char* src) {
	char* ptarget = target;
	
	while(*target) {
		target++;
	}
	while(*target++ = *src++) {
		;
	}
	return ptarget;
	
}

/** Concatenates a limited src array to the end of a target array
 * @param target Pointer to array to be added to
 * @param src Pointer to array to add to target array
 * @param limit Number of characters to concatenate to target from src
 * @return Pointer to target array with added characters
 */
char* mystrncat(char* target, const char* src, size_t limit) {
	int i;
	char* ptarget = target;
	
	ptarget = malloc(limit + mystrlen(target) + 1);
	
	while(*target != '\0') {
		target++;
	}
	while (++i <= limit) {
		*target++ = *src++;
	}
	
	*(++target) = '\0';
	
	return ptarget;
}

/** Copies C style string from a src array to a target array
 * @param target Pointer to target array
 * @param src Pointer to source array
 * @param limit Number of characters to copy from src
 * @return Pointer to target array
 */

char* mystrncpy(char* target, const char* src, size_t limit) {
	int i;
	char* ptarget;
	
	ptarget = target;
	
	for(i = 0; i < limit; i++) {
		*ptarget++ = *src++;
	}
	
	ptarget[i] = '\0';
	
	return ptarget;
}

/**Duplicates C style string with given limit
 * @param src Pointer to array to be duplicated
 * @param limit Number of characters to duplicate
 * @return New character array that is cloned from src
 */
 
 char* mystrndup(const char* src, size_t limit) {
	int length; // Length of the source string
	char* newstr; // Pointer to memory which will hold new string

	length = mystrlen(src) + 1;  // Leave space for the terminator
	newstr = (char*) malloc(length); // Must cast!

	// If no memory was available, return immediately
	if (newstr == 0) return (char *) 0;

	// Otherwise, copy the string and return pointer to new string
	mystrncpy(newstr, src, limit);
	return newstr;
 }
/** Creates pointer to character array of random characters
 * @return Pointer to random character array with size 10
 */
char* rand_char_array() {
	int i;

	char *temp = (char*)malloc(10);
		
	for(i = 0; i < 9; i++) {
		temp[i] = rand_char();
	}
	
	temp[9] = '\0';
	
	
	return temp;
	
	
}
/** Creates 1 random ASCII character
 * @return Random ASCII character
 */
char rand_char() {

	

	char randChar = 'A' + (rand() %26);


	return randChar;
}
