CC = gcc
CFLAGS = -ansi -Wall -Werror -pedantic
DEBUG = -D_DEBUG
TARGET = test
CFILES = main.c vector_int.c test.c
OBJ = main.o vector_int.o test.o
DEP = test.h vector_int.h

all: $(TARGET)

$(TARGET): $(OBJ) $(DEP)
	$(CC) $(OBJ) $(CFLAGS) -o $(TARGET)

debug: $(OBJ) $(DEP)
	$(CC) $(CFILES) $(CFLAGS) -o $(TARGET) $(DEBUG)