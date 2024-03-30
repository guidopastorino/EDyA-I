#include "ArrayList.h"

ArrayList* initialize_list(){
  ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
  assert(list != NULL);
  list->array = (Node*)malloc(sizeof(Node) * INITIAL_CAPACITY);
  assert(list->array != NULL);
  list->capacity = INITIAL_CAPACITY;
  list->size = 0;
  list->head = -1;
  list->tail = -1;
  return list;
}

int isFull(ArrayList* list){
  return list->size == list->capacity;
}

void insert(ArrayList* list, int data){
  if(isFull(list)){
    int newCapacity = list->capacity * GROWTH_FACTOR;
    list->array = (Node*)realloc(list->array, sizeof(Node) * newCapacity);
    assert(list->array != NULL);
    list->capacity = newCapacity;
  }
  Node node; // Nodo a ser insertado
  node.data = data;
  node.next = -1;
  if(list->size == 0){
    list->head = 0;
    list->tail = 0;
  } else {
    list->array[list->tail].next = list->size;
    list->tail = list->size;
  }
  list->array[list->size] = node; // Insertamos el nuevo nodo en el arreglo
  list->size++;
}

void print(ArrayList* list){
  printf("Lista: ");
  int current = list->head;
  while(current != -1){
    Node node = list->array[current];
    if(node.data == list->array[list->tail].data){
      printf("%d ", node.data);
    } else {
      printf("%d -> ", node.data);
    }
    current = node.next;
  }
}