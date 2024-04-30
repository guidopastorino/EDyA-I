#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _SNode {
  int data;
  struct _SNode* next;
} SNode;

SNode* initialize_list(){
  return NULL;
}

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
  assert(pos >= 1);
  if(pos == 1){
    insert_begin(head, data);
  } else {
    SNode* newNode = create_node(data);
    SNode* current = *head;
    for(int i = 1; i<pos-1 && current != NULL; i++){
      current = current->next;
    }
    if(current == NULL){
      printf("Position out of range\n");
      exit(EXIT_FAILURE);
    }
    newNode->next = current->next;
    current->next = newNode;
  }
}

void insert_middle(SNode** head, int data){
  if(*head == NULL){
    insert_begin(head, data);
  } else {
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
  } else {
    SNode* current = *head;
    while(current->next->next != NULL){
      current = current->next;
    }
    free(current->next);
    current->next = NULL;
  }
}

void delete_position(SNode** head, int pos){
  assert(*head != NULL && pos >= 1);
  if(pos == 1){
    delete_begin(head);
  } else {
    SNode* current = *head;
    SNode* temp;
    for(int i = 1; i<pos-1 && current != NULL; i++){
      current = current->next;
    }
    assert(current != NULL && current->next != NULL);
    temp = current->next;
    current->next = current->next->next;
    free(temp);
  }
}

void delete_middle(SNode** head){
  assert(*head != NULL);
  if((*head)->next == NULL){
    delete_begin(head);
  } else {
    SNode* prev = NULL;
    SNode* slow = *head;
    SNode* fast = *head;
    while(fast && fast->next){
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    // si prev es NULL, el nodo a eliminar es el primer nodo
    if(prev == NULL){
      *head = slow->next;
    } else {
      prev->next = slow->next;
    }
    free(slow);
  }
}

void reverse_list(SNode** head){
  assert(*head != NULL && (*head)->next != NULL);
  SNode* prev = NULL;
  SNode* current = *head;
  SNode* next = NULL;
  while(current != NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}

void display_list(SNode* head){
  while(head != NULL){
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

int main(){
  SNode* head = initialize_list();

  for(int i = 10; i<=20; i+=10)
    insert_end(&head, i);

  display_list(head);
  insert_middle(&head, 85);
  display_list(head);

  return 0;
}