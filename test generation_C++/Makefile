# Makefile
CXX = g++
CXXFLAGS = -Wall -Wextra

all: random_string

random_string: main.o gen.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp gen.h
	$(CXX) $(CXXFLAGS) -c $<

gen.o: gen.cpp gen.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o random_string input.txt output.txt

.PHONY: all clean