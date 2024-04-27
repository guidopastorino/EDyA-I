#include "CSList_Funcs.h"

CSNode* initialize_list(){
  return NULL;
}

CSNode* create_node(int data){
  CSNode* newNode = (CSNode*)malloc(sizeof(CSNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->next = newNode;
  return newNode;
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

void display(CSNode* tail){
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