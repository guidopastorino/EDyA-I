// Write a program in C to create and display a circular linked list.
// Test Data :
// Input the number of nodes : 3
// Input data for node 1 : 2
// Input data for node 2 : 5
// Input data for node 3 : 8
// Expected Output :

// Data entered in the list are :                                                                               
// Data 1 = 2                                                                                                   
// Data 2 = 5                                                                                                   
// Data 3 = 8

#include "CSList_Funcs.h"

void insert_begin(CSNode** tail, int data){
  CSNode* newNode = create_node(data);
  if(*tail == NULL){
    *tail = newNode;
  } else {
    newNode->next = (*tail)->next;
    (*tail)->next = newNode;
  }
}

int main(){
  CSNode* tail = initialize_list();

  for(int i = 50; i>0; i-=10)
    insert_begin(&tail, i);

  display(tail);

  return 0;
}