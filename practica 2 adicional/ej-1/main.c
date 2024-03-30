#include "ArrayList.h"

int main(){
  ArrayList* list = initialize_list();
  for(int i = 10; i<=100; i+=10){
    insert(list, i);
  }
  print(list);

  return 0;
}