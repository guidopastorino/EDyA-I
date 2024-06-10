#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct _BSTNode {
  int data;
  struct _BSTNode* left;
  struct _BSTNode* right;
} BSTNode;

BSTNode* create_node(int data){
  BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
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

void bfs(BSTNode* root){
  if(root == NULL) return;
  BSTNode* queue[100];
  int front = 0, rear = 0;
  queue[rear++] = root;
  while(front < rear){
    BSTNode* node = queue[front++];
    printf("%d ", node->data);
    if(node->left)
      queue[rear++] = node->left;
    if(node->right)
      queue[rear++] = node->right;
  }
  printf("\n");
}

// Calcular el tamaño (cantidad de nodos) del subárbol enraizado en un nodo sin usar recursion
typedef struct _StackNode {
  BSTNode* treeNode;
  struct _StackNode* next;
} StackNode;

StackNode* new_stack_node(BSTNode* treeNode){
  StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));
  assert(stackNode != NULL);
  stackNode->treeNode = treeNode;
  stackNode->next = NULL;
  return stackNode;
}

int is_empty(StackNode* top){
  return top == NULL;
}

void push(StackNode** top, BSTNode* treeNode){
  StackNode* stackNode = new_stack_node(treeNode);
  stackNode->next = *top;
  *top = stackNode;
}

BSTNode* pop(StackNode** top){
  if(is_empty(*top)) return NULL;
  StackNode* temp = *top;
  *top = (*top)->next;
  BSTNode* poppedNode = temp->treeNode;
  free(temp);
  return poppedNode;
}

int node_size_non_recursive(BSTNode* node){
  if(node == NULL) return 0;

  int size = 0;

  StackNode* stack = NULL;
  push(&stack, node);

  while(!is_empty(stack)){
    BSTNode* node = pop(&stack);
    size++;
    if(node->left) push(&stack, node->left);
    if(node->right) push(&stack, node->right);
  }

  return size;
}

// Calcular la altura de un arbol sin usar recursion
typedef struct _QueueNode {
  BSTNode* treeNode;
  int depth;
  struct _QueueNode* next;
} QueueNode;

QueueNode* new_queue_node(BSTNode* treeNode, int depth){
  QueueNode* queueNode = (QueueNode*)malloc(sizeof(QueueNode));
  assert(queueNode != NULL);
  queueNode->treeNode = treeNode;
  queueNode->depth = depth;
  queueNode->next = NULL;
  return queueNode;
}

int is_queue_empty(QueueNode* front){
  return front == NULL;
}

void enqueue(QueueNode** front, QueueNode** rear, BSTNode* treeNode, int depth){
  QueueNode* queueNode = new_queue_node(treeNode, depth);
  // si la cola esta vacia
  if(*rear == NULL){
    *front = *rear = queueNode;
  } else {
    (*rear)->next = queueNode;
    *rear = queueNode;
  }
}

QueueNode* dequeue(QueueNode** front, QueueNode** rear){
  if(is_queue_empty(*front)) return NULL;
  QueueNode* temp = *front;
  *front = temp->next;
  if(*front == NULL) *rear = NULL;
  return temp;
}

int non_recursive_height(BSTNode* node){
  if(node == NULL) return -1;
  QueueNode* front = NULL;
  QueueNode* rear = NULL;
  enqueue(&front, &rear, node, 0);
  int maxDepth = 0;
  while(!is_queue_empty(front)){
    QueueNode* current = dequeue(&front, &rear);
    BSTNode* currentNode = current->treeNode;
    int currentDepth = current->depth;
    if(currentDepth > maxDepth){
      maxDepth = currentDepth;
    }
    if(currentNode->left) enqueue(&front, &rear, currentNode->left, currentDepth + 1);
    if(currentNode->right) enqueue(&front, &rear, currentNode->right, currentDepth + 1);
    free(current);
  }
  return maxDepth;
}


// Verifica si un arbol es simétrico (ignorando claves iguales)
int is_mirror(BSTNode* root1, BSTNode* root2){
  if(root1 == NULL && root2 == NULL) return 1;
  if(root1 == NULL || root2 == NULL) return 0;
  return is_mirror(root1->left, root2->right) &&
         is_mirror(root1->right, root2->left);
}

int is_symetric(BSTNode* root){
  if(root == NULL) return 1;
  return is_mirror(root->left, root->right);
}

// Genera el arbol binario espejo de uno dado
BSTNode* create_mirror_tree(BSTNode* root){
  if(root == NULL) return NULL;
  
  BSTNode* newNode = create_node(root->data);

  newNode->left = create_mirror_tree(root->right);
  newNode->right = create_mirror_tree(root->left);

  return newNode;
}

int main(){ 
  BSTNode* root = NULL;
  int nums[] = {30, 20, 40, 10, 25, 35, 50, 5, 60};
  int n = sizeof(nums) / sizeof(nums[0]);
  for(int i = 0; i<n; i++)
    root = insert(root, nums[i]);
    
  //          30
  //        /    \
  //      20      40
  //     /  \    /  \
  //    10  25  35   50
  //   /              \
  //  5                60

  bfs(root);

  printf("Is symetric: %d\n", is_symetric(root)); // 1 (ya que el subarbol izquierdo es un reflejo simetrico del derecho)
  printf("Total nodes in the tree: %d\n", node_size_non_recursive(root));
  printf("Tree height: %d\n", non_recursive_height(root)); // 3

  BSTNode* mirror = create_mirror_tree(root);

  bfs(mirror);

  return 0;
}
