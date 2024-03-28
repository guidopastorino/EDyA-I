#include "matriz.h"

/*
** Implmentacion utilizando un unico arreglo unidimensional
*/

struct Matriz_ {
  size_t filas;
  size_t columnas;
  double* elementos;
};

Matriz* matriz_crear(size_t numFilas, size_t numColumnas) {
  Matriz* matriz = (Matriz*)malloc(sizeof(Matriz));
  assert(matriz != NULL);
  matriz->filas = numFilas;
  matriz->columnas = numColumnas;
  matriz->elementos = (double*)calloc(numFilas * numColumnas, sizeof(double));
  assert(matriz->elementos != NULL);
  return matriz;
}

void matriz_destruir(Matriz* matriz) {
  free(matriz->elementos);
  free(matriz);
}

double matriz_leer(Matriz* matriz, size_t fil, size_t col) {
  assert((fil >= 0 && fil < matriz->filas) && (col >= 0 && col < matriz->columnas));
  return matriz->elementos[fil * matriz->columnas + col];
}

void matriz_escribir(Matriz* matriz, size_t fil, size_t col, double val) {
  assert((fil >= 0 && fil < matriz->filas) && (col >= 0 && col < matriz->columnas));
  matriz->elementos[fil * matriz->columnas + col] = val;
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
  size_t inicio_fila1 = fila1 * matriz->columnas;
  size_t inicio_fila2 = fila2 * matriz->columnas;
  for(size_t i = 0; i<matriz->columnas; i++){
    double temp = matriz->elementos[inicio_fila1 + i];
    matriz->elementos[inicio_fila1 + i] = matriz->elementos[inicio_fila2 + i];
    matriz->elementos[inicio_fila2 + i] = temp;
  }
}

void matriz_insertar_fila(Matriz* matriz, size_t pos) {
  assert(pos < matriz->filas);
  size_t nuevo_tamano = (matriz->filas + 1) * matriz->columnas;
  double* nuevos_elementos = (double*)malloc(sizeof(double) * nuevo_tamano);
  assert(nuevos_elementos != NULL);
  // copiar las filas anteriores hasta la posición de inserción
  for(size_t i = 0; i<pos*matriz->columnas; i++){
    nuevos_elementos[i] = matriz->elementos[i];
  }
  // copiar las filas posteriores desde la posición de inserción
  for(size_t i = pos*matriz->columnas;i<matriz->filas*matriz->columnas; i++){
    nuevos_elementos[i+matriz->columnas] = matriz->elementos[i];
  }
  free(matriz->elementos);
  matriz->elementos = nuevos_elementos;
  matriz->filas++;
}