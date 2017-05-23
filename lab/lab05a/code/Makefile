SRC_DIR = ./src
BIN_DIR = ./bin
CXXFLAGS += -Wextra -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++11

all: prebuild main sample1.o

prebuild:
	mkdir -p $(BIN_DIR)

main: Makefile tree.o main.o string.o
	$(CXX) $(CXXFLAGS) -o main.out \
	$(BIN_DIR)/tree.o $(BIN_DIR)/main.o $(BIN_DIR)/string.o

tree.o: Makefile   $(SRC_DIR)/tree.cpp   $(SRC_DIR)/tree.h 
	$(CXX) -c $(CXXFLAGS) $(SRC_DIR)/tree.cpp \
	-o $(BIN_DIR)/tree.o

string.o: Makefile $(SRC_DIR)/string.cpp $(SRC_DIR)/string.h
	$(CXX) -c $(CXXFLAGS) $(SRC_DIR)/string.cpp \
	-o $(BIN_DIR)/string.o

sample1.o: Makefile $(SRC_DIR)/sample1.cc $(SRC_DIR)/sample1.h
	$(CXX) -c $(CXXFLAGS) $(SRC_DIR)/sample1.cc \
	-o $(BIN_DIR)/sample1.o

main.o: Makefile $(SRC_DIR)/main.cpp $(SRC_DIR)/tree.h 
	$(CXX) -c $(CXXFLAGS) $(SRC_DIR)/main.cpp \
	-o $(BIN_DIR)/main.o

clean:
	rm -rf $(BIN_DIR) main.out

.PHONY: test prebuild main
