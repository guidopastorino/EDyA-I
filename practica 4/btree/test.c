#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

static void imprimir_entero(int data) {
  printf("%d ", data);
}

void imprimir_valor_suma(int dato, void* extra){
  int dato_extra = *(int*)extra;
  printf("Nodo %d sumado a %d: %d\n", dato, dato_extra, dato + dato_extra);
}

int main() {
  BTree ll = btree_unir(1, btree_crear(), btree_crear());
  BTree l = btree_unir(2, ll, btree_crear());
  BTree r = btree_unir(3, btree_crear(), btree_crear());
  BTree raiz = btree_unir(4, l, r);

  // Árbol:
  //    4     (profundidad 0)   (altura 2)        
  //   2 3    (profundidad 1)   (altura 1)        
  //  1       (profundidad 2)   (altura 0)   

  btree_recorrer(raiz, BTREE_RECORRIDO_PRE, imprimir_entero); // 4 2 1 3
  puts("");
  btree_recorrer(raiz, BTREE_RECORRIDO_IN, imprimir_entero); // 1 2 4 3
  puts("");
  btree_recorrer(raiz, BTREE_RECORRIDO_POST, imprimir_entero); // 1 2 3 4
  puts("");

  printf("Nodos: %d\n", btree_nnodos(raiz));
  printf("Nodo con valor 2 en el arbol: %d\n", btree_buscar(raiz, 2));
  printf("Altura arbol: %d\n", btree_altura(raiz));
  printf("Nodos en la profundidad 1: %d\n", btree_nnodos_profundidad(raiz, 1));
  printf("Profundidad del nodo con el valor 3: %d\n", btree_profundidad(raiz, 3));
  printf("Suma de los nodos del arbol: %d\n", btree_sumar(raiz));
  int dato_extra = 10;
  btree_recorrer_extra(raiz, BTREE_RECORRIDO_IN, imprimir_valor_suma, &dato_extra);
  printf("Recorrido BFS Iterativo: ");
  btree_recorrer_bfs_iterativo(raiz, imprimir_entero);
  printf("Recorrido BFS Recursivo: ");
  btree_recorrer_bfs_recursivo(raiz, imprimir_entero);
  printf("Funciones compactadas: \n");
  printf("Nodos: %d\n", btree_nnodos_compact(raiz));
  printf("Nodo con valor 5 en el arbol: %d\n", btree_buscar_compact(raiz, 5));
  printf("Nodo con valor 3 en el arbol: %d\n", btree_buscar_compact(raiz, 3));
  printf("Suma de los nodos del arbol: %d\n", btree_sumar_compact(raiz));

  printf("Arbol copia: \n");
  BTree arbol_copia = btree_copiar(raiz);
  btree_recorrer(arbol_copia, BTREE_RECORRIDO_IN, imprimir_entero); // 1 2 4 3
  puts("");
  printf("Nodos arbol copia: %d\n", btree_nnodos(arbol_copia));

  puts("Btree Mirror: ");
  BTree mirror = btree_mirror(arbol_copia);
  btree_recorrer(mirror, BTREE_RECORRIDO_IN, imprimir_entero); // 1 2 4 3
  puts("");
  printf("Nodos arbol mirror de la copia: %d\n", btree_nnodos(mirror)); // 4

  printf("Es un arbol binario completo 'raiz': %d\n", btree_es_completo(raiz));
  printf("Es un arbol binario completo 'arbol_copia': %d\n", btree_es_completo(arbol_copia));
  printf("Es un arbol binario completo 'mirror': %d\n", btree_es_completo(mirror));
  
  btree_destruir(raiz);
  btree_destruir(arbol_copia);
  btree_destruir(mirror);

  return 0;
}
