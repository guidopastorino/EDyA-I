// This file includes the "basic" functions for a single linked list
#ifndef SLIST_FUNCS_H
#define SLIST_FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct _SNode {
  int data;
  struct _SNode* next;
} Node;

Node* create_node(int data);

void insert_begin(Node** head, int data);

void insert_end(Node** head, int data);

int list_length(Node* head);

void display_list(Node* head);

void free_list(Node* head);

#endif