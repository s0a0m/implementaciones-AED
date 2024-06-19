#include <stdio.h>
#include <stdlib.h>
#include "../headers/arbolBinario.h"

int ARBOL_BINARIO_INDEFINIDO = -9999;

ArbolBinario arbolVacio() {
    return NULL;
}

ArbolBinario armarArbolBinario(ArbolBinario arbolIzquierdo, itemArbolBinario item, ArbolBinario arbolDerecho) {
    NodoArbolBinario* AB = (NodoArbolBinario* ) malloc(sizeof(NodoArbolBinario));
    AB->derecha = arbolDerecho;
    AB->izquierda= arbolIzquierdo;
    AB->raiz = item;
    return AB;
}

ArbolBinario izquierdo(ArbolBinario arbol) {
    return arbol == NULL ? NULL : arbol->izquierda;
}

ArbolBinario derecho(ArbolBinario arbol) {
    return arbol == NULL ? NULL : arbol->derecha;
}

itemArbolBinario raiz(ArbolBinario arbol) {
    return arbol == NULL ? ARBOL_BINARIO_INDEFINIDO : arbol->raiz;
}

int esArbolBinarioVacio(ArbolBinario arbol) {
    return arbol == NULL; 
}

int perteneceArbolBinario(ArbolBinario arbol, itemArbolBinario item) {
    if (arbol == NULL) {
        return 0;
    }
    if (arbol->raiz == item) {
        return 1;
    }
    if (perteneceArbolBinario(arbol->izquierda, item) || perteneceArbolBinario(arbol->derecha, item)) {
        return 1;
    }
    return 0;
}




