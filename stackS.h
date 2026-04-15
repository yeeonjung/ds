#pragma once
#define STACK_SIZE 100

typedef int element;

int isStackEmpty();
int isStackFull();
void push(element item);
element pop();
element peek();
void printStack();