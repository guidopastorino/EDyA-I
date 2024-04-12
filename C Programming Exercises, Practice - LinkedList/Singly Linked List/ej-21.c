// Write a C program to reverse a singly linked list in pairs.
// Test Data and Expected Output :

// Original List: 1 2 3 4 5 6 
// Reverse a singly linked list in pairs:
// 2 1 4 3 6 5 

// Original List: 1 2 3 4 5 
// Reverse a singly linked list in pairs:
// 2 1 4 3 5 

#include "SList_Funcs.h"

void reverse_in_pairs(Node** head) {
Node* prev = NULL;
  Node* current = *head;
  Node* next = NULL;
  while(current != NULL && current->next != NULL){
    next = current->next->next;
    current->next->next = current;
    if(prev != NULL){
      prev->next = current->next;
    } else {
      *head = current->next;
    }
    current->next = next;
    prev = current;
    current = next;
  }
}

int main(){
  Node* head = NULL;
  for(int i = 1; i<=7; i++){
    insert_end(&head, i);
  }
  display_list(head);

  reverse_in_pairs(&head);

  display_list(head);

  return 0;
}