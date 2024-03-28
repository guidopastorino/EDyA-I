#ifndef GLIST_H
#define GLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// Alias para puntero a función
typedef void(*FuncPtr)(void*);
typedef int (*FuncComparadoraPtr)(const void *dato1, const void *dato2);
typedef void (*FuncCopia)(void *dest, const void *src, size_t size);

// Definition of a struct that represents a node of a list with a generic datatype pointer (void*)
typedef struct _GNode {
  void* data; // Any data type can be stored here
  struct _GNode* next; // Pointer to the next node
} GNode;

// Definition of a struct that represents a generic list with a pointer to the head and the size of the list
typedef struct GList {
  size_t data_size;
  struct _GNode* head;
} GList;

GList* initialize_list(size_t data_size);

GNode* create_node(void* data, size_t data_size);

void insert_begin(GList** list, void* data, size_t data_size);

void print_list(GList* list, FuncPtr fPtr);

void printInt(void* data);

void printStr(void* data);

void sglist_destruir(GList* list);

int sglist_vacia(GList* list);

#endif