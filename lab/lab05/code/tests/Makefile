# Where to find code.
USER_DIR = ..
SRC_DIR = $(USER_DIR)/src
BIN_DIR = $(USER_DIR)/bin

TEST_DIR = $(USER_DIR)/tests
TSRC_DIR = $(TEST_DIR)/src
TBIN_DIR = $(TEST_DIR)/bin

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = sample1_unittest.out

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = $(USER_DIR)/../../googletest

GTEST_BIN = $(GTEST_DIR)/bin

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread


all: test

test: pre_test $(TESTS)

pre_test:
	mkdir -p $(TBIN_DIR)

sample1_unittest.o : $(TSRC_DIR)/sample1_unittest.cc \
                     $(SRC_DIR)/sample1.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TSRC_DIR)/sample1_unittest.cc \
	-o $(TBIN_DIR)/$@

sample1_unittest.out : sample1_unittest.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread \
	$(BIN_DIR)/sample1.o \
	$(TBIN_DIR)/sample1_unittest.o \
	$(GTEST_BIN)/gtest_main.a \
	-o $@

#---------------------------------------- 
clean:
	rm -rf $(TESTS) $(TBIN_DIR)

.PHONY: pre_test clean
