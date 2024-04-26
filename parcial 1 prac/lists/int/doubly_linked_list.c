#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int (*Compare)(int, int);
typedef int (*Predicate)(int);

typedef enum { TRAVERSE_FORWARD, TRAVERSE_BACKWARD } Traversing;

typedef struct _DNode {
  int data;
  struct _DNode* prev;
  struct _DNode* next;
} DNode;

DNode* create_node(int data){
  DNode* newNode = (DNode*)malloc(sizeof(DNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

// Insertar al principio
void insert_begin(DNode** head, int data){
  DNode* newNode = create_node(data);
  if(*head == NULL){
    *head = newNode;
  } else {
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
  }
}

// Insertar al final
void insert_end(DNode** head, int data){
  DNode* newNode = create_node(data);
  if(*head == NULL){
    *head = newNode;
  } else {
    DNode* current = *head;
    while(current->next != NULL)
      current = current->next;
    current->next = newNode;
    newNode->prev = current;
  }
}

// Insertar en posición
void insert_pos(DNode** head, int pos, int data){
  assert(pos >= 0);
  if(pos == 0){
    insert_begin(head, data);
    return;
  }
  DNode* newNode = create_node(data);
  DNode* current = *head;
  for(int i = 0; i<pos-1 && current != NULL; i++){
    current = current->next;
  }
  assert(current != NULL);
  newNode->next = current->next;
  if(current->next != NULL){
    current->next->prev = newNode;
  }
  newNode->prev = current;
  current->next = newNode;
}

// Insertar en medio
void insert_middle(DNode** head, int data){
  if(*head == NULL){
    insert_begin(head, data);
  } else {
    DNode* prev = NULL;
    DNode* slow = *head;
    DNode* fast = *head;
    while(fast && fast->next){
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    DNode* newNode = create_node(data);
    if(prev){
      prev->next = newNode;
      newNode->prev = prev;
    }
    newNode->next = slow;
    slow->prev = newNode;
  }
}

// Eliminar al principio
void delete_begin(DNode** head){
  assert(*head != NULL);
  DNode* temp = *head;
  *head = (*head)->next;
  if(*head != NULL){
    (*head)->prev = NULL;
  }
  free(temp);
}

// Eliminar al final
void delete_end(DNode** head){
  assert(*head != NULL);
  if((*head)->next == NULL){
    delete_begin(head);
    return;
  }
  DNode* current = *head;
  while(current->next != NULL){
    current = current->next;
  }
  if(current->prev != NULL){
    current->prev->next = NULL;
  } else {
    *head = NULL;
  }
  free(current);
}

// Eliminar en posición
void delete_pos(DNode** head, int pos){
  assert(*head != NULL && pos >= 0);
  if(pos == 0){
    delete_begin(head);
    return;
  }
  DNode* current = *head;
  for(int i = 0; i<pos && current != NULL; i++)
    current = current->next;
  assert(current != NULL);
  current->prev->next = current->next;
  if(current->next)
    current->next->prev = current->prev;
  free(current);
}

// Eliminar en medio
void delete_mid(DNode** head){
  assert(*head != NULL);
  if((*head)->next == NULL){
    delete_begin(head);
    return;
  }
  DNode* slow = *head;
  DNode* fast = (*head)->next;
  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
  }
  if(slow->prev != NULL)
    slow->prev->next = slow->next;
  else
    *head = slow->prev;

  if(slow->next != NULL)
    slow->next->prev = slow->prev;

  free(slow);
}

// Mostrar lista
void display_list(DNode* head, Traversing direction){
  DNode* current = head;
  if(direction == TRAVERSE_FORWARD){
    while(current){
      printf("%d -> ", current->data);
      current = current->next;
    }
  } else {
    while(current && current->next)
      current = current->next;
    while(current != NULL){
      printf("%d -> ", current->data);
      current = current->prev;
    }
  }
  printf("NULL\n");
}

// Mediana de la lista
int list_median(DNode* head){
  if(head == NULL)
    return 0;

  DNode* slow = head;
  DNode* fast = head;
  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}

// Contiene elemento
int contains(DNode* head, int element){
  while(head){
    if(head->data == element) return 1;
    head = head->next;
  }
  return 0;
}

// comparacion
int compare(int a, int b){
  return (a == b) ? 0 : (a < b) ? -1 : 1;
}

// Intersección de listas
DNode* list_intersection(DNode* head1, DNode* head2, Compare cmp){
  DNode* result = NULL;
  for(DNode* node1 = head1; node1 != NULL; node1 = node1->next){
    if(!contains(node1->next, node1->data) && contains(head2, node1->data)) insert_end(&result, node1->data);
  }
  return result;
}

// Intercalar dos listas
DNode* list_intercale(DNode* head1, DNode* head2){
  DNode* result = NULL;
  while(head1 && head2){
    insert_end(&result, head1->data);
    insert_end(&result, head2->data);
    head1 = head1->next;
    head2 = head2->next;
  }
  while(head1){
    insert_end(&result, head1->data);
    head1 = head1->next;
  }
  while(head2){
    insert_end(&result, head2->data);
    head2 = head2->next;
  }
  return result;
}

// Partición de lista
DNode* list_partition(DNode* head){
  if(head == NULL){
    return NULL;
  }
  DNode* slow = head;
  DNode* fast = head;
  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
  }
  DNode* second_half = slow->next;
  // desconectar la primera mitad con la segunda mitad
  slow->next = NULL;
  return second_half;
}

// Ordenar lista
void sort_list(DNode** head, Compare cmp){
  DNode* current, *nextNode;
  int temp, swapped;
  do {
    current = *head;
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
  } while(swapped);
}

// Insertar en posición correcta
void insert_correct_position(DNode** head, int data, Compare cmp){
  assert(*head != NULL);
  // sort_list(head, cmp);
  if(*head == NULL || cmp((*head)->data, data) > 0){
    insert_begin(head, data);
    return;
  }
  DNode* prev = NULL;
  DNode* current = *head;
  while(current->next != NULL && cmp(current->data, data) <= 0){
    prev = current;
    current = current->next;
  }
  DNode* newNode = create_node(data);
  prev->next = newNode;
  newNode->next = current;
  current->prev = newNode;
  newNode->prev = prev;
}

// Revertir lista
DNode* reverse_list(DNode* head) {
  DNode* temp = NULL;
  DNode* current = head;
  while(current != NULL){
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
  if(temp != NULL)
    head = temp->prev;
  return head;
}

int main(){
  DNode* head = NULL;

  insert_end(&head, 50);
  insert_end(&head, 40);
  insert_end(&head, 30);
  insert_end(&head, 20);
  insert_end(&head, 60);
  insert_end(&head, -50);

  display_list(head, TRAVERSE_FORWARD);

  printf("Reversing:\n");

  DNode* reversed = reverse_list(head);

  display_list(reversed, TRAVERSE_FORWARD);
  display_list(reversed, TRAVERSE_BACKWARD);

  return 0;
}