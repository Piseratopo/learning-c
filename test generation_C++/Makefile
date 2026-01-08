# Makefile
ifeq ($(OS),Windows_NT)
	CC = gcc
	CLEAN_CMD = del /f /q
	MKDIR = if not exist Objects mkdir Objects
else
	CC = clang
	CLEAN_CMD = rm -f
	MKDIR = mkdir -p Objects
endif

CFLAGS = -Wall -Wextra -std=c99
OBJDIR = Objects

# Default target
all: test_editorial

# Test editor program
test_editorial: $(OBJDIR)/test_editorial.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/test_editorial.o: test_editorial.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create Objects directory
$(OBJDIR):
	$(MKDIR)

# Clean up
clean:
ifeq ($(OS),Windows_NT)
	$(CLEAN_CMD) Objects\*.o *.exe program_output.txt
	if exist Objects rmdir Objects
else
	$(CLEAN_CMD) Objects/*.o *.exe program_output.txt
	rm -rf Objects
endif 

# Phony targets
.PHONY: all clean $(OBJDIR)
