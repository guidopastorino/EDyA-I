#include "slist.h"

Node *crear_nodo(int data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insertar_inicio(Node **head, int data){
  Node* newNode = crear_nodo(data);
  newNode->next = *head;
  *head = newNode;
}

void insertar_final(Node **head, int data){
  Node* newNode = crear_nodo(data);
  if(*head == NULL){
    *head = newNode;
  } else {
    Node* current = *head;
    while(current->next != NULL){
      current = current->next;
    }
    current->next = newNode;
  }
}

void insertar_posicion(Node **head, int pos, int data){
  if(pos == 0){
    insertar_inicio(head, data);
    return;
  }
  Node* newNode = crear_nodo(data);
  Node* current = *head;
  for(int i = 0; i<pos-1 && current != NULL; i++){
    current = current->next;
  }
  assert(current != NULL);
  newNode->next = current->next;
  current->next = newNode;
}

void eliminar_inicio(Node **head){
  assert(*head != NULL);
  Node* temp = *head;
  *head = (*head)->next;
  free(temp);
}

void eliminar_final(Node **head){
  assert(*head != NULL);
  if((*head)->next == NULL){
    eliminar_inicio(head);
    return;
  }
  Node* current = *head;
  while(current->next->next != NULL){
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
}

void eliminar_posicion(Node **head, int pos){
  assert(*head != NULL);
  if(pos == 0){
    eliminar_inicio(head);
    return;
  }
  Node* current = *head;
  Node* temp;
  for(int i = 0; i<pos-1 && current != NULL; i++){
    current = current->next;
  }
  assert(current != NULL && current->next != NULL);
  temp = current->next;
  current->next = current->next->next;
  free(temp);
}

void imprimir_lista(Node *head){
  Node* current = head;
  while(current != NULL){
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

void liberar_lista(Node *head){
  Node* current = head;
  while(current != NULL){
    Node* temp = head;
    current = current->next;
    free(temp);
  }
}

int slist_longitud(Node* head){
  Node* current = head;
  int len = 0;
  while(current != NULL){
    len++;
    current = current->next;
  }
  return len;
}

void slist_concatenar(Node** head1, Node* head2){
  if(*head1 == NULL){
    *head1 = head2;
    return;
  }
  Node* current = *head1;
  while(current->next != NULL){
    current = current->next;
  }
  current->next = head2;
}

int slist_contiene(Node* head, int el){
  Node* current = head;
  while(current != NULL){
    if(current->data == el) return 1;
    current = current->next;
  }
  return 0;
}

int slist_indice(Node* head, int el){
  Node* current = head;
  int i = 0;
  while(current != NULL){
    if(current->data == el) return i;
    i++;
    current = current->next;
  }
  return -1;
}

Node* slist_intersecar(Node* head1, Node* head2) {
  Node* result = NULL;
  Node* current = head1;
  while(current != NULL){
    if(slist_contiene(head2, current->data)){
      insertar_final(&result, current->data);
    }
    current = current->next;
  }
  return result;
}

// función de comparación
int compare(int a, int b){
  return (a == b) ? 0 : (a < b) ? -1 : 1;
}

Node* slist_intersecar_custom(Node* head1, Node* head2, int(*funcPtr)(int, int)){
  return NULL;
}

void slist_ordenar(Node** head, int(*funcPtr)(int, int)){
  assert(*head != NULL && (*head)->next != NULL);
  Node *current, *nextNode;
  int temp, swapped;
  do{
    current = *head;
    swapped = 0;
    while(current->next != NULL){
      nextNode = current->next;
      if(funcPtr(current->data, nextNode->data) > 0){
        temp = current->data;
        current->data = nextNode->data;
        nextNode->data = temp;
        swapped = 1;
      }
      current = current->next;
    }
  } while(swapped);
}

Node* slist_reverso(Node* head){
  Node* prev = NULL;
  Node* current = head;
  Node* next = NULL;
  while(current != NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

Node* slist_intercalar(Node* head1, Node* head2){
  Node* result = NULL;
  while(head1 != NULL && head2 != NULL){
    insertar_final(&result, head1->data);
    insertar_final(&result, head2->data);
    head1 = head1->next;
    head2 = head2->next;
  }
  // por si sobran nodos
  while(head1 != NULL){
    insertar_final(&result, head1->data);
    head1 = head1->next;
  }
  while(head2 != NULL){
    insertar_final(&result, head2->data);
    head2 = head2->next;
  }
  return result;
}

Node* slist_partir(Node* head){
  assert(head != NULL && head->next != NULL);
  Node* slowPtr = head;
  Node* fastPtr = head;
  while(fastPtr->next != NULL && fastPtr->next->next != NULL){
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  Node* secondHalf = slowPtr;
  slowPtr = NULL;
  return secondHalf;
}