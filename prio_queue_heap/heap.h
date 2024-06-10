#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef void (*VisitFunc)(int, void*); // Function to print an element
typedef void* (*CopyFunc)(void*); // Copy physically a new element

typedef struct {
  int priority;
  void* data;
} Item;

typedef struct {
  int capacity;
  int size;
  Item** arr;
} MinHeap;

MinHeap* heap_create(int capacity);

void heap_insert(MinHeap* heap, int priority, void* data, CopyFunc copy);

Item* heap_extract_min(MinHeap* heap);

void print_heap(MinHeap* heap, VisitFunc func);

#endif