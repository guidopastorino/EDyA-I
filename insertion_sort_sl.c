#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _SNode {
  int data;
  struct _SNode* next;
} SNode;

SNode* create_node(int data){
  SNode* newNode = (SNode*)malloc(sizeof(SNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

SNode* insert_end(SNode* head, int data){
  SNode* newNode = create_node(data);
  if(head == NULL){
    head = newNode;
  } else {
    SNode* current = head;
    while(current->next != NULL){
      current = current->next;
    }
    current->next = newNode;
  }
  return head;
}

void display_list(SNode* head){
  while(head != NULL){
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

void insertionSort(SNode** head){
  if (*head == NULL || (*head)->next == NULL) return;

  SNode* sorted = NULL;
  SNode* current = *head;

  while (current != NULL) {
    SNode* next = current->next;
    if (sorted == NULL || current->data < sorted->data) {
      current->next = sorted;
      sorted = current;
    } else {
      SNode* search = sorted;
      while (search->next != NULL && search->next->data < current->data) {
        search = search->next;
      }
      current->next = search->next;
      search->next = current;
    }
    current = next;
  }
  *head = sorted;
}

int main(){
  SNode* head = NULL;
  head = insert_end(head, 45);
  head = insert_end(head, 30);
  head = insert_end(head, 60);
  head = insert_end(head, 20);
  head = insert_end(head, 15);

  printf("Lista original:\n");
  display_list(head);

  insertionSort(&head);

  printf("\nLista ordenada:\n");
  display_list(head);

  return 0;
}
