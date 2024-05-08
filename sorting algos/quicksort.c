#include "ArrFuncs.h"

void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high){
  int pivot = arr[high];
  int i = (low - 1);
  for(int j = low; j<=high-1; j++){
    if(arr[j] < pivot){
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quicksort(int arr[], int low, int high){
  if(low < high){
    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot - 1);
    quicksort(arr, pivot + 1, high);
  }
}

int main(){
  printArray(arr, size);
  quicksort(arr, 0, size - 1);
  printArray(arr, size);

  return 0;
}