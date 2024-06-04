/*
  BUBBLE SORT
  
  It is a simple and intuitive sorting algorithm. Repeatedly swap adjacent elements if they are in the wrong order until the array is sorted. In this algorithm, the largest element "goes up" to the end of the array in each iteration. This algorithm is inefficient for large data sets.
    - Total number of passes: n-1
    - Total number of comparisons: (n*(n-1))/2
  
  Complexity Analysis of Bubble Sort:
    - Time Complexity: O(n^2)
    - Auxiliary Space: O(1)

    - Worst case: O(n^2)
      - When the array is already sorted but in inversed order
    - Best case: O(n)
      - When the array is already sorted. We traverse the array without making swaps
    - Average case; O(n^2)
      - Occurs in random arrays

  Advantages of Bubble Sort:
    - Bubble sort is easy to understand and implement.
    - It does not require any additional memory space.
    - It is a stable sorting algorithm, meaning that elements with the same key value maintain their relative order in the sorted output.
  Disadvantages of Bubble Sort:
    - Bubble sort has a time complexity of O(N2) which makes it very slow for large data sets.
    - Bubble sort is a comparison-based sorting algorithm, which means that it requires a comparison operator to determine the relative order of elements in the input data set. It can limit the efficiency of the algorithm in certain cases.

  Steps to sort the array using Bubble Sort:
    - Initial path: Starts from the beginning of the arrangement.
    - Compare Adjacent Elements: Compare the first element with the next.
    - Swap if necessary: ​​If the first element is greater than the second, swap the two elements.
    - Move to next pair: Move to the next pair of adjacent elements and repeat the comparison and swap if necessary.
    - Complete Pass: Once you reach the end of the arrangement, you start again from the beginning.
    - Repeat Until Sorted: Continue this process until a complete pass is performed with no swaps, meaning the array is sorted.
*/

#include "Materials.h"

void bubble_sort(int* arr, int n){
  for(int i = 0; i<n-1; i++){
    for(int j = 0; j<n-i-1; j++){
      if(arr[j] > arr[j+1]){
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
}

int main(){
  print_array(arr, size);
  bubble_sort(arr, size);
  print_array(arr, size);

  return 0;
}