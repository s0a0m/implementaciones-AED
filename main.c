//============================================================================
// Name        : TP1-2024.cpp
// Author      : Cristina Werenitzky
// Version     :
// Copyright   : Your copyright notice
// Description : Programa de prueba de Lista Enlazada
//============================================================================

#include<stdio.h>
#include<stdlib.h>

#include "headers/listaEnlazada.h"  //Include del archivo de cabecera Lista.h - Tipificacion de lista y funciones 

item posicionK(Lista *l, int k); // Funci�n externa - Punto 3) - FALTA IMPLEMENTAR

item posicionK (Lista *l, int k) {
    return 1;
}

int main(){


// -- PROGRAMA DE PRUEBA DE LISTA CON FUNCIONES QUE MODIFICAN LA LISTA POR PARAMETRO

    printf("\nINICIO DEL PROGRAMA DE PRUEBA DE LISTA CON FUNCIONES QUE RETORNAN LA LISTA MODIFICADA\n");

	printf("\n1.Creo una lista, la inicializo en lista vacia y muestro la lista vacia por pantalla: ");
	Lista L;
	crearLista(&L);
    mostrar(L);

    printf("\n2.Pruebo la funcion esListaVacia. Mensaje esperado 'Lista Vacia': ");
    if(esListaVacia(L))
		printf("Lista Vacia\n");
	else
	    printf("Lista NO Vacia\n");

    printf("\n3.Escribo la cantidad de elementos de una lista vacia (= 0): %d \n", longitud(L));

    printf("\n4.Escribo el valor del primer elemento de una lista vacia (= -99999): %d \n", primerElemento(L));

    printf("\n5.Inserto el valor 500 en la lista y muestro la lista por pantalla: ");
	insertar(&L,500);
    mostrar(L);

	printf("\n6.Pruebo la funci�n esListaVacia. Mensaje esperado 'Lista NO Vacia': ");
    if(esListaVacia(L))
		printf("Lista Vacia\n");
	else
		printf("Lista NO Vacia\n");

	printf("\n7.Borro un elemento de la lista y muestro por pantala. Se espera lista vacia: ");
	borrar(&L);
	mostrar(L);

	printf("\n8.Inserto 5 elementos (10,17,22,45,74) en la lista y muestro la lista por pantalla: ");
	insertar(&L,10);
	insertar(&L,17);
	insertar(&L,22);
	insertar(&L,45);
	insertar(&L,74);
	mostrar(L);

    printf("\n9.Escribo la cantidad de elementos de la lista (= 5): %d \n", longitud(L));

    printf("\n10.Escribo el valor del primer elemento de la lista vacia (= 74): %d \n", primerElemento(L));

	printf("\n11.Borro un elemento de la lista y muestro la lista por pantalla: ");
	borrar(&L);
	mostrar(L);

    printf("\n12.Busco si pertenece el valor 100 en la lista. Mensaje esperado 'NO Pertenece': ");
    if(pertenece(L, 100))
		printf("Pertenece\n");
	else
	    printf("NO Pertenece\n");

    printf("\n13.Busco si pertenece el valor 22 en la lista. Mensaje esperado: 'Pertenece': ");

    if(pertenece(L, 22))
    		printf("Pertenece\n");
    	else
    	    printf("NO Pertenece\n");

    printf("\n14.Inserto el valor 88  en la posici�n 3 y muestro la lista por pantalla: ");
    insertarK(&L, 88, 3);
    mostrar(L);

    printf("\n15.Inserto el valor 99  en la posici�n 50 y muestro la lista por pantalla: ");
    insertarK(&L, 99, 50);
    mostrar(L);

    printf("\n16.Inserto el valor 0  en la posici�n -10 y muestro la lista por pantalla: ");
    insertarK(&L, 0, -10);
    mostrar(L);

    printf("\n17.Inserto el valor 1  en la posici�n 1 y muestro la lista por pantalla: ");
    insertarK(&L, 1, 1);
    mostrar(L);

    printf("\n18.Busco el elemento que se encuentra en la posic�n 4 de la lista (= 88): %d\n", posicionK(&L, 4));

    printf("\n19.Muestro la lista luego de invocar a la funci�n externa posicionK: ");
    mostrar(L);

    printf("\n20.Busco el elemento que se encuentra en la posic�n 50 de la lista (= -99999): %d\n", posicionK(&L, 50));

    printf("\n21.Muestro la lista luego de invocar a la funci�n externa posicionK: ");
    mostrar(L);

    printf("\n22.Libero la memoria reservada en forma din�mica\n");
    while(!esListaVacia(L))
    	borrar(&L);

    printf("\nFIN DEL PROGRAMA DE PRUEBA DE LISTA CON FUNCIONES QUE MODIFICAN LA LISTA POR PARAMETRO\n");

// -----------------------------------------------------------------------------------------------------------------------

    return 0;
}