/*
  MERGE SORT

  Merge sort is a sorting algorithm that follows the divide-and-conquer approach. It works by recursively dividing the input array into smaller subarrays and sorting those subarrays then merging them back together to obtain the sorted array.

  In simple terms, we can say that the process of merge sort is to divide the array into two halves, sort each half, and then merge the sorted halves back together. This process is repeated until the entire array is sorted.

  Complexity Analysis of Merge Sort:
  Time Complexity:
    - Best Case: O(n log n), When the array is already sorted or nearly sorted.
    - Average Case: O(n log n), When the array is randomly ordered.
    - Worst Case: O(n log n), When the array is sorted in reverse order.

  Space Complexity: O(n), Additional space is required for the temporary array used during merging.

  Advantages of Merge Sort:
    - Stability: Merge sort is a stable sorting algorithm, which means it maintains the relative order of equal elements in the input array.
    - Guaranteed worst-case performance: Merge sort has a worst-case time complexity of O(N logN),  - which means it performs well even on large datasets.
    - Simple to implement: The divide-and-conquer approach is straightforward.
  Disadvantage of Merge Sort:
    - Space complexity: Merge sort requires additional memory to store the merged sub-arrays during the sorting process. 
    - Not in-place: Merge sort is not an in-place sorting algorithm, which means it requires additional memory to store the sorted data. This can be a disadvantage in applications where memory usage is a concern.
  Applications of Merge Sort:
    - Sorting large datasets
    - External sorting (when the dataset is too large to fit in memory)
    - Inversion counting (counting the number of inversions in an array)
    - Finding the median of an array

  Steps to sort an array using Merge Sort
    - Divide: Divide the list or array recursively into two halves until it can no more be divided.
    - Conquer: Each subarray is sorted individually using the merge sort algorithm.
    - Merge: The sorted subarrays are merged back together in sorted order. The process continues until all elements from both subarrays have been merged.
*/

#include "Materials.h"

void merge(int* arr, int l, int m, int r){
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  // Crear arreglos temporales
  int* L = (int*)malloc(sizeof(int) * n1);
  assert(L != NULL);
  int* R = (int*)malloc(sizeof(int) * n2);
  assert(R != NULL);

  // Copiar datos a los arreglos temporales
  for(i = 0; i<n1; i++)
    L[i] = arr[l + i];
  for(j = 0; j<n2; j++)
    R[j] = arr[m + 1 + j];

  // Fusionar los arreglos temporales de nuevo en arr[]
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

  // Copiar los elementos restantes de leftArr[], si hay alguno
  while(i < n1){
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copiar los elementos restantes de rightArr[], si hay alguno
  while(j < n2){
    arr[k] = R[j];
    j++;
    k++;
  }

  // Liberar la memoria de los arreglos temporales
  free(L);
  free(R);
}

void merge_sort(int* arr, int l, int r){
  if(l < r){
    int m = l + (r - l) / 2;
    // Ordenar la primera y segunda mitad
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    // Fusionar las mitades ordenadas
    merge(arr, l, m, r);
  }
}

int main(){
  print_array(arr, size);
  merge_sort(arr, 0, size - 1);
  print_array(arr, size);

  return 0;
}