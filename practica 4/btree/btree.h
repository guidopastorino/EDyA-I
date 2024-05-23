#ifndef __BTREE_H__
#define __BTREE_H__

typedef void (*FuncionVisitante)(void* dato);
typedef void (*FuncionVisitanteExtra)(void* dato, void* extra);

typedef enum {
  BTREE_RECORRIDO_IN,
  BTREE_RECORRIDO_PRE,
  BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;

typedef struct _BTNodo *BTree;

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear();

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo);

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo);

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right);

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit);

/**
 * Recorrido del arbol, utilizando la funcion pasada y un dato extra
 */
void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitanteExtra visit, void *extra);

/*
 * Retorna la cantidad de nodos en el arbol
 */
int btree_nnodos(BTree arbol);

/*
 * Retorna 1 si el número se encuentra en el arbol, 0 en caso contrario
 */
int btree_buscar(BTree arbol, int dato);

/*
 * Retorna un nuevo arbol que es una copia del arbol dado
 */
BTree btree_copiar(BTree arbol);

/*
 * Retorna la altura del arbol
 */
int btree_altura(BTree arbol);

/*
 * Retorna el número de nodos que se encuentran a la profundidad dada
 */
int btree_nnodos_profundidad(BTree arbol, int profundidad);

/*
 * Retorna la profundidad del nodo que contiene el némero dado, y -1 si el némero no se encuentra en el árbol.
 */
int btree_profundidad(BTree arbol, int dato);

/*
 * Retorna la suma total de los datos del árbol.
 */
int btree_sumar(BTree arbol); 


/*
 * Funciones compactadas del ejercicio 3 (definir de manera compacta llamando a btree_recorrer_extra con un orden, una función visitante y un dato extra apropiados)
*/
// Para determinar cuáles funciones se pueden definir de manera compacta llamando a btree_recorrer_extra, debemos identificar aquellas que pueden ser resueltas mediante un recorrido del árbol mientras se acumula o verifica alguna información adicional.
// - btree_nnodos: Contar los nodos del árbol.
// - btree_buscar: Verificar si un número se encuentra en el árbol.
// - btree_sumar: Sumar los datos del árbol.

// Funcion auxiliar contar nodos
void contar_nodos(int dato, void* extra);
int btree_nnodos_compact(BTree arbol);

// Funcion auxiliar buscar nodo
void buscar_nodo(int dato, void* extra);
int btree_buscar_compact(BTree arbol, int dato);

// Función auxiliar suma
void sumar_datos(int dato, void* extra);
int btree_sumar_compact(BTree arbol);


/*
 * Implementación de recorrido BFS de forma iterativa usando un Queue
*/
void btree_recorrer_bfs_iterativo(BTree arbol, FuncionVisitante visit);

/*
 * Implementación de recorrido BFS de forma recursiva usando una función auxiliar
*/
void btree_recorrer_bfs_recursivo_aux(BTree arbol, int nivel, FuncionVisitante visit); // Función Auxiliar
void btree_recorrer_bfs_recursivo(BTree arbol, FuncionVisitante visit);


#endif /* __BTREE_H__ */
