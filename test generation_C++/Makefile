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

CFLAGS = -Wall -Wextra -std=c2x
OBJDIR = Objects

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
.PHONY: clean $(OBJDIR)
