#include <stdio.h>

void swap(float* a, float* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(float arr[], int n){
  for(int i = 0; i<n-1; i++){
    for(int j = 0; j<n-i-1; j++){
      if(arr[j] > arr[j+1]){
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
}

float mediana(float arr[], int n){
  bubble_sort(arr, n);
  if(n % 2 == 0){
    int indice1 = n / 2 - 1;
    int indice2 = n / 2;
    return (arr[indice1] + arr[indice2]) / 2.0;
  } else {
    int indice = n / 2;
    return arr[indice];
  }
}

int main(){
  float arr[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Mediana: %.1f\n", mediana(arr, n));
  return 0;
}