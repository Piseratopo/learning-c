# Makefile
ifeq ($(OS),Windows_NT)
	CXX = g++
	CLEAN_CMD = del /f /q
	MKDIR = if not exist Object mkdir Object
else
	CXX = clang++
	CLEAN_CMD = rm -f
	MKDIR = mkdir -p Object
endif

CXXFLAGS = -Wall -Wextra
OBJDIR = Object

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
	$(CLEAN_CMD) *.o *.exe input.txt output.txt program_output.txt 

# Phony targets
.PHONY: all clean
