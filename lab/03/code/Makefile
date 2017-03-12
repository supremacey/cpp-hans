CPPC := g++
CFLAGS := -Wall -pedantic -std=c++11
SRC := $(shell ls *.cpp *.h)
OUT := $(subst .cpp,.out,$(SRC))

all: $(OUT)
	@echo "All: Done! --------------------------------------------------"

test: all
	@ echo "Starting test ----------------------------------------------"
	@ ./main.out

valgrind: all
	@ valgrind ./main.out

%.out: %.cpp
	$(CPPC) $(CFLAGS) $< -o $@
	@ echo "------------------------------------------------------------"

clean:
	@rm -rf $(shell ls *.out)
	@echo "Cleaning: Done! ---------------------------------------------"

.PHONY: clean
