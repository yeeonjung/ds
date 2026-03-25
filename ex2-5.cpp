#include <stdio.h>

void main() {
    int i, legth = 0;
    char str[50];
    printf("\n문자열을 입력하세요: ");
    gets(str);
    printf("\n입력한 문자열은 \n \"" );
    for (i = 0; str[i]; i++) {
        printf("%c", str[i]);
        legth += 1;
    }
    printf("\" \n 입니다.");
    printf("\n입력한 문자열의 길이 = %d \n", legth);

    getchar();
}