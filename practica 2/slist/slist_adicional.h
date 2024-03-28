#ifndef SLIST_ADICIONAL_H
#define SLIST_ADICIONAL_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.h" // para el uso de la estructura 'Node' y otras funciones como la de 'crear_nodo'

typedef struct SList {
  Node *primero;
  Node *ultimo;
} SList;

SList *slist_crear(int data);

void slist_agregar_inicio(SList** list, int data);

void slist_agregar_final(SList** list, int data);

#endif