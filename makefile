all: lab1 leap num

lab1: lab1.o
	gcc --std=gnu89 lab1.o -o lab1

lab1.o: lab1.c
	gcc --std=gnu89 -c lab1.c

leap: leap.o
	gcc --std=gnu89 leap.o -o leap

leap.o: leap.c
	gcc --std=gnu89 -c leap.c
	
num: num.o processGrades.o
	gcc --std=gnu89 num.o processGrades.o -o num
	
num.o: num.c
	gcc --std=gnu89 -c num.c
	
processGrades.o: processGrades.c
	gcc --std=gnu89 -c processGrades.c
	
clean:
	rm -f *.o lab1 leap num