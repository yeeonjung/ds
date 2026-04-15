#include <stdlib.h>
#include "stackL.h"

int isStackEmpty() {
    if (top == NULL) return 1;
    else return 0;
}

void push(element item) {
    stackNode* temp = (stackNode*)malloc(sizeof(stackNode));

    temp->data = item;
    temp->link = top;
    top = temp;
}

element pop() {
    element item;
    stackNode* temp = top;
    
    if (isStackEmpty()) {
        printf("\n\n Stack is empty ! \n");
        return 0;
    }
    else {
        item = temp->data;
        top = temp->link;
        free(temp);
        return item;
    }
}

element peek() {
    if (isStackEmpty()){
        printf("\n\n Stack is empty ! \n");
        return 0;
    }
    else return(top->data);
}

void printStack() {
    stackNode* p;
    printf("\n STACK [ ");
    for (p = top; p != NULL; p = p->link)
        printf(" %d ", p->data);
    printf("] ");
}