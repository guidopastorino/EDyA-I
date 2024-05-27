#ifndef __BTREE_H__
#define __BTREE_H__

typedef void (*FuncionVisitante)(int dato);
typedef void (*FuncionVisitanteExtra)(int dato, void* extra);

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
 * Recorrido del arbol, utilizando la funcion pasada y un dato extra.
 */
void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitanteExtra visit, void *extra);

/**
 * Retorna la cantidad de nodos en el arbol.
 */
int btree_nnodos(BTree arbol);

/**
 * Retorna 1 si el número se encuentra en el arbol, 0 en caso contrario.
 */
int btree_buscar(BTree arbol, int dato);

/**
 * Retorna un nuevo arbol que es una copia del arbol dado.
 */
BTree btree_copiar(BTree arbol);

/**
 * Retorna la altura del arbol.
 */
int btree_altura(BTree arbol);

/**
 * Retorna el número de nodos que se encuentran a la profundidad dada.
 */
int btree_nnodos_profundidad(BTree arbol, int profundidad);

/**
 * Retorna la profundidad del nodo que contiene el número dado, y -1 si el número no se encuentra en el árbol.
 */
int btree_profundidad(BTree arbol, int dato);

/**
 * Retorna la suma total de los datos del árbol.
 */
int btree_sumar(BTree arbol); 

/**
 * Funciones compactadas del ejercicio 3 (definir de manera compacta llamando a btree_recorrer_extra con un orden, una función visitante y un dato extra apropiados).
 */
void contar_nodos(int dato, void* extra);
int btree_nnodos_compact(BTree arbol);

void buscar_nodo(int dato, void* extra);
int btree_buscar_compact(BTree arbol, int dato);

void sumar_datos(int dato, void* extra);
int btree_sumar_compact(BTree arbol);

/**
 * Implementación de recorrido BFS de forma iterativa usando un Queue.
 */
void btree_recorrer_bfs_iterativo(BTree arbol, FuncionVisitante visit);

/**
 * Implementación de recorrido BFS de forma recursiva usando una función auxiliar.
 */
void btree_recorrer_bfs_recursivo_aux(BTree arbol, int nivel, FuncionVisitante visit); // Función Auxiliar
void btree_recorrer_bfs_recursivo(BTree arbol, FuncionVisitante visit);

/**
 * Dado un árbol binario, genera el árbol binario espejo, donde el hijo derecho de cada nodo pasa a ser izquierdo y el izquierdo pasa a ser derecho.
 */
BTree btree_mirror(BTree arbol);

/*
 * Determina si un arbol binario es completo o no (todos los niveles tienen dos hijos y las hojas por lo menos están ubicadas de izq a der)
*/

int btree_es_completo(BTree arbol);

#endif /* __BTREE_H__ */