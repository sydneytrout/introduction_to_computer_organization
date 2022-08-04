CC=gcc
CFLAGS=-Wall
C_SRCS=driver.c	ppm.c shape.c
TARGET=ppm
ARGS=input.txt	output.ppm

make:
	$(CC)	$(CFLAGS)	$(C_SRCS) -o $(TARGET)

run: make
	./$(TARGET)	$(ARGS)

clean:
	-rm $(TARGET)
