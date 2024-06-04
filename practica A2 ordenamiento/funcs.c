#include "funcs.h"

int swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void print_array(int arr[], int n){
  for(int i = 0; i<n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}