/*
  QUICK SORT

  The key process in quickSort is a partition(). The target of partitions is to place the pivot (any element can be chosen to be a pivot) at its correct position in the sorted array and put all smaller elements to the left of the pivot, and all greater elements to the right of the pivot.
  Partition is done recursively on each side of the pivot after the pivot is placed in its correct position and this finally sorts the array.

  Choice of pivot:
    - Always pick the first element as a pivot.
    - Always pick the last element as a pivot (casual)
    - Pick a random element as a pivot.
    - Pick the middle as the pivot.

  Partition Algorithm:
    - The logic is simple, we start from the leftmost element and keep track of the index of smaller (or equal) elements as i. While traversing, if we find a smaller element, we swap the current element with arr[i]. Otherwise, we ignore the current element.

  Time and Space complexity:
    - Best case 0(n log n): The best-case scenario for quicksort occur when the pivot chosen at the each step divides the array into roughly equal halves. In this case, the algorithm will make balanced partitions, leading to efficient Sorting.
    - Average case O(n log n): Quicksort’s average-case performance is usually very good in practice, making it one of the fastest sorting Algorithm.
    - Worst case O(n^2): The worst-case Scenario for Quicksort occur when the pivot at each step consistently results in highly unbalanced partitions. When the array is already sorted and the pivot is always chosen as the smallest or largest element.

    - Auxiliary Space: O(1), if we don’t consider the recursive stack space. If we consider the recursive stack space then, in the worst case quicksort could make O(N).

  Advantages of Quick Sort:
    - It is a divide-and-conquer algorithm that makes it easier to solve problems.
    - It is efficient on large data sets.
    - It has a low overhead, as it only requires a small amount of memory to function.

  Disadvantages of Quick Sort:
    - It has a worst-case time complexity of O(N2), which occurs when the pivot is chosen poorly.
    - It is not a good choice for small data sets.
    - It is not a stable sort, meaning that if two elements have the same key, their relative order will not be preserved in the sorted output in case of quick sort, because here we are swapping elements according to the pivot’s position (without considering their original positions).

  - When is it Best to Use QuickSort?
    - Large Arrays: QuickSort is very efficient for large arrays and is generally faster than MergeSort in practice.
    - Internal Sorting: It is ideal for organizing data that fits in main memory.
    - Average Cases: QuickSort tends to have good average performance, even with random input.
*/

#include "Materials.h"

int partition(int* arr, int low, int high){
  // Elige el último elemento como pivote
  int pivot = arr[high];
  // Inicializa el índice del elemento más pequeño
  int i = low - 1;
  // Recorre desde el índice 'low' hasta el índice 'high - 1'
  for(int j = low; j <= high - 1; j++){
    // Si el elemento actual es menor que el pivote
    if(arr[j] < pivot){
      // Incrementa el índice del elemento más pequeño
      i++;
      // Intercambia arr[j] con arr[i]
      swap(&arr[j], &arr[i]);
    }
  }
  // Intercambia el pivote con el elemento en arr[i + 1]
  swap(&arr[i + 1], &arr[high]);
  // Devuelve el índice de partición
  return i + 1;
}

void quicksort(int* arr, int low, int high){
  if(low < high){
    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot - 1);
    quicksort(arr, pivot + 1, high);
  }
}

int main(){
  print_array(arr, size);
  quicksort(arr, 0, size-1);
  print_array(arr, size);

  return 0;
}