// Write a C program to reverse a singly linked list starting at the first position in blocks of size k.
// Test Data and Expected Output :

// Given linked list: 
// 1 2 3 4 5 6 7 8 
// Reverse the first 3 nodes of the said Linked list: 
// 3 2 1 6 5 4 8 7 
// Reverse the first 5 nodes of the said Linked list: 
// 5 6 1 2 3 7 8 4 

#include "SList_Funcs.h"

Node* reverse_in_blocks(Node* head, int k){
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
  if(next != NULL){
    head->next = reverse_in_blocks(next, k);
  }
  return prev;
}


int main(){
  Node* head = NULL;
  for(int i = 1; i<=8; i++){
    insert_end(&head, i);
  }
  display_list(head);
  Node* rev = reverse_in_blocks(head, 2);
  display_list(rev);
  

  return 0;
}