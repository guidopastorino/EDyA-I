#ifndef GQUEUE_H
#define GQUEUE_H

#include "glist.h"

typedef struct GQueue {
  GList lista; // {GNodo* primero,  GNodo* ultimo}
} GQueue;

GQueue* gqueue_crear();
int gqueue_vacio(GQueue*);
GQueue* gqueue_encolar(GQueue*, void*, FuncionCopia);
void* gqueue_desencolar(GQueue*, FuncionDestructora);
void gqueue_recorrer(GQueue*, FuncionVisitante);
void gqueue_destruir(GQueue*, FuncionDestructora);


#endif