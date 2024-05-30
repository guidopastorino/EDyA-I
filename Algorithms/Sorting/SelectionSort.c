/*
El algoritmo de Selection Sort es un método sencillo de ordenamiento que funciona seleccionando repetidamente el elemento más pequeño (o más grande, dependiendo del orden deseado) de la lista y colocándolo en su posición correcta. A continuación se detallan los pasos que sigue el algoritmo:

Pasos del Algoritmo Selection Sort
 - Dividir el array en dos partes: la parte ordenada y la parte no ordenada. Al principio, la parte ordenada está vacía y la parte no ordenada contiene todos los elementos.
 - Encontrar el elemento mínimo en la parte no ordenada.
 - Intercambiar el elemento mínimo con el primer elemento de la parte no ordenada, expandiendo así la parte ordenada en una posición y reduciendo la parte no ordenada en una posición.
 - Repetir los pasos 2 y 3 hasta que toda la lista esté ordenada.
*/

#include "Materials.h"

void selection_sort(int* arr, int n){
  for(int i = 0; i<n-1; i++){
    // Encuentra el mínimo elemento en la parte no ordenada
    int min_idx = i;
    for(int j = i + 1; j<n; j++){
      if(arr[j] < arr[min_idx]){
        min_idx = j;
      }
    }
    // Intercambia el elemento minimo con el primer elemento de la parte no ordenada
    swap(&arr[min_idx], &arr[i]);
  }
}

int main(){
  print_array(arr, size);
  selection_sort(arr, size);
  print_array(arr, size);

  return 0;
}