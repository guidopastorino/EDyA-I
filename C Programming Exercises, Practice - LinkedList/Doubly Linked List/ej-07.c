// Write a program in C to find the maximum value in a doubly linked list.
// Test Data :
// Input the number of nodes : 3
// Input data for node 1 : 5
// Input data for node 2 : 9
// Input data for node 3 : 1
// Expected Output :

// Data entered in the list are :                                                                               
// node 1 : 5                                                                                                   
// node 2 : 9                                                                                                   
// node 3 : 1                                                                                                   
                                                                                                          
// The Maximum Value in the Linked List : 9  

#include "DList_Funcs.h"

int max_val(DNode* head){
  if(head == NULL){
    printf("List is empty\n");
    exit(EXIT_FAILURE);
  }
  int max = head->data;
  while(head != NULL){
    if(head->data > max) max = head->data;
    head = head->next;
  }
  return max;
}

int main(){
  DNode* head = initialize_list();

  for(int i = 10; i<=30; i+=10)
    insert_end(&head, i);

  int max = max_val(head);
  printf("Max: %d\n", max);

  return 0;
}