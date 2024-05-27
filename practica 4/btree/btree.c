#include "btree.h"
#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct _BTNodo {
  int dato;
  struct _BTNodo *left;
  struct _BTNodo *right;
};

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear() { return NULL; }

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo) {
  if (nodo != NULL) {
    btree_destruir(nodo->left);
    btree_destruir(nodo->right);
    free(nodo);
  }
}

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo) { return nodo == NULL; }

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right) {
  BTree nuevoNodo = malloc(sizeof(struct _BTNodo));
  assert(nuevoNodo != NULL);
  nuevoNodo->dato = dato;
  nuevoNodo->left = left;
  nuevoNodo->right = right;
  return nuevoNodo;
}

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit) {
  if(arbol != NULL){
    if(orden == BTREE_RECORRIDO_PRE){
      // Recursivo
      // visit(arbol->dato);
      // btree_recorrer(arbol->left, orden, visit);
      // btree_recorrer(arbol->right, orden, visit);

      // Utilizando una pila general
      StackNode stack = NULL;
      push(&stack, arbol);
      while(!is_empty(stack)){
        BTree node = pop(&stack);
        printf("%d ", node->dato);
        if(node->right) push(&stack, node->right);
        if(node->left) push(&stack, node->left);
      }
    }
    if(orden == BTREE_RECORRIDO_IN){
      // Recursivo
      // btree_recorrer(arbol->left, orden, visit);
      // visit(arbol->dato);
      // btree_recorrer(arbol->right, orden, visit);

      // Utilizando una pila general
      StackNode stack = NULL;
      BTree current = arbol;
      while(current != NULL || !is_empty(stack)){
        while(current != NULL){
          push(&stack, current);
          current = current->left;
        }
        current = pop(&stack);
        printf("%d ", current->dato);
        current = current->right;
      }
    }
    if(orden == BTREE_RECORRIDO_POST){
      // Recursivo
      // btree_recorrer(arbol->left, orden, visit);
      // btree_recorrer(arbol->right, orden, visit);
      // visit(arbol->dato);

      // Utilizando una pila general
      StackNode stack1 = NULL;
      StackNode stack2 = NULL;
      push(&stack1, arbol);
      while(!is_empty(stack1)){
        BTree node = pop(&stack1);
        push(&stack2, node);
        if(node->left) push(&stack1, node->left);
        if(node->right) push(&stack1, node->right);
      }
      while(!is_empty(stack2)){
        BTree node = pop(&stack2);
        printf("%d ", node->dato);
      }
    }
  }
}

/**
 * Recorrido del arbol, utilizando la funcion pasada y un dato extra
 */
void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitanteExtra visit, void *extra){
  // Haciendo recorrido dfs de manera recursiva
  if(arbol != NULL){
    if(orden == BTREE_RECORRIDO_PRE){
      visit(arbol->dato, extra);
      btree_recorrer_extra(arbol->left, orden, visit, extra);
      btree_recorrer_extra(arbol->right, orden, visit, extra);
    }
    if(orden == BTREE_RECORRIDO_IN){
      btree_recorrer_extra(arbol->left, orden, visit, extra);
      visit(arbol->dato, extra);
      btree_recorrer_extra(arbol->right, orden, visit, extra);
    }
    if(orden == BTREE_RECORRIDO_POST){
      btree_recorrer_extra(arbol->left, orden, visit, extra);
      btree_recorrer_extra(arbol->right, orden, visit, extra);
      visit(arbol->dato, extra);
    }
  }
}

/*
 * Retorna la cantidad de nodos en el arbol
 */
int btree_nnodos(BTree arbol){
  if(arbol == NULL) return 0;
  return 1 + btree_nnodos(arbol->left) + btree_nnodos(arbol->right);
}

/*
 * Retorna 1 si el número se encuentra en el arbol, 0 en caso contrario
 */
int btree_buscar(BTree arbol, int dato){
  if(arbol == NULL) return 0;
  if(arbol->dato == dato) return 1;
  if(btree_buscar(arbol->left, dato)) return 1;
  if(btree_buscar(arbol->right, dato)) return 1;
  return 0;
}

/*
 * Retorna un nuevo arbol que es una copia del arbol dado
 */
BTree btree_copiar(BTree arbol){
  if(arbol == NULL) return NULL;
  BTree nuevo_nodo = (BTree)malloc(sizeof(struct _BTNodo));
  assert(nuevo_nodo != NULL);
  nuevo_nodo->dato = arbol->dato;
  // copiar recursivamente los subárboles
  nuevo_nodo->left = btree_copiar(arbol->left);
  nuevo_nodo->right = btree_copiar(arbol->right);
  return nuevo_nodo;
}

/*
 * Retorna la altura del arbol
 */
int btree_altura(BTree arbol){
  if(arbol == NULL) return -1;
  int left_height = btree_altura(arbol->left);
  int right_height = btree_altura(arbol->right);
  return 1 + (left_height > right_height ? left_height : right_height);
}

/*
 * Retorna el número de nodos que se encuentran a la profundidad dada
 */
int btree_nnodos_profundidad(BTree arbol, int profundidad){
  if(arbol == NULL) return 0;
  if(profundidad == 0) return 1;
  int nodos_izquierda = btree_nnodos_profundidad(arbol->left, profundidad - 1);
  int nodos_derecha = btree_nnodos_profundidad(arbol->right, profundidad - 1);
  return nodos_izquierda + nodos_derecha;
}

