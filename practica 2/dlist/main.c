#include "dlist.h"

int main(){
  DList* lista = NULL;
  
  insertar_inicio(&lista, 20);
  insertar_inicio(&lista, 10);
  insertar_final(&lista, 30);

  dlist_recorrer(lista, DLIST_RECORRIDO_HACIA_ADELANTE);
  dlist_recorrer(lista, DLIST_RECORRIDO_HACIA_ATRAS);

  return 0;
}