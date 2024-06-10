#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _BSTNode {
  int data;
  struct _BSTNode* left;
  struct _BSTNode* right;
} BSTNode;

BSTNode* create_node(int data){
  BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
  assert(node != NULL);
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

BSTNode* insert(BSTNode* root, int data){
  if(root == NULL) return create_node(data);
  if(data < root->data){
    root->left = insert(root->left, data);
  } else if(data > root->data){
    root->right = insert(root->right, data);
  }
  return root;
}

// ================ Stack for DFS ==================
typedef struct _StackNode {
  BSTNode* treeNode;
  struct _StackNode* next;
} StackNode;

StackNode* new_stack_node(BSTNode* treeNode){
  StackNode* stack_node = (StackNode*)malloc(sizeof(StackNode));
  assert(stack_node != NULL);
  stack_node->treeNode = treeNode;
  stack_node->next = NULL;
  return stack_node;
}

int is_empty(StackNode* top){
  return top == NULL;
}

void push(StackNode** top, BSTNode* treeNode){
  StackNode* new_node = new_stack_node(treeNode);
  new_node->next = *top;
  *top = new_node;
}

BSTNode* pop(StackNode** top){
  if(is_empty(*top)) return NULL;
  StackNode* temp = *top;
  *top = temp->next;
  BSTNode* poppedNode = temp->treeNode;
  free(temp);
  return poppedNode;
}

// =================================================

// DFS using stack

void preorder(BSTNode* root){
  StackNode* stack = NULL;
  push(&stack, root);
  while(!is_empty(stack)){
    BSTNode* node = pop(&stack);
    printf("%d ", node->data);
    if(node->right) push(&stack, node->right);
    if(node->left) push(&stack, node->left);
  }
  printf("\n");
}

void inorder(BSTNode* root){
  StackNode* stack = NULL;
  BSTNode* current = root;
  while(current != NULL || !is_empty(stack)){
    while(current != NULL){
      push(&stack, current);
      current = current->left;
    }
    current = pop(&stack);
    printf("%d ", current->data);
    current = current->right;
  }
  printf("\n");
}

void postorder(BSTNode* root){
  StackNode* stack1 = NULL;
  StackNode* stack2 = NULL;
  push(&stack1, root);
  while(!is_empty(stack1)){
    BSTNode* node = pop(&stack1);
    push(&stack2, node);
    if(node->left) push(&stack1, node->left);
    if(node->right) push(&stack1, node->right);
  }
  while(!is_empty(stack2)){
    BSTNode* node = pop(&stack2);
    printf("%d ", node->data);
  }
  printf("\n");
}

// BFS using queue
void bfs(BSTNode* root){
  if(root == NULL) return;
  BSTNode* queue[100];
  int front = 0, rear = 0;
  queue[rear++] = root;
  while(front < rear){
    BSTNode* node = queue[front++];
    printf("%d ", node->data);
    if(node->left) queue[rear++] = node->left;
    if(node->right) queue[rear++] = node->right;
  }
  printf("\n");
}

int main(){
  BSTNode* root = NULL;
  root = insert(root, 50);
  root = insert(root, 20);
  root = insert(root, 60);
  root = insert(root, 10);
  root = insert(root, 25);
  root = insert(root, 55);
  root = insert(root, 65);

  printf("BFS: ");
  bfs(root);

  printf("Preorder: ");
  preorder(root);

  printf("Inorder: ");
  inorder(root);

  printf("Postorder: ");
  postorder(root);

  return 0;
}