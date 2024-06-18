
#ifndef PILA_H
#define PILA_H

typedef int item;
extern int INDEFINIDO_PILA;

typedef struct Nodo {
    item dato;
    struct Nodo* siguiente;
} Nodo;  

typedef struct Pila {
    Nodo* cabecera;
    int altura;
} Pila;

void pilaVacia(Pila* pila);
int esPilaVacia(Pila* pila);
item top(Pila* pila);
void pop(Pila* pila);
void push(Pila* pila,item dato);
int altura(Pila* pila);

#endif