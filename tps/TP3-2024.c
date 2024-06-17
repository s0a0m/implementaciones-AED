#include <stdio.h>
#include "../headers/listaEnlazada.h"

item posicionK(Lista*, int); 
int estaContenida(Lista*, Lista*);

item posicionK (Lista *lista, int k) {

    if (esListaVacia(*lista) || k < 1) return -9999;

    if (k == 1) {
        return primerElemento(*lista);
    }
    else {
        borrar(lista);
        return posicionK(lista, k-1);
    }
    
}


// int estaContenida(Lista* lista1, Lista* lista2) {
//     if (esListaVacia(*lista1) || esListaVacia(*lista2)) return 1;
//     if () {
//         borrar(lista1);
//         estaContenida(lista1,lista2); 
//     }
//     return 0;
// }

int main () {

    // PUNTO 6

    Lista lista1;
    int k = 4;

    crearLista(&lista1);
    
    insertar(&lista1,3);
    insertar(&lista1,2);
    insertar(&lista1,1);

    printf("\n\tposicionK -> %d", posicionK(&lista1, k));

    // PUNTO 7

    Lista lista2;
    Lista lista3;

    
    crearLista(&lista2);
    crearLista(&lista3);
    
    insertar(&lista2,3);
    insertar(&lista2,2);
    insertar(&lista2,1);
    
    insertar(&lista3,2);
    insertar(&lista3,3);
    insertar(&lista3,1);


    if (estaContenida(&lista2,&lista3)) printf("\n\testaContenida -> Esta contenida.");
    else printf("\n\testaContenida -> No esta contenida");
    
    // FIN
    printf("\n");
    return 0;
}