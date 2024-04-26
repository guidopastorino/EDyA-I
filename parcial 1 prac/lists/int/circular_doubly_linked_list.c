// circular doubly linked list
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int (*Predicate)(int);
typedef int (*Compare)(int, int);

typedef enum { DISPLAY_FORWARD, DISPLAY_BACKWARD } Traversing;

typedef struct _CDNode {
  int data;
  struct _CDNode* prev;
  struct _CDNode* next;
} CDNode;

// Crear nodo
CDNode* create_node(int data){
  CDNode* newNode = (CDNode*)malloc(sizeof(CDNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->prev = newNode;
  newNode->next = newNode;
  return newNode;
}

// Insertar al principio
void insert_begin(CDNode** tail, int data){
  CDNode* newNode = create_node(data);
  if(*tail == NULL){
    *tail = newNode;
  } else {
    newNode->next = (*tail)->next;
    newNode->prev = *tail;
    (*tail)->next->prev = newNode;
    (*tail)->next = newNode;
  }
}

// Insertar al final
void insert_end(CDNode** tail, int data){
  CDNode* newNode = create_node(data);
  if(*tail == NULL){
    *tail = newNode;
  } else {
    newNode->next = (*tail)->next;
    newNode->prev = *tail;
    (*tail)->next->prev = newNode;
    (*tail)->next = newNode;
    *tail = newNode;
  }
}

// Insertar en posición
void insert_position(CDNode** tail, int pos, int data){
  assert(pos >= 0);
  if(pos == 0){
    insert_begin(tail, data);
  } else {
    CDNode* current = (*tail)->next;
    for(int i = 0; i<pos-1; i++){
      current = current->next;
      if(current == (*tail)->next){
        printf("Position out of range\n");
        return;
      }
    }
    CDNode* newNode = create_node(data);
    // current se encuentra en el nodo anterior al lugar donde se agregará el nuevo nodo
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
    if(current == *tail) *tail = (*tail)->next;
  }
}

// Insertar en medio
void insert_middle(CDNode** tail, int data){
  if(*tail == NULL){
    insert_begin(tail, data);
  } else {
    CDNode* prev = NULL;
    CDNode* slow = (*tail)->next;
    CDNode* fast = (*tail)->next;
    while(fast->next != (*tail)->next && fast->next->next != (*tail)->next){
      slow = slow->next;
      fast = fast->next->next;
    }
    // slow apunta al nodo que queremos insertar
    CDNode* newNode = create_node(data);
    newNode->next = slow->next;
    newNode->prev = slow;
    slow->next->prev = newNode;
    slow->next = newNode;
    if(slow == *tail) *tail = newNode;
  }
}

// Eliminar al principio
void delete_begin(CDNode** tail){
  assert(*tail != NULL);
  if(*tail == (*tail)->next){
    free(*tail);
    *tail = NULL;
  } else {
    CDNode* temp = (*tail)->next;
    (*tail)->next = (*tail)->next->next;
    (*tail)->next->prev = *tail;
    free(temp);
  }
}

// Eliminar al final
void delete_end(CDNode** tail){
  assert(*tail != NULL);
  if(*tail == (*tail)->next){
    free(*tail);
    *tail = NULL;
  } else {
    CDNode* temp = *tail;
    (*tail)->prev->next = (*tail)->next;
    (*tail)->next->prev = (*tail)->prev;
    *tail = (*tail)->prev;
    free(temp);
  }
}

// Eliminar en posición
void delete_position(CDNode** tail, int pos){
  assert(*tail != NULL && pos >= 0);
  if(pos == 0){
    delete_begin(tail);
  } else {
    CDNode* current = (*tail)->next;
    for(int i = 0; i<pos; i++){
      current = current->next;
      if(current == (*tail)->next){
        printf("Position out of range\n");
        return;
      }
    }
    CDNode* temp = current;
    // current apunta al nodo que vamos a eliminar
    current->prev->next = current->next;
    current->next->prev = current->prev;
    if(current == *tail) *tail = current->prev;
    free(temp);
  }
}

// Eliminar en medio
void delete_middle(CDNode** tail){
  assert(*tail != NULL);
  if(*tail == (*tail)->next){
    delete_begin(tail);
  } else {
    CDNode* slow = (*tail)->next;
    CDNode* fast = (*tail)->next;
    while(fast != (*tail)->next && fast->next != (*tail)->next){
      slow = slow->next;
      fast = fast->next->next;
    }
    // slow apunta al nodo anterior que vamos a eliminar
    CDNode* temp = slow->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    if(temp == *tail) *tail = temp->prev;
    free(temp);
  }
}

// Obtener el tail
int list_tail(CDNode* tail){
  if(tail == NULL){
    printf("List is empty\n");
    exit(EXIT_FAILURE);
  } else {
    return tail->data;
  }
}

// Mostrar lista
void display_list(CDNode* tail, Traversing direction){
  if(tail == NULL){
    printf("NULL\n");
  } else {
    if(direction == DISPLAY_FORWARD){
      CDNode* current = tail->next;
      do {
        printf("%d ", current->data);
        current = current->next;
      } while(current != tail->next);
    } else if(direction == DISPLAY_BACKWARD){
      CDNode* current = tail;
      do {
        printf("%d ", current->data);
        current = current->prev;
      } while(current != tail);
    } else {
      printf("Unvalid direction");
    }
    printf("\n");
  }
}

// Mediana de la lista
int list_median(CDNode* tail){
  if(tail == NULL){
    printf("List is empty\n");
    exit(EXIT_FAILURE);
  }
  CDNode* slow = tail->next;
  CDNode* fast = tail->next;
  while(fast != tail && fast->next != tail){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}

int compare(int a, int b){
  return (a == b) ? 0 : (a < b) ? -1 : 1;
}

// Contiene elemento
int contains(CDNode* tail, int element, Compare cmp){
  if(tail == NULL){
    printf("List is empty\n");
    exit(EXIT_FAILURE);
  }
  CDNode* current = tail->next;
  do {
    if(cmp(current->data, element) == 0) return 1;
    current = current->next;
  }while(current != tail->next);
  return 0;
}

// Intersección de listas (intersect)
CDNode* list_intersection(CDNode* tail1, CDNode* tail2, Compare cmp){
  assert(tail1 != NULL && tail2 != NULL);
  CDNode* result = NULL;
  CDNode* current1 = tail1->next;
  do {
    CDNode* current2 = tail2->next;
    do{
      if(cmp(current1->data, current2->data) == 0){
        insert_end(&result, current1->data);
        break;
      }
      current2 = current2->next;
    } while(current2 != tail2->next);
    current1 = current1->next;
  } while(current1 != tail1->next);
  return result;
}

// Intercalar dos listas (interleave)
CDNode* list_interleave(CDNode* tail1, CDNode* tail2){
  assert(tail1 != NULL && tail2 != NULL);
  CDNode* result = NULL;
  CDNode* current1 = tail1->next;
  CDNode* current2 = tail2->next;
  do {
    insert_end(&result, current1->data);
    insert_end(&result, current2->data);
    current1 = current1->next;
    current2 = current2->next;
  } while(current1 != tail1->next && current2 != tail2->next);
  // insertar elementos sobrantes de las dos listas
  while(current1 != tail1->next){
    insert_end(&result, current1->data);
    current1 = current1->next;
  }
  while(current2 != tail2->next){
    insert_end(&result, current2->data);
    current2 = current2->next;
  }
  return result;
}

// Partición de lista
CDNode* list_partition(CDNode* tail){
  assert(tail != NULL);
  CDNode* slow = tail->next;
  CDNode* fast = tail->next;
  while(fast->next != tail && fast->next->next != tail){
    slow = slow->next;
    fast = fast->next->next;
  }
  // slow apunta al nodo anterior al inicio de la segunda mitad
  CDNode* second_half = slow->next;
  tail->next = second_half;
  second_half->prev = tail;
  return tail;
}

// Ordenar lista
void sort_list(CDNode** tail, Compare cmp){
  assert(*tail != NULL);
  CDNode *current, *start;
  int temp, swapped;
  do {
    current = *tail;
    swapped = 0;
    start = current->next;
    do {
      if(cmp(start->data, start->next->data) >= 0){
        int temp = start->data;
        start->data = start->next->data;
        start->next->data = temp;
        swapped = 1;
      }
      start = start->next;
    } while(start != current);
    current = current->next;
  } while(swapped);
}

// Insertar en posición correcta
void insert_correct_position(CDNode** tail, int element, Compare cmp){
  assert(*tail != NULL);
  // ordenamos la lista
  sort_list(tail, compare);
  if(cmp((*tail)->next->data, element) >= 0){
    insert_begin(tail, element);
    return;
  }
  CDNode* newNode = create_node(element);
  CDNode *current = (*tail)->next, *prev;
  do {
    prev = current;
    current = current->next;
  } while(current != (*tail)->next && cmp(current->data, element) < 0);
  prev->next = newNode;
  newNode->prev = prev;
  newNode->next = current;
  current->prev = newNode;
  if(prev == *tail) *tail = (*tail)->next;
}

// Eliminar todas las subsecuencias que suman cero
void delete_all_subsecuences_that_adds_zero(CDNode** tail);

// Filtrar elementos que cumplen un predicado
int predicate(int a){
  return a % 2 == 0;
}

CDNode* list_filter_1(CDNode* tail, Predicate p){
  CDNode* result = NULL;
  CDNode* current = tail->next;
  do {
    if(p(current->data)){
      insert_end(&result, current->data);
    }
    current = current->next;
  } while(current != tail->next);
  return result;
}

void list_filter_2(CDNode** tail, Predicate p){
  assert(*tail != NULL);
  CDNode* current = (*tail)->next;
  do {
    // si el nodo actual no cumple con el predicado, eliminarlo
    if(!p(current->data)){
      if(current == *tail)
        *tail = current->prev;
      if(current->prev != NULL)
        current->prev->next = current->next;
      if(current->next != NULL)
        current->next->prev = current->prev;
    }
    current = current->next;
  } while(current != (*tail)->next);
}

// QUEDA CHEQUEAR EL REVERSE_LIST
// void reverse_list(CircularDoublyLinkedList *list) {
//     if(list->head == NULL) {
//         printf("List is empty!\n");
//         return;
//     }
//     Node *temp = list->head;
//     Node *temp2 = list->tail;
//     for(int i = 0; i < list->size / 2; i++) {
//         int tempData = temp->data;
//         temp->data = temp2->data;
//         temp2->data = tempData;
//         temp = temp->next;
//         temp2 = temp2->prev;
//     }
// }


int main(){
  CDNode* tail = NULL;

  for(int i = 50; i>0; i-=10){
    insert_end(&tail, i);
  }
  
  reverse_list(tail);

  display_list(tail, DISPLAY_FORWARD);

  printf("List tail: %d\n", list_tail(tail));

  return 0;
}