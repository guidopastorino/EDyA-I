#include "funcs.h"

int binary_search_optimized(int* arr, int n, int v){
  int left = 0, right = n - 1;
  int result = -1; // Almacena el indice
  while(left <= right){
    int m = left + (right - left) / 2;
    if(arr[m] <= v){
      result = m;
      left = m + 1;
    } else {
      right = m - 1;
    }
  }
  if(result != -1 && arr[result] == v){
    return result;
  } else {
    return -1;
  }
}

int main(){
  int arr[] = {1,2,3,4,5,6};
  int n = sizeof(arr) / sizeof(arr[0]);
  int v = 6;
  int index = binary_search_optimized(arr, n, v);
  printf("Index of element: %d\n", index);

  return 0;
}