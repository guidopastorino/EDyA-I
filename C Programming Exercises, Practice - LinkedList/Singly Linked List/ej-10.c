// Write a C program to remove duplicates from a single unsorted linked list.
// Test Data and Expected Output :

// Original Singly List:
// 1 2 3 3 4 
// After removing duplicate elements from the said singly list:
// 1 2 3 4 

// Original Singly List:
// 1 2 3 3 4 4 
// After removing duplicate elements from the said singly list:
// 1 2 3 4 

#include "SList_Funcs.h"

void remove_duplicates(Node* head){
  assert(head != NULL);
  Node *ptr1, *ptr2, *dup;
  ptr1 = head;
  while(ptr1 != NULL && ptr1->next != NULL){
    ptr2 = ptr1;
    while(ptr2->next != NULL){
      if(ptr1->data == ptr2->next->data){
        dup = ptr2->next;
        ptr1->next = ptr2->next->next;
        free(dup);
      } else {
        ptr2 = ptr2->next;
      }
    }
    ptr1 = ptr1->next;
  }
}

int main(){
  Node* head = NULL;
  insert_end(&head, 10);
  insert_end(&head, 20);
  insert_end(&head, 30);
  insert_end(&head, 30);
  insert_end(&head, 40);
  insert_end(&head, 40);
  
  printf("Original Singly List: \n");
  display_list(head); // 10 -> 20 -> 30 -> 30 -> 40 -> 40 -> NULL

  remove_duplicates(head);

  display_list(head); // 10 -> 20 -> 30 -> 40 -> NULL

  free_list(head);

  return 0;
}