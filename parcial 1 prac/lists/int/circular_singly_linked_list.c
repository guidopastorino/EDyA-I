// circular singly linked list
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int (*Compare)(int, int);

typedef struct _CSNode {
  int data;
  struct _CSNode* next;
} CSNode;

// Crear nodo
CSNode* create_node(int data){
  CSNode* newNode = (CSNode*)malloc(sizeof(CSNode));
  if(newNode == NULL){
    printf("Error de asignación de memoria al nuevo nodo\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->next = newNode;
  return newNode;
}

// Insertar al principio
void insert_begin(CSNode** tail, int data){
  CSNode* newNode = create_node(data);
  if(*tail == NULL){
    *tail = newNode;
  } else {
    newNode->next = (*tail)->next;
    (*tail)->next = newNode;
  }
}

// Insertar al final
void insert_end(CSNode** tail, int data){
  CSNode* newNode = create_node(data);
  if(*tail == NULL){
    *tail = newNode;
  } else {
    newNode->next = (*tail)->next;
    (*tail)->next = newNode;
    *tail = newNode;
  }
}

// Insertar en posición
void insert_position(CSNode** tail, int pos, int data){
  assert(pos >= 0);
  if(pos == 0){
    insert_begin(tail, data);
    return;
  }
  CSNode* current = (*tail)->next;
  for(int i = 0; i<pos-1; i++){
    current = current->next;
    // si current recorrió la lista completa, no se ha podido encontrar la posición de insercion exacta
    if(current == (*tail)->next){
      printf("Posición fuera de rango\n");
      return;
    }
  }
  // current apunta al nodo anterior de la posicion que queremos insertar
  CSNode* newNode = create_node(data);
  newNode->next = current->next;
  current->next = newNode;
  if(current == *tail) *tail = (*tail)->next; // si current es igual al tail, actualizamos el tail al siguiente
}

// Insertar en medio
void insert_middle(CSNode** tail, int data) {
  if (*tail == NULL) {
    // Lista vacía: Crear nuevo nodo y asignarlo a head y tail
    insert_begin(tail, data);
  } else {
    // Lista no vacía: Encontrar el nodo del medio, insertar nuevo nodo después y actualizar tail
    CSNode* slow = (*tail)->next;
    CSNode* fast = (*tail)->next;

    while (fast->next != (*tail)->next && fast->next->next != (*tail)->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    CSNode* nuevoNodo = create_node(data);
    nuevoNodo->next = slow->next;
    slow->next = nuevoNodo;

    // Actualizar tail si el nuevo nodo se inserta al final
    if (slow == *tail) {
      *tail = nuevoNodo;
    }
  }
}

// Eliminar al principio
void delete_begin(CSNode** tail){
  assert(*tail != NULL);
  if((*tail)->next == *tail){
    free(*tail);
    *tail = NULL;
  } else {
    CSNode* temp = (*tail)->next;
    (*tail)->next = (*tail)->next->next;
    free(temp);
  }
}

// Eliminar al final
void delete_end(CSNode** tail){
  assert(*tail != NULL);
  if((*tail)->next == *tail){
    free(*tail);
    *tail = NULL;
  } else {
    CSNode* current = (*tail)->next;
    while(current->next != *tail){
      current = current->next;
    }
    CSNode* temp = *tail;
    current->next = (*tail)->next;
    *tail = current;
    free(temp);
  }
}

// Eliminar en posición
void delete_position(CSNode** tail, int pos){
  assert(*tail != NULL && pos >= 0);
  if(pos == 0){
    delete_begin(tail);
  } else {
    CSNode* current = (*tail)->next;
    for(int i = 0; i<pos-1; i++){
      current = current->next;
      if(current == (*tail)->next){
        printf("Position out of range\n");
        exit(EXIT_FAILURE);
      }
    }
    // current apunta al nodo anterior que queremos eliminar
    CSNode* temp = current->next;
    current->next = current->next->next;
    if(temp == *tail) *tail = current;
  }
}

// Eliminar en medio
void delete_middle(CSNode** tail){
  assert(*tail != NULL);
  if((*tail)->next == *tail){
    delete_begin(tail);
  } else {
    CSNode* prev = NULL;
    CSNode* slow = (*tail)->next;
    CSNode* fast = (*tail)->next;
    while(fast->next != (*tail)->next && fast->next->next != (*tail)->next){
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    // slow apunta al nodo que vamos a eliminar y prev al anterior
    CSNode* temp = slow;
    if(prev == NULL){
      (*tail)->next = slow->next;
    } else {
      prev->next = slow->next;
    }
    if(slow == *tail) *tail = prev;
    free(temp);
  }
}

// Mostrar lista
void display_list(CSNode* tail){
  if(tail == NULL){
    printf("NULL\n");
  } else {
    CSNode* current = tail->next;
    do {
      printf("%d ", current->data);
      current = current->next;
    } while(current != tail->next);
    printf("\n");
  }
}

// Retorna el tail (ultimo nodo)
int list_tail(CSNode* tail){
  if(tail == NULL){
    printf("La lista está vacía\n");
    exit(EXIT_FAILURE);
  } else {
    return tail->data;
  }
}

// Mediana de la lista
int list_median(CSNode* tail){
  assert(tail != NULL);
  CSNode* slow = tail->next;
  CSNode* fast = tail->next;
  while(fast->next != tail->next && fast->next->next != tail->next){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}

int compare(int a, int b) {return (a == b) ? 0 : (a < b) ? -1 : 1;}

// Contiene elemento
int contains(CSNode* tail, int element, Compare cmp){
  CSNode* current = tail->next;
  do {
    if(cmp(current->data, element) == 0) return 1;
    current = current->next;
  } while(current != tail->next);
  return 0;
}

// Intersección de listas
CSNode* list_intersection(CSNode* tail1, CSNode* tail2, Compare cmp){
  assert(tail1 != NULL && tail2 != NULL);
  CSNode* result = NULL;
  CSNode* current1 = tail1->next;
  do {
    CSNode* current2 = tail2->next;
    do {
      if(cmp(current1->data, current2->data) == 0){
        insert_end(&result, current1->data);
        break;
      }
      current2 = current2->next;
    }while(current2 != tail2->next);
    current1 = current1->next;
  } while(current1 != tail1->next);
  return result;
}

// Intercalar dos listas
CSNode* interleave_lists(CSNode* tail1, CSNode* tail2) {
  assert(tail1 != NULL && tail2 != NULL);
  CSNode* result = NULL;
  CSNode* current1 = tail1->next;
  CSNode* current2 = tail2->next;
  do {
    insert_end(&result, current1->data);
    insert_end(&result, current2->data);
    current1 = current1->next;
    current2 = current2->next;
  } while(current1 != tail1->next && current2 != tail2->next);
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
CSNode* list_partition(CSNode* tail) {
  if(tail == NULL) return NULL;
  CSNode* slow = tail->next;
  CSNode* fast = tail->next;
  while(fast->next != tail && fast->next->next != tail){
    slow = slow->next;
    fast = fast->next->next;
  }
  CSNode* second_half = slow->next;
  tail->next = second_half;
  return tail;
}

// Ordenar lista
void sort_list(CSNode** tail, Compare cmp) {
  assert(*tail != NULL);
  CSNode *current, *start;
  int temp, swapped;
  do {
    current = *tail;
    swapped = 0;
    start = current->next;
    do {
      if(cmp(start->data, start->next->data) >= 0){
        temp = start->data;
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
void insert_correct_position(CSNode** tail, int data, Compare cmp){
  assert(*tail != NULL);
  sort_list(tail, cmp);
  if(cmp((*tail)->data, data) <= 0){
    insert_begin(tail, data);
    return;
  }
  CSNode* prev = NULL;
  CSNode* current = (*tail)->next;
  do {
    prev = current;
    current = current->next;
  } while(current != (*tail)->next && cmp(current->data, data) <= 0);
  CSNode* newNode = create_node(data);
  prev->next = newNode;
  newNode->next = current;
  if(prev == *tail) *tail = (*tail)->next;
}

// Eliminar todas las subsecuencias que suman cero


// Filtrar elementos que cumplen un predicado


// Revertir lista
void reverse(CSNode** tail){
  CSNode* prev = NULL;
  CSNode* curr = (*tail)->next;
  CSNode* next = curr->next;
  while(curr != *tail){
    prev = curr;
    curr = next;
    next = curr->next;
    curr->next = prev; 
  }
  *tail = next;
  (*tail)->next = curr;
}

int main(){
  CSNode* tail = NULL;

  for(int i = 50; i>0; i-=10){
    insert_end(&tail, i);
  }

  display_list(tail);
  reverse(&tail);
  display_list(tail);

  printf("Tail: %d\n", list_tail(tail));

  return 0;
}