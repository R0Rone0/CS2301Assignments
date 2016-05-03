all: stacktest queuetest tsorttest tsorttest2

stacktest: stacktest.o stack.o
	gcc -g --std=gnu89 stacktest.o stack.o -o stacktest

stack.o: stack.c stack.h
	gcc -g -c --std=gnu89 stack.c

stacktest.o: stacktest.c stack.h
	gcc -g -c --std=gnu89 stacktest.c

queuetest: queuetest.o queue.o
	gcc -g --std=gnu89 queuetest.o queue.o -o queuetest
	
queue.o: queue.c queue.h
	gcc -g -c --std=gnu89 queue.c
	
queuetest.o: queuetest.c queue.h
	gcc -g -c --std=gnu89 queuetest.c
	
tsorttest: tsorttest.o tsort.o
	gcc -g --std=gnu89 tsorttest.o tsort.o -o tsorttest
	
tsorttest.o: tsorttest.c tsort.h
	gcc -g -c --std=gnu89 tsorttest.c
	
tsorttest2: tsorttest2.o tsort.o
	gcc -g --std=gnu89 tsorttest2.o tsort.o -o tsorttest2
	
tsorttest2.o: tsorttest2.c tsort.h
	gcc -g -c --std=gnu89 tsorttest2.c
	
tsort.o: tsort.c tsort.h
	gcc -g -c --std=gnu89 tsort.c
	
docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2301assig6

clean:
	rm -f *.o
	rm -f stacktest queuetest tsorttest tsorttest2
