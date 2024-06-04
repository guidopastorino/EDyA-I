#include "funcs.h"

/*
  Cyclic Sort
  El algoritmo Cyclic Sort funciona colocando cada elemento en su posición correcta. Dado que los elementos están en el rango de 1 a N y no se repiten, podemos iterar a través del arreglo y colocar cada elemento en su posición correcta (i.e., el elemento 1 en el índice 0, el elemento 2 en el índice 1, etc.). Este proceso garantiza que cada elemento se coloca en su lugar con un número mínimo de intercambios.
*/

void cyclicsort(int* arr, int n){
  int i = 0;
  while(i < n){
    int correct_index = arr[i] - 1;
    if(arr[i] != arr[correct_index]){
      swap(&arr[i], &arr[correct_index]);
    } else {
      i++;
    }
  }
}

int main(){
  int arr[] = {4,1,3,2};
  int size = sizeof(arr) / sizeof(arr[0]);

  print_array(arr, size);
  cyclicsort(arr, size);
  print_array(arr, size);

  return 0;
}