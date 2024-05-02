// Lista simple
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int (*Predicate)(int);
typedef int (*Compare)(int, int);

typedef struct _SNode {
  int data;
  struct _SNode* next;
} SNode;

// Crear nodo
SNode* create_node(int data){
  SNode* newNode = (SNode*)malloc(sizeof(SNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}
// insertar al inicio
SNode* insert_begin_recursive(SNode* head, int data){
  SNode* newNode = create_node(data);
  newNode->next = head;
  return newNode;
}

// Insertar al final recursivamente
SNode* insert_end_recursive(SNode* head, int data){
  if(head == NULL){
    return create_node(data);
  }
  head->next = insert_end_recursive(head->next, data);
  return head;
}

// Insertar en posición recursivamente
SNode* insert_position_recursive(SNode* head, int pos, int data){
  if(pos == 1 || head == NULL){
    return insert_begin_recursive(head, data);
  }
  head->next = insert_position_recursive(head->next, pos - 1, data);
  return head;
}

// Insertar en medio recursivamente
SNode* insert_middle_recursive(SNode* head, int data){
  if(head == NULL){
    return create_node(data);
  }
  head->next = insert_position_recursive(head->next, 2, data);
  return head;
}

// Eliminar al principio recursivamente
SNode* delete_begin_recursive(SNode* head){
  if(head == NULL){
    return NULL;
  }
  SNode* temp = head->next;
  free(head);
  return temp;
}

// Eliminar al final recursivamente
SNode* delete_end_recursive(SNode* head){
  if(head == NULL){
    return NULL;
  }
  if(head->next == NULL){
    free(head);
    return NULL;
  }
  head->next = delete_end_recursive(head->next);
  return head;
}

// Eliminar en posición recursivamente
SNode* delete_position_recursive(SNode* head, int pos){
  if(head == NULL){
    return NULL;
  }
  if(pos == 0){
    SNode* temp = head->next;
    free(head);
    return temp;
  }
  head->next = delete_position_recursive(head->next, pos - 1);
  return head;
}

// Eliminar en medio recursivamente
SNode* delete_middle_recursive(SNode* head){
  if(head == NULL || head->next == NULL){
    return delete_begin_recursive(head);
  }
  head->next = delete_position_recursive(head->next, 1);
  return head;
}

// Mostrar lista
void display_list(SNode* head){
  while(head != NULL){
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

int main(){
  SNode* head = NULL;

  for(int i = 10; i<=30; i+=10){
    head = insert_end_recursive(head, i);
  }
  display_list(head);

  head = insert_position_recursive(head, 2, 300);

  display_list(head);

  head = insert_middle_recursive(head, 500);

  display_list(head);


  return 0;
}