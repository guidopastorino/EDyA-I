// Write a C program to convert a doubly linked list into an array and return it.
// Test Data and Expected Output :
// Input the number of nodes: 4
// Input data for node 1 : 10
// Input data for node 2 : 11
// Input data for node 3 : 12
// Input data for node 4 : 13

// Doubly linked list in array format:
// 10 11 12 13

#include "DList_Funcs.h"

int* convert_doubly_list_to_array(DNode* head){
  assert(head != NULL);
  int len = list_length(head);
  int* array = (int*)malloc(sizeof(int) * len);
  assert(array != NULL);
  DNode* current = head;
  int index = 0;
  while(current != NULL){
    array[index++] = current->data;
    current = current->next;
  }
  for(int i = 0; i<len; i++){
    printf("%d ", array[i]);
  }
  return array;
}

int main(){
  DNode* head = NULL;
  for(int i = 10; i<=50; i+=10)
    insert_end(&head, i);

  display_list(head, DISPLAY_FORWARD);

  convert_doubly_list_to_array(head);

  return 0;
}