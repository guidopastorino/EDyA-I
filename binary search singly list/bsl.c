#include "bsl.h"

SNode* create_node(int data){
  SNode* newNode = (SNode*)malloc(sizeof(SNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
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

void display_list(SNode* head){
  SNode* current = head;
  while(current != NULL){
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

void free_list(SNode* head){
  SNode* current = head;
  while(current != NULL){
    SNode* temp = current;
    current = current->next;
    free(current);
  }
}

int list_length(SNode* head){
  int len = 0;
  while(head != NULL){
    len++;
    head = head->next;
  }
  return len;
}

SNode* get_node_at(SNode* head, int index){
  SNode* current = head;
  for(int i = 0; i<index; i++){
    if(current == NULL){
      return NULL;
    }
    current = current->next;
  }
  return current;
}

int binary_search(SNode* head, int element){
  int length = list_length(head);
  int low = 0, high = length - 1;
  while(low <= high){
    int mid = (low + high) / 2;
    SNode* mid_node = get_node_at(head, mid);
    if(mid_node == NULL){
      return -1;
    }
    if(mid_node->data == element){
      return mid;
    } else if(mid_node->data < element){
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}