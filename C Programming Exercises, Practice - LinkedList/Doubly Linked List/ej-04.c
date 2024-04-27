// Write a program in C to delete a node from the last node of a doubly linked list.
// Test Data and Expected Output :

// Input the number of nodes (3 or more ): 3                                                                    
//  Input data for node 1 : 1                                                                                    
//  Input data for node 2 : 2                                                                                    
//  Input data for node 3 : 3                                                                                    
                                                                                                              
//  Data entered in the list are :                                                                               
//  node 1 : 1                                                                                                   
//  node 2 : 2                                                                                                   
//  node 3 : 3                                                                                                   
                                                                                                              
//  After deletion the new list are :                                                                            
//  node 1 : 1                                                                                                   
//  node 2 : 2    

#include "DList_Funcs.h"

void delete_end(DNode** head){
  assert(*head != NULL);
  if((*head)->next == NULL){
    free(*head);
    *head = NULL;
  } else {
    DNode* current = *head;
    while(current->next)
      current = current->next;
    if(current->prev)
      current->prev->next = NULL;
    else
      *head = NULL;
    free(current);
  }
}

int main(){
  DNode* head = initialize_list();

  for(int i = 10; i<=20; i+=10)
    insert_end(&head, i);

  display_list(head, DISPLAY_FORWARD);

  delete_end(&head);
  
  display_list(head, DISPLAY_FORWARD);
  
  delete_end(&head);
  
  display_list(head, DISPLAY_FORWARD);

  return 0;
}