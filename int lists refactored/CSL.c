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
  assert(pos >= 1);
  if(pos == 1){
    insert_begin(tail, data);
  } else {
    CSNode* current = (*tail)->next;
    for(int i = 1; i<pos-1; i++){
      current = current->next;
      if(current == (*tail)->next){
        printf("Position out of range\n");
        exit(EXIT_FAILURE);
      }
    }
    CSNode* newNode = create_node(data);
    newNode->next = current->next;
    current->next = newNode;
    if(current == *tail) *tail = (*tail)->next;
  } 
}

void insert_middle(CSNode** tail, int data){
  if(*tail == NULL || (*tail)->next == *tail){
    insert_end(tail, data);
  } else {
    CSNode* slow = (*tail)->next;
    CSNode* fast = (*tail)->next;
    while(fast->next != (*tail)->next && fast->next->next != (*tail)->next){
      slow = slow->next;
      fast = fast->next->next;
    }
    CSNode* newNode = create_node(data);
    newNode->next = slow->next;
    slow->next = newNode;
    if(slow == *tail) *tail = newNode;
  }
}

void delete_begin(CSNode** tail){
  assert(*tail != NULL);
  if(*tail == (*tail)->next){
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
  if(*tail == (*tail)->next){
    free(*tail);
    *tail = NULL;
  } else {
    CSNode* current = (*tail)->next;
    while(current->next != *tail){
      current = current->next;
    }
    CSNode* temp = *tail;
    current->next = (*tail)->next;
    *tail = current;
    free(temp);
  }
}

void delete_position(CSNode** tail, int pos){
  assert(*tail != NULL && pos >= 1);
  if(pos == 1){
    delete_begin(tail);
  } else {
    CSNode* current = (*tail)->next;
    for(int i = 1; i<pos-1; i++){
      current = current->next;
      if(current == (*tail)->next){
        printf("Position out of range\n");
        exit(EXIT_FAILURE);
      }
    }
    CSNode* temp = current->next;
    current->next = current->next->next;
    if(temp == *tail) *tail = current; 
    free(temp);
  }
}

void delete_middle(CSNode** tail){
  assert(*tail != NULL);
  if((*tail)->next == *tail){
    delete_begin(tail);
  } else {
    CSNode* prev = NULL;
    CSNode* slow = (*tail)->next;
    CSNode* fast = (*tail)->next;
    while(fast->next != (*tail)->next && fast->next->next != (*tail)->next){
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    // slow apunta al nodo que vamos a eliminar y prev al anterior
    CSNode* temp = slow;
    // Si prev es NULL, significa que el nodo que estamos eliminando es el nodo inicial de la lista. En este caso, necesitamos actualizar el puntero next del último nodo de la lista (tail) para que apunte al siguiente nodo después del nodo que estamos eliminando.
    // osea 'slow' en este caso apuntaría al primer nodo
    if(prev == NULL){
      (*tail)->next = slow->next;
    } else {
      prev->next = slow->next;
    }
    if(slow == *tail) *tail = prev;
    free(temp);
  }
}

void display_list(CSNode* tail){
  if(tail == NULL){
    printf("NULL\n");
  } else {
    CSNode* current = tail->next;
    do {
      printf("%d ", current->data);
      current = current->next;
    } while(current != tail->next);
    printf("\n");
  }
}

void reverse_list(CSNode** tail){
  CSNode* prev = NULL;
  CSNode* curr = (*tail)->next;
  CSNode* next = curr->next;
  while(curr != *tail){
    prev = curr;
    curr = next;
    next = curr->next;
    curr->next = prev;
  }
  *tail = next;
  (*tail)->next = curr;
}

void delete_duplicates(CSNode** tail);

int main(){
  CSNode* tail = NULL;
  for(int i = 10; i<=40; i+=10)
    insert_end(&tail, i);

  display_list(tail);
  delete_middle(&tail);
  display_list(tail);
  delete_middle(&tail);
  display_list(tail);
  delete_middle(&tail);
  display_list(tail);

  reverse_list(&tail);

  return 0;
}