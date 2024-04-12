// Write a C program to find a pair in a singly linked list whose sum is equal to a given value.
// Test Data and Expected Output :

// Original singly linked list:
// 1 2 3 4 5 6 7 

// Find a pair whose sum is equal to 4:
// (1,3) 

// Find a pair whose sum is equal to 11:
// (4,7) (5,6) 

// Find a pair whose sum is equal to 5:
// (1,4) (2,3) 

// Find a pair whose sum is equal to 14:
// Pair not found.

#include "SList_Funcs.h"

void find_pair(Node* head, int target) {
  Node* first = head;
  Node* second;
  int found;
  while(first != NULL && first->next != NULL){
    second = first->next;
    while(second != NULL){
      if((first->data + second->data) == target){
        printf("(%d, %d)\n", first->data, second->data);
        found = 1;
      }
      second = second->next;
    }
    first = first->next;
  }

  if(!found){
    printf("Pair not found\n");
  }
}

int main(){
  Node* head = NULL;
  for(int i = 1; i<8; i++) insert_end(&head, i);
  display_list(head);

  int target = 5;

  find_pair(head, target);

  return 0;
}