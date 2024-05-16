#ifndef GPILA_H
#define GPILA_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef void (*FuncionDestructora)(void*);
typedef void (*FuncionVisitante)(void*);
typedef int (*FuncionComparadora)(void*, void*);
typedef void* (*FuncionCopia)(void*);

typedef struct _GNode {
  void* data;
  struct _GNode* next;
} GNode;

typedef GNode* GList;

typedef struct Stack {
  GList top;
} Stack;

typedef Stack* GStack;

GStack stack_crear();
void stack_destruir(GStack, FuncionDestructora);
int stack_vacia(GStack);
void stack_recorrer(GStack, FuncionVisitante);
int compare(void*, void*);
GStack stack_insertar(GStack, void *, FuncionCopia, FuncionComparadora);
int stack_buscar(GStack, void *, FuncionComparadora);
// construye una lista ordenada a partir de un arreglo de elementos y su longitud.
GStack stack_arr(void **, int, FuncionCopia, FuncionComparadora);

#endif