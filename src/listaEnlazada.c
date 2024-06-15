#include <stdio.h>
#include <stdlib.h>
#include "../headers/listaEnlazada.h"

void crearLista (Lista* lista) {
    *lista = NULL;
}

int esListaVacia (Lista lista) {
    return lista == NULL;
}

void mostrar (Lista lista) {
    Nodo* actual = lista;
    printf("\tLISTA");
    if (esListaVacia(lista)) printf(" => [NULL]");
    while (actual != NULL)
    {
        printf(" => [%d]", actual->valor);
        actual = actual->siguiente;
    }
}

item primerElemento (Lista lista) {
    if (esListaVacia(lista)) return -99999;
    return lista->valor;
}

void insertar (Lista* lista,item valor) {
    Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = *lista;
    *lista = nuevoNodo;
}

void borrar (Lista* lista) {
    if (!esListaVacia(*lista)) {
        Nodo* aux = *lista;
        *lista = (*lista)->siguiente;
        free(aux);
    }
}

int longitud (Lista lista) {
    Nodo* actual = lista;
    int longitud = 0;
    while (actual != NULL)
    {
        longitud++;
        actual = actual->siguiente;
    }
    return longitud;
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

void insertarK (Lista* lista,item valor,int k) {

    Nodo* nuevoNodo = (Nodo*) malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;

    if (esListaVacia(*lista) || k == 1) {
        nuevoNodo->siguiente = *lista;
        *lista = nuevoNodo;
        return;
    }

    Nodo* actual = *lista;
    Nodo* anterior = *lista;
    int posicion = 0;
    
    while (actual != NULL && posicion < k - 1)
    {
        anterior = actual;
        actual = actual->siguiente;
        posicion++;
    }

    anterior->siguiente = nuevoNodo;
    
    if (actual == NULL) {
        nuevoNodo->siguiente = NULL;
    } else {
        nuevoNodo->siguiente = actual;
    }
}
