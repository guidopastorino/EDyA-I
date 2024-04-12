// 34. Write a C program to to merge alternate nodes of two singly linked lists.
// Test Data and Expected Output :

// First linked list: 9 7 5 3 1 
// Second linked list: 10 8 6 4 2 
// Merged linked list: 9 10 7 8 5 6 3 4 1 2 

#include "SList_Funcs.h"

Node* merge_alternate_nodes(Node* head1, Node* head2){
  Node* result = NULL;
  while(head1 != NULL && head2 != NULL){
    insert_end(&result, head1->data);
    head1 = head1->next;
    insert_end(&result, head2->data);
    head2 = head2->next;
  }
  while(head1 != NULL){
    insert_end(&result, head1->data);
    head1 = head1->next;
  }
  while(head2 != NULL){
    insert_end(&result, head2->data);
    head2 = head2->next;
  }
  return result;
}

int main(){
  Node* head1 = NULL;
  Node* head2 = NULL;
  for(int i = 1; i<=7; i++){
    insert_end(&head1, i);
    insert_end(&head1, i*10);
  }
  Node* merged_list = merge_alternate_nodes(head1, head2);
  display_list(merged_list); // 1 -> 10 -> 2 -> 20 -> 3 -> 30 -> 4 -> 40 -> 5 -> 50 -> 6 -> 60 -> 7 -> 70 -> NULL

  return 0;
}