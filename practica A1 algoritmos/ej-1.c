#include <stdio.h>

unsigned long long fibonacci(int n){
  if(n == 0) return 0;
  if(n == 1) return 1;

  unsigned long long a = 0;
  unsigned long long b = 1;
  unsigned long long c;

  for(int i = 2; i<=n; i++){
    c = a + b;
    a = b;
    b = c;
  }

  return b;
}

int main(){
  int n;
  printf("Nth fib number: ");
  scanf("%d", &n);

  printf("%llu\n", fibonacci(n));

  return 0;
}