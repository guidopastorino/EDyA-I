#include "stack.h"
#include "btree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct _StackNode {
  BTree treeNode;
  struct _StackNode* next;
};

StackNode new_stack_node(BTree treeNode){
  StackNode stackNode = (StackNode)malloc(sizeof(struct _StackNode));
  assert(stackNode != NULL);
  stackNode->treeNode = treeNode;
  stackNode->next = NULL;
  return stackNode; 
}

int is_empty(StackNode top){
  return top == NULL;
}

BTree top(StackNode top){
  if(top == NULL) return NULL;
  return top->treeNode;
}

// insert begin
void push(StackNode* top, BTree treeNode){
  StackNode newNode = new_stack_node(treeNode);
  newNode->next = *top;
  *top = newNode;
}

// delete begin
BTree pop(StackNode* top){
  if(is_empty(*top)){
    printf("Stack is empty. Cannot pop\n");
    return NULL;
  }
  StackNode temp = *top;
  *top = (*top)->next;
  BTree poppedNode = temp->treeNode;
  free(temp);
  return poppedNode;
}