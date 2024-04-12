// Dada una lista enlazada simple ordenada, agrega el nuevo elemento en la posicion correcta según su orden

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _SNodo {
  int dato;
  struct _SNodo* sig;
} SNodo;

typedef struct SList {
  SNodo* primero;
  SNodo* ultimo;
} SList;

SNodo* crear_nodo(int dato){
  SNodo* nuevoNodo = (SNodo*)malloc(sizeof(SNodo));
  assert(nuevoNodo != NULL);
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;
  return nuevoNodo;
}

SList* inicializar_lista(){
  SList* nuevaLista = (SList*)malloc(sizeof(SList));
  assert(nuevaLista != NULL);
  nuevaLista->primero = NULL;
  nuevaLista->ultimo = NULL;
  return nuevaLista;
}

SList* insertar_inicio(SList* lista, int dato){
  SNodo* nuevoNodo = crear_nodo(dato);
  if(lista->primero == NULL){
    lista->primero = lista->ultimo = nuevoNodo;
  } else {
    nuevoNodo->sig = lista->primero;
    lista->primero = nuevoNodo;
  }
  return lista;
}

SList* insertar_elemento_posicion_correcta(SList* lista, int elemento){
  if(lista == NULL){
    lista = inicializar_lista();
  }
  if(elemento <= lista->primero->dato){
    insertar_inicio(lista, elemento);
  } else {
    SNodo* nuevoNodo = crear_nodo(elemento);
    SNodo* current = lista->primero;
    SNodo* prev = NULL;
    while(current != NULL && elemento > current->dato){
      prev = current;
      current = current->sig;
    }
    prev->sig = nuevoNodo;
    nuevoNodo->sig = current;
    if(current == NULL){
      lista->ultimo = nuevoNodo;
    }
  }
  return lista;
}

void imprimir_lista(SList* lista){
  SNodo* current = lista->primero;
  while(current != NULL){
    printf("%d -> ", current->dato);
    current = current->sig;
  }
  printf("NULL\n");
}

int main(){
  SList* lista = inicializar_lista();
  for(int i = 10; i>0; --i){
    lista = insertar_inicio(lista, i);
  }

  imprimir_lista(lista);

  lista = insertar_elemento_posicion_correcta(lista, 8);
  lista = insertar_elemento_posicion_correcta(lista, 1);
  lista = insertar_elemento_posicion_correcta(lista, 11);

  imprimir_lista(lista);

  return 0;
}