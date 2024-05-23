#include "gbtree.h"

void* copiar_entero(void* dato){
  int* dato_nuevo = (int*)malloc(sizeof(int));
  assert(dato_nuevo != NULL);
  *dato_nuevo = *(int*)dato;
  return dato_nuevo;
}

void imprimir_entero(void* dato){
  printf("%d ", *(int*)dato);
}

int main(){
  int nums[] = {1,2,3,4,5};
  GBTree n5 = gbtree_unir(&nums[4], gbtree_crear(), gbtree_crear(), copiar_entero);
  GBTree n4 = gbtree_unir(&nums[3], gbtree_crear(), gbtree_crear(), copiar_entero);
  GBTree n3 = gbtree_unir(&nums[2], gbtree_crear(), gbtree_crear(), copiar_entero);
  GBTree n2 = gbtree_unir(&nums[1], n4, n5, copiar_entero);
  GBTree root = gbtree_unir(&nums[0], n2, n3, copiar_entero);

  //         1          
  //        / \          
  //       2   3         
  //      / \           
  //     4   5          

  gbtree_recorrer(root, GBTREE_RECORRIDO_PRE, imprimir_entero);
  puts("");
  gbtree_recorrer(root, GBTREE_RECORRIDO_IN, imprimir_entero);
  puts("");
  gbtree_recorrer(root, GBTREE_RECORRIDO_POST, imprimir_entero);
  puts("");

  gbtree_destruir(root);

  return 0;
}