#ifndef SORT_H
#define SORT_H

// Function prototypes:
void timesort (int a[], int count, int sortType);
void print_int_array(int nums[], int count);
void sort_descending(int nums[], int count);
void print_timeval(struct timeval t);
struct timeval timediff(struct timeval time1, struct timeval time2);
void populate_array(int* a, int arraySize);
int rand_gen();
void sort_descending_pointers(int* nums, int count);

#endif
