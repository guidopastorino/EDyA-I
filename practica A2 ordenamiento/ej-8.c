#include "funcs.h"

int partition(int* arr, int low, int high){
  int pivot = arr[high];
  int i = low - 1;
  for(int j = low; j<=high-1; j++){
    if(arr[j] < pivot){
      i++;
      swap(&arr[j], &arr[i]);
    }
  }
  swap(&arr[i+1], &arr[high]);
  return i+1;
}

int quickselect(int* arr, int low, int high, int k){
  if(low == high){
    return arr[low];
  }
  int pivot = partition(arr, low, high);
  if(k == pivot){
    return arr[k];
  } else if(k < pivot){
    return quickselect(arr, low, pivot - 1, k);
  } else {
    return quickselect(arr, pivot + 1, high, k);
  }
}

int find_kth_element(int* arr, int n, int k){
  if(k < 0 || k >= n){
    printf("K fuera de rango\n");
    exit(EXIT_FAILURE);
  }
  return quickselect(arr, 0, n - 1, k);
}

int main(){
  int arr[] = {9,8,1,2,5,3,4,7,6};
  int n = sizeof(arr) / sizeof(arr[0]);
  print_array(arr, n);
  int k = 8; // Queremos encontrar el 9no elemento más pequeño (índice 8 en 0-based indexing)
  int kth_element = find_kth_element(arr, n, k);
  printf("%dth element: %d\n", k + 1, kth_element);

  return 0;
}