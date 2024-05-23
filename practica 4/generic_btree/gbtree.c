#include "gbtree.h"

struct _GBTreeNode {
  void* dato;
  struct _GBTreeNode* left;
  struct _GBTreeNode* right;
};

/**
 * Devuelve un arbol vacío.
 */
GBTree gbtree_crear() { return NULL; }

/**
 * Destruccion del árbol.
 */
void gbtree_destruir(GBTree arbol){
  if(arbol != NULL){
    gbtree_destruir(arbol->left);
    gbtree_destruir(arbol->right);
    free(arbol);
  }
}

/**
 * Indica si el árbol es vacío.
 */
int gbtree_vacio(GBTree arbol){
  return arbol == NULL;
}

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
GBTree gbtree_unir(void* dato, GBTree left, GBTree right, FuncionCopia copy){
  GBTree nodo = (GBTree)malloc(sizeof(struct _GBTreeNode));
  assert(nodo != NULL);
  nodo->dato = copy(dato);
  nodo->left = left;
  nodo->right = right;
  return nodo;
}

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void gbtree_recorrer(GBTree arbol, Recorrido orden, FuncionVisitante visit){
  if(arbol != NULL){
    if(orden == GBTREE_RECORRIDO_PRE){
      visit(arbol->dato);
      gbtree_recorrer(arbol->left, orden, visit);
      gbtree_recorrer(arbol->right, orden, visit);
    }
    if(orden == GBTREE_RECORRIDO_IN){
      gbtree_recorrer(arbol->left, orden, visit);
      visit(arbol->dato);
      gbtree_recorrer(arbol->right, orden, visit);
    }
    if(orden == GBTREE_RECORRIDO_POST){
      gbtree_recorrer(arbol->left, orden, visit);
      gbtree_recorrer(arbol->right, orden, visit);
      visit(arbol->dato);
    }
  }
}

/**
 * Recorrido del arbol, utilizando la funcion pasada y un dato extra
 */
void gbtree_recorrer_extra(GBTree arbol, Recorrido orden, FuncionVisitanteExtra visit, void* extra){
  if(arbol != NULL){
    if(orden == GBTREE_RECORRIDO_PRE){
      visit(arbol->dato, extra);
      gbtree_recorrer_extra(arbol->left, orden, visit, extra);
      gbtree_recorrer_extra(arbol->right, orden, visit, extra);
    }
    if(orden == GBTREE_RECORRIDO_IN){
      gbtree_recorrer_extra(arbol->left, orden, visit, extra);
      visit(arbol->dato, extra);
      gbtree_recorrer_extra(arbol->right, orden, visit, extra);
    }
    if(orden == GBTREE_RECORRIDO_POST){
      gbtree_recorrer_extra(arbol->left, orden, visit, extra);
      gbtree_recorrer_extra(arbol->right, orden, visit, extra);
      visit(arbol->dato, extra);
    }
  }
}