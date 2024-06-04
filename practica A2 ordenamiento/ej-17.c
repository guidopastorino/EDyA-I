#include "funcs.h"

int binary_search(int* arr, int low, int high, int key){
  while(low <= high){
    int mid = low + (high - low) / 2;
    if(arr[mid] == key){
      return mid;
    } else if(arr[mid] < key){
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return low;
}

void binary_insertion_sort(int* arr, int size){
  for(int i = 1; i<size; i++){
    int key = arr[i];
    // buscamos la posición en donde debe ser insertado el elemento
    int pos = binary_search(arr, 0, i - 1, key);
    // movemos el subarray para conservar espacio de inserción del elemento
    memmove(&arr[pos + 1], &arr[pos], (i - pos) * sizeof(int));
    // insertamos el elemento en la posición correcta
    arr[pos] = key;
  }
}

int main(){
  int arr[] = {8,6,4,1,2,3,5};
  int size = sizeof(arr) / sizeof(arr[0]);

  print_array(arr, size);
  binary_insertion_sort(arr, size);
  print_array(arr, size);

  return 0;
}