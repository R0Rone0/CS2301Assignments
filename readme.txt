Name: Nick Green
CS 2301 Assignment 1

Program List:
num.c:
	Program runs in UNIX terminal and takes inputs and displays them upon
 	execution. Program also calls outside function processGrades, which takes
 	the input values from main and determines the maximum, minimum, and average
 	values of the user defined inputs.
	
	Default Value:						MAX_GRADES = 20
	
	Inputting less than MAX_GRADES results in a WARNING message, telling user
	there is more space to use. Inputting more than MAX_GRADES results in an 
	ERROR message, telling user that not all grades are being taken into account
	by outside function processGrades. Inputting exactly 20 values does not
	produce any WARNING or ERROR messages.
	
processGrades.c:
	Call function processGrades which takes in grades array and integer
	value of input arguments.
	
	WARNING: Will not take grades outside of user defined limit when
	calculating max, min, and average values of grades.
	
leap.c:
	Program determines whether the year input by the user is a
 	leap year or not.
	
