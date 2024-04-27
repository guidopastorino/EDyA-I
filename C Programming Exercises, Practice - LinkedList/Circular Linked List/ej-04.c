// Write a program in C to delete a node from the middle of a circular linked list.

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

void delete_middle(CSNode** tail){
  assert(*tail != NULL);
  if(*tail == (*tail)->next){
    delete_begin(tail);
  } else {
    CSNode* slow = (*tail)->next;
    CSNode* fast = (*tail)->next;
    // hacemos fast->next != *tail && fast->next->next != *tail para evitar crear una variable "prev", si queremos usar "prev", usamos fast != *tail && fast->next != *tail
    while(fast->next != *tail && fast->next->next != *tail){
      slow = slow->next;
      fast = fast->next->next;
    }
    // slow apunta al nodo anterior a eliminar
    CSNode* temp = slow->next;
    slow->next = slow->next->next;
    // actualizamos tail
    if(temp == *tail) *tail = slow->next->next;
    free(temp);
  }
}

int main(){
  CSNode* tail = initialize_list();
  for(int i = 10; i<=50; i+=10)
    insert_end(&tail, i);

  display(tail);
  delete_middle(&tail);
  display(tail);
  delete_middle(&tail);
  display(tail);
  delete_middle(&tail);
  display(tail);
  delete_middle(&tail);
  display(tail);
  delete_middle(&tail);
  display(tail);



  return 0;
}