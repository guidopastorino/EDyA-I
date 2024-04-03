// Write a C program to remove the Nth node from the end of a singly linked list.
// Test Data and Expected Output :

// Original Singly List:
// 1 2 3 4 5 

// Remove 1st node from the end of a singly linked list:
// 1 2 3 4 

// Remove 3rd node from the end of a singly linked list:
// 1 3 4

#include "SList_Funcs.h"

void remove_nth_node_from_end(Node** head, int n){
  assert(*head != NULL && n > 0);
  Node *prev = NULL, *slowPtr = *head, *fastPtr = *head;
  for(int i = 0; i<n; i++){
    if(fastPtr == NULL){
      printf("La lista es menor que el número\n");
      exit(EXIT_FAILURE);
    }
    fastPtr = fastPtr->next;
  }
  while(fastPtr != NULL){
    prev = slowPtr;
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next;
  }
  printf("Nodo eliminado: %d\n", slowPtr->data);
  // si slowPtr apunta al primer nodo:
  if(prev == NULL){
    *head = (*head)->next;
  } else {
    prev->next = slowPtr->next;
  }
  free(slowPtr);
}

int main(){
  Node* head = NULL;
  for(int i = 10; i<=50; i+=10){
    insert_end(&head, i);
  }
  display_list(head);

  remove_nth_node_from_end(&head, 1);
  remove_nth_node_from_end(&head, 1);
  remove_nth_node_from_end(&head, 1);

  display_list(head);

  free_list(head);

  return 0;
}