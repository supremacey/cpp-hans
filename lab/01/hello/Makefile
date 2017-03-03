CPPC := g++-6 #clang++
CFLAGS := -Wall -Wextra -pedantic -std=c++11 -g 
SRC := $(shell ls *.cpp)
OUT := $(subst .cpp,,$(SRC))

all: $(OUT)

%: %.cpp
	$(CPPC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OUT)

.PHONY: clean all

