#include "DList_Funcs.h"

DNode* initialize_list(){
  return NULL;
}

DNode* create_node(int data){
  DNode* newNode = (DNode*)malloc(sizeof(DNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void insert_begin(DNode** head, int data){
  DNode* newNode = create_node(data);
  if(*head == NULL){
    *head = newNode;
  } else {
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
  }
}

void insert_end(DNode** head, int data){
  DNode* newNode = create_node(data);
  if(*head == NULL){
    *head = newNode;
  } else {
    DNode* current = *head;
    while(current->next != NULL)
      current = current->next;
    current->next = newNode;
    newNode->prev = current;
  }
}

void delete_begin(DNode** head){
  if(*head == NULL){
    printf("List is empty\n");
    exit(EXIT_FAILURE);
  }
  DNode* temp = *head;
  *head = (*head)->next;
  if(*head != NULL){
    (*head)->prev = NULL;
  }
  free(temp);
}

int list_length(DNode* head){
  int len = 0;
  while(head != NULL){
    len++;
    head = head->next;
  }
  return len;
}

void display_list(DNode* head, Traversing direction){
  if(head == NULL){
    printf("NULL\n");
  } else {
    DNode* current = head;
    if(direction == DISPLAY_FORWARD){
      while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
      }
    } else {
      while(current != NULL && current->next != NULL){
        current = current->next;
      }
      while(current != NULL){
        printf("%d -> ", current->data);
        current = current->prev;
      }
    }
    printf("NULL\n");
  }
}