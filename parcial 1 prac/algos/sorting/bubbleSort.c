#include <stdio.h>

void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int arr[], int size){
  for(int i = 0; i < size - 1; i++){
    for(int j = 0; j < size - i - 1; j++){
      if(arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
    }
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
  bubble_sort(arr, size);
  print_array(arr, size);

  return 0;
}