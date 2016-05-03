Name: Nick Green
Username: negreen
CS 2301 Assignment 5

Doxygen Comments: http://users.wpi.edu/~negreen/cs2301assig5/index.html

File List:
etest.c:
	Program creates 4 employee structs and fills them with data. Program then
	puts these structs in text file which can be accessed through VI. Program
	will then print structs on command line for user.
	
	File: etest.txt
	
	Variation: etest-testmode
		To run testmode version of etest.c, input ./etest-testmode into
		command line. This will define TESTMODE and run any code commented
		out through conditional compilation.
	
etest2.c:
	Program prompts user to input data to fill in Employee structs. Program
	asks how many employees will be input to allocate appropiate memory, then
	prompts user for the name, salary, and department of employee. After all
	data fields have been input, struct is written to text file.
	
	File: etest1.txt
	
etest3.c:
	Program prompts user to determine the number of employee structs to read
	from etest2.c text file holding employee data. If number requested by user
	is either more or less than the amount of data in the text file, a warning
	is displayed informing the user.
	
	File: etest1.txt
	
etest6.c:
	Program prompts user to input data to fill in Employee structs. Program
	asks how many employees will be input to allocate appropiate memory, then
	prompts user for the name, salary, and department of employee. After all
	data fields have been input, struct is written to bin file.
	
	File: etest6.bin
	
etest7.c:
	Program prompts user to determine the number of employee structs to read
	from etest6.c bin file holding employee data. If number requested by user
	is either more or less than the amount of data in the text file, a warning
	is displayed informing the user.
	
	File: etest6.bin


	