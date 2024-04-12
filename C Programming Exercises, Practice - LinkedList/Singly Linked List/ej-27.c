// Write a C program to remove all elements from a singly linked list that are greater than a given value x.

#include "SList_Funcs.h"

void remove_greater_than(Node** head, int x) {
  // verificamos que la lista no inicie con un nodo mayor a x
  while(*head != NULL && (*head)->data > x){
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
  }
  Node* current = *head;
  // eliminamos los nodos restantes
  while(current != NULL && current->next != NULL){
    if(current->next->data > x){
      Node* temp = current->next;
      current->next = current->next->next;
      free(temp);
    } else {
      current = current->next;
    }
  }
}

int main(){
  Node* head = NULL;
  insert_begin(&head, 6);
  for(int i = 1; i<=8; i++){
    insert_end(&head, i);
  }
  display_list(head);
  int x = 4;
  remove_greater_than(&head, x);
  display_list(head);

  return 0;
}