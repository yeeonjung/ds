#ifndef INSERTLINKEDLIST_H
#define INSERTLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* data;
    struct Node* next;
} Node;

typedef struct linkedList_h {
    Node* head;
    int count;
} linkedList_h;

linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* L);
void insertFirstNode(linkedList_h* L, const char* data);
void insertLastNode(linkedList_h* L, const char* data);
void freeLinkedList_h(linkedList_h* L);

linkedList_h* createLinkedList_h(void) {
    linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
    if (L == NULL) return NULL;
    L->head = NULL;
    L->count = 0;
    return L;
}

void printList(linkedList_h* L) {
    if (L == NULL) {
        printf("리스트가 존재하지 않습니다.\n");
        return;
    }
    if (L->head == NULL) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }

    Node* current = L->head;
    printf("[ ");
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("]\n");
}

void insertFirstNode(linkedList_h* L, const char* data) {
    if (L == NULL) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = (char*)malloc(strlen(data) + 1);
    if (newNode->data == NULL) {
        free(newNode);
        return;
    }
    strcpy(newNode->data, data);
    newNode->next = L->head;
    L->head = newNode;
    L->count++;
}

void insertLastNode(linkedList_h* L, const char* data) {
    if (L == NULL) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = (char*)malloc(strlen(data) + 1);
    if (newNode->data == NULL) {
        free(newNode);
        return;
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (L->head == NULL) {
        L->head = newNode;
    } else {
        Node* current = L->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    L->count++;
}

void freeLinkedList_h(linkedList_h* L) {
    if (L == NULL) return;
    Node* current = L->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    L->head = NULL;
    L->count = 0;
}

#endif // INSERTLINKEDLIST_H
