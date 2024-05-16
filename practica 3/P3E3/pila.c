#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct _Pila {
  GList lista;
};

Pila pila_crear(){
  Pila pila = (Pila)malloc(sizeof(struct _Pila));
  assert(pila != NULL);
  pila->lista = glist_crear();
  return pila;
}

int pila_vacia (Pila p){
  return glist_vacia(p->lista);
}

Pila pila_apilar(Pila p, void* dato, FuncionCopia copy){
  glist_agregar_final(p->lista, dato, copy);
  return p;
}

void* pila_tope(Pila p){
  assert(!pila_vacia(p));
  return p->lista->first->data;
}

Pila pila_desapilar(Pila p, FuncionDestructora destruir){
  assert(!pila_vacia(p));
  GNode* nodo = p->lista->first;
  p->lista->first = nodo->next;
  if(p->lista->first == NULL)
    p->lista->last = NULL;
  destruir(nodo->data);
  free(nodo);
  return p;
}

void pila_destruir(Pila p, FuncionDestructora destruir){
  GNode* current = p->lista->first;
  while(current != NULL){
    GNode* temp = current;
    destruir(temp->data);
    free(temp);
    current = current->next;
  }
  free(p->lista); // eliminar lista
  free(p);
}