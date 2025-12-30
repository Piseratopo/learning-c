# Makefile
CXX = g++
CXXFLAGS = -Wall -Wextra

# Default target
all: test_editorial random_string

# Test editor program
test_editorial: test_editorial.o
	$(CXX) $(CXXFLAGS) -o $@ $^

test_editorial.o: test_editorial.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Random string generator
random_string: main.o gen.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp gen.h
	$(CXX) $(CXXFLAGS) -c $<

gen.o: gen.cpp gen.h
	$(CXX) $(CXXFLAGS) -c $<

# Clean up
clean:
	del /f /q *.o *.exe input.txt output.txt program_output.txt 2>nul

# Phony targets
.PHONY: all clean