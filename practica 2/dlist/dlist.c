#include "dlist.h"

DList* crear_lista(DNodo* nodo){
  DList* lista = (DList*)malloc(sizeof(DList));
  assert(lista != NULL);
  lista->primero = nodo;
  lista->ultimo = nodo;
  return lista;
}

DNodo *crear_nodo(int dato){
  DNodo* nuevoNodo = (DNodo*)malloc(sizeof(DNodo));
  assert(nuevoNodo != NULL);
  nuevoNodo->dato = dato;
  nuevoNodo->ant = NULL;
  nuevoNodo->sig = NULL;
  return nuevoNodo;
}

void insertar_inicio(DList** lista, int dato){
  DNodo* nuevoNodo = crear_nodo(dato);
  if(*lista == NULL){
    *lista = crear_lista(nuevoNodo);
  } else {
    nuevoNodo->sig = (*lista)->primero;
    (*lista)->primero->ant = nuevoNodo;
    (*lista)->primero = nuevoNodo;
  }
}

void insertar_final(DList** lista, int dato){
  DNodo* nuevoNodo = crear_nodo(dato);
  if(*lista == NULL){
    *lista = crear_lista(nuevoNodo);
  } else {
    nuevoNodo->ant = (*lista)->ultimo;
    (*lista)->ultimo->sig = nuevoNodo;
    (*lista)->ultimo = nuevoNodo;
  }
}

void insertar_posicion(DList **lista, int dato);

void eliminar_inicio(DList **lista){
  assert(*lista != NULL);
  DNodo* temp = (*lista)->primero;
  (*lista)->primero = (*lista)->primero->sig;
  if((*lista)->primero == NULL){
    (*lista)->ultimo = NULL;
  } else {
    (*lista)->primero->ant = NULL;
  }
  free(temp);
}

void eliminar_final(DList **lista){
  assert(*lista != NULL);
  DNodo* temp = (*lista)->ultimo;
  (*lista)->ultimo = (*lista)->ultimo->ant;
  if((*lista)->ultimo == NULL){
    (*lista)->primero = NULL;
  } else {
    (*lista)->ultimo->sig = NULL;
  }
  free(temp);
}

void eliminar_posicion(DList **lista, int pos){
  assert(*lista != NULL);
}

int longitud_lista(DList *lista){
  DNodo* current = lista->primero;
  int len = 0;
  while(current != NULL){
    len++;
    current = current->sig;
  }
  return len;
}

void imprimir_adelante(DList *lista){
  DNodo* current = lista->primero;
  while(current != NULL){
    printf("%d -> ", current->dato);
    current = current->sig;
  }
  printf("NULL\n");
}

void imprimir_atras(DList *lista){
  DNodo* current = lista->ultimo;
  while(current != NULL){
    printf("%d -> ", current->dato);
    current = current->ant;
  }
  printf("NULL\n");
}

void dlist_recorrer(DList *lista, DListOrdenDeRecorrido tipo){
  if(tipo == DLIST_RECORRIDO_HACIA_ADELANTE){
    imprimir_adelante(lista);
  } else if (tipo == DLIST_RECORRIDO_HACIA_ATRAS){
    imprimir_atras(lista);
  } else {
    printf("Número de tipo no válido\n");
  }
}

void liberar_lista(DList *lista){
  DNodo* current = lista->primero;
  while(current != NULL){
    DNodo* temp = current;
    current = current->sig;
    free(temp);
  }
}