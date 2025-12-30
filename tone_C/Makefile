CC = gcc
CFLAGS = -std=c23 -Wall -Wextra -O2
TARGET = tone_generator
SOURCE = main.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE) -lm

clean:
	del $(TARGET).exe 2>nul || rm -f $(TARGET)

.PHONY: all clean