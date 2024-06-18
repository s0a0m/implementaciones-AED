#include <stdio.h>
#include <stdlib.h>
#include "../headers/fila.h"

int INDEFINIDO_FILA = -9999;

Fila filaVacia(Fila* fila) {
    fila->longitud = 0;
    fila->final = NULL;
    fila->frente = NULL;
    return *fila;
}

int esFilaVacia(Fila* fila) {
    return fila->frente == NULL;
}

item frente(Fila* fila) {
    return fila->frente == NULL ? INDEFINIDO_FILA : fila->frente->dato;
}

Fila* enfila(Fila* fila, item dato) {
    Nodo* nodo = (Nodo*) malloc(sizeof(Nodo)); 
    nodo->dato = dato;
    nodo->siguiente = NULL;

    if (fila->frente == NULL) {
        fila->frente = nodo;
    } else {
        fila->final->siguiente = nodo;
    }

    fila->final = nodo;
    fila->longitud++;
    return fila;
}

void defila(Fila* fila) {
    if (fila->frente == NULL) return; 
    Nodo* aux = fila->frente;
    fila->frente = fila->frente->siguiente;
    if (fila->longitud == 1) {
        fila->final = NULL;
    } 
    free(aux);
    fila->longitud--;
}
