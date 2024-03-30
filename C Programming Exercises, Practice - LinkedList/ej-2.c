// 2. Write a program in C to create a singly linked list of n nodes and display it in reverse order.
// Test Data :
// Input the number of nodes : 3
// Input data for node 1 : 5
// Input data for node 2 : 6
// Input data for node 3 : 7
// Expected Output :

//  Data entered in the list are :                                                                               
//  Data = 5                                                                                                     
//  Data = 6                                                                                                     
//  Data = 7                                                                                                     
                                                                                                              
//  The list in reverse are :                                                                                    
//  Data = 7                                                                                                     
//  Data = 6                                                                                                     
//  Data = 5 

#include "SList_Funcs.h"

Node* reverse_list(Node* head){
  Node* prev = NULL;
  Node* current = head;
  Node* next = NULL;
  while(current != NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
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
  
  printf("Data entered in the list are:\n");
  display_list(head);

  Node* reversed_list = reverse_list(head);
  printf("The list in reverse are:\n");
  display_list(reversed_list);

  return 0;
}