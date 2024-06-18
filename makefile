CC = gcc
TARGET = main.exe
CFLAGS = -g -Wall
SRC = src/cochera.c src/listaEnlazada.c src/pila.c src/fila.c

all: ./Build
	$(CC) $(CFLAGS) tps/TP$(TP)-2024.c $(SRC) -o ./Build/$(TARGET)

./Build:
	if not exist Build mkdir Build

clean:
	del /Q ./Build\$(TARGET)
