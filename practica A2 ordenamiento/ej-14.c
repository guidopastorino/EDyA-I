#include "funcs.h"

/*
  'bottom-up' mergesort: En lugar de dividir el arreglo recursivamente, el enfoque "bottom-up" comienza con subarreglos de tamaño 1 y los combina en subarreglos de mayor tamaño de manera iterativa hasta que todo el arreglo está ordenado.

  ejemplo de array:
  -  -  -  -  -  -  -  -   (1)
      --  --  --  --       (2)
        ----  ----         (4)
         --------          (8)
*/

void merge(int* arr, int l, int m, int r){
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  
  int* L = (int*)malloc(sizeof(int) * n1);
  assert(L != NULL);
  int* R = (int*)malloc(sizeof(int) * n2);
  assert(R != NULL);

  for(i = 0; i<n1; i++)
    L[i] = arr[l + i];
  for(j = 0; j<n2; j++)
    R[j] = arr[m + 1 + j];
  
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

void mergesort_bottom_up(int* arr, int n){
  for(int curr_size = 1; curr_size <= n - 1; curr_size = curr_size * 2){
    for(int left_start = 0; left_start < n - 1; left_start += curr_size * 2){
      int mid = left_start + curr_size - 1;
      int right_end = ((left_start + 2 * curr_size - 1) < (n - 1) ? (left_start + 2 * curr_size - 1) : (n - 1));
      merge(arr, left_start, mid, right_end);
    }
  }
}

int main(){
  int arr[] = {9,1,2,4,3,5,8,7,6};
  int size = sizeof(arr) / sizeof(arr[0]);

  print_array(arr, size); // 9 1 2 4 3 5 8 7 6
  mergesort_bottom_up(arr, size);
  print_array(arr, size); // 1 2 3 4 5 6 7 8 9

  return 0;
}