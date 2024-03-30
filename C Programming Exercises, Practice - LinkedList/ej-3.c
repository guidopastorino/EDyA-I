// 3. Write a program in C to create a singly linked list of n nodes and count the number of nodes.
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
      
//  Total number of nodes = 3 

#include "SList_Funcs.h"

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
  int len = 0;
  for(Node* curr = head; curr != NULL; curr = curr->next){
    len++;
  }
  display_list(head);
  printf("Total number of nodes = %d\n", len);

  return 0;
}