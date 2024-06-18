#ifndef FILA_H
#define FILA_H

extern int INDEFINIDO_FILA;

typedef int item;

typedef struct Nodo {
    item dato;
    struct Nodo* siguiente;
} Nodo;

typedef struct Fila
{
    Nodo* frente;
    Nodo* final;
    int longitud;
} Fila;

Fila filaVacia(Fila* fila);
int esFilaVacia(Fila* fila);
item frente(Fila* fila);
Fila* enfila(Fila* fila, item dato);
void defila(Fila* fila);

#endif