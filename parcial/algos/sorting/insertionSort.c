#include <stdio.h>

void insertion_sort(int arr[], int size){
  int i, j, key;
  for(i = 1; i<size; i++){
    key = arr[i];
    j = i - 1;
    while(j >= 0 && key < arr[j]){
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
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
  insertion_sort(arr, size);
  print_array(arr, size);


  return 0;
}