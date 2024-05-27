#ifndef _COLAPRIORIDAD_H_
#define _COLAPRIORIDAD_H_

#include "maxheap.h"

typedef struct _Item* Item;
typedef struct _ColaPrioridad* ColaPrioridad;

/*
 * Crea una cola de prioridad
*/
ColaPrioridad cola_prioridad_crear(int, FuncionComparadora);

/*
 * Retorna 1 si la cola de prioridad está vacía, 0 en caso contrario
*/
int cola_prioridad_es_vacia(ColaPrioridad);

/*
 * Retorna el elemento prioritario de la cola.
*/
void* cola_prioridad_maximo(ColaPrioridad);

/*
 * Elimina el elemento prioritario de la cola.
*/
void cola_prioridad_eliminar_maximo(ColaPrioridad);

/*
 * Inserta un elemento en la cola con una determinada prioridad.
*/
ColaPrioridad cola_prioridad_insertar(ColaPrioridad, void*, int, FuncionCopia);

/*
 * Destruye la cola de prioridad
*/
void cola_prioridad_destruir(ColaPrioridad);

#endif