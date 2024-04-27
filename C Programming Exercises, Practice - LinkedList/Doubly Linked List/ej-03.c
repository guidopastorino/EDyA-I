// Write a program in C to insert a new node in the middle of a doubly linked list.
// Test Data and Expected Output :

//   Doubly Linked List : Insert new node at the middle in a doubly linked list :                                 
// ----------------------------------------------------------------------------------                            
//  Input the number of nodes (3 or more ): 3                                                                    
//  Input data for node 1 : 2                                                                                    
//  Input data for node 2 : 4                                                                                    
//  Input data for node 3 : 5                                                                                    
                                                                                                              
//  Data entered in the list are :                                                                               
//  node 1 : 2                                                                                                   
//  node 2 : 4                                                                                                   
//  node 3 : 5                                                                                                   
//  Input the position ( 2 to 2 ) to insert a new node : 2                                                       
//  Input data for the position 2 : 3                                                                            
                                                                                                              
//  After insertion the new list are :                                                                           
//  node 1 : 2                                                                                                   
//  node 2 : 3                                                                                                   
//  node 3 : 4                                                                                                   
//  node 4 : 5

#include "DList_Funcs.h"

void insert_middle(DNode** head, int data){
  if(*head == NULL){
    insert_begin(head, data);
  } else {
    DNode* slow = *head;
    DNode* fast = *head;
    while(fast->next != NULL && fast->next->next != NULL){
      slow = slow->next;
      fast = fast->next->next;
    }
    DNode* newNode = create_node(data);
    // slow es el nodo anterior al nuevo nodo a insertar
    newNode->next = slow->next;
    newNode->prev = slow;
    if(slow->next != NULL){
      slow->next->prev = newNode;
    }
    slow->next = newNode;
  }
}

int main(){
  DNode* head = initialize_list();

  for(int i = 10; i<=40; i+=10)
    insert_end(&head, i);

  insert_middle(&head, 7);

  display_list(head, DISPLAY_FORWARD);
  display_list(head, DISPLAY_BACKWARD);
  
  return 0;
}