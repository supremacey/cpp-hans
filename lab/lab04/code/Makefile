##################### Original Makefile #############################
#
# Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++11
# 
# main : main.o string.o 
# 	g++ -o main main.o string.o $(Flags)
# 
# string.o : string.cpp string.h
# 	g++ -o string.o -c string.cpp $(Flags)
# 
# main.o : main.cpp string.h
# 	g++ -o main.o -c main.cpp $(Flags) 
# 
##################### Improved Makefile #############################
CXXFLAGS += -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++11

main : main.o string.o 
	$(CXX) -o main main.o string.o $(CXXFLAGS)

string.o : string.cpp string.h
	$(CXX) -o string.o -c string.cpp $(CXXFLAGS)

main.o : main.cpp string.h tests.h
	$(CXX) -o main.o -c main.cpp $(CXXFLAGS) 

clean:
	-@rm main.o string.o main

PHONY: clean
