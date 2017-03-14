CPPC := g++
CFLAGS := -Wall -pedantic -std=c++11
SRC := $(shell ls *.cpp)
HPP := $(shell ls *.h)
OUT := $(subst .cpp,.o,$(SRC))

all: $(OUT) $(HPP)
	@ echo "Starts linking! ---------------------------------------------"
	$(CPPC) $^ -o main.out
	@ echo "All: Done! --------------------------------------------------"

test: all
	@ echo "Starting test -----------------------------------------------"
	@ ./main.out

valgrind: all
	@ valgrind ./main.out

%.o: %.cpp
	$(CPPC) -c $(CFLAGS) $< -o $@
	@ echo "-------------------------------------------------------------"

clean:
	@ rm -rf $(OUT) main.out
	@ echo "Cleaning: Done! ---------------------------------------------"

.PHONY: clean
