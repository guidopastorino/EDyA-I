// Write a C program to remove duplicates from a sorted singly linked list.
// Test Data and Expected Output :

// Original sorted singly linked list:
// 1 2 3 3 5 6 6 

// After removing duplicates from the said sorted linked list:
// 1 2 3 5 6 

#include "SList_Funcs.h"

void remove_duplicates(Node** head){
  Node* current = *head;
  while(current != NULL){
    Node* runner = current;
    while(runner->next != NULL){
      if(runner->next->data == current->data){
        Node* duplicated = runner->next;
        runner->next = runner->next->next;
        free(duplicated);
      } else {
        runner = runner->next;
      }
    }
    current = current->next;
  }
}

int main(){
  Node* head = NULL;
  insert_end(&head, 1);
  insert_end(&head, 2);
  insert_end(&head, 3);
  insert_end(&head, 3);
  insert_end(&head, 5);
  insert_end(&head, 6);
  insert_end(&head, 6);
  display_list(head); // 1 -> 2 -> 3 -> 3 -> 5 -> 6 -> 6 -> NULL
  remove_duplicates(&head);
  display_list(head); // 1 -> 2 -> 3 -> 5 -> 6 -> NULL


  return 0;
}