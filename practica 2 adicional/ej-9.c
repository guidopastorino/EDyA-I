#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// Implementar una función que determine si una lista enlazada es palíndromo. Por ejemplo
// k → a → y → a → k → NULL
// output -> true

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

void display_list(SNode* head){
  while(head != NULL){
    printf("%c -> ", head->data);
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

// Dada una lista enlazada, convierte la misma en un string.
// k → a → y → a → k → NULL
// output: kayak
char* convertToStr(SNode* head){
  assert(head != NULL);
  int len = list_length(head);
  char* str = (char*)malloc(sizeof(char)*(len+1));
  int i = 0;
  while(head != NULL){
    str[i] = head->data;
    head = head->next;
    i++;
  }
  str[i] = '\0';
  return str;
}

bool isPalindrome(SNode* head){
  assert(head != NULL);
  char *strList = convertToStr(head);
  int len = strlen(strList);
  int i = 0, j = len - 1;
  while(i < j){
    while(!isalnum(strList[i]) && i < j){
      i++;
    }
    while(!isalnum(strList[j]) && i < j){
      j--;
    }
    if(tolower(strList[i]) != tolower(strList[j])){
      return false;
    }
    i++;
    j--;
  }
  return true;
}

void free_list(SNode* head){
  while(head != NULL){
    SNode* temp = head;
    head = head->next;
    free(temp);
  }
}

int main(){
  char palabra1[] = "kayak";
  char palabra2[] = "tortuga";

  SNode* head1 = NULL;
  SNode* head2 = NULL;

  for(int i = 0; palabra1[i] != '\0'; i++){
    insert_end(&head1, palabra1[i]);
  }

  for(int i = 0; palabra2[i] != '\0'; i++){
    insert_end(&head2, palabra2[i]);
  }

  display_list(head1);
  display_list(head2);

  bool res1 = isPalindrome(head1);
  bool res2 = isPalindrome(head2);

  printf("Palindromos:\n");

  printf("%s: %s, %s: %s\n", palabra1, res1 == 1 ? "si" : "no", palabra2, res2 == 1 ? "si" : "no");

  free_list(head1);
  free_list(head2);

  return 0;
}