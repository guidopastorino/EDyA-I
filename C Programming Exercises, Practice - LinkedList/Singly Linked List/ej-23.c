// Write a C program to delete alternate nodes of a singly linked list.
// Test Data and Expected Output :

// Original List:
// 1 2 3 4 5 6 7 

// Delete alternate nodes of the said singly linked list:
// 1 3 5 7

#include "SList_Funcs.h"

void delete_alternate_nodes(Node** head){
  assert(head != NULL);
  Node *temp, *current = *head;
  while (current != NULL && current->next != NULL){
    temp = current->next;
    current->next = temp->next;
    free(temp);
    current = current->next;
  }
}

int main(){
  Node* head = NULL;
  for(int i = 1; i<=7; i++){
    insert_end(&head, i);
  }
  display_list(head);

  delete_alternate_nodes(&head);
  
  display_list(head);

  free_list(head);

  return 0;
}