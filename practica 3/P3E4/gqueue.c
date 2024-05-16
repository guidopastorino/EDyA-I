#include "gqueue.h"

GQueue* gqueue_crear(){
  GQueue* queue = (GQueue*)malloc(sizeof(GQueue));
  assert(queue != NULL);
  queue->lista = glist_crear();
  return queue;
}

int gqueue_vacio(GQueue* queue){
  return queue->lista->primero == NULL;
}

GQueue* gqueue_encolar(GQueue* queue, void* dato, FuncionCopia copy){
  queue->lista = glist_insertar_final(queue->lista, dato, copy);
  return queue;
}

void* gqueue_desencolar(GQueue* queue, FuncionDestructora destroy){
  if(gqueue_vacio(queue)){
    printf("Queue vacío, no se puede desencolar\n");
    exit(EXIT_FAILURE);
  }
  GNodo* nodo = queue->lista->primero;
  queue->lista = glist_eliminar_inicio(queue->lista, destroy);
  return nodo->data;
}

void gqueue_recorrer(GQueue* queue, FuncionVisitante visit){
  if(gqueue_vacio(queue)){
    printf("Queue vacío\n");
    exit(EXIT_FAILURE);
  }
  glist_mostrar(queue->lista, visit);
}

void gqueue_destruir(GQueue* queue, FuncionDestructora destroy){
  glist_destruir(queue->lista, destroy);
  free(queue->lista);
  free(queue);
}
