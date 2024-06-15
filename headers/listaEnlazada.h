#define LISTA_ENLAZADA_H
#ifdef LISTA_ENLAZADA_H

typedef int item;

typedef struct Nodo {
    item valor;
    struct Nodo* siguiente;
} Nodo;

typedef struct Nodo* Lista;

void crearLista (Lista*);
int esListaVacia (Lista); 
void mostrar (Lista); 
item primerElemento (Lista);
void insertar (Lista*,item);
void borrar (Lista*);
int longitud (Lista);
int pertenece (Lista,item);
void insertarK (Lista*,item,int);

#endif