/*
 * Retorna la profundidad del nodo que contiene el némero dado, y -1 si el némero no se encuentra en el árbol.
 */
int btree_profundidad(BTree arbol, int dato){
  if(arbol == NULL) return -1;
  if(arbol->dato == dato) return 0;
  int left_depth = btree_profundidad(arbol->left, dato);
  if(left_depth >= 0) return (left_depth + 1);
  int right_depth = btree_profundidad(arbol->right, dato);
  if(right_depth >= 0) return (right_depth + 1);
}

/*
 * Retorna la suma total de los datos del árbol.
 */
int btree_sumar(BTree arbol){
  if(arbol == NULL) return 0;
  int left_sum = btree_sumar(arbol->left);
  int right_sum = btree_sumar(arbol->right);
  return arbol->dato + left_sum + right_sum;
}

/*
 * Funciones compactadas del ejercicio 3 (definir de manera compacta llamando a btree_recorrer_extra con un orden, una función visitante y un dato extra apropiados)
*/

// Funcion auxiliar contar nodos
void contar_nodos(int dato, void* extra){
  int* contador = (int*)extra;
  (*contador)++;
}

int btree_nnodos_compact(BTree arbol){
  int contador = 0;
  btree_recorrer_extra(arbol, BTREE_RECORRIDO_IN, contar_nodos, &contador);
  return contador;
}

// Funcion auxiliar buscar nodo
void buscar_nodo(int dato, void* extra){
  int* buscado_y_encontrado = (int*)extra;
  int buscado = buscado_y_encontrado[0];
  if(dato == buscado){
    buscado_y_encontrado[1] = 1;
  }
}

int btree_buscar_compact(BTree arbol, int dato){
  int buscado_y_encontrado[2] = {dato, 0};
  btree_recorrer_extra(arbol, BTREE_RECORRIDO_IN, buscar_nodo, &buscado_y_encontrado);
  return buscado_y_encontrado[1]; // Retorna si se encontró el elemento o no
}

// Función auxiliar suma
void sumar_datos(int dato, void* extra){
  int* suma = (int*)extra;
  (*suma) += dato;
}

int btree_sumar_compact(BTree arbol){
  int suma = 0;
  btree_recorrer_extra(arbol, BTREE_RECORRIDO_IN, sumar_datos, &suma);
  return suma;
}

/*
 * Implementación de recorrido BFS de forma iterativa usando un Queue
*/
void btree_recorrer_bfs_iterativo(BTree arbol, FuncionVisitante visit){
  if(arbol == NULL) return;
  int count = btree_nnodos(arbol);
  BTree* queue = (BTree*)malloc(sizeof(BTree) * count);
  assert(queue != NULL);
  int front = 0, rear = 0;
  queue[rear++] = arbol; // enqueue the root
  while(front < rear){
    BTree node = queue[front++]; // dequeue the front 
    visit(node->dato);
    if(node->left)
      queue[rear++] = node->left; // enqueue the left subnode
    if(node->right)
      queue[rear++] = node->right; // enqueue the right subnode
  }
  printf("\n");
  free(queue);
}

/*
 * Implementación de recorrido BFS de forma recursiva usando una función auxiliar
*/
void btree_recorrer_bfs_recursivo_aux(BTree arbol, int nivel, FuncionVisitante visit){
  if(arbol == NULL) return;
  if(nivel == 1){
    visit(arbol->dato);
  } else if (nivel > 1){
    btree_recorrer_bfs_recursivo_aux(arbol->left, nivel - 1, visit);
    btree_recorrer_bfs_recursivo_aux(arbol->right, nivel - 1, visit);
  }
}

void btree_recorrer_bfs_recursivo(BTree arbol, FuncionVisitante visit){
  if(arbol == NULL) return;
  int altura = btree_altura(arbol);
  for(int i = 1; i<=altura+1; i++){
    btree_recorrer_bfs_recursivo_aux(arbol, i, visit);
  }
  printf("\n");
}

/*
 * dado un árbol binario, genera el árbol binario espejo, donde el hijo derecho de cada nodo pasa a ser izquierdo y el izquierdo pasa a ser derecho.
*/
BTree btree_mirror(BTree arbol){
  if(arbol == NULL) return NULL;

  BTree mirror_node = (BTree)malloc(sizeof(struct _BTNodo));
  assert(mirror_node != NULL);
  
  mirror_node->dato = arbol->dato;

  mirror_node->left = btree_mirror(arbol->left);
  mirror_node->right = btree_mirror(arbol->right);

  return mirror_node;
}

/*
 * Determina si un arbol binario es completo o no (todos los niveles tienen dos hijos y las hojas por lo menos están ubicadas de izq a der)
*/
static int btree_es_completo_aux(BTree arbol, int index, int count){
  if(arbol == NULL) return 1;
  if(index >= count) return 0;
  return btree_es_completo_aux(arbol->left, 2 * index + 1, count) && btree_es_completo_aux(arbol->right, 2 * index + 2, count);
}

int btree_es_completo(BTree arbol){
  if(arbol == NULL) return 1;
  int index = 0;
  int count = btree_nnodos(arbol);
  return btree_es_completo_aux(arbol, index, count);
}