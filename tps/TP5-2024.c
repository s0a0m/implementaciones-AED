#include <stdio.h>
#include <stdlib.h>
#include "../headers/pila.h"

Pila* eliminarNegativos(Pila* pila);

Pila* eliminarNegativos(Pila* pila) {

    if (altura(pila) == 0) {
        Pila* resultado = (Pila*) malloc(sizeof(Pila));
        pilaVacia(resultado);
         return resultado;
    }

    item valor = top(pila);
    pop(pila);
    
    Pila* resultado = eliminarNegativos(pila);

    if (valor >= 0) {
        push(resultado, valor);
    }

    return resultado;
}

int main() {
    Pila pila;
    pilaVacia(&pila);

    // Llenar la pila con algunos valores
    push(&pila, 5);
    push(&pila, -3);
    push(&pila, 8);
    push(&pila, -2);
    push(&pila, 10);

    printf("Pila original:\n");
    while (!esPilaVacia(&pila)) {
        printf("%d ", top(&pila));
        pop(&pila);
    }
    printf("\n");

    // Restaurar la pila original
    push(&pila, 5);
    push(&pila, -3);
    push(&pila, 8);
    push(&pila, -2);
    push(&pila, 10);

    // Eliminar elementos negativos
    Pila* pilaSinNegativos = eliminarNegativos(&pila);

    printf("Pila sin elementos negativos:\n");
    while (!esPilaVacia(pilaSinNegativos)) {
        printf("%d ", top(pilaSinNegativos));
        pop(pilaSinNegativos);
    }
    printf("\n");

    // Liberar memoria de la pila original y la nueva pila sin negativos
    free(pilaSinNegativos);

    return 0;
}