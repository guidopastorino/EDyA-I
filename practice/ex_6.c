#include <stdio.h>

#define SIZE 7

void dfs_preorder(int arr[], int index, int size){
  if(index >= size) return;
  printf("%d ", arr[index]);
  dfs_preorder(arr, 2 * index + 1, size); // Recorrer el subarbol izquierdo
  dfs_preorder(arr, 2 * index + 2, size); // Recorrer el subarbol derecho
}

void dfs_inorder(int arr[], int index, int size){
  if(index >= size) return;
  dfs_inorder(arr, 2 * index + 1, size); // Recorrer el subarbol izquierdo
  printf("%d ", arr[index]);
  dfs_inorder(arr, 2 * index + 2, size); // Recorrer el subarbol derecho
}

void dfs_postorder(int arr[], int index, int size){
  if(index >= size) return;
  dfs_postorder(arr, 2 * index + 1, size); // Recorrer el subarbol izquierdo
  dfs_postorder(arr, 2 * index + 2, size); // Recorrer el subarbol derecho
  printf("%d ", arr[index]);
}

int is_minheap(int arr[], int size){
  for(int i = 0; i <= (size - 2) / 2; i++){
    if(arr[i] > arr[2 * i + 1]) return 0;
    if(2 * i + 2 < size && arr[i] > arr[2 * i + 2]) return 0;
  }
  return 1;
}

int is_maxheap(int arr[], int size){
  for(int i = 0; i <= (size - 2) / 2; i++){
    if(arr[i] < arr[2 * i + 1]) return 0;
    if(2 * i + 2 < size && arr[i] < arr[2 * i + 2]) return 0;
  }
  return 1;
}

void print_array(int arr[], int size){
  for(int i = 0; i<size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main(){
  int min_heap[SIZE] = {1, 4, 7, 8, 10, 20, 40};
  //          1
  //        /   \ 
  //       4     7
  //      / \   / \ 
  //     8  10 20 40          

  int max_heap[SIZE] = {50, 20, 35, 15, 13, 20, 10};
  //          50
  //        /   \ 
  //       20    35
  //      / \    / \ 
  //     15  13 20 10 

  // Recorridos DFS con Min Heap:
  printf("DFS Min Heap: \n");
  printf("Preorder: ");
  dfs_preorder(min_heap, 0, SIZE); // 1 4 8 10 7 20 40
  printf("\n");

  printf("Inorder: ");
  dfs_inorder(min_heap, 0, SIZE); // 8 4 10 1 20 7 40
  printf("\n");

  printf("Postorder: ");
  dfs_postorder(min_heap, 0, SIZE); // 8 10 4 20 40 7 1
  printf("\n");

  printf("BFS Min Heap: ");
  print_array(min_heap, SIZE); // 1 4 7 8 10 20 40


  // Verificar si es un min heap
  printf("Is min heap (minheap): %d\n", is_minheap(min_heap, SIZE));
  printf("Is max heap (minheap): %d\n", is_maxheap(min_heap, SIZE));
  printf("Is min heap (maxheap): %d\n", is_minheap(max_heap, SIZE));
  printf("Is max heap (maxheap): %d\n", is_maxheap(max_heap, SIZE));

  return 0;
}