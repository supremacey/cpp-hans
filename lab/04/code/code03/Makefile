include ../Makefile.include

SRC := $(shell ls *.cpp)
HPP := $(shell ls *.h)
OBJ := $(SRC:.cpp=.o)

main.out: $(OBJ) $(HPP)
	$(CXX) -o main.out $(OBJ)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	@rm -f $(OBJ) main.out

.PHONY: clean
