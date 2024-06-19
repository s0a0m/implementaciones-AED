#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

typedef char itemArbolBinario;

extern int ARBOL_BINARIO_INDEFINIDO;

typedef struct NodoArbolBinario {
    itemArbolBinario raiz; 
    struct NodoArbolBinario* derecha;
    struct NodoArbolBinario* izquierda;
} NodoArbolBinario;

typedef struct NodoArbolBinario* ArbolBinario;

ArbolBinario arbolVacio();
ArbolBinario armarArbolBinario(ArbolBinario arbolIzquierdo, itemArbolBinario item, ArbolBinario arbolDerecho);
ArbolBinario izquierdo(ArbolBinario arbol);
ArbolBinario derecho(ArbolBinario arbol);
itemArbolBinario raiz(ArbolBinario arbol);
int esArbolBinarioVacio(ArbolBinario arbol);
int perteneceArbolBinario(ArbolBinario arbol, itemArbolBinario item);

#endif