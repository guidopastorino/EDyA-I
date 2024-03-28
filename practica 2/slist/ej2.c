#include "slist.h"

int main(){
  Node* head = NULL;

  insertar_final(&head, 5);
  insertar_final(&head, 30);
  insertar_final(&head, 20);
  insertar_final(&head, 10);
  insertar_final(&head, 1);


  imprimir_lista(head);

  int (*funcPtr)(int, int) = &compare;

  slist_ordenar(&head, funcPtr);

  imprimir_lista(head);


  Node* secondHalf = slist_partir(head);
  imprimir_lista(secondHalf);


  liberar_lista(head);

  return 0;
}