// LISTA DOBLEMENTE ENLAZADA 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum { DISPLAY_FORWARDS, DISPLAY_BACKWARDS } Traversing;

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

void insert_end(DNode** head, int data){
  DNode* newNode = create_node(data);
  if(*head == NULL){
    *head = newNode;
  } else {
    DNode* current = *head;
    while(current->next != NULL){
      current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
  }
}

void insert_position(DNode** head, int pos, int data){
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

void insert_middle(DNode** head, int data){
  if(*head == NULL){
    insert_begin(head, data);
    return;
  }
  DNode* prev = NULL;
  DNode* slow = *head;
  DNode* fast = *head;
  while(fast != NULL && fast->next != NULL){
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  DNode* newNode = create_node(data);
  prev->next = newNode;
  newNode->prev = prev;
  newNode->next = slow;
  slow->prev = newNode;
}

void delete_begin(DNode** head){
  assert(*head != NULL);
  DNode* temp = *head;
  *head = (*head)->next;
  if(*head != NULL){
    (*head)->next->prev = NULL;
  }
  free(temp);
}

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

void delete_position(DNode** head, int pos){
  assert(*head != NULL && pos >= 0);
  if(pos == 0){
    delete_begin(head);
    return;
  }
  DNode* current = *head;
  for(int i = 0; i<pos && current != NULL; i++){
    current = current->next;
  }
  assert(current != NULL);
  if(current->next != NULL){
    current->next->prev = current->prev;
  }
  current->prev->next = current->next;
  free(current);
}

void delete_middle(DNode** head){
  if((*head)->next == NULL){
    delete_begin(head);
    return;
  }
  DNode* prev = NULL;
  DNode* slow = *head;
  DNode* fast = *head;
  while(fast && fast->next){
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prev->next = slow->next;
  if(slow->next){
    slow->next->prev = prev;
  }
  free(slow);
}

int list_median(DNode* head){
  DNode* slow = head;
  DNode* fast = head;
  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}

void display(DNode* head, Traversing rec){
  DNode* current = head;
  if(rec == DISPLAY_FORWARDS){
    while(current != NULL){
      printf("%d -> ", current->data);
      current = current->next;
    }
  }
  if(rec == DISPLAY_BACKWARDS){
    while(current != NULL && current->next != NULL){
      current = current->next;
    }
    while(current != NULL){
      printf("%d -> ", current->data);
      current = current->prev;
    }
  }
  printf("NULL\n");
}


int main(){
  DNode* head = NULL;
  insert_end(&head, 10);
  insert_end(&head, 20);
  insert_end(&head, 30);
  display(head, DISPLAY_FORWARDS);
  insert_position(&head, 1, 80);
  display(head, DISPLAY_FORWARDS);
  insert_middle(&head, 44);
  display(head, DISPLAY_FORWARDS);
  delete_begin(&head);
  display(head, DISPLAY_FORWARDS);
  printf("After deleting middle: \n");
  delete_middle(&head);
  display(head, DISPLAY_FORWARDS);
  printf("%d\n", list_median(head));
  return 0;
}