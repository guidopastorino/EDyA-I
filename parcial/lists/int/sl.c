// SINGLY LINKED LIST

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _SNodo {
  int dato;
  struct _SNodo* sig;
} SNodo;

SNodo* crear_nodo(int dato){
  SNodo* nuevoNodo = (SNodo*)malloc(sizeof(SNodo));
  assert(nuevoNodo != NULL);
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;
  return nuevoNodo;
}

void insertar_inicio(SNodo** head, int dato){
  SNodo* nuevoNodo = crear_nodo(dato);
  nuevoNodo->sig = *head;
  *head = nuevoNodo;
}

void insertar_final(SNodo** head, int dato){
  SNodo* nuevoNodo = crear_nodo(dato);
  if(*head == NULL){
    *head = nuevoNodo;
  } else {
    SNodo* current = *head;
    while(current->sig != NULL){
      current = current->sig;
    }
    current->sig = nuevoNodo;
  }
}

void insertar_mitad(SNodo** head, int dato){
  if(*head == NULL){
    insertar_inicio(head, dato);
    return;
  }
  SNodo* nuevoNodo = crear_nodo(dato);
  SNodo* slowPtr = *head;
  SNodo* fastPtr = *head;
  while(fastPtr->sig != NULL && fastPtr->sig->sig != NULL){
    slowPtr = slowPtr->sig;
    fastPtr = fastPtr->sig->sig;
  }
  nuevoNodo->sig = slowPtr->sig;
  slowPtr->sig = nuevoNodo;
}

void insertar_posicion(SNodo** head, int pos, int dato){
  assert(pos >= 0);
  if(pos == 0){
    insertar_inicio(head, dato);
    return;
  }
  SNodo* nuevoNodo = crear_nodo(dato);
  SNodo* current = *head;
  for(int i = 0; i<pos-1 && current != NULL; i++){
    current = current->sig;
  }
  assert(current != NULL); // verificamos que la posicion que nos pasaron no exceda
  nuevoNodo->sig = current->sig;
  current->sig = nuevoNodo;
}

void eliminar_inicio(SNodo** head){
  assert(*head != NULL);
  SNodo* temp = *head;
  *head = (*head)->sig;
  free(temp);
}

void eliminar_final(SNodo** head){
  assert(*head != NULL);
  if((*head)->sig == NULL){
    eliminar_inicio(head);
    return;
  }
  SNodo* current = *head;
  while(current->sig->sig != NULL){
    current = current->sig;
  }
  free(current->sig);
  current->sig = NULL;
}

void eliminar_mitad(SNodo** head){
  assert(*head != NULL);
  SNodo* prev = NULL;
  SNodo* slowPtr = *head;
  SNodo* fastPtr = *head;
  while(fastPtr != NULL && fastPtr->sig != NULL){
    prev = slowPtr;
    slowPtr = slowPtr->sig;
    fastPtr = fastPtr->sig->sig;
  }
  if(prev == NULL){
    eliminar_inicio(head);
  } else {
    prev->sig = slowPtr->sig;
    free(slowPtr);
  }
}

void eliminar_posicion(SNodo** head, int pos){
  assert(*head != NULL && pos >= 0);
  if(pos == 0){
    eliminar_inicio(head);
    return;
  }
  SNodo* current = *head;
  SNodo* temp;
  for(int i = 0; i<pos-1 && current != NULL; i++){
    current = current->sig;
  }
  assert(current != NULL && current->sig != NULL);
  temp = current->sig;
  current->sig = current->sig->sig;
  free(temp);
}

void imprimir_lista(SNodo* head){
  while(head != NULL){
    printf("%d -> ", head->dato);
    head = head->sig;
  }
  printf("NULL\n");
}

int main(){
  SNodo* head = NULL;
  insertar_final(&head, 30);
  insertar_final(&head, 40);
  insertar_mitad(&head, 100);

  imprimir_lista(head);
  eliminar_mitad(&head);
  imprimir_lista(head);
  eliminar_mitad(&head);
  imprimir_lista(head);
  eliminar_mitad(&head);
  imprimir_lista(head);

  return 0;
}