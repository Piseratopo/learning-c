CC = gcc
CFLAGS = -std=c23 -Wall
TARGET = waterc
SRC = waterc.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) -lm

clean:
	rm -f $(TARGET)
