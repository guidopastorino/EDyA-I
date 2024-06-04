/*
¿Cómo cambia el problema de encontrar el máximo si trabajamos con arreglos ordenados? Ídem mínimo y mediana
- En un arreglo ordenado de manera creciente, el máximo es el último elemento, y el mínimo el primero elemento.
- En un arreglo ordenado de manera decreciente, el máximo es el primer elemento, y el mínimo el último elemento.
- Para calcular la mediana del arreglo, se nos presentan dos casos:
Teniendo a 'n' como el tamaño del arreglo, podemos obtener la mediana de las siguientes formas: 
  1. Si el tamaño del arreglo es impar, entonces la mediana es arr[n/2].
  2. Si el tamaño del arreglo es par, entonces la mediana es el promedio entre los dos elementos centrales, es decir: (arr[(n/2) - 1] + arr[n/2]) / 2.0.
Aplicando estos conceptos a los siguientes tipos de arreglos:
  - Arreglo creciente
  - Arreglo decreciente
  - Arreglo constante
  - Arreglo aleatorio
El programa nos quedaría:
*/
#include "funcs.h"

int find_min(int arr[], int n, int isAscending){
  if(isAscending){
    return arr[0];
  } else {
    return arr[n - 1];
  }
}

int find_max(int arr[], int n, int isAscending){
  if(isAscending){
    return arr[n - 1];
  } else {
    return arr[0];
  }
}

double mediana(int arr[], int n){
  if(n % 2 == 0){
    return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
  } else {
    return arr[n / 2];
  }
}

int main(){
  int arr1[] = {1,2,3,4,5,6,7}; // Array creciente
  int arr2[] = {7,6,5,4,3,2,1}; // Array decreciente
  int arr3[] = {5,5,5,5,5,5,5}; // Array constante
  int arr4[] = {10,1,9,2,8,3,7,4,6,5}; // Array aleatorio

  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  int n3 = sizeof(arr3) / sizeof(arr3[0]);
  int n4 = sizeof(arr4) / sizeof(arr4[0]);

  printf("Arreglo creciente: \n");
  print_array(arr1, n1);
  printf("Min arr1: %d\n", find_min(arr1, n1, 1));
  printf("Max arr1: %d\n", find_max(arr1, n1, 1));
  printf("Mediana arr1: %.f\n", mediana(arr1, n1));

  printf("Arreglo decreciente: \n");
  print_array(arr2, n2);
  printf("Min arr2: %d\n", find_min(arr2, n2, 0));
  printf("Max arr2: %d\n", find_max(arr2, n2, 0));
  printf("Mediana arr2: %.f\n", mediana(arr2, n2));

  printf("Arreglo constante: \n");
  print_array(arr3, n3);
  printf("Min arr3: %d\n", find_min(arr3, n3, 0));
  printf("Max arr3: %d\n", find_max(arr3, n3, 0));
  printf("Mediana arr3: %.f\n", mediana(arr3, n3));

  // Ordenamos el arreglo aleatorio para obtener los resultados (bubble sort)
  for(int i = 0; i<n4-1; i++){
    for(int j = i + 1; j<n4; j++){
      if(arr4[i] > arr4[j]){
        int temp = arr4[i];
        arr4[i] = arr4[j]; 
        arr4[j] = temp;
      }
    }
  }

  printf("Arreglo aleatorio: \n");
  print_array(arr4, n4);
  printf("Min arr4: %d\n", find_min(arr4, n4, 1));
  printf("Max arr4: %d\n", find_max(arr4, n4, 1));
  printf("Mediana arr4: %.f\n", mediana(arr4, n4));

  return 0;
}