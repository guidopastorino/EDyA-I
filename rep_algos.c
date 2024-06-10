#include <stdio.h>

void print_array(int arr[], int size){
  for(int i = 0; i<size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(){
  int arr[] = {4, 2, 8, 7, 10, 9, 5, 6, 3, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  print_array(arr, size);

  return 0;
}