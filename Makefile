CC = gcc
CFLAGS = -Wall -Wextra

TARGET = byte-order-test

all: $(TARGET)

$(TARGET): add-nbo.c
	$(CC) $(CFLAGS) add-nbo.c -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean

