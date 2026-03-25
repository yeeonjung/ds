#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() 
{
    int i = 0, n;
    int multiply[9];

    printf("\n1~9의 정수를 입력하세요: ");

    while (1) {
        scanf ("%d", &n);
        if (n < 0 || n >9)
            printf("\n1~9의 정수를 입력하세요: ");
            
    }

}