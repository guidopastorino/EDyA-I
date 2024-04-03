// Write a C program to get the n number of nodes from the end of a singly linked list.
// Test Data and Expected Output :

// Original list:
// 1 3 5 11 
// Last 2 nodes from the end of the said singly list:
// 5 11 
// Last 3 nodes from the end of the said singly list:
// 3 5 11 
// Last 4 nodes from the end of the said singly list:
// 1 3 5 11 
// Last 1 node from the end of the said singly list:
// 11 
// Last 5 node from the end of the said singly list:

#include "SList_Funcs.h"

void get_n_nodes_from_end(Node* head, int n){
  assert(head != NULL && n > 0);
  Node* slowPtr = head, *fastPtr = head;
  for(int i = 0; i<n; i++){
    if(fastPtr == NULL) {
      printf("La lista es menor que 'n'\n");
      return;
    }
    fastPtr = fastPtr->next;
  }
  while(fastPtr != NULL){
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next;
  }
  printf("Lista de los ultimos %d nodos desde el final: ", n);
  display_list(slowPtr);
}

int main(){
  Node* head = NULL;
  for(int i = 10; i<=50; i+=10){
    insert_end(&head, i);
  }

  get_n_nodes_from_end(head, 3);
  get_n_nodes_from_end(head, 4);

  free_list(head);

  return 0;
}