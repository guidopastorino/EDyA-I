#include "glist.h"

int main(){ 
  GList* list = initialize_list(sizeof(int));

  int nums[] = {10, 20, 30, 40, 50};

  for(int i = 0; i<5; i++){
    insert_begin(&list, &nums[i], sizeof(int));
  }

  print_list(list, printInt);

  return 0;
}