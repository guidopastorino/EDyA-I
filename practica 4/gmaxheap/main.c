#include "maxheap.h"

void* copiar_entero(void* dato){
  int* copia = (int*)malloc(sizeof(int));
  assert(copia != NULL);
  *copia = *(int*)dato;
  return copia;
}

int comparar_entero(void* dato1, void* dato2){
  return (*(int*)dato1) - (*(int*)dato2);
}

void imprimir_entero(void* dato){
  printf("%d ", *(int*)dato);
}

void destruir_entero(void* dato){
  free(dato);
}

int main(){
  BHeap heap = bheap_crear(10, comparar_entero);

  int a = 10;
  int b = 20;
  int c = 30;
  int d = 40;
  int e = 50;

  heap = bheap_insertar(heap, &a, copiar_entero);
  heap = bheap_insertar(heap, &b, copiar_entero);
  heap = bheap_insertar(heap, &c, copiar_entero);
  heap = bheap_insertar(heap, &d, copiar_entero);
  heap = bheap_insertar(heap, &e, copiar_entero);

  bheap_recorrer(heap, imprimir_entero);
  puts("");

  heap = bheap_eliminar(heap, &e, destruir_entero);
  bheap_recorrer(heap, imprimir_entero);
  puts("");

  int nums[] = {9,4,2,6,8};

  void** arr = (void**)malloc(sizeof(void*) * 5);

  for(int i = 0; i<5; i++)
    arr[i] = &nums[i];


  for(int i = 0; i<5; i++)
    printf("%d ", *(int*)arr[i]); // 9 4 2 6 8
  printf("\n");


  heap_sort(&arr, 5, comparar_entero, copiar_entero);


  for(int i = 0; i<5; i++)
    printf("%d ", *(int*)arr[i]); // 9 8 6 4 2
  printf("\n");

  free(arr);


  bheap_destruir(heap);

  return 0;
}