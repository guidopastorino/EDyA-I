#ifndef GLIST_H
#define GLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef void* (*FuncionCopia)(void*);
typedef void (*FuncionVisitante)(void*);
typedef void (*FuncionComparadora)(void*, void*);
typedef void (*FuncionDestructora)(void*);

typedef struct _GNodo {
  void* data;
  struct _GNodo* next;
} GNodo;

typedef struct LinkedList {
  GNodo* primero;
  GNodo* ultimo;
} LinkedList;

typedef struct LinkedList* GList;

GList glist_crear();

// es como hacer enqueue ¿¿¿¿????
GList glist_insertar_final(GList, void*, FuncionCopia);

// es como hacer dequeue ¿¿¿¿????
GList glist_eliminar_inicio(GList, FuncionDestructora);

int glist_vacio(GList);

void glist_destruir(GList, FuncionDestructora);

void glist_mostrar(GList, FuncionVisitante);

#endif