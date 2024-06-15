#include <stdio.h>
#include "listaEnlazada.h"

Lista listaVacia () {
    return NULL;
}

int esListaVacia (Lista lista) {
    return lista == NULL;
}

void mostrar (Lista lista) {
    Nodo* actual = lista;
    printf("\tLISTA[]: ");
    if (esListaVacia(lista)) printf(" => [NULL]");
    while (actual != NULL)
    {
        printf(" => [%d]", actual->valor);
        actual = actual->siguiente;
    }
}

item primerElemento (Lista lista) {
    if (esListaVacia(lista)) return NULL;
    return lista->valor;
}

// void insertar (Lista*,item) {

// }

// void borrar (Lista*) {

// }

int longitud (Lista lista) {
    Nodo* actual = lista;
    int longitud = 0;
    while (actual != NULL)
    {
        longitud++;
        actual = actual->siguiente;
    }
}

int pertenece (Lista lista,item valor) {
    Nodo* actual = lista;
    while (actual != NULL)
    {
        if (actual->valor == valor) return 1;
        actual = actual->siguiente;
    }
    return 0;
}

// void insertarK (Lista*,item,int) {

// }
