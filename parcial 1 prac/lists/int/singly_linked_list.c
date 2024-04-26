// Lista simple
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int (*Predicate)(int);
typedef int (*Compare)(int, int);

typedef struct _SNode {
  int data;
  struct _SNode* next;
} SNode;

// Crear nodo
SNode* create_node(int data){
  SNode* newNode = (SNode*)malloc(sizeof(SNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Insertar al principio
SNode* insert_begin(SNode* head, int data){
  SNode* newNode = create_node(data);
  newNode->next = head;
  head = newNode;
  return head;
}

// Insertar al final
SNode* insert_end(SNode* head, int data){
  SNode* newNode = create_node(data);
  if(head == NULL){
    head = newNode;
  } else {
    SNode* current = head;
    while(current->next != NULL){
      current = current->next;
    }
    current->next = newNode;
  }
  return head;
}

// Insertar en posición
SNode* insert_position(SNode* head, int pos, int data){
  assert(pos >= 0);
  if(pos == 0){
    head = insert_begin(head, data);
    return head;
  }
  SNode* current = head;
  for(int i = 0; i<pos-1 && current != NULL; i++){
    current = current->next;
  }
  assert(current != NULL);
  SNode* newNode = create_node(data);
  newNode->next = current->next;
  current->next = newNode;
  return head;
}

// Insertar en medio
SNode* insert_middle(SNode* head, int data){
  if(head == NULL){
    head = insert_begin(head, data);
    return head;
  }
  SNode* prev = NULL;
  SNode* slow = head;
  SNode* fast = head;
  while(fast && fast->next){
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  SNode* newNode = create_node(data);
  // prev apunta al nodo anterior al de insertar
  prev->next = newNode;
  newNode->next = slow;
  return head;
}

// Eliminar al principio
SNode* delete_begin(SNode* head){
  assert(head != NULL);
  SNode* temp = head;
  head = head->next;
  free(temp);
  return head;
}

// Eliminar al final
SNode* delete_end(SNode* head){
  assert(head != NULL);
  if(head->next == NULL){
    head = delete_begin(head);
  } else {
    SNode* current = head;
    while(current->next->next != NULL){
      current = current->next;
    }
    free(current->next);
    current->next = NULL;
  }
  return head;
}

// Eliminar en posición
SNode* delete_position(SNode* head, int pos){
  assert(pos >= 0 && head != NULL);
  if(pos == 0){
    head = delete_begin(head);
  } else {
    SNode* current = head;
    SNode* temp;
    for(int i = 0; i<pos-1 && current != NULL; i++){
      current = current->next;
    }
    assert(current != NULL && current->next != NULL);
    temp = current->next;
    current->next = current->next->next;
    free(temp);
  }
  return head;
}

// Eliminar en medio
SNode* delete_middle(SNode* head){
  assert(head != NULL);
  if(head->next == NULL){
    head = delete_begin(head);
  } else {
    SNode* prev = NULL;
    SNode* slow = head;
    SNode* fast = head;
    while(fast && fast->next){
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    // slow es el nodo a eliminar
    prev->next = slow->next;
    free(slow);
  }
  return head;
}

// Mostrar lista
void display_list(SNode* head){
  while(head != NULL){
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

// Mediana de la lista
int list_median(SNode* head){
  SNode* slow = head;
  SNode* fast = head;
  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}

// Contiene elemento
int contains(SNode* head, int element, Compare cmp){
  while(head != NULL){
    if(cmp(head->data, element) == 0) return 1;
    head = head->next;
  }
  return 0;
}

int compare(int a, int b){
  return (a == b) ? 0 : (a < b) ? -1 : 1;
}

// Intersección de listas
SNode* list_intersection(SNode* head1, SNode* head2, Compare cmp){
  SNode* result = NULL;
  for(SNode* node1 = head1; node1 != NULL; node1 = node1->next){
    if(!contains(node1->next, node1->data, cmp) && contains(head2, node1->data, cmp))
      result = insert_end(result, node1->data);
  }

  return result;
}

// Intercalar dos listas
SNode* list_intercale(SNode* head1, SNode* head2){
  SNode* result = NULL;
  while(head1 && head2){
    result = insert_end(result, head1->data);
    result = insert_end(result, head2->data);
    head1 = head1->next;
    head2 = head2->next;
  }
  while(head1){
    result = insert_end(result, head1->data);
    head1 = head1->next;
  }
  while(head2){
    result = insert_end(result, head2->data);
    head2 = head2->next;
  }
  return result;
}

// Partición de lista
SNode* list_partition(SNode* head){
  assert(head != NULL && head->next != NULL);
  SNode* prev = NULL;
  SNode* slow = head;
  SNode* fast = head;
  while(fast && fast->next){
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  // Ahora slow apunta al inicio de la segunda mitad
  // Desconectamos las dos mitades
  if(prev) prev->next = NULL;
  return slow;
}

// Ordenar lista
SNode* sort_list(SNode* head, Compare cmp){
  assert(head != NULL && head->next != NULL);
  SNode* current;
  SNode* nextNode;
  int temp, swapped;
  do {
    current = head;
    swapped = 0;
    while(current->next != NULL){
      nextNode = current->next;
      if(cmp(current->data, nextNode->data) > 0){
        temp = current->data;
        current->data = nextNode->data;
        nextNode->data = temp;
        swapped = 1;
      }
      current = current->next;
    }
  }while(swapped);
  return head;
}

// Insertar en posición correcta
SNode* insert_correct_position(SNode* head, int data, Compare cmp){
  assert(head != NULL);
  // Ordenamos la lista (por si la pasan desordenada)
  head = sort_list(head, compare);

  // verificamos si hay que insertarlo al inicio
  if(head->next == NULL || cmp(data, head->data) < 0){
    head = insert_begin(head, data);
    return head;
  }

  // buscamos la posicion correcta e insertamos el nodo
  SNode* newNode = create_node(data);
  SNode* current = head;
  SNode* prev = NULL;
  while(current && cmp(data, current->data) >= 0){
    prev = current;
    current = current->next;
  }
  newNode->next = current;
  prev->next = newNode;

  return head;
}

// Eliminar todas las subsecuencias que suman cero
SNode* delete_all_subsecuences_that_adds_zero(SNode* head){
  assert(head != NULL);
  SNode* prev = NULL;
  SNode* current = head;
  while(current != NULL){
    SNode* temp = current;
    int sum = 0;
    while(temp != NULL){
      sum += temp->data;
      if(sum == 0){
        if(prev == NULL){
          head = head->next;
          current = head;
        } else {
          prev->next = temp->next;
          current = prev->next;
        }
        break;
      }
      temp = temp->next;
    }
    if(temp == NULL){
      prev = current;
      current = current->next;
    }
  }
  return head;
}

int predicate(int data){
  return (data % 2) == 0;
}

// Filtrar elementos que cumplen un predicado
SNode* filter_elements(SNode* head, Predicate p){
  SNode* result = NULL;
  while(head != NULL){
    if(p(head->data)){
      result = insert_end(result, head->data);
    }
    head = head->next;
  }
  return result;
}

// Revertir lista
SNode* reverse_list(SNode* head){
  assert(head != NULL);
  SNode* prev = NULL;
  SNode* current = head;
  SNode* next = NULL;
  while(current != NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

int main(){
  SNode* head = NULL;

  for(int i = 10; i<=50; i+=10){
    head = insert_end(head, i);
  }
  display_list(head);

  SNode* list = reverse_list(head);

  display_list(list);

  return 0;
}