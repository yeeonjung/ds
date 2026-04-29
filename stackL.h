#include guard
#ifndef __STACKL_H__
#define __STACKL_H__

typedef int element;

typedef struct stackNode {
    element data;
    struct stackNode* link;
} stackNode;

stackNode* top;

int isStackEmpty();
void push(element item);
element pop();
element peek();
void printStack();

#endif // __STACKL_H__