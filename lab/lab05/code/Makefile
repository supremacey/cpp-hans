CXXFLAGS = -Wextra -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++11

main.out: Makefile tree.o main.o string.o
	$(CXX) $(CXXFLAGS) -o main.out tree.o main.o string.o

tree.o: Makefile   tree.cpp   tree.h 
	$(CXX) -c $(CXXFLAGS) tree.cpp -o tree.o

string.o: Makefile string.cpp string.h
	$(CXX) -c $(CXXFLAGS) string.cpp -o string.o

main.o: Makefile main.cpp tree.h 
	$(CXX) -c $(CXXFLAGS) main.cpp -o main.o

clean:
	rm -f *.o main.out

.PHONY: main
