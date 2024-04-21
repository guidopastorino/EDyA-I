#ifndef BSL_H
#define BSL_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// nodo de una lista enlazada simple
typedef struct _SNode {
  int data;
  struct _SNode* next;
} SNode;

SNode* create_node(int data);

void insert_end(SNode** head, int data);

void display_list(SNode* head);

void free_list(SNode* head);

SNode* get_node_at(SNode* head, int index);

int binary_search(SNode* head, int element);

#endif