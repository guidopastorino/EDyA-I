// Write a program in C to delete a node from any position in a doubly linked list.
// Test Data and Expected Output :

//  Doubly Linked List : Delete node from any position of a doubly linked list :                                 
// ----------------------------------------------------------------------------------                            
//  Input the number of nodes (3 or more ): 3                                                                    
//  Input data for node 1 : 1                                                                                    
//  Input data for node 2 : 2                                                                                    
//  Input data for node 3 : 3                                                                                    
                                                                                                              
//  Data entered in the list are :                                                                               
//  node 1 : 1                                                                                                   
//  node 2 : 2                                                                                                   
//  node 3 : 3                                                                                                   
//  Input the position ( 1 to 3 ) to delete a node : 3                                                           
                                                                                                              
//  After deletion the new list are :                                                                            
//  node 1 : 1                                                                                                   
//  node 2 : 2 

#include "DList_Funcs.h"

void delete_position(DNode** head, int pos){
  assert(*head != NULL);
  if(pos == 1){
    free(*head);
    *head = NULL;
  } else {
    DNode* current = *head;
    for(int i = 1; i<pos && current != NULL; i++){
      current = current->next;
    }
    assert(current != NULL);
    // current apunta al nodo que vamos a eliminar
    printf("current: %d\n", current->data);
    current->prev->next = current->next;
    if(current->next != NULL){
      current->next->prev = current->prev;
    }
    free(current);
  }
}

int main(){
  DNode* head = initialize_list();

  for(int i = 10; i<=30; i+=10)
    insert_end(&head, i);

  display_list(head, DISPLAY_FORWARD);

  delete_position(&head, 1);

  display_list(head, DISPLAY_FORWARD);
  display_list(head, DISPLAY_BACKWARD);


  return 0;
}