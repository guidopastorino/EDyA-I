// LISTA SIMPLEMENTE ENLAZADA 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _SNode {
  int data;
  struct _SNode* next;
} SNode;

// función comparadora que toma dos enteros y retorna los mismos valores que strcmp
typedef int(*FuncVisitante)(int, int);

SNode* create_node(int data){
  SNode* newNode = (SNode*)malloc(sizeof(SNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insert_begin(SNode** head, int data){
  SNode* newNode = create_node(data);
  newNode->next = *head;
  *head = newNode;
}

void insert_end(SNode** head, int data){
  SNode* newNode = create_node(data);
  if(*head == NULL){
    *head = newNode;
  } else {
    SNode* current = *head;
    while(current->next != NULL){
      current = current->next;
    }
    current->next = newNode;
  }
}

void insert_position(SNode** head, int pos, int data){
  assert(pos >= 0);
  if(pos == 0){
    insert_begin(head, data);
    return;
  }
  SNode* newNode = create_node(data);
  SNode* current = *head;
  for(int i = 0; i<pos-1 && current != NULL; i++){
    current = current->next;
  }
  assert(current != NULL);
  newNode->next = current->next;
  current->next = newNode;
}

void insert_middle(SNode** head, int data){
  if(*head == NULL){
    insert_begin(head, data);
    return;
  }
  SNode* slow = *head;
  SNode* fast = *head;
  while(fast->next && fast->next->next){
    slow = slow->next;
    fast = fast->next->next;
  }
  SNode* newNode = create_node(data);
  newNode->next = slow->next;
  slow->next = newNode;
}

void delete_begin(SNode** head){
  assert(*head != NULL);
  SNode* temp = *head;
  *head = (*head)->next;
  free(temp);
}

void delete_end(SNode** head){
  assert(*head != NULL);
  if((*head)->next == NULL){
    delete_begin(head);
    return;
  }
  SNode* current = *head;
  while(current->next->next != NULL){
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
}

void delete_position(SNode** head, int pos){
  assert(*head != NULL && pos >= 0);
  if(pos == 0){
    delete_begin(head);
    return;
  }
  SNode* current = *head;
  SNode* temp;
  for(int i = 0; i<pos-1 && current != NULL; i++){
    current = current->next;
  }
  assert(current != NULL && current->next != NULL);
  temp = current->next; // nodo a eliminar
  current->next = current->next->next;
  free(temp);
}

void delete_middle(SNode** head){
  if((*head)->next == NULL){
    delete_begin(head);
    return;
  }
  SNode* prev = NULL;
  SNode* slow = *head;
  SNode* fast = *head;
  while(fast->next && fast->next->next){
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  // slow apunta al nodo
  SNode* temp = slow;
  prev->next = slow->next;
  free(temp);
}

void display_list(SNode* head){
  while(head != NULL){
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

int list_length(SNode* head){
  int count = 0;
  while(head != NULL){
    count++;
    head = head->next;
  }
  return count;
}

int list_median(SNode* head){
  SNode* slow = head;
  SNode* fast = head;
  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}

// nodos en comun (comparten sublista)
SNode* list_common_sublist(SNode* head1, SNode* head2){
  int len1 = list_length(head1);
  int len2 = list_length(head1);
  SNode* curr1 = head1;
  SNode* curr2 = head2;
  if(len1 > len2){
    for(int i = 0; i<len1-len2; i++){
      curr1 = curr1->next;
    }
  } else {
    for(int i = 0; i<len2-len1; i++){
      curr2 = curr2->next;
    }
  }
  while(curr1 && curr2){
    if(curr1 == curr2) return curr1;
    curr1 = curr1->next;
    curr2 = curr2->next;
  }
  return NULL;
}

// intercala dos listas
SNode* list_intercale(SNode* head1, SNode* head2){
  SNode* result = NULL;
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

int compare(int a, int b) {return (a == b) ? 0 : (a < b) ? -1 : 1;}

int list_contains(SNode* head, int element, FuncVisitante cmp){
  while(head){
    if(cmp(head->data, element) == 0) return 1;
    head = head->next;
  }
  return 0;
}

SNode* list_intersection(SNode* head1, SNode* head2, FuncVisitante cmp){
  SNode* result = NULL;
  while(head1){
    if(!list_contains(head1->next, head1->data, cmp) && list_contains(head2, head1->data, cmp)) insert_end(&result, head1->data);
    head1 = head1->next;
  }
  return result;
}

SNode* list_partition(SNode* head){
  SNode* slow = head;
  SNode* fast = head;
  while(fast->next && fast->next->next){
    slow = slow->next;
    fast = fast->next->next;
  }
  SNode* second_half = slow->next;
  slow->next = NULL;
  return second_half;
}

void sort_list(SNode** head, FuncVisitante cmp){
  assert(*head != NULL && (*head)->next != NULL);
  SNode *current, *nextNode;
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

// devuelve la lista ordenada y con el elemento en la posicion correcta
void insert_correct_position(SNode** head, int data, FuncVisitante cmp){
  // ordenamos la lista
  sort_list(head, cmp);
  if(head == NULL || cmp(data, (*head)->data) < 0){
    // insertamos al inicio el nuevo nodo
    insert_begin(head, data);
  }
  SNode* newNode = create_node(data);
  SNode* current = *head;
  SNode* prev = NULL;
  while(current && cmp(data, current->data) >= 0){
    prev = current;
    current = current->next;
  }
  newNode->next = current;
  prev->next = newNode;
}

void delete_all_subsecuences_that_adds_zero(SNode** head);

int main(){
  SNode* head = NULL;
  insert_end(&head, 50);
  insert_end(&head, 40);
  insert_end(&head, 30);
  insert_end(&head, 20);
  insert_end(&head, 10);
  insert_end(&head, 5);
  display_list(head);
  int (*cmp)(int, int) = &compare;
  insert_correct_position(&head, 35, cmp);
  display_list(head);

  return 0;
}