#ifndef DLIST_FUNCS_H
#define DLIST_FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Ways to traverse the list */
typedef enum { DISPLAY_FORWARD, DISPLAY_BACKWARD } Traversing;

/* Estructura de nodo _DNode */
typedef struct _DNode {
  int data;
  struct _DNode* prev;
  struct _DNode* next;
} DNode;

/* Initialize list */
DNode* initialize_list();

/* Create node */
DNode* create_node(int data);

/* Insert begin */
void insert_begin(DNode** head, int data);

/* Delete begin */
void delete_begin(DNode** head);

/* Insert end */
void insert_end(DNode** head, int data);

/* Create node */
int list_length(DNode* head);

/* Display list */
void display_list(DNode* head, Traversing direction);

#endif /* _DLIST_FUNCS_H_ */