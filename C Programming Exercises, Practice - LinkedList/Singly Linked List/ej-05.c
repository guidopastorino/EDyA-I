// Write a program in C to delete a node from the middle of a Singly Linked List.
// Test Data and Expected Output :

// Input the number of nodes : 3                                                                                
//  Input data for node 1 : 2                                                                                    
//  Input data for node 2 : 5                                                                                    
//  Input data for node 3 : 8                                                                                    
                                                                                                              
//  Data entered in the list are :                                                                               
//  Data = 2                                                                                                     
//  Data = 5                                                                                                     
//  Data = 8                                                                                                     
                                                                                                              
//  Input the position of node to delete : 2                                                                     
                                                                                                              
//  Deletion completed successfully.                                                                             
                                                                                                              
//  The new list are  :                                                                                          
//  Data = 2                                                                                                     
//  Data = 8 

#include "SList_Funcs.h"

void delete_middle(Node** head){
  assert(*head != NULL && (*head)->next != NULL);

  Node* slowPtr = *head;
  Node* fastPtr = *head;
  Node* prev = NULL;

  while(fastPtr->next != NULL && fastPtr->next->next != NULL){
    prev = slowPtr;
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }

  Node* temp = slowPtr;
  prev->next = slowPtr->next;
  free(temp);

  printf("Insertion completed successfully.\n");
}

int main(){
  Node* head = NULL;
  int n;
  printf("Input the number of nodes (3 or more): ");
  scanf("%d", &n);
  assert(n >= 3);
  for(int i = 0; i<n; i++){
    int data;
    printf("Input data for node %d: ", i+1);
    scanf("%d", &data);
    insert_end(&head, data);
  }
  printf("Data entered in the list:\n");
  display_list(head);

  delete_middle(&head);

  display_list(head);
  

  return 0;
}