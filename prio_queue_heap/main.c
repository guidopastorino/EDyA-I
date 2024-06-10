#include "queue.h"

static void print_item(int priority, void* data){
  printf("(%d, %d) ", priority, *(int*)data);
}

static void* copy_int(void* data){
  int* new_int = (int*)malloc(sizeof(int));
  assert(new_int != NULL);
  *new_int = *(int*)data;
  return new_int;
}

int main(){
  PriorityQueue* queue = pq_create(10);

  int j = 1;
  for(int i = 10; i<=90; i+=10)
    pq_insert(queue, j++, &i, copy_int);

  int new_item = 15;

  pq_insert(queue, 0, &new_item, copy_int);

  pq_print(queue, print_item);

  puts("");

  return 0;
}