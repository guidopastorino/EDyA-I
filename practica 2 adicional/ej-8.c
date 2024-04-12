// 8. Dada la lista enlazada:
// L0 → L1 → . . . → Ln−1 → Ln
// Reordenarla a la forma:
// L0 → Ln → L1 → Ln−1 → L2 → Ln−2 → . . .
// algo: dividir la lista en dos, revertir la segunda mitad e intercalar las dos mitades (unificar) en una lista sola

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _SNode {
  int data;
  struct _SNode* next;
} SNode;

SNode* create_node(char data){
  SNode* newNode = (SNode*)malloc(sizeof(SNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insert_end(SNode** head, int data){
  SNode* newNode = create_node(data);
  if(*head == NULL){
    *head = newNode;
  } else {
    SNode* current = *head;
    while(current->next != NULL){
      current = current->next;
    }
    current->next = newNode;
  }
}

void display(SNode* head){
  SNode* current = head;
  while(current != NULL){
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

SNode* reverse_list(SNode* head){
  SNode* prev = NULL;
  SNode* current = head;
  SNode* next = NULL;
  while(current != NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

void rearrage_list(SNode** head){
  SNode* prev = NULL;
  SNode* slowPtr = *head;
  SNode* fastPtr = *head;
  while(fastPtr != NULL && fastPtr->next != NULL){
    prev = slowPtr;
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  prev->next = NULL;
  SNode* reversed_second_half = reverse_list(slowPtr);
  SNode* current1 = *head;
  SNode* current2 = reversed_second_half;
  SNode* temp;
  while(current2 != NULL){
    temp = current1->next;
    current1->next = current2;
    current1 = current2;
    current2 = temp;
  }
}

int main(){
  SNode* head = NULL;
  for(int i = 0; i<10; insert_end(&head, ++i));
  display(head);
  rearrage_list(&head);
  display(head);

  return 0;
}