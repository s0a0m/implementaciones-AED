#include <stdio.h>
#include <stdlib.h>
#include "../headers/pila.h"

int INDEFINIDO_PILA = -9999;

void pilaVacia(Pila* pila) {
    pila->altura = 0;
    pila->cabecera = NULL;
}

int esPilaVacia(Pila* pila) {
    return pila->cabecera == NULL;
}

int altura(Pila* pila) {
    return pila->altura;
}

item top(Pila* pila) {
    return pila->cabecera == NULL ? INDEFINIDO_PILA : pila->cabecera->dato;
}

void pop(Pila* pila) {
    if (pila->cabecera != NULL) {
        Nodo* aux = pila->cabecera;
        pila->cabecera = pila->cabecera->siguiente;
        pila->altura--;
        free(aux);
    } 
}

void push(Pila* pila,item dato) {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = dato;
    nodo->siguiente = pila->cabecera;
    pila->cabecera = nodo;
    pila->altura++;
}
