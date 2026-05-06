#include <stdio.h>
#include "cQueueS.h"

int main(void){
    QueueType* cQ = createCQueue();
    element data;
    printf("\n ***** 원형 큐 연산 *****\n");
    printf("\n 삽입 A>>"); enQueue(cQ, 'A'); printCQ(cQ);
    printf("\n 삽입 B>>"); enQueue(cQ, 'B'); printCQ(cQ);
    printf("\n 삽입 C>>"); enQueue(cQ, 'C'); printCQ(cQ);
    data = peekCQ(cQ); printf(" peek utem : %c \n", data);
    printf("\n 삭제 >>"); data = deQueue(cQ); printCQ(cQ);
    printf("\t 삭제데이터 : %c \n", data);
    printf("\n 삭제 >>"); data = deQueue(cQ); printCQ(cQ);
    printf("\t 삭제데이터 : %c \n", data);
    printf("\n 삭제 >>"); data = deQueue(cQ); printCQ(cQ);
    printf("\t\t 삭제데이터 : %c \n", data);
    printf("\n 삽입 D>>"); enQueue(cQ, 'D'); printCQ(cQ);
    printf("\n 삽입 E>>"); enQueue(cQ, 'E'); printCQ(cQ);
    getchar(); return 0;
}