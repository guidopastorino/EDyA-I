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
    free(temp);
  }
}

void delete_subsecuences_that_adds_zero(SNode** head) {
  SNode* current = *head;
  SNode* prev = NULL;
  while(current != NULL){
    SNode* temp = current;
    int sum = 0;
    while(temp != NULL){
      sum += temp->data;
      if(sum == 0){
        // si la subsecuencia empieza desde el *head
        if(prev == NULL){
          *head = temp->next;
          current = *head;
        } else {
          prev->next = temp->next;
          current = prev->next;
        }
        break;
      }
      temp = temp->next;
    }
    if(temp == NULL){
      temp = current;
      current = current->next;
    }
  }
}

int main(){
  int nums1[] = {6, -6, 8, 4, -12, 9, 8, -8};
  int nums2[] = {4, 6, -10, 8, 9, 10, -19, 10, -18, 20, 25};

  SNode* head1 = NULL;
  SNode* head2 = NULL;

  // Adding nodes
  for(int i = 0; i<sizeof(nums1)/sizeof(nums1[0]); i++){
    insert_end(&head1, nums1[i]);
  }

  for(int i = 0; i<sizeof(nums2)/sizeof(nums2[0]); i++){
    insert_end(&head2, nums2[i]);
  }

  display_list(head1); // 6 -> -6 -> 8 -> 4 -> -12 -> 9 -> 8 -> -8 -> NULL
  display_list(head2); // 4 -> 6 -> -10 -> 8 -> 9 -> 10 -> -19 -> 10 -> -18 -> 20 -> 25 -> NULL

  delete_subsecuences_that_adds_zero(&head1);
  delete_subsecuences_that_adds_zero(&head2);

  display_list(head1); // NULL
  display_list(head2); // 20 -> 25 -> NULL

  free_list(head1);
  free_list(head2);

  return 0;
}