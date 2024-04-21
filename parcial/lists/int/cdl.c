// CIRCULAR DOUBLY LIST
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum { TRAVERSE_BACKWARDS, TRAVERSE_FORWARD } Traversing;

typedef struct _CDNode {
  int data;
  struct _CDNode* prev;
  struct _CDNode* next;
} CDNode;

CDNode* create_node(int data){
  CDNode* newNode = (CDNode*)malloc(sizeof(CDNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->prev = newNode;
  newNode->next = newNode;
  return newNode;
}

void insert_begin(CDNode** tail, int data){
  CDNode* newNode = create_node(data);
  if(*tail == NULL){
    *tail = newNode;
  } else {
    CDNode* temp = (*tail)->next;
    newNode->next = temp;
    newNode->prev = *tail;
    temp->prev = newNode;
    (*tail)->next = newNode;
  }
}

void insert_end(CDNode** tail, int data){
  CDNode* newNode = create_node(data);
  if(*tail == NULL){
    *tail = newNode;
  } else {
    CDNode* temp = (*tail)->next;
    newNode->next = temp;
    newNode->prev = *tail;
    (*tail)->next = newNode;
    temp->prev = newNode;
    *tail = newNode;
  }
}

void insert_position(CDNode** tail, int pos, int data){
  assert(pos >= 0);
  if(pos == 0){
    insert_begin(tail, data);
    return;
  }
  CDNode* newNode = create_node(data);
  CDNode* current = (*tail)->next;
  for(int i = 0; i<pos-1; i++){
    current = current->next;
    if(current == (*tail)->next){
      printf("Posición fuera de rango\n");
      return;
    }
  }
  newNode->next = current->next;
  newNode->prev = current;
  current->next->prev = newNode;
  current->next = newNode;
  if(current == *tail){
    *tail = (*tail)->next;
  }
}

void delete_begin(CDNode** tail){
  assert(*tail != NULL);
  if((*tail)->next == *tail){
    free(*tail);
    *tail = NULL;
  } else {
    CDNode* temp = (*tail)->next;
    (*tail)->next = temp->next;
    temp->next->prev = *tail;
    free(temp);
  }
}

void delete_end(CDNode** tail){
  assert(*tail != NULL);
  if((*tail)->next == *tail){
    free(*tail);
    *tail = NULL;
  } else {
    CDNode* temp = *tail;
    *tail = temp->prev;
    (*tail)->next = temp->next;
    temp->next->prev = *tail;
    free(temp);
  }
}

void delete_position(CDNode** tail, int pos){
  assert(*tail != NULL && pos >= 0);
  if(pos == 0){
    delete_begin(tail);
    return;
  }
  CDNode* current = (*tail)->next;
  for(int i = 0; i<pos; i++){
    current = current->next;
    if(current == (*tail)->next){
      printf("Posición fuera de rango\n");
      return;
    }
  }
  current->prev->next = current->next;
  current->next->prev = current->prev;
  if(current == *tail){
    *tail = current->prev;
  }
  free(current);
}

void display_list(CDNode* tail, Traversing direction){
  if(tail != NULL){
    CDNode* current = tail->next;
    do {
      printf("%d ", current->data);
      current = current->next;
    } while(current != tail->next);
    printf("\n");
  } else {
    printf("NULL\n");
  }
}

int main(){
  CDNode* tail = NULL;
  insert_position(&tail, 0, 10);
  insert_position(&tail, 1, 20);
  insert_position(&tail, 2, 30);
  insert_position(&tail, 3, 40);
  display_list(tail, TRAVERSE_FORWARD);
  delete_position(&tail, 3);
  display_list(tail, TRAVERSE_FORWARD);


  return 0;
}