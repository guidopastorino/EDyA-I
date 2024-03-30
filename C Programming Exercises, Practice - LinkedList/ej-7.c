// Write a C program that converts a singly linked list into a string and returns it.
// Test Data and Expected Output :


// Linked List: Convert a Singly Linked list into a string
// -------------------------------------------------------------
// Input the number of nodes: 3
//  Input data for node 1 : 10
//  Input data for node 2 : 20
//  Input data for node 3 : 30

// Return data entered in the list as a string:
// The linked list: 10 20 30

#include "SList_Funcs.h"

void convert_list_to_string(Node* head){
  int total_size = 1;
  Node* current = head;

  while(current != NULL){
    total_size += snprintf(NULL, 0, "%d ", current->data);
    current = current->next;
  }

  char* buffer = (char*)malloc(sizeof(char) * total_size);
  assert(buffer != NULL);
  buffer[0] = '\0';
  
  current = head;

  while(current != NULL){
    snprintf(buffer + strlen(buffer), total_size - strlen(buffer), "%d ", current->data);
    current = current->next;
  }

  printf("%s", buffer);
  free(buffer);
}

int main(){
  int n;
  printf("Input the number of nodes: ");
  scanf("%d", &n);

  Node* head = NULL;

  for(int i = 0; i<n; i++){
    int data;
    printf("Input data for node %d: ", i+1);
    scanf("%d", &data);
    insert_end(&head, data);
  }
  printf("Linked list: ");
  display_list(head); // 1 -> 2 -> 3 -> NULL

  printf("Data entered in the list as a string: ");
  convert_list_to_string(head);


  free_list(head);

  return 0;
}