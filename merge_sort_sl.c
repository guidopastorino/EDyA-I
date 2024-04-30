#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _SNode {
    int data;
    struct _SNode* next;
} SNode;

SNode* create_node(int data) {
    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    assert(newNode != NULL);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

SNode* insert_end(SNode* head, int data) {
    SNode* newNode = create_node(data);
    if (head == NULL) {
        head = newNode;
    } else {
        SNode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

void display_list(SNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// -------------------------------------------

SNode* merge(SNode* left, SNode* right) {
    SNode* result = NULL;
    if (left == NULL) return right;
    if (right == NULL) return left;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

void split(SNode* list, SNode** left, SNode** right) {
    SNode* slow;
    SNode* fast;

    if (list == NULL || list->next == NULL) {
        *left = list;
        *right = NULL;
    } else {
        slow = list;
        fast = list->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *left = list;
        *right = slow->next;
        slow->next = NULL;
    }
}

void mergeSort(SNode** head) {
    SNode* current = *head;
    SNode* left;
    SNode* right;

    if (current == NULL || current->next == NULL) return;

    split(current, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *head = merge(left, right);
}

int main() {
    SNode* head = NULL;
    head = insert_end(head, 45);
    head = insert_end(head, 30);
    head = insert_end(head, 60);
    head = insert_end(head, 20);
    head = insert_end(head, 15);

    printf("Lista original:\n");
    display_list(head);

    mergeSort(&head);

    printf("\nLista ordenada:\n");
    display_list(head);

    return 0;
}
