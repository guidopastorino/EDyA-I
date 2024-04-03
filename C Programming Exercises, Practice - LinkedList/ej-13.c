// Write a C program to partition a singly linked list based on a specific value.
// Test Data and Expected Output:

// Original list:
// 3 5 7 5 9 2 1
// Linked List after partition around 5:
// 3 2 1 5 7 5 9

#include "SList_Funcs.h"

Node* partition_list(Node *head, int x){
  
}

int main()
{
  Node *head = NULL;
  insert_end(&head, 1);
  insert_end(&head, 7);
  insert_end(&head, 8);
  insert_end(&head, 4);
  insert_end(&head, 3);
  insert_end(&head, 5);
  insert_end(&head, 6);
  insert_end(&head, 0);

  int x = 5;
  Node* p_list = partition_list(head, x);

  printf("Partition list around the value %d:\n", x);
  display_list(p_list);

  return 0;
}