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

  for(int i = 10; i<=50; i+=10){
    head = insert_end(head, i);
  }
  display_list(head);

  SNode* list = reverse_list(head);

  display_list(list);

  return 0;
}