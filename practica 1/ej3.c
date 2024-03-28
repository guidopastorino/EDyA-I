#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
  int *direccion;
  int capacidad;
} ArregloEnteros;

ArregloEnteros *arreglo_enteros_crear(int capacidad)
{
  ArregloEnteros *arreglo = (ArregloEnteros *)malloc(sizeof(ArregloEnteros));
  assert(arreglo != NULL);
  arreglo->direccion = (int *)malloc(sizeof(int) * capacidad);
  assert(arreglo->direccion != NULL);
  arreglo->capacidad = capacidad;
  return arreglo;
}

void arreglo_enteros_destruir(ArregloEnteros *arreglo)
{
  free(arreglo->direccion);
  free(arreglo);
}

int arreglo_enteros_leer(ArregloEnteros *arreglo, int pos)
{
  assert(pos >= 0 && pos < arreglo->capacidad);
  return arreglo->direccion[pos];
}

void arreglo_enteros_escribir(ArregloEnteros *arreglo, int pos, int dato)
{
  assert(pos >= 0 && pos <= arreglo->capacidad);
  arreglo->direccion[pos] = dato;
}

int arreglo_enteros_capacidad(ArregloEnteros *arreglo)
{
  return arreglo->capacidad;
}

void arreglo_enteros_imprimir(ArregloEnteros *arreglo)
{
  for (int i = 0; i < arreglo->capacidad; i++)
    printf("%d ", arreglo->direccion[i]);
}

void arreglo_enteros_ajustar(ArregloEnteros *arreglo, int capacidad)
{
  assert(capacidad >= 0);
  arreglo->direccion = realloc(arreglo->direccion, sizeof(int) * capacidad);
  assert(arreglo != NULL);
  arreglo->capacidad = capacidad;
}

void arreglo_enteros_insertar(ArregloEnteros *arreglo, int pos, int dato)
{
  assert(pos >= 0 && pos < arreglo->capacidad);
  arreglo_enteros_ajustar(arreglo, arreglo->capacidad + 1);
  for (int i = arreglo->capacidad - 1; i > pos; i--)
  {
    arreglo->direccion[i] = arreglo->direccion[i - 1];
  }
  arreglo->direccion[pos] = dato;
}

void arreglo_enteros_eliminar(ArregloEnteros *arreglo, int pos)
{
  assert(pos >= 0 && pos < arreglo->capacidad);
  for (int i = pos; i < arreglo->capacidad - 1; i++)
  {
    arreglo->direccion[i] = arreglo->direccion[i + 1];
  }
  arreglo_enteros_ajustar(arreglo, arreglo->capacidad - 1);
}

int main()
{
  int capacidad_inicial = 10;

  ArregloEnteros *arreglo = arreglo_enteros_crear(capacidad_inicial);

  for (int i = 0; i < capacidad_inicial; i++)
  {
    arreglo_enteros_escribir(arreglo, i, i * 10);
  }

  arreglo_enteros_insertar(arreglo, 3, 300);

  arreglo_enteros_eliminar(arreglo, 3);

  arreglo_enteros_imprimir(arreglo);

  arreglo_enteros_destruir(arreglo);

  return 0;
}