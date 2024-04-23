// SINGLY GENERAL LINKED LIST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef void (*PrintData)(void*);

typedef struct _GNode {
  void* data;
  struct _GNode* next;
} GNode;

GNode* initialize_list(){
  return NULL;
}

GNode* create_nodo(void* data, size_t data_size){
  GNode* newNode = (GNode*)malloc(sizeof(GNode));
  assert(newNode != NULL);
  newNode->data = malloc(data_size);
  assert(newNode->data != NULL);
  memcpy(newNode->data, data, data_size);
  newNode->next = NULL;
  return newNode;
}

GNode* insert_begin(GNode* head, void* data, size_t data_size){
  GNode* newNode = create_nodo(data, data_size);
  newNode->next = head;
  head = newNode;
  return head;
}

GNode* insert_end(GNode* head, void* data, size_t data_size){
  GNode* newNode = create_nodo(data, data_size);
  if(head == NULL){
    head = newNode;
  } else {
    GNode* current = head;
    while(current->next != NULL){
      current = current->next;
    }
    current->next = newNode;
  }
  return head;
}

void print_double(void* data){
  printf("%f -> ", *(double*)data);
}

void print_char(void* data){
  printf("%c -> ", *(char*)data);
}

void print_float(void* data){
  printf("%f -> ", *(float*)data);
}

void print_int(void* data){
  printf("%d -> ", *(int*)data);
}

void print_string(void* data){
  printf("%s -> ", (char*)data);
}

void print_list(GNode* head, PrintData f){
  while(head != NULL){
    (*f)(head->data);
    head = head->next;
  }
  printf("NULL\n");
}

GNode* destroy_list(GNode* head){
  while(head != NULL){
    GNode* temp = head;
    head = head->next;
    free(temp);
  }
  head = NULL;
  return head;
}

int main(){
  GNode* head = initialize_list();
  for(int i = 50; i>0; i-=10)
    head = insert_begin(head, &i, sizeof(int));

  char* cadena = "Hola Mundo";
  head = insert_begin(head, cadena, strlen(cadena) + 1); // pasamos la longitud y le agregamos + 1 para el caracter nulo '\0'
  
  char ch = 'Z';
  head = insert_end(head, &ch, sizeof(char));

  float float_num = 3.14;
  head = insert_end(head, &float_num, sizeof(float));
  double double_num = 123.456;
  head = insert_begin(head, &double_num, sizeof(double));

  print_double(head->data);
  print_string(head->next->data);
  print_int(head->next->next->data);
  print_int(head->next->next->next->data);
  print_int(head->next->next->next->next->data);
  print_int(head->next->next->next->next->next->data);
  print_int(head->next->next->next->next->next->next->data);
  print_char(head->next->next->next->next->next->next->next->data);
  print_list(head->next->next->next->next->next->next->next->next, print_float);

  // List:
  // 123.456000 -> Hola Mundo -> 10 -> 20 -> 30 -> 40 -> 50 -> Z -> 3.140000 -> NULL

  head = destroy_list(head);
  print_list(head, print_double); // NULL

  return 0;
}