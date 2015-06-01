TARGET = euphoria
LIBS = -lm
CC = gcc
CFLAGS = -g

.PHONY: default all clean debug

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@ -g


clean:
	-rm -f *.o
	-rm -f $(TARGET)