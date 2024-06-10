#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heap.h"

typedef struct {
  MinHeap* heap;
} PriorityQueue;

PriorityQueue* pq_create(int capacity);

void pq_insert(PriorityQueue* pq, int priority, void* data, CopyFunc copy);

Item* pq_extract_min(PriorityQueue* pq);

void pq_print(PriorityQueue* pq, VisitFunc func);

#endif