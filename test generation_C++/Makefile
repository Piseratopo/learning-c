# Makefile
ifeq ($(OS),Windows_NT)
	CXX = g++
	CLEAN_CMD = del /f /q
	MKDIR = if not exist Objects mkdir Objects
else
	CXX = clang++
	CLEAN_CMD = rm -f
	MKDIR = mkdir -p Objects
endif

CXXFLAGS = -Wall -Wextra
OBJDIR = Objects

# Default target
all: test_editorial test_generation

# Test editor program
test_editorial: $(OBJDIR)/test_editorial.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/test_editorial.o: test_editorial.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Test generation program
test_generation: $(OBJDIR)/test_generation.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/test_generation.o: test_generation.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create Objects directory
$(OBJDIR):
	$(MKDIR)

# Clean up
clean:
ifeq ($(OS),Windows_NT)
	$(CLEAN_CMD) Objects\*.o *.exe input.txt output.txt program_output.txt
	if exist Objects rmdir Objects
else
	$(CLEAN_CMD) Objects/*.o *.exe input.txt output.txt program_output.txt
	rm -rf Objects
endif 

# Phony targets
.PHONY: all clean $(OBJDIR)
