#include "DList_Funcs.h"

int main(){
  DNode* head = initialize_list();
  
  insert_end(&head, 10);
  insert_begin(&head, 20);

  display_list(head, DISPLAY_FORWARD);
  display_list(head, DISPLAY_BACKWARD);

  return 0;
}