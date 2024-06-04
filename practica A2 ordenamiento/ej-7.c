#include "funcs.h"
/*
  Para obtener la mediana de un arreglo con un tiempo mejor que 0(nlogn) (promedio de quicksort), usaremos quickselect (Quickselect is a selection algorithm to find the k-th smallest element in an unordered list. It is related to the quick sort sorting algorithm.), que es similar a quicksort, pero en vez de enfocarse en todo el arreglo, se enfoca en la parte en donde el k-ésimo menor debe ir insertado, reduciendo la complejidad a 0(n) en el mejor caso y O(n^2) en el peor caso.
*/

// partition (similar as quicksort)
int partition(int* arr, int low, int high){
  int pivot = arr[high];
  int i = low - 1;
  for(int j = low; j <= high - 1; j++){
    if(arr[j] <= pivot){
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

int quickselect(int* arr, int low, int high, int k){
  if(low == high){ // Arreglo con un elemento
    return arr[low];
  }

  int pivotIndex = partition(arr, low, high);

  if(k == pivotIndex){
    return arr[k];
  } else if(k < pivotIndex) {
    return quickselect(arr, low, pivotIndex - 1, k);
  } else {
    return quickselect(arr, pivotIndex + 1, high, k);
  }
}

int find_median(int* arr, int n){
  int k = n / 2;
  if(n % 2 == 0){ // arreglo par
    int m1 = quickselect(arr, 0, n - 1, k - 1); // m1 está en la posicion 'k-1'
    int m2 = quickselect(arr, 0, n - 1, k); // m2 está en la posicion 'k'
    return (m1 + m2) / 2; // la mediana es el promedio de la suma de los dos elementos centrales
  } else {
    return quickselect(arr, 0, n - 1, k); // la mediana está en la posicion 'k'
  }
}

int main(){
  int arr[] = {9,8,1,2,5,3,4,7,6}; // 1,2,3,4,5,6,7,8,9 -> 5
  int n = sizeof(arr) / sizeof(arr[0]);

  print_array(arr, n);

  int median = find_median(arr, n);

  printf("Median: %d\n", median);

  return 0;
}