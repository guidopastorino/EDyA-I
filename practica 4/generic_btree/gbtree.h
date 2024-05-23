#ifndef GBTREE_H
#define GBTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Function alias type declarations
typedef void (*FuncionVisitante)(void*);
typedef void (*FuncionVisitanteExtra)(void*, void*);
typedef void* (*FuncionCopia)(void*);

typedef struct _GBTreeNode* GBTree;

typedef enum {
  GBTREE_RECORRIDO_PRE,
  GBTREE_RECORRIDO_IN,
  GBTREE_RECORRIDO_POST,
} Recorrido;

/**
 * Devuelve un arbol vacío.
 */
GBTree gbtree_crear();

/**
 * Destruccion del árbol.
 */
void gbtree_destruir(GBTree);

/**
 * Indica si el árbol es vacío.
 */
int gbtree_vacio(GBTree);

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
GBTree gbtree_unir(void*, GBTree, GBTree, FuncionCopia);

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void gbtree_recorrer(GBTree, Recorrido, FuncionVisitante);

/**
 * Recorrido del arbol, utilizando la funcion pasada y un dato extra
 */
void gbtree_recorrer_extra(GBTree, Recorrido, FuncionVisitanteExtra, void*);

/*
 * Retorna la cantidad de nodos en el arbol
 */


/*
 * Retorna 1 si el número se encuentra en el arbol, 0 en caso contrario
 */


/*
 * Retorna un nuevo arbol que es una copia del arbol dado
 */


/*
 * Retorna la altura del arbol
 */


/*
 * Retorna el número de nodos que se encuentran a la profundidad dada
 */


/*
 * Retorna la profundidad del nodo que contiene el némero dado, y -1 si el némero no se encuentra en el árbol.
 */


/*
 * Retorna la suma total de los datos del árbol.
 */


/*
 * Traverse Tree (DFS)
 */


/*
 * Traverse Tree (BFS)
 */



#endif /* _GBTREE_H_ */