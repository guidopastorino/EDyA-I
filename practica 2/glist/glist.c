#include "glist.h"

// initialize new list
GList* initialize_list(size_t data_size){
  GList* list = (GList*)malloc(sizeof(GList));
  assert(list != NULL);
  list->data_size = data_size;
  list->head = NULL;
  return list;
}

// Create new node
GNode* create_node(void* data, size_t data_size){
  GNode* newNode = (GNode*)malloc(sizeof(GNode));
  assert(newNode != NULL);
  newNode->data = malloc(data_size);
  assert(newNode->data != NULL);
  memcpy(newNode->data, data, data_size);
  newNode->next = NULL;
  return newNode;
}

// insert begin
void insert_begin(GList** list, void* data, size_t data_size){
  GNode* newNode = create_node(data, data_size);
  newNode->next = (*list)->head;
  (*list)->head = newNode;
}

// print nodes
void print_list(GList* list, FuncPtr fPtr){
  GNode* current = list->head;
  while(current != NULL){
    (*fPtr)(current->data);
    current = current->next;
  }
  printf("NULL\n");
}

void printInt(void* data){
  printf("%d -> ", *(int*)data);
}

void printStr(void* data){
  printf("%s -> ", (char*)data);
}

void sglist_destruir(GList* list){
  GNode* current = list->head;
  while(current != NULL){
    GNode* temp = current;
    current = current->next;
    free(temp);
  }
}

int sglist_vacia(GList* list){
  return list->head == NULL;
}

// asumimos que los datos que se reciben serán enteros (int)
int compare(void* a, void* b){
  int x = *(int*)a;
  int y = *(int*)b;
  return (x == y) ? 0 : (x < y) ? -1 : 1;
}

// 'list' es una lista ordenada de enteros
GList* sglist_insertar(GList** list, void *data, FuncCopia fCopia, FuncComparadoraPtr funcComparadora){
  if(sglist_vacia(*list) == 1){
    *list = initialize_list(sizeof(*data));
  }

  GNode* newNode = create_node(data, (*list)->data_size);

  if((*list)->head == NULL || funcComparadora(data, (*list)->head->data) < 0){
    newNode->next = (*list)->head;
    (*list)->head = newNode;
    return;
  }

  GNode* actual = (*list)->head;
  GNode* prev = NULL;

  while(actual != NULL && funcComparadora(data, actual->data) >= 0){
    prev = actual;
    actual = actual->next;
  }

  newNode->next = actual;
  prev->next = newNode;
 
  return *list;
}