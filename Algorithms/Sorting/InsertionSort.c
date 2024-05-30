/*
El algoritmo de Insertion Sort es un método de ordenamiento sencillo y eficiente para listas pequeñas. Funciona de manera similar a cómo ordenarías una mano de cartas: tomas una carta a la vez y la insertas en la posición correcta en tu mano ordenada.

Funcionamiento paso a paso del algoritmo:
  - Empieza en el segundo elemento del array (considerando el primer elemento como un array ordenado de un solo elemento).
  - Compara el segundo elemento con el primero y lo inserta en la posición correcta.
  - Luego toma el tercer elemento y lo inserta en la posición correcta entre los dos primeros.
  - Repite este proceso para cada elemento del array, siempre insertando el elemento en la parte ya ordenada del array.
*/

#include "Materials.h"

void insertion_sort(int* arr, int n){
  int i, j, key;
  for(int i = 1; i<n; i++){
    key = arr[i];
    j = i - 1;
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