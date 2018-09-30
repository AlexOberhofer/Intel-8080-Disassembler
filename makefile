CC=gcc
CFLAGS=-I.
DEPS=i8080d.h
TARGET=i8080d

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

makei8080d: src/$(TARGET).o
	$(CC) -g -o ./bin/$(TARGET) ./src/$(TARGET).c

clean:
	rm ./bin/i8080d
	rm ./src/$(TARGET).o