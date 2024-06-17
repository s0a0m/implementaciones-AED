CC = gcc
TARGET = main.exe
CFLAGS = -g -Wall
SRC = main.c src/listaEnlazada.c

all: ./Build
	$(CC) $(CFLAGS) $(SRC) -o ./Build/$(TARGET)

./Build:
	if not exist Build mkdir Build

clean:
	del /Q ./Build\$(TARGET)
