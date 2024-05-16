#include "glist.h"

GList glist_crear(){
  GList lista = (GList)malloc(sizeof(LinkedList));
  assert(lista != NULL);
  lista->primero = NULL;
  lista->ultimo = NULL;
  return lista;
}

GList glist_insertar_final(GList lista, void* dato, FuncionCopia copy){
  GNodo* nuevoNodo = (GNodo*)malloc(sizeof(GNodo));
  assert(nuevoNodo != NULL);
  nuevoNodo->data = copy(dato);
  nuevoNodo->next = NULL;
  if(glist_vacio(lista)){
    lista->primero = nuevoNodo;
  } else {
    lista->ultimo->next = nuevoNodo;
  }
  lista->ultimo = nuevoNodo;
  return lista;
}

GList glist_eliminar_inicio(GList lista, FuncionDestructora destroy){
  assert(lista->primero != NULL);
  GNodo* temp = lista->primero;
  lista->primero = lista->primero->next;
  if(lista->primero == NULL){
    lista->ultimo = NULL;
  }
  destroy(temp->data);
  free(temp);
  return lista;
}

int glist_vacio(GList lista){
  return lista->primero == NULL;
}

void glist_destruir(GList lista, FuncionDestructora destroy){
  GNodo* current = lista->primero;
  while(current != NULL){
    GNodo* temp = current;
    destroy(temp->data);
    free(temp);
    current = current->next;
  }
  free(lista);
}

void glist_mostrar(GList lista, FuncionVisitante visit){
  for(GNodo* nodo = lista->primero; nodo != NULL; nodo = nodo->next){
    visit(nodo->data);
  }
  printf("\n");
}