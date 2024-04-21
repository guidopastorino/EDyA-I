#include <stdio.h>

void selection_sort(int arr[], int size){
  int i, j, min_index;
  for(i = 0; i < size - 1; i++){
    min_index = i;
    // encuentra el elemento minimo en la parte del arreglo no ordenado
    for(j = i + 1; j<size; j++){
      if(arr[j] < arr[min_index]){
        min_index = j;
      }
    }
    // intercambia el elemento minimo con el primer elemento de la parte no ordenada
    int temp = arr[min_index];
    arr[min_index] = arr[i];
    arr[i] = temp;
  }
}

void print_array(int arr[], int size){
  for(int i = 0; i<size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(){
  int arr[] = {8,6,4,5,7,3,1,2,9};
  int size = sizeof(arr) / sizeof(arr[0]);
  print_array(arr, size);
  selection_sort(arr, size);
  print_array(arr, size);

  return 0;
}