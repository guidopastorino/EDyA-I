// Write a C program to implement a binary tree using linked list representation.
// Test Data and Expected Output :

// Traversal of a binary tree: 
// 40 20 50 10 30 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _TNode {
  int data;
  struct _TNode* left;
  struct _TNode* right;
} TNode;


TNode* create_tree_node(int data){
  TNode* newNode = (TNode*)malloc(sizeof(TNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void inorder_traversal(TNode* node){
  if(node == NULL) return;

  inorder_traversal(node->left);
  printf("%d ", node->data);
  inorder_traversal(node->right);
}

int main(){
  /*
  let's make the following tree:
        10
        /\
      20  30
      /\    \
    40  50   60
  */

  TNode* root = create_tree_node(10);
  root->left = create_tree_node(20);
  root->right = create_tree_node(30);
  root->right->right = create_tree_node(60);
  root->left->left = create_tree_node(40);
  root->left->right = create_tree_node(50);

  inorder_traversal(root); // 40 20 50 10 30 60

  return 0;
}