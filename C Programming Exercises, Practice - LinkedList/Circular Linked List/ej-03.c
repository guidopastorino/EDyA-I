// Write a program in C to delete a node from the beginning of a circular linked list.
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
                                                                                                            
// The deleted node is -> 2                                                                                     
// After deletion the new list are :                                                                            
// Data 1 = 5                                                                                                   
// Data 2 = 8 

#include "CSList_Funcs.h"

void delete_begin(CSNode** tail){
  assert(*tail != NULL);
  if(*tail == (*tail)->next){
    free(*tail);
    *tail = NULL;
  } else {
    CSNode* temp = (*tail)->next;
    (*tail)->next = (*tail)->next->next;
    free(temp);
  }
}

int main(){
  CSNode* tail = initialize_list();
  for(int i = 10; i<=20; i+=10)
    insert_end(&tail, i);

  display(tail);

  delete_begin(&tail);

  display(tail);

  delete_begin(&tail);

  display(tail);
  
  return 0;
}