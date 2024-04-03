//  Write a C program that rotates a singly linked list to the right by k places.
// Test Data and Expected Output :

// Original List: 1 3 4 7 9 

// Rotate the said singly linked list to the right by 1 places:
// 9 1 3 4 7 

// Rotate the said singly linked list to the right by 2 places:
// 4 7 9 1 3 

// Rotate the said singly linked list to the right by 4 places:
// 7 9 1 3 4 

#include "SList_Funcs.h"

void rotate_k_right(Node** head, int k){
  assert(head != NULL && k > 0);
  Node* current = *head;
  int count = 1;
  while(current->next){
    current = current->next;
    count++;
  }
  current->next = *head;
  for(int i = 0; i<(count-k%count); i++){
    current = current->next;
  }
  *head = current->next;
  current->next = NULL;
}

int main(){
  Node* head = NULL;
  for(int i = 1; i<=5; i++) insert_end(&head, i);

  display_list(head);

  int k = 3;

  rotate_k_right(&head, k);

  display_list(head);

  free_list(head);

  return 0;
}