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

void display_list(SNode* head){
  while(head != NULL){
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

int list_length(SNode* head){
  int len = 0;
  while(head != NULL){
    len++;
    head = head->next;
  }
  return len;
}

void insertion_sort(SNode** head) {
  assert(*head != NULL && (*head)->next != NULL);
  SNode* sorted = NULL;
  SNode* current = *head;
  while(current != NULL){
    SNode* next = current->next;
    if(sorted == NULL || current->data < sorted->data){
      current->next = sorted;
      sorted = current;
    } else {
      SNode* current_sorted = sorted;
      while(current_sorted->next != NULL && current->data > current_sorted->next->data){
        current_sorted = current_sorted->next;
      }
      current->next = current_sorted->next;
      current_sorted->next = current;
    }
    current = next;
  }
  *head = sorted;
}

int main(){
  SNode* head = NULL;
  for(int i = 50; i>0; i-=10){
    insert_end(&head, i);
  }

  display_list(head);

  insertion_sort(&head);

  display_list(head);

  return 0;
}