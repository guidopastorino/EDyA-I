// 1. Write a program in C to create and display a Singly Linked List.
// Test Data :
// Input the number of nodes : 3
// Input data for node 1 : 5
// Input data for node 2 : 6
// Input data for node 3 : 7
// Expected Output :

//  Data entered in the list :                                                                                   
//  Data = 5                                                                                                     
//  Data = 6                                                                                                     
//  Data = 7 

#include "SList_Funcs.h"

int main(){
  Node* head = NULL;
  int n;
  printf("Number of nodes: ");
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    int data;
    printf("Input data for node %d: ", i+1);
    scanf("%d", &data);
    insert_end(&head, data);
  }
  
  printf("Data entered in the list: \n");
  for(Node* curr = head; curr != NULL; curr = curr->next){
    printf("Data: %d\n", curr->data);
  }

  free_list(head);

  return 0;
}