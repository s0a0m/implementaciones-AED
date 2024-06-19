#include <stdio.h>
#include <stdlib.h>
#include "../headers/arbolBinario.h"



int main () {
    ArbolBinario a1 = armarArbolBinario(arbolVacio(), 'A', arbolVacio());
    ArbolBinario a2 = armarArbolBinario(arbolVacio(), 'B', arbolVacio());
    ArbolBinario a3 = armarArbolBinario(a1, 'C', a2);

    // Pruebas
    printf("Raiz de a3: %c\n", raiz(a3)); // Deberia imprimir 'C'
    printf("Raiz del hijo izquierdo de a3: %c\n", raiz(izquierdo(a3))); // Deberia imprimir 'A'
    printf("Raiz del hijo derecho de a3: %c\n", raiz(derecho(a3))); // Deberia imprimir 'B'

    // Verificar si el arbol esta vacio
    printf("a3 esta vacio: %d\n", esArbolBinarioVacio(a3)); // Deberia imprimir 0 (false)
    printf("a1 esta vacio: %d\n", esArbolBinarioVacio(a1)); // Deberia imprimir 0 (false)
    printf("Arbol vacio esta vacio: %d\n", esArbolBinarioVacio(arbolVacio())); // Deberia imprimir 1 (true)

    // Verificar pertenencia de elementos
    printf("C pertenece a a3: %d\n", perteneceArbolBinario(a3, 'C')); // Deberia imprimir 1 (true)
    printf("A pertenece a a3: %d\n", perteneceArbolBinario(a3, 'A')); // Deberia imprimir 1 (true)
    printf("B pertenece a a3: %d\n", perteneceArbolBinario(a3, 'B')); // Deberia imprimir 1 (true)
    printf("D pertenece a a3: %d\n", perteneceArbolBinario(a3, 'D')); // Deberia imprimir 0 (false)
}