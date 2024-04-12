// Write a C program to create and reorder a linked list placing all even-numbered nodes ahead of all odd-numbered nodes.
// Test Data and Expected Output :

// Original Singly List:
// 1 2 3 4 5 6 

// Reorder the said linked list placing all even-numbered 
// nodes ahead of all odd-numbered nodes:
// 1 3 5 2 4 6

#include "SList_Funcs.h"


// Función para reorganizar la lista colocando todos los nodos impares antes que los pares
Node* reorder_list(Node* head){
  assert(head != NULL);
  Node* odd_head = NULL; // Puntero al inicio de la lista de impares
  Node* even_head = NULL; // Puntero al inicio de la lista de pares
  Node* odd_tail = NULL; // Puntero al final de la lista de impares
  Node* even_tail = NULL; // Puntero al final de la lista de pares

  while(head != NULL){
    if(head->data % 2 != 0){ // Nodo impar
      if(odd_head == NULL){
        odd_head = head;
        odd_tail = head;
      } else {
        odd_tail->next = head;
        odd_tail = odd_tail->next;
      }
    } else { // Nodo par
      if(even_head == NULL){
        even_head = head;
        even_tail = head;
      } else {
        even_tail->next = head;
        even_tail = even_tail->next;
      }
    }
    head = head->next; // Pasamos al siguiente nodo
  }
  
  // Return list: odd -> even
  if(odd_head == NULL)
    return even_head;
  odd_tail->next = even_head;
  if(even_tail != NULL)
    even_tail->next = NULL; // Asegurarse de que la lista de pares termine
  return odd_head;

  // Return list: even -> odd
  // if(even_head == NULL)
  //   return odd_head;
  // even_tail->next = odd_head;
  // if(odd_tail != NULL)
  //   odd_tail->next = NULL; // Asegurarse de que la lista de impares termine
  // return even_head;
}



int main(){
  Node* head = NULL;
  insert_end(&head, 10);
  insert_end(&head, 9);
  insert_end(&head, 2);
  insert_end(&head, 4);

  display_list(head);

  Node* listOr = reorder_list(head);
  display_list(listOr);

  free_list(head);
  free_list(listOr);
  return 0;
}