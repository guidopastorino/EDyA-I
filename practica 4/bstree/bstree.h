#ifndef __BSTREE_H__
#define __BSTREE_H__

typedef void *(*FuncionCopiadora)(void *dato);
typedef int (*FuncionComparadora)(void *, void *);
typedef void (*FuncionDestructora)(void *dato);
typedef void (*FuncionVisitanteExtra)(void *dato, void *extra);
#include <stdlib.h>

typedef enum {
  BTREE_RECORRIDO_IN,  /** Inorden */
  BTREE_RECORRIDO_PRE, /** Preorden */
  BTREE_RECORRIDO_POST /** Postorden */
} BSTreeRecorrido;

typedef struct _BST_Nodo *BSTree;

/**
 * Retorna un arbol de busqueda binaria vacio.
 */
BSTree bstee_crear();

/**
 * Destruye el arbol y sus datos.
 */
void bstree_destruir(BSTree, FuncionDestructora);

/**
 * Retorna 1 si el dato se encuentra y 0 en caso contrario.
 */
int bstree_buscar(BSTree, void *, FuncionComparadora);

/**
 * Inserta un dato no repetido en el arbol, manteniendo la propiedad del arbol
 * de busqueda binaria.
 */
BSTree bstree_insertar(BSTree, void *, FuncionCopiadora, FuncionComparadora);

/**
 * Recorrido DSF del arbol
 */
void bstree_recorrer(BSTree, BSTreeRecorrido, FuncionVisitanteExtra,
                     void *extra);

/*
 * Elimina un elemento del arbol
*/
BSTree bstree_eliminar(BSTree arbol, void *dato, FuncionComparadora, FuncionDestructora);

/*
 * Retorna el k-ésimo menor elemento con k parámetro
*/
// ¿Qué recorrido del árbol procesa los elementos de menor a mayor?
// El recorrido inorden del árbol procesa los elementos de menor a mayor. Esto se debe a que, en un árbol de búsqueda binaria, el recorrido inorden visita primero el subárbol izquierdo, luego la raíz y finalmente el subárbol derecho, lo que garantiza que los elementos se visiten en orden ascendente.

// ¿Qué información adicional podría almacenar en los nodos para realizar esta operación de manera más eficiente?
// Una información adicional útil sería el tamaño del subárbol enraizado en cada nodo. Esto permitiría calcular rápidamente la posición de un nodo relativa a su posición en el árbol completo y decidir en cuál de los subárboles buscar el k-ésimo menor elemento sin necesidad de explorar ambos subárboles por completo.
void* bstree_k_esimo_menor_aux(BSTree arbol, int k);
void* bstree_k_esimo_menor(BSTree arbol, int k);

/*
 * Determina si el arbol dado cumple la propiedad de un arbol de busqueda binaria
*/
int btree_validar_aux(BSTree arbol, void* min, void* max, FuncionComparadora cmp);
int btree_validar(BSTree arbol, FuncionComparadora cmp);

/**
 * Busca en el árbol binario de búsqueda el menor entero mayor a k.
 */
void* bstree_cota_inferior(BSTree arbol, int k);



#endif //__BSTREE_H__