// LISTA DOBLE CIRCULAR ENLAZADA 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Ways to traverse the list
typedef enum { TRAVERSE_FORWARD, TRAVERSE_BACKWARD } Traversing;

// Functions type alias
typedef int (*Predicate)(int);

// Struct that represents a node of the list
typedef struct _CDNode {
  int data;
  struct _CDNode* prev;
  struct _CDNode* next;
} CDNode;

CDNode* create_node(int data){
  CDNode* newNode = (CDNode*)malloc(sizeof(CDNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->prev = newNode;
  newNode->next = newNode;
  return newNode;
}

CDNode* insert_begin(CDNode* tail, int data){
  CDNode* newNode = create_node(data);
  if(tail == NULL){
    tail = newNode;
  } else {
    CDNode* temp = tail->next;
    newNode->next = temp;
    newNode->prev = tail;
    temp->prev = newNode;
    tail->next = newNode;
  }
  return tail;
}

CDNode* insert_end(CDNode* tail, int data){
  CDNode* newNode = create_node(data);
  if(tail == NULL){
    tail = newNode;
  } else {
    CDNode* temp = tail->next;
    newNode->next = temp;
    newNode->prev = tail;
    temp->prev = newNode;
    tail->next = newNode;
    tail = newNode;
  }
  return tail;
}

CDNode* insert_position(CDNode* tail, int pos, int data){
  assert(tail != NULL && pos >= 0);
  if(pos == 0){
    tail = insert_begin(tail, data);
    return tail;
  }
  CDNode* current = tail->next;
  for(int i = 0; i<pos-1 && current != tail; i++){
    current = current->next;
  }
  CDNode* newNode = create_node(data);
  // el nodo actual (current) está un nodo anterior al nodo que queremos colocar
  newNode->next = current->next;
  current->next = newNode;
  newNode->prev = current;
  newNode->next->prev = newNode;
  if(current == tail) tail = tail->next;
  return tail;
}

CDNode* insert_middle(CDNode* tail, int data){
  if(tail == NULL){
    tail = insert_begin(tail, data);
    return tail;
  }
  CDNode* slow = tail->next;
  CDNode* fast = tail->next;
  while(fast != tail && fast->next != tail){
    slow = slow->next;
    fast = fast->next->next;
  }
  CDNode* newNode = create_node(data);
  newNode->prev = slow;
  newNode->next = slow->next;
  slow->next->prev = newNode;
  slow->next = newNode;
  if(slow == tail) tail = slow->next;
  return tail;
}

CDNode* delete_begin(CDNode* tail){
  assert(tail != NULL);
  if(tail == tail->next){
    free(tail);
    tail = NULL;
  } else {
    CDNode* temp = tail->next;
    tail->next = temp->next;
    temp->next->prev = tail;
    free(temp);
  }
  return tail;
}

CDNode* delete_end(CDNode* tail){
  assert(tail != NULL);
  if(tail == tail->next){
    free(tail);
    tail = NULL;
  } else {
    CDNode* temp = tail;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    tail = temp->prev;
    free(temp);
  }
  return tail;
}

CDNode* delete_position(CDNode* tail, int pos){
  assert(tail != NULL);
  if(pos == 0){
    tail = delete_begin(tail);
    return tail;
  }
  CDNode* current = tail->next;
  for(int i = 0; i<pos && current != tail; i++){
    current = current->next;
  }
  CDNode* temp = current;
  current->prev->next = current->next;
  current->next->prev = current->prev;
  if(current == tail) tail = current->prev;
  free(current);
  return tail;
}

CDNode* delete_middle(CDNode* tail){
  assert(tail != NULL);
  if(tail == tail->next){
    free(tail);
    tail = NULL;
    return tail;
  }
  CDNode* slow = tail->next;
  CDNode* fast = tail->next;
  while(fast != tail && fast->next != tail){
    slow = slow->next;
    fast = fast->next->next;
  }
  CDNode* temp = slow;
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  if(temp == tail) tail = temp->prev;
  free(temp);
  return tail;
}

CDNode* display_list(CDNode* tail, Traversing direction){
  if(tail == NULL){
    printf("NULL\n");
  } else {
    if(direction == TRAVERSE_FORWARD){
      CDNode* current = tail->next;
      do{
        printf("%d ", current->data);
        current = current->next;
      }while(current != tail->next);
      printf("\n");
    } else if(direction == TRAVERSE_BACKWARD) {
      CDNode* current = tail;
      do{
        printf("%d ", current->data);
        current = current->prev;
      }while(current != tail);
      printf("\n");
    } else {
      printf("Dirección inválida\n");
    }
  }
}

int list_length(CDNode* tail){
  if(tail == NULL) return 0;
  CDNode* current = tail->next;
  int len = 0;
  do {
    len++;
    current = current->next;
  } while(current != tail->next);
  return len;
}

CDNode* list_median(CDNode* tail);

CDNode* list_partition(CDNode* tail);

CDNode* list_intercale(CDNode* tail1, CDNode* tail2);

CDNode* list_intersection(CDNode* tail1, CDNode* tail2);

CDNode* list_filter(CDNode* tail, Predicate p);

int main(){
  CDNode* tail = NULL;
  tail = insert_begin(tail, 10);
  tail = insert_middle(tail, 20);
  tail = insert_middle(tail, 30);
  tail = insert_middle(tail, 40);
  tail = insert_middle(tail, 50);
  
  display_list(tail, TRAVERSE_FORWARD);

  CDNode* partition = list_partition(tail);
  display_list(partition, TRAVERSE_FORWARD);

  return 0;
}