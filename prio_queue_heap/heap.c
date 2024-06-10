#include "heap.h"

void swap(Item** a, Item** b){
  Item* temp = *a;
  *a = *b;
  *b = temp;
}

int parent(int i) { return (i - 1) / 2; }

int left_child(int i) { return 2 * i + 1; }

int right_child(int i) { return 2 * i + 2; }

void heapify_down(MinHeap* heap, int i){
  int left = left_child(i);
  int right = right_child(i);
  int smallest = i;
  if(left < heap->size && heap->arr[left]->priority < heap->arr[smallest]->priority){
    smallest = left;
  }
  if(right < heap->size && heap->arr[right]->priority < heap->arr[smallest]->priority){
    smallest = right;
  }
  if(smallest != i){
    swap(&heap->arr[i], &heap->arr[smallest]);
    heapify_down(heap, smallest);
  }
}

void heapify_up(MinHeap* heap, int i){
  while(i != 0 && heap->arr[parent(i)]->priority > heap->arr[i]->priority){
    swap(&heap->arr[parent(i)], &heap->arr[i]);
    i = parent(i);
  }
}

MinHeap* heap_create(int capacity){
  MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
  assert(heap != NULL);
  heap->arr = (Item**)malloc(sizeof(Item*) * capacity);
  assert(heap->arr != NULL);
  for(int i = 0; i<capacity; i++)
    heap->arr[i] = NULL;
  heap->capacity = capacity;
  heap->size = 0;
  return heap;
}

void heap_insert(MinHeap* heap, int priority, void* data, CopyFunc copy){
  if(heap->size == heap->capacity){
    printf("Heap full, cannot insert\n");
    return;
  }
  Item* item = (Item*)malloc(sizeof(Item));
  assert(item != NULL);
  item->priority = priority;
  item->data = copy(data);
  int i = heap->size;
  heap->arr[i] = item;
  heap->size++;
  heapify_up(heap, i);
}

Item* heap_extract_min(MinHeap* heap){
  if(heap->size == 0){
    printf("Cannot extract min, heap is empty\n");
    return NULL;
  }
  Item* item = heap->arr[0];
  heap->arr[0] = heap->arr[--heap->size];
  heapify_down(heap, 0);
  return item;
}

void print_heap(MinHeap* heap, VisitFunc func){
  for(int i = 0; i<heap->size; i++){
    func(heap->arr[i]->priority, heap->arr[i]->data);
  }
  printf("\n");
}