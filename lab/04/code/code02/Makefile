include ../Makefile.include

main.out:  main.o rational.o matrix.o 
	$(CXX) $(CXXFLAGS) -o main.out main.o rational.o matrix.o 

main.o: main.cpp matrix.h rational.h vector.h 
	$(CXX) -c $(CXXFLAGS) main.cpp -o main.o


rational.o: rational.cpp rational.h 
	$(CXX) -c $(CXXFLAGS) rational.cpp -o rational.o


matrix.o: matrix.cpp matrix.h rational.h vector.h 
	$(CXX) -c $(CXXFLAGS) matrix.cpp -o matrix.o

clean: 
	@rm -f *.o main.out
 
.PHONY: clean

