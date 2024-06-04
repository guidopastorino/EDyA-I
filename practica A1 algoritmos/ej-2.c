#include <stdio.h>
#include <math.h>
#include <time.h>

// Utilizando multiplicación iterativa (b^n)
unsigned long long exponenciacion_iterativo(unsigned long long b, unsigned long long n){
  unsigned long long result = 1;
  for(int i = 0; i<n; i++){
    result *= b;
  }
  return result;
}


// Utilizando exponenciación binaria (b^n)
unsigned long long exponenciacion_binaria(unsigned long long b, unsigned long long n){
  unsigned long long result = 1;
  unsigned long long base = b;
  while(n > 0){
    if(n % 2 == 1){
      result *= base;
    }
    base *= base;
    n /= 2;
  }
  return result;
}

int main(){
  unsigned long long base = 10;
  unsigned long long potencia = 10;
  printf("Cálculo: %llu^%llu\n", base, potencia);

  clock_t start, end;
  double expected_time;

  // Caso 1
  start = clock();
  printf("Utilizando multiplicación iterativa: %llu\n", exponenciacion_iterativo(base, potencia));
  end = clock();
  expected_time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Tiempo total de ejecución de la multiplicación iterativa: %f\n", expected_time);

  // Caso 2
  start = clock();
  printf("Utilizando exponenciación binaria: %llu\n", exponenciacion_binaria(base, potencia));
  end = clock();
  expected_time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Tiempo total de ejecución de la exponenciación binaria: %f\n", expected_time);

  return 0;
}