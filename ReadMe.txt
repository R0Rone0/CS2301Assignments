Name: Nick Green
CS 2301 Assignment 2

Doxygen comments: http://users.wpi.edu/~negreen/cs2301assig2/index.html

Program List:
at.c:
	Main program for demonstrating arrays. It fills them and prints them.
	Depends on print_int_array.c to print array on command line.
	Depends on print_arrays.h header.
	
	SAMPLE_IN_ARRAY_SIZE							default: 10
	
print_int_array.c:
	Print an array of ints, one per line. Used in at.c to print array input by user.
	Depends on print_arrays.h header.
	
at2.c:
	Main program for demonstrating arrays. It fills them, sorts them, and prints them
	from user input.
	Depends on store_array.c to store user input as int array.
	Depends on sort_array.c to sort int array in ascending order using bubble sort.
	Depends on at2.h header.
	
	SAMPLE_IN_ARRAY_SIZE							default: 10
	
store_array.c:
	Function to store input from command line into array of ints.
	Depends on at2.h header.
	
sort_array.c:
	Bubble sort function. Takes in array and arraySize and sorts in ascending order.
	Depends on sort_array.h header
	
at3.c:
	Main program for demonstrating arrays. It fills them with random numbers,
    sorts them in ascending order using bubble sort, and prints them.
	Depends on sort_array.c to populate array with random numbers.
	Depends on sort_array.c to sort array using bubble sort.
	Depends on at3.h header.
	
	SAMPLE_IN_ARRAY_SIZE							default: 10
	
populate_array.c:
	Populate random array function. Populates given array with random numbers.
	Depends on sort_array.h header.
	
rand_gen.c:
	Random number generator function. Takes in MAX rand and returns rand number.
	Depends on sort_array.h header.