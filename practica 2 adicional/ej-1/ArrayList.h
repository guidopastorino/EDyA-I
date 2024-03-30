// ARRAYLIST IMPLEMENTATION IN C
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INITIAL_CAPACITY 10
#define GROWTH_FACTOR 2

typedef struct Node {
  int data;
  int next; // indice del siguiente nodo
} Node;

typedef struct {
  Node* array;
  int capacity;
  int size;
  int head; // indice del primer elemento
  int tail; // indice del último elemento
} ArrayList;

ArrayList* initialize_list();

int isFull(ArrayList* list);

void insert(ArrayList* list, int data);

void print(ArrayList* list);

#endif