// Binary tree
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _BTNode {
  int data;
  struct _BTNode* left;
  struct _BTNode* right;
} BTNode;

BTNode* create_node(int data){
  BTNode* node = (BTNode*)malloc(sizeof(BTNode));
  assert(node != NULL);
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int nodes_count(BTNode* root){
  if(root == NULL) return 0;
  return 1 + nodes_count(root->left) + nodes_count(root->right);
}

BTNode* insert(BTNode* root, int data){
  if(root == NULL) return create_node(data);
  int count = nodes_count(root);
  BTNode** queue = (BTNode**)malloc(sizeof(BTNode*) * count);
  assert(queue != NULL);
  int front = 0, rear = 0;
  queue[rear++] = root;
  while(front != rear){
    BTNode* node = queue[front++];
    if(node->left == NULL){
      node->left = create_node(data);
      break;
    } else {
      queue[rear++] = node->left;
    }
    if(node->right == NULL){
      node->right = create_node(data);
      break;
    } else {
      queue[rear++] = node->right;
    }
  }
  free(queue);
  return root;
}

BTNode* delete_deepest(BTNode* root, BTNode* d_node){
  if(root == NULL) return NULL;
  int count = nodes_count(root);
  BTNode** queue = (BTNode**)malloc(sizeof(BTNode*) * count);
  assert(queue != NULL);
  int front = 0, rear = 0;
  queue[rear++] = root;
  while(front != rear){
    BTNode* temp = queue[front++];
    if(temp == d_node){
      temp = NULL;
      free(d_node);
      break;
    }
    if(temp->left != NULL){
      if(temp->left == d_node){
        temp->left = NULL;
        free(d_node);
        break;
      } else {
        queue[rear++] = temp->left;
      }
    }
    if(temp->right != NULL){
      if(temp->right == d_node){
        temp->right = NULL;
        free(d_node);
        break;
      } else {
        queue[rear++] = temp->right;
      }
    }
  }
  free(queue);
  return root;
}

BTNode* delete(BTNode* root, int data){
  if(root == NULL) return NULL;
  if(root->left == NULL && root->right == NULL){
    if(root->data == data){
      return NULL;
    } else {
      return root;
    }
  }
  int count = nodes_count(root);
  BTNode** queue = (BTNode**)malloc(sizeof(BTNode*) * count);
  assert(queue != NULL);
  int front = 0, rear = 0;
  BTNode *temp = NULL, *key_node = NULL;
  queue[rear++] = root;
  while(front != rear){
    temp = queue[front++];
    if(temp->data == data){
      key_node = temp;
      break;
    }
    if(temp->left)
      queue[rear++] = temp->left;
    if(temp->right)
      queue[rear++] = temp->right;
  }
  if(key_node != NULL){
    int x = temp->data;
    key_node->data = x;
    delete_deepest(root, temp);
  }
  free(queue);
  return root;
}

void bfs(BTNode* root){
  if(root == NULL) return;
  int count = nodes_count(root);
  BTNode** queue = (BTNode**)malloc(sizeof(BTNode*) * count);
  assert(queue != NULL);
  int front = 0, rear = 0;
  queue[rear++] = root;
  while(front < rear){
    BTNode* node = queue[front++];
    printf("%d ", node->data);
    if(node->left)
      queue[rear++] = node->left;
    if(node->right)
      queue[rear++] = node->right;
  }
  printf("\n");
  free(queue);
}

void preorder(BTNode* root){
  if(root != NULL){
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

int main(){
  BTNode* root = NULL;
  for(int i = 10; i<=50; i+=10)
    root = insert(root, i);

  bfs(root);
  preorder(root);
  return 0;
}