#include "matriz.h"

/*
** Implementacion utilizando un arreglo bidimensional (arreglo de punteros a arreglo)
*/

struct Matriz_ {
  size_t filas;
  size_t columnas;
  double** elementos;
};


Matriz* matriz_crear(size_t numFilas, size_t numColumnas) {
  Matriz* matriz = (Matriz*)malloc(sizeof(Matriz));
  assert(matriz != NULL);
  matriz->elementos = (double**)calloc(numFilas, sizeof(double*));
  assert(matriz->elementos != NULL);
  for(int i = 0; i<numFilas; i++){
    matriz->elementos[i] = (double*)calloc(numColumnas, sizeof(double));
    assert(matriz->elementos[i] != NULL);
  }
  matriz->filas = numFilas;
  matriz->columnas = numColumnas;
  return matriz;
}

void matriz_destruir(Matriz* matriz) {
  for(int i = 0; i<matriz->filas; i++){
    free(matriz->elementos[i]);
  }
  free(matriz->elementos);
  free(matriz);
}

double matriz_leer(Matriz* matriz, size_t fil, size_t col) {
  return matriz->elementos[fil][col];
}

void matriz_escribir(Matriz* matriz, size_t fil, size_t col, double val) {
  assert(fil < matriz->filas && col < matriz->columnas);
  matriz->elementos[fil][col] = val;
}

size_t matriz_num_filas(Matriz* matriz) {
  return matriz->filas;
}

size_t matriz_num_columnas(Matriz* matriz) {
  return matriz->columnas;
}

// c)
void matriz_intercambiar_filas(Matriz* matriz, size_t fila1, size_t fila2){
  assert(fila1 < matriz->filas && fila2 < matriz->filas);
  double* temp = matriz->elementos[fila1];
  matriz->elementos[fila1] = matriz->elementos[fila2];
  matriz->elementos[fila2] = temp;
}

void matriz_insertar_fila(Matriz* matriz, size_t pos){
  assert(pos < matriz->filas);
  matriz->elementos = (double**)realloc(matriz->elementos, sizeof(double*) * (matriz->filas + 1));
  assert(matriz->elementos != NULL);
  // desplazar hacia abajo las filas para hacerle lugar a la nueva fila
  for(size_t i = matriz->filas; i>pos; i--){
    matriz->elementos[i] = matriz->elementos[i-1];
  }
  matriz->elementos[pos] = (double*)malloc(sizeof(double) * matriz->columnas);
  assert(matriz->elementos[pos] != NULL);
  matriz->filas++;
}

