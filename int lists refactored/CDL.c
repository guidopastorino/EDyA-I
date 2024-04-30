#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int(*Compare)(int, int);

typedef enum { DISPLAY_FORWARD, DISPLAY_BACKWARD } Traversing;

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
    newNode->next = (*tail)->next;
    newNode->prev = *tail;
    (*tail)->next->prev = newNode;
    (*tail)->next = newNode;
  }
}

void insert_end(CDNode** tail, int data){
  CDNode* newNode = create_node(data);
  if(*tail == NULL){
    *tail = newNode;
  } else {
    newNode->next = (*tail)->next;
    newNode->prev = *tail;
    (*tail)->next->prev = newNode;
    (*tail)->next = newNode;
    *tail = newNode;
  }
}

void insert_middle(CDNode** tail, int data){
  if(*tail == NULL){
    insert_begin(tail, data);
  } else {
    CDNode* slow = (*tail)->next;
    CDNode* fast = (*tail)->next;
    while(fast->next != (*tail)->next && fast->next->next != (*tail)->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    CDNode* newNode = create_node(data);
    newNode->next = slow->next;
    newNode->prev = slow;
    slow->next->prev = newNode; 
    slow->next = newNode;
    if(slow == *tail) *tail = newNode;
  }
}

void insert_position(CDNode** tail, int pos, int data){
  assert(pos >= 1);
  if(pos == 1){
    insert_begin(tail, data);
  } else {
    CDNode* current = (*tail)->next;
    for(int i = 1; i<pos-1; i++){
      current = current->next;
      if(current == (*tail)->next){
        printf("Position out of range\n");
        exit(EXIT_FAILURE);
      }
    }
    CDNode* newNode = create_node(data);
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
    if(current == *tail) *tail = (*tail)->next;
  }
}

void delete_begin(CDNode** tail){
  assert(tail != NULL);
  if(*tail == (*tail)->next){
    free(*tail);
    *tail = NULL;
  } else {
    CDNode* temp = (*tail)->next;
    (*tail)->next = (*tail)->next->next;
    (*tail)->next->prev = *tail;
    free(temp);
  }
}

void delete_end(CDNode** tail){
  assert(*tail != NULL);
  if(*tail == (*tail)->next){
    free(*tail);
    *tail = NULL;
  } else {
    CDNode* temp = *tail;
    (*tail)->prev->next = (*tail)->next;
    (*tail)->next->prev = (*tail)->prev;
    *tail = (*tail)->prev;
    free(temp);
  }
}

void delete_middle(CDNode** tail){
  assert(*tail != NULL);
  if(*tail == (*tail)->next){
    delete_begin(tail);
  } else {
    CDNode* slow = (*tail)->next;
    CDNode* fast = (*tail)->next;
    while(fast != (*tail)->next && fast->next != (*tail)->next){
      slow = slow->next;
      fast = fast->next->next;
    }
    // slow->next apunta al nodo que vamos a eliminar
    CDNode* temp = slow->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    if(temp == *tail) *tail = temp->prev;
    free(temp);
  }
}

void delete_position(CDNode** tail, int pos){
  assert(pos >= 1);
  if(pos == 1){
    delete_begin(tail);
  } else {
    CDNode* current = (*tail)->next;
    for(int i = 1; i<pos; i++){
      current = current->next;
      if(current == (*tail)->next){
        printf("Position out of range\n");
        exit(EXIT_FAILURE);
      }
    }
    // current apunta al nodo a eliminar
    current->prev->next = current->next;
    current->next->prev = current->prev;
    if(current == *tail) *tail = current->prev;
    free(current);
  }
}

void display_list(CDNode* tail, Traversing direction){
  if(tail == NULL){
    printf("NULL\n");
  } else {
    if(direction == DISPLAY_FORWARD){
      CDNode* current = tail->next;
      do {
        printf("%d ", current->data);
        current = current->next;
      } while(current != tail->next);
    } else {
      CDNode* current = tail;
      do {
        printf("%d ", current->data);
        current = current->prev;
      } while(current != tail);
    }
    printf("\n");
  }
}

void reverse_list(CDNode** head) {
  
}

void delete_duplicates(CDNode** tail);

int compare(int a, int b){
  return (a == b) ? 0 : (a < b) ? -1 : 1;
}

void insert_correct_position(CDNode** tail, int element, Compare cmp);

int main(){
  CDNode* tail = NULL;
  insert_end(&tail, 10);
  insert_end(&tail, 20);
  insert_end(&tail, 30);
  insert_end(&tail, 40);
  insert_end(&tail, 50);
  display_list(tail, DISPLAY_FORWARD);
  reverse_list(&tail);
  display_list(tail, DISPLAY_FORWARD);


  return 0;
}