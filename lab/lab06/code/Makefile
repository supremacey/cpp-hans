# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002
CXXFLAGS = -Wextra -Wundef -Wpedantic -Wreturn-type -Wall -std=c++11 -O3 -flto


nr06 : Makefile nr06.o listtest.o vectortest.o 
	$(CXX) $(CXXFLAGS) -o nr06.out   nr06.o listtest.o vectortest.o 

nr06.o : Makefile   nr06.cpp   vectortest.h listtest.h timer.h
	$(CXX) -c $(CXXFLAGS) nr06.cpp -o  nr06.o


listtest.o : Makefile   listtest.cpp   listtest.h 
	$(CXX) -c $(CXXFLAGS) listtest.cpp -o  listtest.o


vectortest.o : Makefile   vectortest.cpp   vectortest.h 
	$(CXX) -c $(CXXFLAGS) vectortest.cpp -o  vectortest.o

clean: 
	rm *.o nr06.out

.PHONY: clean
