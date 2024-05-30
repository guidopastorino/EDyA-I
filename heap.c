#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 10

typedef struct _MinHeap {
  int size;
  int arr[MAX_SIZE];
} MinHeap;

// inicializar
void initialize(MinHeap* heap){
  heap->size = 0;
}

// padre
int parent(int i){
  return (i - 1) / 2;
}

// hijo izq
int left_child(int i){
  return 2 * i + 1;
}

// hijo der
int right_child(int i){
  return 2 * i + 2;
}

// swap
void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

// heapify down (al eliminar)
void heapify_down(MinHeap* heap, int i){
  int left = left_child(i);
  int right = right_child(i);
  int smallest = i;

  if(left < heap->size && heap->arr[left] < heap->arr[smallest]){
    smallest = left;
  }

  if(right < heap->size && heap->arr[right] < heap->arr[smallest]){
    smallest = right;
  }

  if(smallest != i){
    swap(&heap->arr[smallest], &heap->arr[i]);
    heapify_down(heap, smallest);
  }
}

// heapify up (al insertar)
void heapify_up(MinHeap* heap, int i){
  while(i != 0 && heap->arr[parent(i)] > heap->arr[i]){
    swap(&heap->arr[parent(i)], &heap->arr[i]);
    i = parent(i);
  }
}

// insertar elemento
void insertar(MinHeap* heap, int data){
  if(heap->size == MAX_SIZE){
    printf("Cannot insert element, heap is full\n");
    return;
  }

  // insert element to the end of the heap
  int i = heap->size;
  heap->arr[i] = data;
  heap->size++;

  // heapify up to mantain the heap property
  heapify_up(heap, i);
}

// extraer min (raiz)
int extract_min(MinHeap* heap){
  if(heap->size == 0){
    printf("Cannot extract min, heap is empty\n");
    exit(EXIT_FAILURE);
  }
  if(heap->size == 1){
    heap->size--;
    return heap->arr[0];
  }
  int min_element = heap->arr[0];
  heap->arr[0] = heap->arr[--heap->size];
  heapify_down(heap, 0); // hacer heapify down desde la raíz
  return min_element;
}

// decrementar clave (actualizar valor de la clave)
// i: index of the key to be decreased
// void decrease_key(MinHeap* heap, int i, int new_val){
//   heap->arr[i] = new_val;
//   heapify_up(heap, i);
// }

// eliminar elemento
// 1. Reemplazamos el elemento a ser eliminado por el ultimo elemento en el heap (last leaf)
// 2. eliminamos el ultimo elemento
void delete(MinHeap* heap, int key){
  int i;
  for(i = 0; i<heap->size; i++){
    if(heap->arr[i] == key){
      break;
    }
  }

  if(i == heap->size){
    printf("Element to be deleted not found\n");
    return;
  }

  heap->arr[i] = heap->arr[--heap->size]; // reemplazamos el elemento a ser eliminado por el ultimo elemento y eliminamos el ultimo elemento
  
  heapify_down(heap, i);
  heapify_up(heap, i);
}

// heap sort (ordenar array usando heap)
void heap_sort(int* arr, int size){
  MinHeap heap;
  heap.size = size;
  // copiamos los elementos del array al heap
  for(int i = 0; i<size; i++){
    heap.arr[i] = arr[i];
  }
  // extraemos uno por uno el minimo (raiz) del heap y lo copiamos al array
  for(int i = 0; i<size; i++){
    arr[i] = extract_min(&heap);
  }
}

// imprimir heap
void print_array(MinHeap* heap){
  for(int i = 0; i<heap->size; i++){
    printf("%d ", heap->arr[i]);
  }
  printf("\n");
}

int main(){
  MinHeap heap;
  initialize(&heap);

  insertar(&heap, 50);
  insertar(&heap, 40);
  insertar(&heap, 30);
  insertar(&heap, 20);
  insertar(&heap, 10);
  insertar(&heap, 35);

  print_array(&heap);

  return 0;
}