#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int (*Compare)(int, int);
typedef int (*Predicate)(int);

typedef enum { TRAVERSE_FORWARD, TRAVERSE_BACKWARD } Traversing;

typedef struct _DNode {
  int data;
  struct _DNode* prev;
  struct _DNode* next;
} DNode;

DNode* create_node(int data){
  DNode* newNode = (DNode*)malloc(sizeof(DNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}




// Mostrar lista
void display_list(DNode* head, Traversing direction){
  DNode* current = head;
  if(direction == TRAVERSE_FORWARD){
    while(current){
      printf("%d -> ", current->data);
      current = current->next;
    }
  } else {
    while(current && current->next)
      current = current->next;
    while(current != NULL){
      printf("%d -> ", current->data);
      current = current->prev;
    }
  }
  printf("NULL\n");
}


int main(){
  DNode* head = NULL;

  insert_end(&head, 50);
  insert_end(&head, 40);
  insert_end(&head, 30);
  insert_end(&head, 20);
  insert_end(&head, 60);
  insert_end(&head, -50);

  display_list(head, TRAVERSE_FORWARD);

  printf("Reversing:\n");

  DNode* reversed = reverse_list(head);

  display_list(reversed, TRAVERSE_FORWARD);
  display_list(reversed, TRAVERSE_BACKWARD);

  return 0;
}