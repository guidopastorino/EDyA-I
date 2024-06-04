#include "funcs.h"

int partition(int* arr, int low, int high){
  int pivot = arr[high];
  int i = low - 1;
  for(int j = low; j<=high-1; j++){
    if(arr[j] < pivot){
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i+1], &arr[high]);
  return i+1;
}

void quickselect_k(int* arr, int low, int high, int k){
  if(low < high){
    int pivot = partition(arr, low, high);
    if(k == pivot){
      return;
    } else if(k < pivot) {
      quickselect_k(arr, low, pivot - 1, k);
    } else {
      quickselect_k(arr, pivot + 1, high, k);
    }
  }
}

void sort_k_elements(int* arr, int k){
  for(int i = 0; i<k-1; i++){
    for(int j = i+1; j<k; j++){
      if(arr[i] > arr[j]) swap(&arr[i], &arr[j]);
    }
  }
}

void find_k_smallest_elements(int* arr, int n, int k){
  if(k <= 0 || k > n){
    printf("K out of range");
    exit(EXIT_FAILURE);
  }
  quickselect_k(arr, 0, n-1, k);
  sort_k_elements(arr, k);
}

int main(){
  int arr[] = {9,8,1,2,5,3,4,7,6};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 5;
  print_array(arr, n);
  find_k_smallest_elements(arr, n, k);
  sort_k_elements(arr, k);
  printf("First %d elements: ", k);
  print_array(arr, k);

  return 0;
}