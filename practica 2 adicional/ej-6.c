#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _SNode {
  char data;
  struct _SNode* next;
} SNode;

SNode* create_node(char data){
  SNode* newNode = (SNode*)malloc(sizeof(SNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insert_end(SNode** head, char data){
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

void display(SNode* head){
  SNode* current = head;
  while(current != NULL){
    printf("%c -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

SNode* reverse_list(SNode* head){
  SNode* prev = NULL;
  SNode* current = head;
  SNode* next = NULL;
  while(current != NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

void printLastNNodes(SNode* head, int n){
  if(n <= 0) {
    printf("No hay sufijo en común\n");
    return;
  }

  SNode* current = head;
  while(current != NULL && n--) current = current->next;

  SNode* mainPtr = head;
  while(current != NULL){
    mainPtr = mainPtr->next;
    current = current->next;
  }

  printf("Sufijo más largo en común: ");
  while(mainPtr != NULL){
    printf("%c ", mainPtr->data);
    mainPtr = mainPtr->next;
  }
  printf("\n");
}

void sufijo_mas_largo_comun(SNode* l1, SNode* l2){
  l1 = reverse_list(l1);
  l2 = reverse_list(l2);

  SNode *temp1 = l1, *temp2 = l2;
  int count = 0;
  while(temp1 != NULL && temp2 != NULL){
    if(temp1->data != temp2->data) break;
    count++;
    temp1 = temp1->next;
    temp2 = temp2->next;
  }

  l1 = reverse_list(l1);
  l2 = reverse_list(l2);

  printLastNNodes(l1, count);
}

int main(){
  SNode* l1 = NULL;
  SNode* l2 = NULL;

  char* str1 = "listening";
  char* str2 = "walking";

  for(int i = 0; str1[i] != '\0'; i++){
    insert_end(&l1, str1[i]);
  }

  for(int i = 0; str2[i] != '\0'; i++){
    insert_end(&l2, str2[i]);
  }

  display(l1);
  display(l2);

  sufijo_mas_largo_comun(l1, l2);

  return 0;
}