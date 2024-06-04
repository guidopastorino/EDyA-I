/*
  INSERTION SORT
  
  Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list. It is a stable sorting algorithm, meaning that elements with equal values maintain their relative order in the sorted output. It is considered an “in-place” sorting algorithm, meaning it doesn’t require any additional memory space beyond the original array.

  Time Complexity of Insertion Sort
    - Best case: O(n), If the list is already sorted, where n is the number of elements in the list.
    - Average case: O(n^2), If the list is randomly ordered
    - Worst case: O(n^2), If the list is in reverse order

  Advantages of Insertion Sort:
    - Simple and easy to implement.
    - Stable sorting algorithm.
    - Efficient for small lists and nearly sorted lists.
    - Space-efficient.

  Disadvantages of Insertion Sort:
    - Inefficient for large lists.
    - Not as efficient as other sorting algorithms (e.g., merge sort, quick sort) for most cases.

  Applications of Insertion Sort:
    - Insertion sort is commonly used in situations where:
    - The list is small or nearly sorted.
    - Simplicity and stability are important.

  Steps to sort an array using Insertion Sort:
    - Select Current Element: Start from the second element (the first element is already considered sorted).
    - Compare with Previous Elements: Compares the current element with the previous elements of the already sorted array.
    - Move Elements: Moves elements larger than the current element one position forward.
    - Insert Current Element: Inserts the current element in the correct position.
    - Repeat: Repeat the process for each element in the array until the entire array is sorted.
*/

#include "Materials.h"

void insertion_sort(int* arr, int size){
  for(int i = 1; i<size; i++){
    int key = arr[i];
    int j = i - 1;
    // Mueve los elementos del arreglo que son mayores que el key
    // una posición hacia adelante de su posición actual
    while(j >= 0 && key < arr[j]){
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main(){
  print_array(arr, size);
  insertion_sort(arr, size);
  print_array(arr, size);

  return 0;
}