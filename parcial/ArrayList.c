// ARRAYLIST C IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ArrayList {
  int *data;
  int size; // tamaño actual
  int capacity; // capacidad de la lista
} ArrayList;

ArrayList* initialize(int capacity){
  ArrayList* arraylist = (ArrayList*)malloc(sizeof(ArrayList));  
  assert(arraylist != NULL);
  arraylist->data = (int*)calloc(capacity, sizeof(int));
  assert(arraylist->data != NULL);
  arraylist->size = 0;
  arraylist->capacity = capacity;
  return arraylist;
}

void realloc_data(ArrayList* arraylist, int newSize){
  arraylist->data = (int*)realloc(arraylist->data, sizeof(int) * newSize);
  assert(arraylist->data != NULL);
  arraylist->capacity = newSize;
}

void append(ArrayList* arraylist, int element){
  if(arraylist->size == arraylist->capacity){
    realloc_data(arraylist, arraylist->capacity * 2);
  }
  arraylist->data[arraylist->size] = element;
  arraylist->size++;
}

void pop(ArrayList* arraylist){
  if(arraylist->size == 0){
    printf("La lista está vacía\n");
    return;
  }
  arraylist->size--;
}

void print(ArrayList* arraylist){
  printf("{ ");
  for(int i = 0; i<arraylist->size; i++){
    printf("%d ", arraylist->data[i]);
  }
  printf("}\n");
}

int main(){
  ArrayList* arraylist = initialize(10);
  append(arraylist, 10);
  print(arraylist);
  pop(arraylist);
  print(arraylist);

  return 0;
}