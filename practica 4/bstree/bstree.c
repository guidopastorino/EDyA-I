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

/*
 * Convertir un árbol binario de búsqueda en un árbol binario completo
*/
// Perform inorder traversal to store the elements in the array
static void bs_tree_a_array(BSTree arbol, void** array, int* index){
  if(arbol != NULL){
    bs_tree_a_array(arbol->izq, array, index);
    array[(*index)++] = arbol->dato;
    bs_tree_a_array(arbol->der, array, index);
  }
}

static BSTree array_a_complete_bs_tree(void** array, int start, int end, FuncionCopiadora copiar){
  if(start > end) return NULL;

  int mid = (start + end) / 2;

  BSTree nodo = (BSTree)malloc(sizeof(struct _BST_Nodo));
  assert(nodo != NULL);
  nodo->dato = copiar(array[mid]);
  nodo->izq = array_a_complete_bs_tree(array, start, mid - 1, copiar);
  nodo->der = array_a_complete_bs_tree(array, mid + 1, end, copiar);
  nodo->tam_subarbol = 1 + (nodo->izq ? nodo->izq->tam_subarbol : 0) + (nodo->der ? nodo->der->tam_subarbol : 0);

  return nodo;
}


BSTree bst_convertir_completo(BSTree arbol, FuncionCopiadora copiar){
  if(arbol == NULL) return NULL;

  int n = arbol->tam_subarbol;
  void** array = (void**)malloc(sizeof(void*) * n);
  assert(array != NULL);
  int index = 0;
  
  bs_tree_a_array(arbol, array, &index);

  BSTree nuevoArbol = array_a_complete_bs_tree(array, 0, n - 1, copiar);

  free(array);
  return nuevoArbol;
}

/*
 * Busca en el árbol binario de búsqueda el menor entero mayor a k.
*/
static void* bstree_cota_inferior_aux(BSTree arbol, int k){
  if(arbol == NULL) return NULL;
  if(*(int*)arbol->dato <= k){
    return bstree_cota_inferior_aux(arbol->der, k);
  } else {
    void* candidato_izq = bstree_cota_inferior_aux(arbol->izq, k);
    if(candidato_izq != NULL){
      return candidato_izq;
    } else {
      return arbol->dato;
    }
  }
}

void* bstree_cota_inferior(BSTree arbol, int k){
  if(arbol == NULL) return NULL;
  return bstree_cota_inferior_aux(arbol, k);
}

/*
 * visita a los datos en el intervalo [cota inf, cota sup].
*/
static void bstree_recorrer_intervalo_aux(BSTree arbol, void* cota_inf, void* cota_sup, FuncionComparadora cmp, FuncionVisitanteExtra visitante, void* extra){
  if(arbol == NULL) return;
  if(cmp(arbol->dato, cota_inf) > 0){
    bstree_recorrer_intervalo_aux(arbol->izq, cota_inf, cota_sup, cmp, visitante, extra);
  }
  if(cmp(arbol->dato, cota_inf) >= 0 && cmp(arbol->dato, cota_sup) <= 0){
    visitante(arbol->dato, extra);
  }
  if(cmp(arbol->dato, cota_sup) < 0){
    bstree_recorrer_intervalo_aux(arbol->der, cota_inf, cota_sup, cmp, visitante, extra);
  }
}

void bstree_recorrer_intervalo(BSTree arbol, void* cota_inf, void* cota_sup, FuncionComparadora cmp, FuncionVisitanteExtra visitante, void* extra){
  if(arbol == NULL) return;
  return bstree_recorrer_intervalo_aux(arbol, cota_inf, cota_sup, cmp, visitante, extra);
}

/*
 * Dado un arbol de búsqueda binaria, reordene las referencias de los nodos de manera que se convierta en una lista doblemente circular (ordenada)
*/
static BSTree cdlist_bstree_concatenar(BSTree lista1, BSTree lista2){
  if(lista1 == NULL) return lista2;
  if(lista2 == NULL) return lista1;

  BSTree ultimo1 = lista1->izq;
  BSTree ultimo2 = lista2->izq;

  // conectar el ultimo de la primera lista con el primero de la segunda
  ultimo1->der = lista2;
  lista2->izq = ultimo1;

  // conectar el ultimo de la segunda lista con el primero de la primera
  ultimo2->der = lista1;
  lista1->izq = ultimo2;

  return lista1;
}

