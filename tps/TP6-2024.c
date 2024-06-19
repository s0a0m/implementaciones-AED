#include <stdio.h>
#include <stdlib.h>
#include "../headers/fila.h"

Fila* mezclar(Fila* fila1, Fila* fila2);

static void mostar(Fila* fila) {
    Nodo* aux = fila->frente;
    printf("\n\tFRENTE");
    while (aux != NULL)
    {
        printf(" -> %d", aux->dato);
        aux = aux->siguiente;
    }
    printf(" -> NULL");
}

// 🫥

Fila* mezclar(Fila* fila1, Fila* fila2) {
    Fila* resultado = (Fila*) malloc(sizeof(Fila));
    filaVacia(resultado);

    if (esFilaVacia(fila1)) {
        while (!esFilaVacia(fila2)) {
            enfila(resultado, frente(fila2));
            defila(fila2);
        }
        return resultado;
    }

    if (esFilaVacia(fila2)) {
        while (!esFilaVacia(fila1)) {
            enfila(resultado, frente(fila1));
            defila(fila1);
        }
        return resultado;
    }

    if (frente(fila1) <= frente(fila2)) {
        enfila(resultado, frente(fila1));
        defila(fila1);
    } else {
        enfila(resultado, frente(fila2));
        defila(fila2);
    }

    Fila* restoMezclado = mezclar(fila1, fila2);
    while (!esFilaVacia(restoMezclado)) {
        enfila(resultado, frente(restoMezclado));
        defila(restoMezclado);
    }
    free(restoMezclado);

    return resultado;
}




void liberarFila(Fila* fila) {
    while (!esFilaVacia(fila)) {
        defila(fila);
    }
    free(fila);
}

int main() {
    Fila fila1, fila2;

    filaVacia(&fila1);
    filaVacia(&fila2);

    // Enfila algunos elementos en fila1
    enfila(&fila1, 1);
    enfila(&fila1, 2);
    enfila(&fila1, 3);
    // Enfila algunos elementos en fila2
    enfila(&fila2, 4);
    enfila(&fila2, 5);
    enfila(&fila2, 6);
    // Mostrar contenido de fila1
    printf("Contenido de fila1:\n");
    mostar(&fila1);
    printf("\n");

    // Mostrar contenido de fila2
    printf("Contenido de fila2:\n");
    mostar(&fila2);
    printf("\n");

    // Mezclar filas
    Fila* filaMezclada = mezclar(&fila1, &fila2);

    // Mostrar contenido de filaMezclada
    printf("Contenido de filaMezclada:\n");
    mostar(filaMezclada);
    printf("\n");

    // Liberar memoria
    liberarFila(filaMezclada);

    // Verificar esFilaVacia y frente
    printf("La fila1 esta vacia? %s\n", esFilaVacia(&fila1) ? "Si" : "No");
    printf("Frente de fila1: %d\n", frente(&fila1));

    // Desenfila elementos de fila1
    defila(&fila1);
    defila(&fila1);
    defila(&fila1);

    // Verificar esFilaVacia y frente nuevamente
    printf("La fila1 esta vacia? %s\n", esFilaVacia(&fila1) ? "Si" : "No");
    printf("Frente de fila1: %d\n", frente(&fila1));

    // Liberar memoria de filas restantes
    liberarFila(&fila1);
    liberarFila(&fila2);

    return 0;
}