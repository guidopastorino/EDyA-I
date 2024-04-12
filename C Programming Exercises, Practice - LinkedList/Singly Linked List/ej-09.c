// Write a C program to detect and remove a loop in a singly linked list.
// Test Data and Expected Output :

// Original singly linked list:
// 1 2 3 4 5 

// Create the loop:
// Following statement display the loop:
// displayList(head);

// After removing the said loop:
// 1 2 3 4 5 

#include "SList_Funcs.h"

void detect_and_remove_loop(Node* head){
  assert(head != NULL && head->next != NULL);
  Node* slow = head;
  Node* fast = head;
  while(slow && fast->next){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) break; // Loop detected
  }
  if(slow == fast){
    slow = head;
    while(slow->next != fast->next){
      slow = slow->next;
      fast = fast->next;
    }
    fast->next = NULL; // removing the loop
  }
}

int main(){
  Node* head = NULL;
  head = create_node(10);
  head->next = create_node(20);
  head->next->next = create_node(30);
  head->next->next->next = create_node(40);
  head->next->next->next->next = create_node(50);
  printf("Current list: ");
  display_list(head);

  // Haciendo el loop
  head->next->next->next = head->next->next;

  printf("After removing the loop: ");
  detect_and_remove_loop(head);
  display_list(head);


  return 0;
}