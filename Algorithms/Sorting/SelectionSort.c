/*
  SELECTION SORT
  Selection Sort is a simple sorting algorithm that works by repeatedly selecting the smallest (or largest, depending on the desired sorting) element from the unsorted portion of the array and placing it in the correct position.

  Time Complexity: The time complexity of Selection Sort is O(n^2) as there are two nested loops:
    - One loop to select an element of Array one by one = O(n)
    - Another loop to compare that element with every other Array element = O(n)
    - Therefore overall complexity = O(n) * O(n) = O(n*n) = O(n^2)
  Auxiliary Space: O(1) as the only extra memory used is for temporary variables while swapping two values in Array. The selection sort never makes more than O(n) swaps and can be useful when memory writing is costly. 

  Advantages of Selection Sort Algorithm
    - Simple and easy to understand.
    - Works well with small datasets.
  Disadvantages of the Selection Sort Algorithm
    - Selection sort has a time complexity of O(n^2) in the worst and average case.
    - Does not work well on large datasets.
    - Does not preserve the relative order of items with equal keys which means it is not stable.

  Steps to sort an array using Selection Sort
    - Divide the array into two parts: An ordered part and an unordered part.
    - Find the minimum: Find the smallest element in the unordered portion.
    - Swap: Swap the smallest element found with the first element of the unsorted portion.
    - Expand sorted part: Move the boundary between the sorted and unsorted part one position to the right.
    - Repeat: Repeat steps 2 to 4 until the entire unsorted portion is empty and therefore the array is sorted.
*/

#include "Materials.h"

void selection_sort(int* arr, int n){
  // Mover el límite de la parte no ordenada
  for(int i = 0; i<n-1; i++){
    // Encontrar el elemento mínimo en la parte no ordenada
    int min_idx = i;
    for(int j = i + 1; j<n; j++){
      if(arr[j] < arr[min_idx]){
        min_idx = j;
      }
    }
    // Intercambiar el elemento mínimo encontrado con el primer elemento
    swap(&arr[min_idx], &arr[i]);
  }
}

int main(){
  print_array(arr, size);
  selection_sort(arr, size);
  print_array(arr, size);

  return 0;
}