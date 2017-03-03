CC := clang++
CFLAGS := -Wall -pedantic -std=c++11 
SRC := $(shell ls *.cpp)
OUT := $(subst .cpp,.out,$(SRC))

all: $(OUT) 

%.out: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OUT)

.PHONY: clean
