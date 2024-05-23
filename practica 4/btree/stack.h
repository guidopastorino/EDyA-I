#ifndef STACK_H
#define STACK_H

#include "btree.h"

typedef struct _StackNode* StackNode;

StackNode new_stack_node(BTree treeNode);

int is_empty(StackNode top);

BTree top(StackNode top);

void push(StackNode* top, BTree treeNode);

BTree pop(StackNode* top);


#endif