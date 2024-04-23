// LISTA SIMPLE CIRCULAR ENLAZADA 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _CSNode {
  int data;
  struct _CSNode* next;
} CSNode;

CSNode* create_node(int data){
  CSNode* newNode = (CSNode*)malloc(sizeof(CSNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->next = newNode;
  return newNode;
}

void insert_begin(CSNode** tail, int data){
  CSNode* newNode = create_node(data);
  if(*tail == NULL){
    *tail = newNode;
  } else {
    newNode->next = (*tail)->next;
    (*tail)->next = newNode;
  }
}

void insert_end(CSNode** tail, int data){
  CSNode* newNode = create_node(data);
  if(*tail == NULL){
    *tail = newNode;
  } else {
    newNode->next = (*tail)->next;
    (*tail)->next = newNode;
    *tail = newNode;
  }
}

void insert_position(CSNode** tail, int pos, int data){
  assert(pos >= 0);
  if(pos == 0){
    insert_begin(tail, data);
    return;
  }
  CSNode* newNode = create_node(data);
  CSNode* current = (*tail)->next;
  for(int i = 0; i<pos-1; i++){
    current = current->next;
    if(current == (*tail)->next){
      printf("Posicion fuera de rango\n");
      return;
    }
  }
  newNode->next = current->next;
  current->next = newNode;
  if(current == *tail){
    *tail = (*tail)->next;
  }
}

void insert_middle(CSNode** tail, int data){
  if(*tail == NULL){
    insert_begin(tail, data);
    return;
  }
  CSNode* prev = NULL;
  CSNode* slow = (*tail)->next;
  CSNode* fast = (*tail)->next;
  while(fast && fast->next != (*tail)->next && fast->next->next != (*tail)->next){
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  CSNode* newNode = create_node(data);
  newNode->next = slow->next;
  slow->next = newNode;
}

void delete_begin(CSNode** tail){
  assert(*tail != NULL);
  if((*tail)->next == *tail){ // lista con un solo nodo
    free(*tail);
    *tail = NULL;
  } else {
    CSNode* temp = (*tail)->next;
    (*tail)->next = (*tail)->next->next;
    free(temp);
  }
}

void delete_end(CSNode** tail){
  assert(*tail != NULL);
  if((*tail)->next == *tail){
    free(*tail);
    *tail = NULL;
  } else {
    CSNode* current = (*tail)->next;
    while(current->next != *tail){
      current = current->next;
    }
    current->next = (*tail)->next;
    free(*tail);
    *tail = current;
  }
}

void delete_position(CSNode** tail, int pos){
  assert(*tail != NULL && pos >= 0);
  if(pos == 0){
    delete_begin(tail);
    return;
  }
  CSNode* prev = NULL;
  CSNode* current = (*tail)->next;
  for(int i = 0; i<pos; i++){
    prev = current;
    current = current->next;
    if(current == (*tail)->next){
      printf("Posicion fuera de rango\n");
      return;
    }
  }
  prev->next = current->next;
  if(current == *tail) *tail = prev;
  free(current);
}

void delete_middle(CSNode** tail){
  assert(*tail != NULL);
  if((*tail)->next == *tail){
    delete_begin(tail);
    return;
  }
  CSNode* prev = NULL;
  CSNode* slow = (*tail)->next;
  CSNode* fast = (*tail)->next;
  while(fast != *tail && fast->next != *tail){
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  // Verifica si la lista tiene un número par de elementos
  if (fast->next == *tail) {
    prev = slow;
  }
  prev->next = slow->next;
  if(slow == *tail){
    *tail = prev;
  }
  free(slow);
}

void display_list(CSNode* tail){
  if(tail == NULL){
    printf("NULL\n");
  } else {
    CSNode* current = tail->next;
    do {
      printf("%d ", current->data);
      current = current->next;
    }while(current != tail->next);
    printf("\n");
  }
}

int main(){
  CSNode* tail = NULL;
  insert_begin(&tail, 70);
  insert_begin(&tail, 80);
  insert_begin(&tail, 90);
  display_list(tail);
  delete_middle(&tail);
  display_list(tail);
  delete_middle(&tail);
  display_list(tail);


  return 0;
}