#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int (*FuncionComparadora)(void*, void*);
typedef void (*FuncionVisitante)(void*);
typedef void (*FuncionDestructora)(void*);
typedef void* (*FuncionCopia)(void*);

typedef struct _BHeap* BHeap;

/*
 *  Crea un heap vacío con una capacidad y una funcion de comparación dadas
*/
BHeap bheap_crear(int, FuncionComparadora);

/*
 *  Destruye el heap
*/
void bheap_destruir(BHeap);

/*
 *  Retorna 1 si el heap está vacío o 0 en caso contrario
*/
int bheap_es_vacio(BHeap);

/*
 *  Recorre los nodos utilizando búsqueda por extensión (bfs), aplicando la función dada en cada elemento
*/
void bheap_recorrer(BHeap, FuncionVisitante);

/*
 *  Agrega un elemento al heap, realocando el arreglo en caso de ser necesario. El resultado debe ser nuevamente un heap binario.
*/
BHeap bheap_insertar(BHeap, void*, FuncionCopia);

/*
 * que elimine un elemento del heap. El resultado debe ser nuevamente un heap binario.
*/
BHeap bheap_eliminar(BHeap, void*, FuncionDestructora);

/*
 * A partir de un arreglo arbitrario cree un heap binario
*/
BHeap bheap_crear_desde_arr(void **arr, int largo, FuncionCopia copiar,FuncionComparadora comp);

/*
 * Extrae la raíz del heap
*/
void* bheap_extraer_maximo(BHeap heap);

/*
 * Heap Sort (array-based heap sorting algorithm) - Sorts an array using a heap
*/
void heap_sort(void*** arr, int size, FuncionComparadora cmp, FuncionCopia copy);

#endif /* _MAXHEAP_H_ */