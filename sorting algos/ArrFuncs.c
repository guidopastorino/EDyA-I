#include "ArrFuncs.h"

int arr[] = {19, 6, 0, 1, 5, 13, 9, 10, 12, 3, 7};
int size = sizeof(arr) / sizeof(arr[0]);

void printArray(int arr[], int size){
  for(int i = 0; i<size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}