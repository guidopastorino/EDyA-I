// Write a C program to reverse alternate k nodes of a given singly linked list.
// Test Data and Expected Output :

// Original List: 1 2 3 4 5 6 7 8

// Reverse alternate k (k=2) nodes of the said singly linked list:
// 2 1 3 4 6 5 7 8

// Reverse alternate k (k=3) nodes of the said singly linked list:
// 3 1 2 4 6 5 8 7

// Reverse alternate k (k=4) nodes of the said singly linked list:
// 4 2 1 3 6 5 8 7

#include "SList_Funcs.h"

Node* reverse_alternatively_k_nodes(Node* head, int k){
  assert(k >= 0);
  Node* prev = NULL;
  Node* current = head;
  Node* next = NULL;
  int count = 0;
  while(current != NULL && count < k){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    count++;
  }
  // head now points to the kth+1 node
  if(head != NULL){
    head->next = current;
  }
  count = 0;
  while(current != NULL && count < k - 1){
    current = current->next;
    count++;
  }
  if(current != NULL){
    current->next = reverse_alternatively_k_nodes(current->next, k);
  }
  return prev;
}

int main(){
  Node* head = NULL;
  for(int i = 1; i<=10; i++)
    insert_end(&head, i);
  
  display_list(head);

  head = reverse_alternatively_k_nodes(head, 3);
  display_list(head);

  free_list(head);

  return 0;
}