Name: Nick Green
Username: negreen
CS 2301 Assignment 6

Doxygen URL: http://users.wpi.edu/~negreen/cs2301assig6/index.html

Source Files:
stacktest.c:
	Main function for stacktest executable. Program creates a stack data struct
	that can have data pushed on, popped off, and looked at by a user. Program
	also tests functionality of stack through systematic testing.
	
	Stack: LIFO (Last In First Out) data struct
	
	Defaults: MAX_STACK_SIZE 5
	
	Functions: stack.c
			   stack.h
	
stack.c:
	Source file containing functions for stacktest.c source file. File contains
	functions that allow user to interact with stack data struct. User can push
	data to struct, pop data from struct, and peek at data in struct.
	
queuetest.c:
	Main function for queuetest executable. Program creates a queue data struct
	that can have data pushed on, popped of, and looked at by a user. Program
	also test functionality of queue through systematic testing.
	
	Queue: FIFO (First In First Out) data struct
	
	Defaults: MAX_QUEUE_SIZE 5
	
	Functions: queue.c
			   queue.h
	
queue.c:
	Source file containing functions for queuetest.c source file. File contains
	functions that allow user to interact with queue data struct. User can push
	data to struct, pop data from struct, and peek at data in struct.
	
tsorttest.c:
	Main function for tsorttest executable. Program creates a binary tree
	filled with integers defined by user input. Program then puts these
	integers in a binary tree, and sorts them in descending order using one
	of 3 algorithms: Pre-Order, In-Order, & Post-Order.
	
	Defaults: arraySize 10
	
	Functions: tsort.c
			   tsort.h
	
tsorttest2.c:
	Main function for tsorttest2 executable. Program creates a binary tree
	filled with random integers. Program then puts these integers in a 
	binary tree, and sorts them in descending order using one of 3 algorithms:
	Pre-Order, In-Order, & Post-Order.
	
	Defaults: arraySize 10
	
	Functions: tsort.c
			   tsort.h
	
tsort.c:
	Source file containing functions for tsorttest.c and tsorttest2.c source
	files. File contains functions to create a binary tree, sort a tree using
	1 of 3 algorithms, free a tree using 1 of 3 algorithms, and generate random
	integers to fill in a specified array.
	
