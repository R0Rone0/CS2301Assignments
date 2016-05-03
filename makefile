all: at at2 docs at3

at: at.o print_arrays.o
	gcc -g --std=gnu89 at.o print_arrays.o -o at

at.o: at.c
	gcc -g --std=gnu89 -c at.c

print_arrays.o: print_arrays.c
	gcc -g --std=gnu89 -c print_arrays.c
	
at2: at2.o store_array.o sort_array.o
	gcc -g --std=gnu89 at2.o store_array.o sort_array.o -o at2

at2.o: at2.c
	gcc -g --std=gnu89 -c at2.c
	
store_arrays.o: store_array.c
	gcc -g --std=gnu89 -c store_array.c
	
sort_array.o: sort_array.c
	gcc -g --std=gnu89 -c sort_array.c
	
at3: at3.o
	gcc -g --std=gnu89 at3.o store_array.o sort_array.o -o at3
	
at3.o: at3.c
	gcc -g --std=gnu89 -c at3.c
	
docs:
	doxygen
	chmod u+rwx html/*
	chmod g+r html/*
	chmod o+r html/*
	cp -pr html/* ~/public_html/cs2301assig2

clean:
	rm -f *.o at at2 docs at3
	