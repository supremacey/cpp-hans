
# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


CXXFLAGS += -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++11


main.out : Makefile   main.o rational.o matrix.o 
	$(CXX) $(CXXFLAGS) -o main.out   main.o rational.o matrix.o 

main.o : Makefile   main.cpp   matrix.h rational.h vector.h 
	$(CXX) -c $(CXXFLAGS) main.cpp -o  main.o


rational.o : Makefile   rational.cpp   rational.h 
	$(CXX) -c $(CXXFLAGS) rational.cpp -o  rational.o


matrix.o : Makefile   matrix.cpp   matrix.h rational.h vector.h 
	$(CXX) -c $(CXXFLAGS) matrix.cpp -o  matrix.o

clean: 
	rm -rf *.o main
 
.PHONY: clean

