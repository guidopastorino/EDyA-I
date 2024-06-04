#include <stdio.h>

/*
  Podemos diseñar un algoritmo simple en O(n) para encontrar un pico en un array. Este algoritmo recorrerá el array y verificará las condiciones para cada elemento hasta encontrar un pico.
*/
int encontrar_pico_iterativo(int* arr, int n){
  // Si hay un solo elemento, ese es el pico
  if(n == 1) return 0;
  // Verificar extremos
  if(arr[0] >= arr[1]) return 0;
  if(arr[n - 1] >= arr[n - 2]) return n - 1;
  // Verificar elementos internos
  int index = -1;
  for(int i = 1; i < n && index == -1; i++){
    if(arr[i] >= arr[i + 1] && arr[i] >= arr[i - 1]){
      printf("a");
      index = i;
    }
  }
  return index;
}

/*
  Algoritmo mejor que 0(n) (binary search)
*/
int encontrar_pico_recursivo(int* arr, int low, int high, int n){
  int mid = low + (high - low) / 2;
  if((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n - 1 || arr[mid] >= arr[mid + 1])){
    return mid;
  }
  if(mid == 0 && arr[mid - 1] > arr[mid]){
    return encontrar_pico_recursivo(arr, low, high - 1, n);
  } else {
    return encontrar_pico_recursivo(arr, low + 1, high, n);
  }
}


int main(){
  int arr[] = {1, 15, 3, 4, 8};
  int n = sizeof(arr) / sizeof(arr[0]);

  int pico_iter = encontrar_pico_iterativo(arr, n);
  int pico_rec = encontrar_pico_recursivo(arr, 0, n - 1, n);

  printf("Pico iterativo: %d\n", pico_iter);
  printf("Pico recursivo: %d\n", pico_rec);

  return 0;
}