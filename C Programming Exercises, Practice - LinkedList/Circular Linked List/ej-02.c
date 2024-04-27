// Write a program in C to insert a node at any position in a circular linked list.
// Test Data and Expected Output :

// Input the number of nodes : 3                                                                                
// Input data for node 1 : 2                                                                                    
// Input data for node 2 : 5                                                                                    
// Input data for node 3 : 8                                                                                    
                                                                                                            
// Data entered in the list are :                                                                               
// Data 1 = 2                                                                                                   
// Data 2 = 5                                                                                                   
// Data 3 = 8                                                                                                   
// Input the position to insert a new node : 3                                                                  
// Input data for the position 3 : 7                                                                            
                                                                                                            
// After insertion the new list are :                                                                           
// Data 1 = 2                                                                                                   
// Data 2 = 5                                                                                                   
// Data 3 = 7                                                                                                   
// Data 4 = 8

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

void insert_position(CSNode** tail, int pos, int data){
  assert(pos >= 1);
  if(pos == 1){
    insert_begin(tail, data);
  } else {
    CSNode* current = (*tail)->next;
    for(int i = 1; i<pos-1; i++){
      current = current->next;
      if(current == (*tail)->next){
        printf("Position out of range\n");
        exit(EXIT_FAILURE);
      }
    }
    // current apunta al nodo anterior a intertar
    CSNode* newNode = create_node(data);
    newNode->next = current->next;
    current->next = newNode;
    if(current == *tail) *tail = (*tail)->next;
  }
}

int main(){
  CSNode* tail = initialize_list();
  insert_begin(&tail, 50);
  insert_begin(&tail, 40);
  insert_begin(&tail, 30);
  insert_begin(&tail, 20);
  insert_begin(&tail, 10);
  display(tail);

  insert_position(&tail, 6, 150);
  display(tail);


  return 0;
}