#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

int buscar_repetido(int arr[], int len) {
  int i, j;
  for (i = 0; i < len; i++) {
    for (j = 0; j < len; j++) {
      if (arr[i] == arr[j] && i != j)
        return i;
    }
  }
  return -1;
}

// mejora a O(n) (lineal)
int buscar_repetido_mejorado(int arr[], int len){
  int aux[101] = {0};
  for(int i = 0; i<len; i++){
    if(aux[arr[i]] > 0) return i;
    aux[arr[i]]++;
  }
  return -1;
}

void print_array(int* arr, int n){
  for(int i = 0; i<n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main(){
  int arr[SIZE];
  srand((unsigned int)time(NULL));
  for(int i = 0; i<SIZE; i++)
    arr[i] = rand() % SIZE;

  clock_t start, end;
  double time;
  start = clock();
  printf("Repetido f1: %d\n", buscar_repetido(arr, SIZE));
  end = clock();
  time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Ejecución f1: %f\n", time);
  // 
  start = clock();
  printf("Repetido f2: %d\n", buscar_repetido_mejorado(arr, SIZE));
  end = clock();
  time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Ejecución f2: %f\n", time);
  

  return 0;
}