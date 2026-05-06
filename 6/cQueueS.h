#pragma once
#define cQ_SIZE 4

typedef char element;

typedef struct {
    element queue[cQ_SIZE];
    int front, rear;
} QueueType;

QueueType* createCQueue();
int isCqueueEmpty(QueueType* cQ);
int isCQueueFull(QueueType* cQ);
void enQueue(QueueType* cQ, element item);
element deQueue(QueueType* cQ);
element peekCQ(QueueType* cQ);
void printCQ(QueueType* cQ);