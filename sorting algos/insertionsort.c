#include "ArrFuncs.h"

void insertion_sort(int arr[], int n){
  int i, j, key;
  for(int i = 1; i<n; i++){
    key = arr[i];
    j = i - 1;
    while(j >= 0 && key < arr[j]){
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main(){
  printArray(arr, size);
  insertion_sort(arr, size);
  printArray(arr, size);

  return 0;
}