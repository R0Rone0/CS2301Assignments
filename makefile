all: life

life: life.o board.o
	gcc -g life.o board.o -lreadline -lncurses -o life

life.o: life.c life.h
	gcc -g -c --std=gnu89 life.c

board.o: board.c life.h
	gcc -g -c --std=gnu89 board.c


clean:
	rm -f *.o life

docs:
	doxygen
	chmod a+r,a-x html/*
	cp -p html/* ~/public_html/cs2301assig7
