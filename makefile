all:ctest

# Executable depends on the two object files
ctest: ctest.o mystring.o 
	gcc -g ctest.o mystring.o -o ctest

# Object file depends on source and header files
ctest.o: ctest.c mystring.h 
	gcc -g -c ctest.c

# Object file depends on source and header files
mystring.o: mystring.c mystring.h 
	gcc -g -c mystring.c

clean: 
	rm -f mystring.o ctest.o ctest

# Typing "make docs" will generate Doxygen files, set proper permissions,
# and copy into ~/public_html/cs2301assig3 .
docs:
	doxygen
	chmod u+rwx html/*
	chmod g+r html/*
	chmod o+r html/*
	cp -pr html/* ~/public_html/cs2301assig3
