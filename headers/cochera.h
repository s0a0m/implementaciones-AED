#ifndef COCHERA_H
#define COCHERA_H

extern int indefinido;

typedef struct Auto {
    int informacion;
    struct Auto* siguiente;
}Auto; 

typedef struct Cochera {
    Auto* cabecera;
    int capacidad;
    int cantidadAutos;
} Cochera; 

void cocheraVacia(Cochera* cochera, int capacidadMaxima);
int estacionar(Cochera* cochera, int informacion);
int estaVacia(Cochera* cochera);
void quitarUltimo(Cochera* cochera); 
void salir(Cochera* cochera, int informacion);
int ultimo(Cochera* cochera);
int estacionado(Cochera* cochera, int informacion);
int capacidad(Cochera* cochera);
int libre(Cochera* cochera);

#endif