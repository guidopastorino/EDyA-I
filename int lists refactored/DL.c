#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
  assert(pos >= 1);
  if(pos == 1){
    insert_begin(head, data);
  } else {
    DNode* newNode = create_node(data);
    DNode* current = *head;
    for(int i = 1; i<pos-1 && current != NULL; i++){
      current = current->next;
    }
    assert(current != NULL);
    newNode->next = current->next;
    if(current->next != NULL){
      current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
  }
}

void insert_middle(DNode** head, int data){
  if(*head == NULL){
    insert_begin(head, data);
  } else {
    DNode* slow = *head;
    DNode* fast = *head;
    while(fast && fast->next){
      fast = fast->next->next;
      if(fast != NULL){
        slow = slow->next;
      }
    }
    DNode* newNode = create_node(data);
    // 'slow' apunta al nodo previo de insercion
    newNode->prev = slow;
    newNode->next = slow->next;
    if(slow->next != NULL)
      slow->next->prev = newNode;
    slow->next = newNode;
  }
}

void delete_begin(DNode** head){
  assert(*head != NULL);
  DNode* temp = *head;
  *head = (*head)->next;
  if(*head != NULL){
    (*head)->prev = NULL;
  }
  free(temp);
}

void delete_end(DNode** head){
  assert(*head != NULL);
  if((*head)->next == NULL){
    delete_begin(head);
  } else {
    DNode* current = *head;
    while(current->next != NULL)
      current = current->next;
    if(current->prev != NULL){
      current->prev->next = NULL;
    } else {
      *head = NULL;
    }
    free(current);
  }
}

void delete_position(DNode** head, int pos){
  assert(*head != NULL);
  if(pos == 1){
    delete_begin(head);
  } else {
    DNode* current = *head;
    for(int i = 1; i<pos && current != NULL; i++){
      current = current->next;
    }
    assert(current != NULL);
    // current apunta al nodo que vamos a eliminar
    current->prev->next = current->next;
    if(current->next)
      current->next->prev = current->prev;
    free(current);
  }
}

void delete_middle(DNode** head){
  assert(*head != NULL);
  if((*head)->next == NULL){
    delete_begin(head);
  } else {
    DNode* prev = NULL;
    DNode* slow = *head;
    DNode* fast = *head;
    while(fast && fast->next){
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = slow->next;
    if(slow->next)
      slow->next->prev = prev;
    free(slow);
  }
}

void reverse_list(DNode** head){
  assert(*head != NULL && (*head)->next != NULL);
  DNode* current = *head;
  DNode* temp;
  while(current != NULL){
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
  if(temp != NULL)
    *head = temp->prev;
}

void display(DNode* head){
  while(head != NULL){
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

int main(){
  DNode* head = NULL;
  for(int i = 10; i<=50; i+=10)
    insert_end(&head, i);
  
  display(head);
  delete_middle(&head);
  display(head);
  reverse_list(&head);
  display(head);


  return 0;
}