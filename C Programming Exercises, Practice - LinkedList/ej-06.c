// 9. Write a program in C to delete the last node of a Singly Linked List.
// Test Data :
// Input the number of nodes : 3
// Input data for node 1 : 1
// Input data for node 2 : 2
// Input data for node 3 : 3
// Expected Output :

//  Data entered in the list are :                                                                               
//  Data = 1                                                                                                     
//  Data = 2                                                                                                     
//  Data = 3                                                                                                     
                                                                                                              
//  The new list after deletion the last node are  :                                                             
//  Data = 1                                                                                                     
//  Data = 2 

#include "SList_Funcs.h"

void delete_last(Node** head){
  assert(*head != NULL);
  if((*head)->next == NULL){
    free(*head);
    *head = NULL;
    return;
  }
  Node* current = *head;
  while(current->next->next != NULL){
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
}

int main(){
  Node* head = NULL;
  int n;
  printf("Input the number of nodes: ");
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    int data;
    printf("Input data for node %d: ", i+1);
    scanf("%d", &data);
    insert_end(&head, data);
  }
  printf("Data entered in the list:\n");
  display_list(head);
  printf("The new list after deletion the last node are:\n");
  delete_last(&head);
  display_list(head);

  free_list(head);

  return 0;
}