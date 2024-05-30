#include "Materials.h"

int arr[10] = {12, 25, 7, 18, 30, 9, 22, 3, 14, 27};
int size = sizeof(arr) / sizeof(arr[0]);

void print_array(int* arr, int size){
  for(int i = 0; i<size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}