#include "SList_Funcs.h"

Node* create_node(int data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insert_begin(Node** head, int data){
  Node* newNode = create_node(data);
  newNode->next = *head;
  *head = newNode;
}

void insert_end(Node** head, int data){
  Node* newNode = create_node(data);
  if(*head == NULL){
    *head = newNode;
  } else {
    Node* current = *head;
    while(current->next != NULL){
      current = current->next;
    }
    current->next = newNode;
  }
}

void display_list(Node* head){
  Node* current = head;
  while(current != NULL){
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

void free_list(Node* head){
  Node* current = head;
  while(current != NULL){
    Node* temp = current;
    current = current->next;
    free(temp);
  }
}