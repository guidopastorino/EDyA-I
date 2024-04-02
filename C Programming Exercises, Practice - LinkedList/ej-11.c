#include "SList_Funcs.h"

Node* getIntersection(Node* head1, Node* head2){
  int len1 = list_length(head1), len2 = list_length(head2);
  Node *curr1 = head1, *curr2 = head2;
  if(len1 > len2){
    for(int i = 0; i<len1-len2; i++){
      curr1 = curr1->next;
    }
  } else {
    for(int i = 0; i<len2-len1; i++){
      curr2 = curr2->next;
    }
  }
  while(curr1 && curr2){
    if(curr1 == curr2) return curr1;
    curr1 = curr1->next;
    curr2 = curr2->next;
  }
  return NULL;
}

int main(){
  // Listas con intersección (comparten nodo)
  Node *head1 = NULL, *head2 = NULL;
  head1 = create_node(10);  
  head1->next = create_node(20);  
  head1->next->next = create_node(30);  
  head1->next->next->next = create_node(40);  
  head1->next->next->next->next = create_node(50); 
  display_list(head1); // 10 -> 20 -> 30 -> 40 -> 50 -> NULL
  head2 = create_node(10);  
  head2->next = create_node(20);  
  head2->next->next = create_node(30);  
  head2->next->next->next = create_node(40);  
  head2->next->next->next->next = create_node(50); 
  head2->next->next->next->next->next = create_node(60); 
  head2->next->next->next->next->next->next = head1->next->next; // conectamos al nodo 30 de la lista 1
  display_list(head2); // 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> 30 -> 40 -> 50 -> NULL
                       //                                     ↑↑
                       //                             nodo intersección
                       //                          (compartirán la sublista)

  Node* nodoInterseccion1 = getIntersection(head1, head2);

  if(nodoInterseccion1 != NULL){
    printf("El nodo de intersección es: %d\n", nodoInterseccion1->data);
  } else {
    printf("La lista no tiene intersección\n");
  }



  return 0;
}