#include <stdio.h>
#include <stdlib.h>
#include "../headers/cochera.h"

int moverAutos(Cochera* cocheraOrigen, Cochera* cocheraDestino, int autosAMover);

int moverAutos(Cochera* cocheraOrigen, Cochera* cocheraDestino, int autosAMover) {
    if (autosAMover + libre(cocheraDestino) > capacidad(cocheraDestino)) return 0;
    for (int i = 0; i < autosAMover; i++)
    {
        if (estaVacia(cocheraOrigen)) break;
        estacionar(cocheraDestino,ultimo(cocheraOrigen));
        quitarUltimo(cocheraOrigen);
    }
    return 1;
}


void liberarCochera(Cochera* cochera) {
    Auto* actual = cochera->cabecera;
    Auto* siguiente = NULL;

    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }

    cochera->cabecera = NULL;
    cochera->cantidadAutos = 0;
}

int main () {
    Cochera cochera1, cochera2;

    cocheraVacia(&cochera1, 5);
    cocheraVacia(&cochera2, 5);

    estacionar(&cochera1, 101);
    estacionar(&cochera1, 102);
    estacionar(&cochera1, 103);

    printf("Cochera 1 (despues de estacionar 3 autos):\n");
    Auto* temp = cochera1.cabecera;
    while (temp != NULL) {
        printf("%d ", temp->informacion);
        temp = temp->siguiente;
    }
    printf("\n");

    moverAutos(&cochera1, &cochera2, 2);

    printf("Cochera 1 (despues de mover 2 autos):\n");
    temp = cochera1.cabecera;
    while (temp != NULL) {
        printf("%d ", temp->informacion);
        temp = temp->siguiente;
    }
    printf("\n");

    printf("Cochera 2 (despues de recibir 2 autos):\n");
    temp = cochera2.cabecera;
    while (temp != NULL) {
        printf("%d ", temp->informacion);
        temp = temp->siguiente;
    }
    printf("\n");

    int autoId = 102;
    printf("¿Auto %d esta estacionado en cochera1? %s\n", autoId, estacionado(&cochera1, autoId) ? "Si" : "No");

    salir(&cochera2, 103);
    printf("Cochera 2 (despues de salir el auto 103):\n");
    temp = cochera2.cabecera;
    while (temp != NULL) {
        printf("%d ", temp->informacion);
        temp = temp->siguiente;
    }
    printf("\n");

    printf("¿Cochera 1 esta vacia? %s\n", estaVacia(&cochera1) ? "Si" : "No");

    quitarUltimo(&cochera2);
    printf("Cochera 2 (despues de quitar el ultimo auto):\n");
    temp = cochera2.cabecera;
    while (temp != NULL) {
        printf("%d ", temp->informacion);
        temp = temp->siguiente;
    }
    printf("\n");

    printf("Capacidad de cochera2: %d\n", capacidad(&cochera2));
    printf("Espacio libre en cochera2: %d\n", libre(&cochera2));

    liberarCochera(&cochera1);
    liberarCochera(&cochera2);
    
    return 0;
}