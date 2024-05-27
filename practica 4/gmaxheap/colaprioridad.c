#include "colaprioridad.h"

struct _Item {
  void* dato;
  int prioridad;
};

struct _ColaPrioridad {
  BHeap heap;
};

/*
 * Compara dos elementos en base a su prioridad
*/
static int comparar_elementos(void* dato1, void* dato2){
  Item item1 = (Item)dato1;
  Item item2 = (Item)dato2;
  return item1->prioridad - item2->prioridad;
}

/*
 * Crea una cola de prioridad
*/
ColaPrioridad cola_prioridad_crear(int capacidad, FuncionComparadora cmp){
  ColaPrioridad cp = (ColaPrioridad)malloc(sizeof(struct _ColaPrioridad));
  assert(cp != NULL);
  cp->heap = bheap_crear(capacidad, cmp);
  return cp;
}

/*
 * Retorna 1 si la cola de prioridad está vacía, 0 en caso contrario
*/
int cola_prioridad_es_vacia(ColaPrioridad cp){
  return bheap_es_vacio(cp->heap);
}

/*
 * Retorna el elemento prioritario de la cola.
*/
void* cola_prioridad_maximo(ColaPrioridad cp) {
  if (cola_prioridad_es_vacia(cp)) {
    return NULL;
  }
  Item max_item = (Item)cp->heap;
  return max_item->dato;
}

/*
 * Elimina el elemento prioritario de la cola.
*/
void cola_prioridad_eliminar_maximo(ColaPrioridad cp){
  bheap_extraer_maximo(cp->heap);
}

/*
 * Inserta un elemento en la cola con una determinada prioridad.
*/
ColaPrioridad cola_prioridad_insertar(ColaPrioridad cp, void* dato, int prioridad, FuncionCopia copy){
  Item item = (Item)malloc(sizeof(struct _Item));
  assert(item != NULL);
  item->dato = dato;
  item->prioridad = prioridad;
  bheap_insertar(cp->heap, dato, copy);
}

/*
 * Destruye la cola de prioridad
*/
void cola_prioridad_destruir(ColaPrioridad cp){
  bheap_destruir(cp->heap);
  free(cp);
}