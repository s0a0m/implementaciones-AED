#include <stdio.h>
#include "../headers/listaEnlazada.h"

item posicionK(Lista*, int); 
int estaContenida(Lista*, Lista*);
int ordenInverso(int);
int digitoMayorIterativa(int);
int digitoMayorRecursiva(int);
int contienePalindromo(char*);
int estaOrdenado(int*);


int buscaPar(int*, int, int);

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


int estaContenida(Lista* lista1, Lista* lista2) {   
    if (esListaVacia(*lista1)) return 1;

    if (pertenece(*lista2,primerElemento(*lista1))) {
        borrar(lista1);
        return estaContenida(lista1,lista2); 
    }
    return 0;
}

int ordenInverso(int numero) {
    if (numero < 0) {
        printf("Ingresar numero mayor a 0");
        return 1;
    }
    if (numero == 0) return 0;
    printf("%d",numero % 10);
    return ordenInverso(numero/10);
}

int digitoMayorIterativa(int numero) {

    if (numero <= 0) {
        printf("Ingresar numero mayor a 0.");
        return -1;
    }

    int digito = numero % 10;
    int mayor = numero % 10; 
    while (numero != 0)
    {
        numero = numero / 10;
        digito = numero % 10;
        if (mayor < digito) {
            mayor = digito;
        } 
    }
    return mayor;
}

int digitoMayorRecursiva(int numero) {
    if (numero <= 0) {
        printf("Ingresar numero mayor a 0.");
        return -1;
    }
    
    if (numero < 10) {
        return numero;
    } else {
        int mayor = digitoMayorRecursiva(numero/10);
        if (mayor > numero % 10) {
            return mayor;
        } else {
            return numero % 10;
        }
    }
}

// int contienePalindromo(char* palabra) {
//     return 0;   
// }

// int buscaPar(int* arreglo, int x, int y) {
//     return 0;
// }

int estaOrdenado(int* arreglo) {
    int actual = arreglo[0];
    int i = 0;
    for  (i = 0; arreglo[i] != '\0'; i++)
    {
        if (actual > arreglo[i]) return 0;
        actual = arreglo[i];
    }
    return 1;
}

int main () {

    // PUNTO 2

    int num = 917230;
    printf("\n\tordenInverso(%d) => ", num);
    ordenInverso(num);

    // PUNTO 3

    printf("\n\tdigitoMayorIterativa(%d) => ", num);
    printf("%d",digitoMayorIterativa(num));
    printf("\n\tdigitoMayorRecursiva(%d) => ", num);
    printf("%d",digitoMayorRecursiva(num));

    // PUNTO 4

    // PUNTO 5

    int arregloNumeros[] = {2,2,1,3,4,5,100};

    printf("\n\testaOrdenado() => ");
    if (estaOrdenado(arregloNumeros)) printf("Esta ordenado");
    else printf("No esta ordenado");

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


    if (estaContenida(&lista2,&lista3)) {
        printf("\n\testaContenida() -> Esta contenida.");
    }
    else {
        printf("\n\testaContenida() -> No esta contenida");
    }

    // PUNTO 8 
    
    // FIN
    printf("\n");
    return 0;
}