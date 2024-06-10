#include "queue.h"

PriorityQueue* pq_create(int capacity){
  PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
  assert(pq != NULL);
  pq->heap = heap_create(capacity);
  return pq;
}

void pq_insert(PriorityQueue* pq, int priority, void* data, CopyFunc copy){
  heap_insert(pq->heap, priority, data, copy);
}

Item* pq_extract_min(PriorityQueue* pq){
  Item* item = heap_extract_min(pq->heap);
  return item;
}

void pq_print(PriorityQueue* pq, VisitFunc func){
  print_heap(pq->heap, func);
}