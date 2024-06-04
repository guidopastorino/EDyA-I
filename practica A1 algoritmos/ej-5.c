#include <stdio.h>

int sobreviviente(int n){
  int resultado = 0;
  for(int i = 2; i <= n; i++)
    resultado = (resultado + 2) % i;
  return resultado + 1;
}

int main(){
  int n = 9;

  int s = sobreviviente(n);
  printf("Sobreviviente: %d\n", s);

  return 0;
}