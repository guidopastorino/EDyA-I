// Write a C program to split a singly linked list into two halves.
// Test Data and Expected Output :

// Original List: 1 2 3 4 5 
// Split the said singly linked list into halves:
// First half: 1 2 3 
// Second half: 4 5 

// Original List: 1 2 3 4 5 6 
// Split the said singly linked list into halves:
// First half: 1 2 3 
// Second half: 4 5 6 

#include "SList_Funcs.h"

void split_list(Node *head, Node **first_half, Node **second_half){
  assert(head != NULL);
  int count = list_length(head);
  int middle = count / 2;
  *first_half = head;
  Node* current = head;
  while(middle > 1){
    current = current->next;
    middle--;
  }
  *second_half = current->next;
  current->next = NULL;
}

int main(){
  Node* head = NULL;
  for(int i = 1; i<=6; i++){
    insert_end(&head, i);
  }
  display_list(head);


  Node* first_half = NULL;
  Node* second_half = NULL;
  split_list(head, &first_half, &second_half);
  display_list(first_half);
  display_list(second_half);

  return 0;
}