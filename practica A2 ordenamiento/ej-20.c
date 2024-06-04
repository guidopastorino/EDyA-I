#include "funcs.h"

int count_inversions(int* arr, int size){
  int count = 0;
  for(int i = 0; i<size-1; i++){
    for(int j = i + 1; j<size; j++){
      if(arr[i] > arr[j]) count ++;
    }
  }
  return count;
}

int count_swaps_bubble_sort(int* arr, int size){
  int swaps = 0;
  for(int i = 0; i<size-1; i++){
    for(int j = 0; j<size-i-1; j++){
      if(arr[j] > arr[j + 1]){
        // swap
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        swaps++;
      }
    }
  }
  return swaps;
}

int main(){
  int size = 1000;
  int arr[size];

  for(int i = 0; i<size; i++){
    arr[i] = rand() % 1000;
  }

  // printf("Array original: ");
  // print_array(arr, size);

  int inversiones = count_inversions(arr, size);
  printf("Numero total de inversiones: %d\n", inversiones);

  int swaps = count_swaps_bubble_sort(arr, size);
  printf("Numero total de swaps: %d\n", swaps);

  // printf("Array ordenado: ");
  // print_array(arr, size);

  printf("%s\n", inversiones == swaps ? "El numero total de inversiones es igual al de los swaps\n" : "El numero total de inversiones es distinto al de los swaps");

  return 0;
}