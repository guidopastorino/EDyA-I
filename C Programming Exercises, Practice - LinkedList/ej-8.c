// Write a C program that converts a singly linked list into an array and returns it.
// Test Data and Expected Output :


// Linked List: Convert a Singly Linked list into a string
// -------------------------------------------------------------
// Input the number of nodes: 3
//  Input data for node 1 : 10
//  Input data for node 2 : 20
//  Input data for node 3 : 30

// Return data entered in the list as a string:
// The linked list: 10 20 30

#include "SList_Funcs.h"

int* covert_list_to_array(Node* head, int len){
  assert(head != NULL);
  int* array = (int*)malloc(sizeof(int) * len);
  assert(array != NULL);
  int i = 0;
  while(head != NULL){
    array[i++] = head->data;
    head = head->next;
  }
  return array;
}

int main(){
  Node* head = NULL;
  for(int i = 10; i<=30; i+=10){
    insert_end(&head, i);
  }
  printf("Current list: ");
  display_list(head);

  int len = list_length(head);
  int* array = covert_list_to_array(head, len);

  printf("Array: ");
  for(int i = 0; i<len; i++){
    printf("%d ", array[i]);
  }

  free_list(head);
  free(array);

  return 0;
}