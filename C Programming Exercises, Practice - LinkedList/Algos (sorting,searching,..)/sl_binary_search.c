#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _SNode {
  int data;
  struct _SNode* next;
} SNode;

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
  while(head != NULL){
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
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
    current = current->next;
  }
  return current;
}

int binary_search_list(SNode* head, int element){
  int low = 0, high = list_length(head) - 1;
  while(low <= high){
    int mid = (low + high) / 2;
    SNode* midNode = get_node_at(head, mid);
    if(midNode == NULL) return -1;
    if(midNode->data == element){
      return mid;
    } else if(midNode->data < element){
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}


int main(){
  SNode* head = NULL;
  for(int i = 10; i<=50; i+=10){
    insert_end(&head, i);
  }

  display_list(head);

  int element = 10;
  int index = binary_search_list(head, element);
  printf("Index: %d\n", index);

  return 0;
}