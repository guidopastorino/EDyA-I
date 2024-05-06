#include <stdio.h>

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

void printArray(int arr[], int size){
  for(int i = 0; i<size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main(){
  int arr[] = {19, 6, 0, 1, 5, 13, 9, 10, 12, 3, 7};
  int size = sizeof(arr) / sizeof(arr[0]);

  printArray(arr, size);
  quicksort(arr, 0, size - 1);
  printArray(arr, size);

  return 0;
}