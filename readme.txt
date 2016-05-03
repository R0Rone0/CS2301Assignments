Author: Nick Green
Username: negreen
CS 2301 Assignment 4

Doxygen comments: http://users.wpi.edu/~negreen/cs2301assig4/index.html

Program List:
sorttest.c:
	Initial main program that takes in integers and sorts these integers in 
	descending order. Program has no limit of integers that can be input into
	program. Program also gets timestamps from before and after sorting 
	integers, in order to find the time it took to sort the numbers.
	
	User Inputs: At least 2 integers to run. No maximum limit on integers.
	
	Sorting 2 integers: Time = 2 microseconds

sorttest2.c:
	New main program that takes in 2 integer values from the user, however,
	does not sort these integers. The first value input is a array size for the
	array in which random numbers are stored. This integer can be any value
	greater than 1. The second value, either a 1 or 2, defines which sorting
	method will be used to sort the randomly generated values in the array.
	A value of 1 will sort the values by indexing the array, as in sorttest.c.
	A value of 2 will sort the values using incrementing pointers.
	
	User Inputs: 1: Max array size of random numbers to sort.
				 2: Sort type => 0: Descending bubble sort by indexing
								 1: Descending bubble sort by pointers
								 
	Sort 100000 random numbers in descending order:
		sortType = 0: 46 seconds, 478126 microseconds
		sortType = 1: 43 seconds, 508761 microseconds
		
		sortType = 1 was 2 seconds, 969365 microseconds faster
		
		NOTE: Random seed was turned OFF for this test
			  (same array was sorted)
	
timesort.c:
	Contains function timesort(), which takes in an array, arraySize, and 
	sortType, and sorts the given array values according to the selected 
	sorting algorithm. 
	
	This function is called in both the sorttest.c and sorttest2.c files.
	In sorttest.c, the sortType is fixed at 1, so it will always sort by 
	indexing the array. In sorttest2.c, this the sortType is user defined
	on the command line.

sort.c:
	Contains sorting functions and random number generator for random array.
	Two sorting functions are included here:
		sortType = 0: sort_descending(int nums[], int count);
		sortType = 1: sort_descending_pointers(int* nums, int count);
	Contains print functions to print integer arrays and timestamp values.
	Contains a struct to store values of time elapsed for a sort test.
	Contains function to populate array with random integers.

