// DOUBLY LINKED LIST
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _Dnodo {
  int dato;
  struct _Dnodo* ant;
  struct _Dnodo* sig;
} Dnodo;

Dnodo* crear_nodo(int dato){
  Dnodo* nuevoNodo = (Dnodo*)malloc(sizeof(Dnodo));
  assert(nuevoNodo != NULL);
  nuevoNodo->dato = dato;
  nuevoNodo->ant = NULL;
  nuevoNodo->sig = NULL;
  return nuevoNodo;
}

void insertar_inicio(Dnodo** head, int dato){
  Dnodo* nuevoNodo = crear_nodo(dato);
  if(*head == NULL){
    *head = nuevoNodo;
  } else {
    nuevoNodo->sig = *head;
    (*head)->ant = nuevoNodo;
    *head = nuevoNodo;
  }
}

void insertar_final(Dnodo** head, int dato){
  Dnodo* nuevoNodo = crear_nodo(dato);
  if(*head == NULL){
    *head = nuevoNodo;
  } else {
    Dnodo* current = *head;
    while(current->sig != NULL){
      current = current->sig;
    }
    current->sig = nuevoNodo;
    nuevoNodo->ant = current;
  }
}

void insertar_posicion(Dnodo** head, int pos, int dato){
  if(pos == 0){
    insertar_inicio(head, dato);
    return;
  }
  Dnodo* nuevoNodo = crear_nodo(dato);
  Dnodo* current = *head;
  for(int i = 0; i<pos-1 && current != NULL; i++){
    current = current->sig;
  }
  assert(current != NULL);
  nuevoNodo->sig = current->sig;
  if(current->sig != NULL){
    current->sig->ant = nuevoNodo;
  }
  current->sig = nuevoNodo;
  nuevoNodo->ant = current;
}

void insertar_mitad(Dnodo** head, int dato){
  Dnodo* nuevoNodo = crear_nodo(dato);
  Dnodo* prev = NULL;
  Dnodo* slowPtr = *head;
  Dnodo* fastPtr = *head;
  while(fastPtr != NULL && fastPtr->sig != NULL){
    prev = slowPtr;
    slowPtr = slowPtr->sig;
    fastPtr = fastPtr->sig->sig;
  }
  if(prev == NULL){
    insertar_inicio(head, dato);
  } else {
    prev->sig = nuevoNodo;
    nuevoNodo->ant = prev;
    nuevoNodo->sig = slowPtr;
    slowPtr->ant = nuevoNodo;
  }
}

void eliminar_inicio(Dnodo** head){
  assert(*head != NULL);
  Dnodo* temp = *head;
  *head = (*head)->sig;
  if(*head != NULL){
    (*head)->ant = NULL;
  }
  free(temp);
}

void eliminar_final(Dnodo** head){
  assert(*head != NULL);
  if((*head)->sig == NULL){
    eliminar_inicio(head);
    return;
  }
  Dnodo* current = *head;
  while(current->sig != NULL){
    current = current->sig;
  }
  if(current->ant != NULL){
    current->ant->sig = NULL;
  } else {
    *head = NULL;
  }
  free(current);
}

void eliminar_posicion(Dnodo** head, int pos){
  assert(*head != NULL);
  if(pos == 0){
    eliminar_inicio(head);
    return;
  }
  Dnodo* current = *head;
  for(int i = 0; i<pos && current != NULL; i++){
    current = current->sig;
  }
  assert(current != NULL && current->sig != NULL);
  if(current->sig != NULL){
    current->sig->ant = current->ant;
  }
  current->ant->sig = current->sig;
  free(current);
}

void eliminar_mitad(Dnodo** head){
  assert(*head != NULL);
  Dnodo* prev = NULL;
  Dnodo* slowPtr = *head;
  Dnodo* fastPtr = *head;
  while(fastPtr != NULL && fastPtr->sig != NULL){
    prev = slowPtr;
    slowPtr = slowPtr->sig;
    fastPtr = fastPtr->sig->sig;
  }
  if(prev == NULL){
    eliminar_inicio(head);
  } else {
    prev->sig = slowPtr->sig;
    if(slowPtr->sig != NULL){
      slowPtr->sig->ant = prev;
    }
    free(slowPtr);
  }
}

void imprimir(Dnodo* head){
  while(head != NULL){
    printf("%d -> ", head->dato);
    head = head->sig;
  }
  printf("NULL\n");
}

int main(){
  Dnodo* head = NULL;
  insertar_inicio(&head, 10);
  insertar_final(&head, 20);
  insertar_mitad(&head, 50);
  imprimir(head);
  eliminar_mitad(&head);
  imprimir(head);
  eliminar_mitad(&head);
  imprimir(head);
  return 0;
}