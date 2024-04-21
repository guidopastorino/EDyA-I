// Binary search in a singly linked list
#include "bsl.h"

int main(){
  SNode* head = NULL;
  for(int i = 10; i<=50; i+=10){
    insert_end(&head, i);
  }

  int element = 10;
  int found = binary_search(head, element);
  printf("%d\n", found);

  display_list(head);

  free_list(head);

  return 0;
}