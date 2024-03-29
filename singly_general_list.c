// LISTA DOBLEMENTE ENLAZADA
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct _GNode {
  void* data;
  struct _GNode* next;
} GNode;

typedef struct GList {
  GNode* head;
  size_t size; // Tamaño de cada nodo
} GList;

typedef void(*FnPrintPtr)(void* data);

GList* initialize_list(size_t size){
  GList* list = (GList*)malloc(sizeof(GList));
  assert(list != NULL);
  list->head = NULL;
  list->size = size;
  return list;
}

GNode* create_node(void* data, size_t data_size){
  GNode* newNode = (GNode*)malloc(sizeof(GNode));
  assert(newNode != NULL);
  newNode->data = malloc(sizeof(data_size));
  assert(newNode->data != NULL);
  memcpy(newNode->data, data, data_size);
  newNode->next = NULL;
  return newNode;
}

void insert_begin(GList** list, void* data){
  GNode* newNode = create_node(data, (*list)->size);
  newNode->next = (*list)->head;
  (*list)->head = newNode;
}

void insert_end(GList** list, void* data){
  GNode* newNode = create_node(data, (*list)->size);
  if((*list)->head == NULL){
    (*list)->head = newNode;
  } else {
    GNode* current = (*list)->head;
    while(current->next != NULL){
      current = current->next;
    }
    current->next = newNode;
  }
}

void delete_begin(GList** list){
  assert((*list)->head != NULL);
  GNode* temp = (*list)->head;
  (*list)->head = (*list)->head->next;
  free(temp);
}

void delete_end(GList** list){
  assert((*list)->head != NULL);
  if((*list)->head->next == NULL){
    delete_begin(list);
    return;
  }
  GNode* current;
  for(current = (*list)->head; current->next->next != NULL; current = current->next);
  free(current->next);
  current->next = NULL;
}

void printInt(void* data){
  printf("%d -> ", *(int*)data);
}

void imprimir_lista(GList* list, FnPrintPtr fptr){
  for(GNode* curr = list->head; curr != NULL; curr = curr->next){
    (*fptr)(curr->data);
  }
  printf("NULL\n");
}

void free_list(GList* list){
  for(GNode* curr = list->head; curr != NULL; curr = curr->next){
    GNode* temp = curr;
    curr = curr->next;
    free(temp);
  }
}

int main(){
  GList* list = initialize_list(sizeof(int));
  for(int i = 10; i<=50; i+=10){
    insert_end(&list, &i);
  }

  void (*fPtr)(void*) = &printInt;

  imprimir_lista(list, fPtr);

  delete_begin(&list);

  imprimir_lista(list, fPtr);

  delete_end(&list);

  imprimir_lista(list, fPtr);

  free_list(list);

  return 0;
}