#include "SList_Funcs.h"

Node* merge_lists(Node* l1, Node* l2){
  if(!l1) return l2;
  if(!l2) return l1;

  if(l1->data < l2->data){
    l1->next = merge_lists(l1->next, l2);
    return l1;
  } else {
    l2->next = merge_lists(l1, l2->next);
    return l2;
  }
}

Node* merge_k_lists(Node** lists, int n){
  if(n == 0) return NULL;
  if(n == 1) return lists[0];
  if(n == 0) return merge_lists(lists[0], lists[1]);

  int mid = n / 2;
  Node* left = merge_k_lists(lists, mid);
  Node* right = merge_k_lists(lists + mid, n - mid);

  return merge_lists(left, right);
}

int main(){
  Node* head1 = create_node(5);
  head1->next = create_node(10);
  head1->next->next = create_node(15);
  head1->next->next->next = create_node(20);
  head1->next->next->next->next = create_node(25);

  Node* head2 = create_node(10);
  head2->next = create_node(20);
  head2->next->next = create_node(30);
  head2->next->next->next = create_node(40);
  head2->next->next->next->next = create_node(50);

  Node* head3 = create_node(45);
  head3->next = create_node(50);
  head3->next->next = create_node(55);
  head3->next->next->next = create_node(60);
  head3->next->next->next->next = create_node(65);

  Node* lists[] = {head1, head2, head3};
  int n = sizeof(lists) / sizeof(lists[0]);

  Node* merged_lists = merge_k_lists(lists, n);
  display_list(merged_lists);

  return 0;
}