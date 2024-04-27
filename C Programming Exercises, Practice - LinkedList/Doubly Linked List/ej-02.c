// Write a program in C to insert a new node at any position in a doubly linked list
// Input the number of nodes (3 or more ): 3                                                                    
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

void insert_position(DNode** head, int pos, int data){
  assert(pos >= 1);
  if(pos == 1){
    insert_begin(head, data);
  } else {
    DNode* newNode = create_node(data);
    DNode* current = *head;
    for(int i = 1; i<pos-1 && current != NULL; i++){
      current = current->next;
    }
    if(current == NULL){
      printf("Position out of range\n");
      exit(EXIT_FAILURE);
    }
    newNode->next = current->next;
    if(current->next != NULL)
      current->next->prev = newNode;
    current->next = newNode;
    newNode->prev = current;
  }
}

int main(){
  DNode* head = initialize_list();
  for(int i = 10; i<=50; i+=10)
    insert_end(&head, i);
  
  display_list(head, DISPLAY_FORWARD);
  display_list(head, DISPLAY_BACKWARD);

  insert_position(&head, 4, 100);

  display_list(head, DISPLAY_FORWARD);
  display_list(head, DISPLAY_BACKWARD);
  
  return 0;
}