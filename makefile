CC=clang
CFLAGS=-I.
DEPS=i8080d.h
TARGET=i8080d

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

makei8080d: src/$(TARGET).o
	@mkdir -p bin
	$(CC) -g -std=c11 -Wall -o ./bin/$(TARGET) ./src/$(TARGET).c

clean:
	rm ./bin/i8080d
	rm ./src/$(TARGET).o