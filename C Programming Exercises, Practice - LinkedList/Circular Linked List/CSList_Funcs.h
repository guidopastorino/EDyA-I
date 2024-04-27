#ifndef CSLIST_FUNCS_H
#define CSLIST_FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _CSNode {
  int data;
  struct _CSNode* next;
} CSNode;

CSNode* initialize_list();

CSNode* create_node(int data);

void insert_end(CSNode** tail, int data);

void display(CSNode* tail);

#endif /* _CSLIST_FUNCS_H_ */