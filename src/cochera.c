#include <stdio.h>
#include <stdlib.h>
#include "../headers/cochera.h"

int indefinido = -9999;

void cocheraVacia(Cochera* cochera, int capacidadMaxima) {
    cochera->cabecera = NULL;
    cochera->capacidad = capacidadMaxima;
    cochera->cantidadAutos  = 0;
}

int estacionar(Cochera* cochera, int informacion) {
    if (cochera->cantidadAutos >= cochera->capacidad) return 0;
    Auto* nuevoAuto = (Auto*) malloc(sizeof(Auto));
    nuevoAuto->informacion = informacion;
    nuevoAuto->siguiente = cochera->cabecera;
    cochera->cabecera = nuevoAuto;
    cochera->cantidadAutos++;
    return 1;
}

int estaVacia(Cochera* cochera) {
    return cochera->cantidadAutos == 0;
}

void quitarUltimo(Cochera* cochera) {
    if (cochera->cantidadAutos == 0) return;

    Auto* aux = cochera->cabecera;

    cochera->cabecera = cochera->cabecera->siguiente;
    cochera->cantidadAutos--;
    
    free(aux);
} 

void salir(Cochera* cochera, int informacion) {

    Auto* actual = cochera->cabecera;
    Auto* anterior = cochera->cabecera;

    while (actual != NULL && actual->informacion != informacion)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) return;

    anterior->siguiente = actual->siguiente;
    free(actual);
    cochera->cantidadAutos--;
}

int ultimo(Cochera* cochera) {
    if (cochera->cantidadAutos == 0) return  indefinido;
    return cochera->cabecera->informacion;
}

int estacionado(Cochera* cochera, int informacion) {
    Auto* aux = cochera->cabecera;
    
    while (aux != NULL && aux->informacion != informacion)
    {
        aux = aux->siguiente;
    }
    if (aux == NULL) return 0;
    return 1;
}

int capacidad(Cochera* cochera) {
    return cochera->capacidad;
}

int libre(Cochera* cochera) {
    return cochera->cantidadAutos;
}
