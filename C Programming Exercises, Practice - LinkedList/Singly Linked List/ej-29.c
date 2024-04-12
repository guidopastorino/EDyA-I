// Write a C program to interleave elements of two singly linked lists alternatively.
// Test Data and Expected Output :

// Original Lists:
// List1: 1 3 5 7 
// List2: 2 4 6 8 

// After interleaving the two linked lists alternatively:
// List1: 1 2 3 4 5 6 7 8 
// List2: 2 3 4 5 6 7 8

#include "SList_Funcs.h"

void interleave(Node** head1, Node** head2){
  assert(*head1 != NULL && *head2 != NULL);
  Node *curr1 = *head1, *curr2 = *head2;
  while(curr1 != NULL && curr2 != NULL){
    Node* temp1 = curr1->next;
    Node* temp2 = curr2->next;
    curr1->next = curr2;
    curr2->next = temp1;
    curr1 = temp1;
    curr2 = temp2;
  }
}

int main(){
  Node* head1 = create_node(1);
  Node* head2 = create_node(2);

  insert_end(&head1, 3);
  insert_end(&head1, 5);
  insert_end(&head1, 7);
  insert_end(&head2, 4);
  insert_end(&head2, 6);
  insert_end(&head2, 8);

  display_list(head1);
  display_list(head2);

  interleave(&head1, &head2);
  
  display_list(head1);
  display_list(head2);

  return 0;
}