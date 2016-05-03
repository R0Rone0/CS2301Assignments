/** mystring.h
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

char* mystrdup(const char* src);
size_t mystrlen(const char* str);
char* mystrcpy(char* array, const char* string);
char* mystrcat(char* target, const char* src);
char* mystrncpy(char* target, const char* src, size_t limit);
char* mystrncat(char* target, const char* src, size_t limit);
char* mystrndup(const char* src, size_t limit);
char* rand_char_array();
char rand_char();
