#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b));

int costo_minimo(int* P[], int M, int N){
  int** dp = (int**)malloc(sizeof(int*) * M);
  for(int i = 0; i<M; i++)
    dp[i] = (int*)malloc(sizeof(int) * N);
  dp[0][0] = P[0][0];
  for(int i = 1; i<M; i++) // Para la primera fila
    dp[i][0] = dp[i-1][0] + P[i][0];
  for(int j = 1; j<N; j++) // Para la primera columna
    dp[0][j] = dp[0][j-1] + P[0][j];
  for(int i = 1; i<M; i++){
    for(int j = 1; j<N; j++){
      dp[i][j] = P[i][j] + MIN(dp[i-1][j], dp[i][j-1]);
    }
  }
  int resultado = dp[M-1][N-1];
  // liberar memoria de dp
  for(int i = 0; i<M; i++)
    free(dp[i]);
  free(dp);
  return resultado;
}

int main(){
  int M = 3, N = 3;
  int* P[] = {
    (int[]){1, 3, 1},
    (int[]){1, 5, 1},
    (int[]){4, 2, 1}
  };

  printf("Costo minimo: %d\n", costo_minimo(P, M, N));

  return 0;
}