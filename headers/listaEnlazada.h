#define LISTA_ENLAZADA_H
#ifdef LISTA_ENLAZADA_H

typedef int item;

typedef struct Nodo {
    item valor;
    Nodo* siguiente;
}Nodo;

typedef struct Nodo* Lista;

Lista listaVacia ();
int esListaVacia (Lista); 
void mostrar (Lista); 
item primerElemento (Lista);
void insertar (Lista*,item);
void borrar (Lista*);
int longitud (Lista);
int pertenece (Lista,item);
void insertarK (Lista*,item,int);

#endif