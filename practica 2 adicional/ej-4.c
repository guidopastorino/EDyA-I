// DETECT A LOOP IN A CIRCULAR LINKED LIST
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _CNode
{
  int data;
  struct _CNode *next;
} CNode;

CNode *create_node(int data)
{
  CNode *newNode = (CNode *)malloc(sizeof(CNode));
  assert(newNode != NULL);
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void display_list(CNode *head)
{
  CNode *current = head;
  do
  {
    printf("%d ", current->data);
    current = current->next;
  } while (current != head);
  printf("\n");
}

CNode* detect_loop(CNode* list){
  assert(list != NULL && list->next != NULL);
  CNode *slowPtr = list, *fastPtr = list;
  slowPtr = slowPtr->next;
  fastPtr = fastPtr->next->next;
  while(slowPtr && fastPtr && fastPtr->next){
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
    if(slowPtr == fastPtr){
      break;
    }
  }
  if(slowPtr != fastPtr){
    return NULL;
  }
  slowPtr = list;
  while(slowPtr != fastPtr){
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next;
  }
  return slowPtr;
}


int main()
{
  CNode* first = create_node(1);
  CNode* second = create_node(2);
  CNode* third = create_node(3);
  CNode* fourth = create_node(4);
  CNode* fifth = create_node(5);
  
  // lets suppose the following list
  // 1 -> 2 -> 3 -> 4 -> 5
  //            ↖       ↙
  //             ↖     ↙
  //              ↖   ↙
  //               ↖ ↙
  
  // There is a loop starting node 3 (the loop nodes are: 3, 4, 5)
  
  first->next = second;
  second->next = third;
  third->next = fourth; // loop starts here
  fourth->next = fifth;
  fifth->next = third;

  // if we try to print this, we will get the following output:
  // display_list(first); // -> 1 2 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 3 4 5 ... 
  // There will be a loop between 3 and 4.

  CNode* loopNode = detect_loop(first);
  if(loopNode != NULL){
    printf("Loop starts at node: %d\n", loopNode->data);
  } else {
    printf("There is no loop in the list.\n");
  }

  return 0;
}

// How do you find the loop in the linked list?
// A loop can be detected by using a slow and fast pointer algorithm. In this algorithm, a slow pointer moves by one node and a fast pointer moves by two nodes and at any point, when the slow and fast pointer points to the same node, it means the loop is detected at that node and if the fast pointer reaches to end, it means linked list doesn’t contain the loop.