static BSTree cdlist_bstree_to_cdlist_aux(BSTree arbol){
  if(arbol == NULL) return NULL;
  BSTree lista_izq = cdlist_bstree_to_cdlist_aux(arbol->izq);
  BSTree lista_der = cdlist_bstree_to_cdlist_aux(arbol->der);

  arbol->izq = arbol->der = arbol;

  BSTree result = cdlist_bstree_concatenar(lista_izq, arbol);
  result = cdlist_bstree_concatenar(result, lista_der);

  return result;
}

BSTree cdlist_bstree_to_cdlist(BSTree arbol){
  return cdlist_bstree_to_cdlist_aux(arbol);
}

/*
 *  Dado un arreglo con los datos del recorrido PRE ORDER de un árbol binario de búsqueda, reconstruye el árbol
*/
static BSTree construir_arbol_preorden_aux(void** recorrido, int* index, void* limite_inferior, void* limite_superior, int size, FuncionCopiadora copiar, FuncionComparadora cmp){
  if(*index >= size) return NULL;

  void* valor = recorrido[*index];

  if((limite_inferior != NULL && cmp(valor, limite_inferior) <= 0) || (limite_superior != NULL && cmp(valor, limite_superior) >= 0)) return NULL; // Fuera de rango

  BSTree nodo = (BSTree)malloc(sizeof(struct _BST_Nodo));
  assert(nodo != NULL);

  nodo->dato = copiar(valor);
  nodo->tam_subarbol = 1;

  (*index)++; // Incrementamos el índice

  nodo->izq = construir_arbol_preorden_aux(recorrido, index, limite_inferior, valor, size, copiar, cmp);
  nodo->der = construir_arbol_preorden_aux(recorrido, index, valor, limite_superior, size, copiar, cmp);

  if(nodo->izq) nodo->tam_subarbol += nodo->izq->tam_subarbol;
  if(nodo->der) nodo->tam_subarbol += nodo->der->tam_subarbol;

  return nodo;
}

BSTree construir_arbol_preorden(void** recorrido, int size, FuncionCopiadora copiar, FuncionComparadora cmp){
  int index = 0;
  return construir_arbol_preorden_aux(recorrido, &index, NULL, NULL, size, copiar, cmp);
}

/*
 * Dada una secuencia de datos, determina si corresponde al recorrido BFS de un árbol binario de búsqueda completo y, en dicho caso, lo construya de manera eficiente. Extra: considerar el caso en que no tenemos la información de que el árbol sea completo.
*/
int verificar_bfs_bst_aux(void** arr, int size, int index, void* min, void* max, FuncionComparadora cmp){
  if(index >= size) return 1;

  void* value = arr[index];

  if((min && cmp(value, min) <= 0) || (max && cmp(value, max) >= 0)) return 0;

  return verificar_bfs_bst_aux(arr, size, 2 * index + 1, min, value, cmp) &&
         verificar_bfs_bst_aux(arr, size, 2 * index + 2, value, max, cmp);
}

int verificar_bfs_bst(void** arr, int size, FuncionComparadora cmp){
  if(size == 0) return 1;
  return verificar_bfs_bst_aux(arr, size, 0, NULL, NULL, cmp);
}

BSTree construir_bst_recorrido_bfs_aux(void** arr, int size, int index, FuncionCopiadora copiar){
  if(index >= size) return NULL;

  BSTree nodo = (BSTree)malloc(sizeof(struct _BST_Nodo));
  assert(nodo != NULL);
  nodo->dato = copiar(arr[index]);
  nodo->izq = construir_bst_recorrido_bfs_aux(arr, size, 2 * index + 1, copiar);
  nodo->der = construir_bst_recorrido_bfs_aux(arr, size, 2 * index + 2, copiar);
  nodo->tam_subarbol = 1 + (nodo->izq ? nodo->izq->tam_subarbol : 0) + (nodo->der ? nodo->der->tam_subarbol : 0);

  return nodo;
}

BSTree construir_bst_recorrido_bfs(void** arr, int size, FuncionCopiadora copiar, FuncionComparadora cmp){
  if(!verificar_bfs_bst(arr, size, cmp)) return NULL;
  return construir_bst_recorrido_bfs_aux(arr, size, 0, copiar);
}