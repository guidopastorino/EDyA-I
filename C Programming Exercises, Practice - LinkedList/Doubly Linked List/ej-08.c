// Write a C program to convert a Doubly Linked list into a string.
// Test Data and Expected Output :
// Input the number of nodes: 4
// Input data for node 1 : 10
// Input data for node 2 : 11
// Input data for node 3 : 12
// Input data for node 4 : 13

// The doubly linked list in string format: 10 11 12 13

#include "DList_Funcs.h"

void convert_doubly_linked_list_to_string(DNode* head){
  int total_size = 0;
  DNode* current = head;
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
  printf("%s\n", buffer);
  printf("Buffer length: %lld\n", strlen(buffer));
  free(buffer);
}

int main(){
  DNode* head = NULL;
  for(int i = 10; i<=50; i+=10)
    insert_end(&head, i);
  
  display_list(head, DISPLAY_FORWARD);

  convert_doubly_linked_list_to_string(head);

  return 0;
}