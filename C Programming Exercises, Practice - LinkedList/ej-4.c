// 6. Write a program in C to insert a node in the middle of a Singly Linked List.
// Test Data and Expected Output :

// Input the number of nodes (3 or more) : 4                                                                    
//  Input data for node 1 : 1                                                                                    
//  Input data for node 2 : 2                                                                                    
//  Input data for node 3 : 3                                                                                    
//  Input data for node 4 : 4                                                                                    
                                                                                                              
//  Data entered in the list are :                                                                               
//  Data = 1                                                                                                     
//  Data = 2                                                                                                     
//  Data = 3                                                                                                     
//  Data = 4                                                                                                     
                                                                                                              
//  Input data to insert in the middle of the list : 5                                                           
//  Input the position to insert new node : 3                                                                    
                                                                                                              
//  Insertion completed successfully.                                                                             
                                                                                                              
//  The new list are :                                                                                           
//  Data = 1                                                                                                     
//  Data = 2                                                                                                     
//  Data = 5                                                                                                     
//  Data = 3                                                                                                     
//  Data = 4  

#include "SList_Funcs.h"

void insert_middle(Node** head){
  assert(*head != NULL);
  int data;
  printf("Input data to insert in the middle of the list: ");
  scanf("%d", &data);

  // insert node at the middle
  Node* newNode = create_node(data);

  Node* slowPtr = *head;
  Node* fastPtr = *head;
  while(fastPtr != NULL && fastPtr->next != NULL){
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  newNode->next = slowPtr->next;
  slowPtr->next = newNode;

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

  insert_middle(&head);

  display_list(head);

  free_list(head);

  return 0;
}