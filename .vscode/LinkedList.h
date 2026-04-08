#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* data;
    struct Node* next;
} listNode;

typedef struct linkedList_h {
    listNode* head;
    int count;
} linkedList_h;

linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* L);
void insertLastNode(linkedList_h* L, const char* data);
listNode* searchNode(linkedList_h* L, const char* data);
void insertMiddleNode(linkedList_h* L, listNode* p, const char* data);
void deleteNode(linkedList_h* L, listNode* p);
void reverse(linkedList_h* L);
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

    listNode* current = L->head;
    printf("[ ");
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("]\n");
}

void insertLastNode(linkedList_h* L, const char* data) {
    if (L == NULL) return;
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
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
        listNode* current = L->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    L->count++;
}

listNode* searchNode(linkedList_h* L, const char* data) {
    if (L == NULL) return NULL;
    listNode* current = L->head;
    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void insertMiddleNode(linkedList_h* L, listNode* p, const char* data) {
    if (L == NULL || p == NULL) return;
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    if (newNode == NULL) return;
    newNode->data = (char*)malloc(strlen(data) + 1);
    if (newNode->data == NULL) {
        free(newNode);
        return;
    }
    strcpy(newNode->data, data);
    newNode->next = p->next;
    p->next = newNode;
    L->count++;
}

void deleteNode(linkedList_h* L, listNode* p) {
    if (L == NULL || p == NULL) return;
    
    if (L->head == p) {
        L->head = p->next;
        free(p->data);
        free(p);
        L->count--;
        return;
    }

    listNode* current = L->head;
    while (current != NULL && current->next != p) {
        current = current->next;
    }
    
    if (current != NULL) {
        current->next = p->next;
        free(p->data);
        free(p);
        L->count--;
    }
}

void reverse(linkedList_h* L) {
    if (L == NULL || L->head == NULL) return;
    
    listNode* prev = NULL;
    listNode* current = L->head;
    listNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    L->head = prev;
}

void freeLinkedList_h(linkedList_h* L) {
    if (L == NULL) return;
    listNode* current = L->head;
    while (current != NULL) {
        listNode* temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    L->head = NULL;
    L->count = 0;
}

#endif // LINKEDLIST_H
