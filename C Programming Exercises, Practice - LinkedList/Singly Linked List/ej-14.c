// Write a C program that takes two linked lists of numbers. Each node contains a single digit and returns the sum of those numbers of said linked lists as a linked list.
// Test Data and Expected Output :

// List-1
// 8 7 9 2 
// List-2
// 2 1 2 3 

// Adding said two lists:
// 0 9 1 6 

#include "SList_Funcs.h"

Node* obtener_suma(Node* head1, Node* head2){
  Node* result = 0;
  int carry = 0;
  while(head1 != NULL && head2 != NULL){
    int sum = 0;
    sum += (head1 ? head1->data : 0) + (head2 ? head2->data : 0) + carry;
    carry = sum / 10;
    sum %= 10; // Para que el valor se mantenga entre 0 y 9
    insert_end(&result, sum);
    if(head1) head1 = head1->next;
    if(head2) head2 = head2->next;
  }
  return result;
}

int main(){
  Node* head1 = create_node(8);
  head1->next = create_node(7);
  head1->next->next = create_node(9);
  head1->next->next->next = create_node(2);

  Node* head2 = create_node(2);
  head2->next = create_node(1);
  head2->next->next = create_node(2);
  head2->next->next->next = create_node(3);

  display_list(head1);
  display_list(head2);

  Node* sumList = obtener_suma(head1, head2);
  display_list(sumList);

  free_list(head1);
  free_list(head2);

  return 0;
}