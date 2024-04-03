// Write a C program that removes elements with odd indices from a singly linked list.
// Test Data and Expected Output :

// Original linked list:
// 7 6 5 4 3 2 1

// Linked list after removing odd indices:
// 6 4 2

#include "SList_Funcs.h"

void remove_odd_indices(Node** head) {
  // The linked list is indexed as follows:
  // list: 1 -> 2 -> 3 -> 4 -> NULL
  //    i: 1 -> 2 -> 3 -> 4 -> NULL
  //  res: 2 -> 4 -> NULL
  
  assert(*head != NULL);
  Node *prev = NULL, *current = *head;
  int index = 1;
  while(current != NULL){
    if(index % 2 == 1){ // odd index
      if(prev == NULL){
        *head = current->next;
        free(current);
        current = *head;
      } else {
        prev->next = current->next;
        free(current);
        current = prev->next;
      }
    } else {
      prev = current;
      current = current->next;
    }
    index++;
  }
}

int main(){
  Node* head = NULL;
  for(int i = 7; i>0; --i){
    insert_end(&head, i);
  }
  display_list(head);

  remove_odd_indices(&head);

  display_list(head);

  free_list(head);

  return 0;
}