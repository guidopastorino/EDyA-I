#include "ArrFuncs.h"

void selection_sort(int arr[], int n){
  int i, j, min_idx;
  for(i = 0; i<n-1; i++){
    min_idx = i;
    for(j = i+1; j<n; j++){
      if(arr[j] < arr[min_idx]){
        min_idx = j;
      }
    }
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}

int main(){
  printArray(arr, size);
  selection_sort(arr, size);
  printArray(arr, size);
  return 0;
}