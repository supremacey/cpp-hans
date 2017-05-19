# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002

Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++11 -Wextra
CPP = g++


solve : Makefile   solve.o fifteen.o 
	$(CPP) $(Flags) -o solve.out   solve.o fifteen.o 

solve.o : Makefile   solve.cpp   fifteen.h move.h 
	$(CPP) -c $(Flags) solve.cpp -o  solve.o


fifteen.o : Makefile   fifteen.cpp   fifteen.h move.h 
	$(CPP) -c $(Flags) fifteen.cpp -o  fifteen.o

clean:
	rm -f *.out *.o

.PHONY: clean

