#include <stdio.h>
#include <stdlib.h>
#include "cQueueS.h"

QueueType* createCQueue(){
    QueueType* cQ;
    cQ = (QueueType*)malloc(sizeof(QueueType));
    cQ->front = 0;
    cQ->rear = 0;
    return cQ;
}

int isCQueueFull(QueueType* cQ){
    if((cQ->rear + 1) % cQ_SIZE == cQ->front){
        printf("Circular Queue is full! \n\t");
        return 1;
    }
    else return 0;
}

int isCqueueEmpty(QueueType* cQ){
    if(cQ->front == cQ->rear){
        printf("Circular Queue is empty! \n\t");
        return 1;
    }
    else return 0;
}

void enQueue(QueueType* cQ, element item){
    if(isCQueueFull(cQ)) return;
    else {
        cQ->rear = (cQ->rear + 1) % cQ_SIZE;
        cQ->queue[cQ->rear] = item;
    }
}

element deQueue(QueueType* cQ){
    if(isCqueueEmpty(cQ)) return 0;
    else {
        cQ->front = (cQ->front + 1) % cQ_SIZE;
        return cQ->queue[cQ->front];
    }
}

element peekCQ(QueueType* cQ){
    if(isCqueueEmpty(cQ)) exit(1);
    else return cQ->queue[(cQ->front + 1) % cQ_SIZE];
}

void printCQ(QueueType* cQ){
    int i, first, last;
    first = (cQ->front + 1) % cQ_SIZE;
    last = (cQ->rear + 1) % cQ_SIZE;
    printf("Circular Queue : [");
    i = first;
    while(i != last){
        printf("%3c ", cQ->queue[i]);
        i = (i + 1) % cQ_SIZE;
    }
    printf("]\n");
}