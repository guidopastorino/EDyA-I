#include "bstree.h"
#include <assert.h>
#include <stdlib.h>

/**
 * Estructura del nodo del arbol de busqueda binaria.
 * Tiene un puntero al dato (dato),
 * un puntero al nodo raiz del subarbol izquierdo (izq),
 * y un puntero al nodo raiz del subarbol derecho (der).
 */
struct _BST_Nodo {
  void *dato;
  struct _BST_Nodo *izq, *der;
  int tam_subarbol; 
};

/**
 * bstee_crear: Retorna un arbol de busqueda binaria vacio
 */
BSTree bstee_crear() { return NULL; }

/**
 * bstree_destruir: Destruye el arbol y sus datos
 */
void bstree_destruir(BSTree raiz, FuncionDestructora destr) {
  if (raiz != NULL) {
    bstree_destruir(raiz->izq, destr);
    bstree_destruir(raiz->der, destr);
    destr(raiz->dato);
    free(raiz);
  }
};

/**
 * bstree_buscar: Retorna 1 si el dato se encuentra y 0 en caso
 * contrario
 */
int bstree_buscar(BSTree raiz, void *dato, FuncionComparadora comp) {
  if (raiz == NULL)
    return 0;
  else if (comp(dato, raiz->dato) == 0) // raiz->dato == dato
    return 1;
  else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    return bstree_buscar(raiz->izq, dato, comp);
  else // raiz->dato < dato
    return bstree_buscar(raiz->der, dato, comp);
}

/**
 * bstree_insertar: Inserta un dato no repetido en el arbol, manteniendo la
 * propiedad del arbol de busqueda binaria
 */
BSTree bstree_insertar(BSTree raiz, void *dato, FuncionCopiadora copia,
                       FuncionComparadora comp) {
  if (raiz == NULL) { // insertar el dato en un nuevo nodo
    struct _BST_Nodo *nuevoNodo = malloc(sizeof(struct _BST_Nodo));
    assert(nuevoNodo != NULL);
    nuevoNodo->dato = copia(dato);
    nuevoNodo->izq = nuevoNodo->der = NULL;
    nuevoNodo->tam_subarbol = 1; // El nuevo subárbol tiene un solo hijo 
    return nuevoNodo;
  } else if (comp(dato, raiz->dato) < 0){ // dato < raiz->dato
    raiz->izq = bstree_insertar(raiz->izq, dato, copia, comp);
    raiz->tam_subarbol++;
  } else if (comp(dato, raiz->dato) > 0){ // raiz->dato < dato
    raiz->der = bstree_insertar(raiz->der, dato, copia, comp);
    raiz->tam_subarbol++;
  }
  // si el dato ya se encontraba, no es insertado
  return raiz;
}

/**
 * bstree_recorrer: Recorrido DSF del arbol
 */
void bstree_recorrer(BSTree raiz, BSTreeRecorrido orden,
                     FuncionVisitanteExtra visita, void *extra) {
  if (raiz != NULL) {
    if (orden == BTREE_RECORRIDO_PRE)
      visita(raiz->dato, extra);
    bstree_recorrer(raiz->izq, orden, visita, extra);
    if (orden == BTREE_RECORRIDO_IN)
      visita(raiz->dato, extra);
    bstree_recorrer(raiz->der, orden, visita, extra);
    if (orden == BTREE_RECORRIDO_POST)
      visita(raiz->dato, extra);
  }
}

/*
 * Elimina un elemento del arbol
*/
BSTree find_min(BSTree arbol){
  BSTree current = arbol;
  while(current->izq != NULL)
    current = current->izq;
  return current;
}

BSTree bstree_eliminar(BSTree arbol, void *dato, FuncionComparadora cmp, FuncionDestructora destruir){
  if(arbol == NULL) return NULL;
  if(cmp(dato, arbol->dato) < 0){ // dato < arbol->dato
    arbol->izq = bstree_eliminar(arbol->izq, dato, cmp, destruir);
    arbol->tam_subarbol--;
  } else if(cmp(dato, arbol->dato)){ // dato > arbol->dato
    arbol->der = bstree_eliminar(arbol->der, dato, cmp, destruir);
    arbol->tam_subarbol--;
  } else {
    // si el nodo tiene un solo hijo o ninguno
    if(arbol->izq == NULL || arbol->der == NULL){
      BSTree temp = arbol->izq ? arbol->izq : arbol->der;
      if(temp == NULL){ // si no tiene hijos
        temp = arbol;
        arbol = NULL;
      } else {
        *arbol = *temp; // copiamos el contenido
      }
      destruir(temp); // eliminamos el nodo
    } else {
      // si el nodo tiene dos hijos
      BSTree temp = find_min(arbol->der); // Buscamos el sucesor inorder más chico del subarbol derecho
      arbol->dato = temp->dato; // Intercambiamos valores
      arbol->der = bstree_eliminar(arbol->der, temp->dato, cmp, destruir); // eliminamos el sucesor inorder más chico del subarbol derecho
      arbol->tam_subarbol--;
    }
  }
  return arbol;
}


/*
 * Retorna el k-ésimo menor elemento con k parámetro
*/
void* bstree_k_esimo_menor_aux(BSTree arbol, int k){
  if(arbol == NULL) return NULL;
  int tam_izq = arbol->izq ? arbol->izq->tam_subarbol : 0;
  if(k == tam_izq + 1){
    return arbol->dato;
  } else if(k <= tam_izq){
    return bstree_k_esimo_menor_aux(arbol->izq, k);
  } else {
    return bstree_k_esimo_menor_aux(arbol->der, k - tam_izq - 1);
  }
}

void* bstree_k_esimo_menor(BSTree arbol, int k){
  if(arbol == NULL || k <= 0 || k > arbol->tam_subarbol + 1) return NULL;
  return bstree_k_esimo_menor_aux(arbol, k);
}


/*
 * Determina si el arbol dado cumple la propiedad de un arbol de busqueda binaria
*/
int btree_validar_aux(BSTree arbol, void* min, void* max, FuncionComparadora cmp){
  if(arbol == NULL) return 1;
  if((min && cmp(arbol->dato, min) <= 0) || (max && cmp(arbol->dato, max) >= 0)) return 0;
  return btree_validar_aux(arbol->izq, min, arbol->dato, cmp) &&
         btree_validar_aux(arbol->der, arbol->dato, max, cmp);
}

int btree_validar(BSTree arbol, FuncionComparadora cmp){
  return btree_validar_aux(arbol, NULL, NULL, cmp);
}


