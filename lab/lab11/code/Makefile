CXXFLAGS += -Wundef -Wall -std=c++11

main.out: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
	./main.out

clean:
	rm -f *.o *.out

.PHONY: clean
