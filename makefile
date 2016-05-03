all: etest etest2 etest3 etest6 etest7 etest-testmode

etest: etest.o struct.o
	gcc -g etest.o struct.o -o etest

etest.o: etest.c etest.h
	gcc -g -c --std=gnu89 etest.c

etest2: etest2.o struct.o
	gcc -g etest2.o struct.o -o etest2 -lreadline -lcurses
	
etest2.o: etest2.c etest.h
	gcc -g -c --std=gnu89 etest2.c -o etest2.o
	
etest3: etest3.o struct.o
	gcc -g etest3.o struct.o -o etest3
	
etest3.o: etest3.c etest.h
	gcc -g -c --std=gnu89 etest3.c -o etest3.o
	
etest6: etest6.o struct.o
	gcc -g etest6.o struct.o -o etest6 -lreadline -lcurses
	
etest6.o: etest6.c etest.h
	gcc -g -c --std=gnu89 etest6.c -o etest6.o
	
etest7: etest7.o struct.o
	gcc -g etest7.o struct.o -o etest7
	
etest7.o: etest7.c etest.h
	gcc -g -c --std=gnu89 etest7.c -o etest7.o

struct.o: struct.c etest.h
	gcc -g -c --std=gnu89 struct.c -o struct.o
	
etest-testmode: etest-testmode.o struct.o
	gcc -g etest-testmode.o struct.o -o etest-testmode 

etest-testmode.o: etest.c etest.h
	gcc -g -DTESTMODE=1 -c --std=gnu89 etest.c -o etest-testmode.o

clean:
	rm -f *.o etest etest2 etest3 etest6 etest7 etest-testmode

docs:
	doxygen
	chmod u+rwx html/*
	chmod g+r html/*
	chmod o+r html/*
	cp -pr html/* ~/public_html/cs2301assig5
