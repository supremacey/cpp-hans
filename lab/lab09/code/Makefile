# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++11 -Wextra
CPP = g++

default: test.out

main.out : Makefile   main.o powerproduct.o bigint.o rational.o 
	$(CPP) $(Flags) -o main.out   main.o powerproduct.o bigint.o rational.o 

main.o : Makefile   main.cpp   rational.h bigint.h polynomial.h powerproduct.h 
	$(CPP) -c $(Flags) main.cpp -o  main.o

test.out: Makefile test.cpp powerproduct.o bigint.o rational.o
	$(CPP) $(Flags) test.cpp powerproduct.o bigint.o rational.o -o $@
	@echo ""
	@echo "Starting test.out ----------------------------------------------------"
	./test.out

powerproduct.o : Makefile   powerproduct.cpp   powerproduct.h 
	$(CPP) -c $(Flags) powerproduct.cpp -o  powerproduct.o


bigint.o : Makefile   bigint.cpp   bigint.h 
	$(CPP) -c $(Flags) bigint.cpp -o  bigint.o


rational.o : Makefile   rational.cpp   rational.h bigint.h 
	$(CPP) -c $(Flags) rational.cpp -o  rational.o


clean:
	rm -f *.out *.o

.PHONY: clean


