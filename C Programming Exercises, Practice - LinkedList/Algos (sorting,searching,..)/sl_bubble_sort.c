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

void swap(SNode* node1, SNode* node2){
  int temp = node1->data;
  node1->data = node2->data;
  node2->data = temp;
}

void bubble_sort_list(SNode** head){
  int len = list_length(*head);
  for(int i = 0; i<len-1; i++){
    for(int j = 0; j<len-i-1; j++){
      SNode* node1 = get_node_at(*head, j);
      SNode* node2 = get_node_at(*head, j + 1);
      if(node1->data > node2->data){
        swap(node1, node2);
      }
    }
  }
}

int main(){
  SNode* head = NULL;
  insert_end(&head, 90);
  insert_end(&head, 80);
  insert_end(&head, 56);
  insert_end(&head, 70);
  insert_end(&head, 88);
  insert_end(&head, 101);
  insert_end(&head, 45);
  insert_end(&head, 20);
  insert_end(&head, 21);
  insert_end(&head, 19);

  display_list(head); // 90 -> 80 -> 56 -> 70 -> 88 -> 101 -> 45 -> 20 -> 21 -> 19 -> NULL

  bubble_sort_list(&head);

  display_list(head); // 19 -> 20 -> 21 -> 45 -> 56 -> 70 -> 80 -> 88 -> 90 -> 101 -> NULL

  return 0;
}