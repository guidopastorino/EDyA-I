// Write a program in C to delete a node from the middle of a doubly linked list.
// Test Data and Expected Output :

// Input the number of nodes (3 or more ): 3                                                                    
// Input data for node 1 : 1                                                                                    
// Input data for node 2 : 2                                                                                    
// Input data for node 3 : 3                                                                                    
                                                                                                            
// Data entered in the list are :                                                                               
// node 1 : 1                                                                                                   
// node 2 : 2                                                                                                   
// node 3 : 3                                                                                                   
// Input the position ( 1 to 3 ) to delete a node : 2                                                           
                                                                                                            
// After deletion the new list are :                                                                            
// node 1 : 1                                                                                                   
// node 2 : 3

#include "DList_Funcs.h"

void delete_middle(DNode** head){
  if(*head == NULL){
    printf("List is empty\n");
    exit(EXIT_FAILURE);
  }
  if((*head)->next == NULL){
    delete_begin(head);
  } else {
    DNode* slow = *head;
    DNode* fast = *head;
    while(fast && fast->next){
      slow = slow->next;
      fast = fast->next->next;
    }
    DNode* temp = slow;
    slow->prev->next = slow->next;
    if(slow->next){
      slow->next->prev = slow->prev;
    }
    free(temp);
  }
}

int main(){
  DNode* head = initialize_list();

  for(int i = 10; i<=30; i+=10)
    insert_end(&head, i);

  display_list(head, DISPLAY_FORWARD); // 10 -> 20 -> 30 -> NULL

  delete_middle(&head);

  display_list(head, DISPLAY_FORWARD); // 10 -> 30 -> NULL

  delete_middle(&head);

  display_list(head, DISPLAY_FORWARD); // 10 -> NULL
  
  delete_middle(&head);

  display_list(head, DISPLAY_FORWARD); // NULL

  return 0;
}