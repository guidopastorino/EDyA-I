#include "funcs.h"

int hoare_partition(int* arr, int low, int high){
  int pivot = arr[low];
  int i = low - 1;
  int j = high + 1;
  while(1){
    // Encuentra el primer elemento desde la izquierda que es mayor que el pivote
    do {
      i++;
    } while(arr[i] < pivot);

    // Encuentra el primer elemento desde la derecha que es menor que el pivote
    do {
      j--;
    } while(arr[j] > pivot);

    // Si los índices se cruzan, devolver j
    if(i >= j)
      return j;

    // Intercambiar elementos
    swap(&arr[i], &arr[j]);
  }
}

void quicksort(int* arr, int low, int high){
  if(low < high){
    int pivot = hoare_partition(arr, low, high);
    quicksort(arr, low, pivot);
    quicksort(arr, pivot + 1, high);
  }
}

int main(){
  int arr[] = {7,6,4,1,2,3,5,10,8,9};
  int size = sizeof(arr) / sizeof(arr[0]);

  print_array(arr, size);
  quicksort(arr, 0, size - 1);
  print_array(arr, size);

  return 0;
}