#include "matriz.h"

int main(){
  Matriz* matriz = matriz_crear(10, 10);
  int filas = matriz_num_filas(matriz);
  int columnas = matriz_num_columnas(matriz);

  for(int i = 0; i<filas; i++){
    for(int j = 0; j<columnas; j++){
      matriz_escribir(matriz, i, j, 1 + (i*1) + (j*1));
    }
  }

  for(int i = 0; i<filas; i++){
    for(int j = 0; j<columnas; j++){
      printf("%.f ", matriz_leer(matriz, i, j));
    }
    printf("\n");
  }

  printf("\n");

  matriz_insertar_fila(matriz, 0);

  filas = matriz_num_filas(matriz);
  columnas = matriz_num_columnas(matriz);

  printf("%d %d\n", filas, columnas);

  for(int i = 0; i<filas; i++){
    for(int j = 0; j<columnas; j++){
      printf("%.f ", matriz_leer(matriz, i, j));
    }
    printf("\n");
  }
  
  matriz_destruir(matriz);

  return 0;
}