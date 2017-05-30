# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002

Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++11
CPP = g++

all: main.out
	./main.out

main.out : Makefile   main.o 
	$(CPP) $(Flags) -o main.out   main.o 

main.o : Makefile   main.cpp   units.h 
	$(CPP) -c $(Flags) main.cpp -o  main.o


clean:
	rm -f *.o *.out

.PHONY: clean

