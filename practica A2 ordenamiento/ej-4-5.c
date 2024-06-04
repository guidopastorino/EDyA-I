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

void quicksort(int* arr, int low, int high){
  if(low < high){
    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot - 1);
    quicksort(arr, pivot + 1, high);
  }
}

void merge(int arr[], int l, int m, int r){
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int* L = (int*)malloc(sizeof(int) * n1);
  assert(L != NULL);
  int* R = (int*)malloc(sizeof(int) * n2);
  assert(R != NULL);

  for(i = 0; i<n1; i++){
    L[i] = arr[l + i];
  }
  for(j = 0; j<n2; j++){
    R[j] = arr[m + 1 + j];
  }

  i = 0;
  j = 0;
  k = l;

  while(i < n1 && j < n2){
    if(L[i] <= R[j]){
      arr[k] = L[i];
      i++; 
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while(i < n1){
    arr[k] = L[i];
    i++;
    k++;
  }
  
  while(j < n2){
    arr[k] = R[j];
    j++;
    k++;
  }

  free(L);
  free(R);
}

void mergesort(int arr[], int l, int r){
  if(l < r){
    int m = l + (r - l) / 2;
    mergesort(arr, l, m); 
    mergesort(arr, m + 1, r); 
    merge(arr, l, m, r);
  }
}

void time_func(int* arr, int size, void (*fPtr)(int*, int, int), char* funcName){
  clock_t start, end;
  double time;
  printf("%s: \n", funcName);
  printf("Unsorted: \n");
  print_array(arr, size);
  start = clock();
  fPtr(arr, 0, size - 1);
  end = clock();
  printf("Sorted: \n");
  print_array(arr, size);
  printf("Tiempo de ejecución de %s: ", funcName);
  time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("%f\n", time);
}

int main(){
  int arr1[] = {8,6,4,1,2,3,5,8};
  int size1 = sizeof(arr1) / sizeof(arr1[0]);

  time_func(arr1, size1, quicksort, "QuickSort");
  int arr2[] = {8,6,4,1,2,3,5,8};
  int size2 = sizeof(arr2) / sizeof(arr2[0]);
  
  time_func(arr2, size2, mergesort, "MergeSort");


  return 0;
}