#include <stdio.h>

int main() {
    int i, legth = 0;
    char str[50];
    printf("\n문자열을 입력하세요: ");
    fgets(str, sizeof(str), stdin);
    printf("\n입력한 문자열은 \n \"" );
    for (i = 0; str[i]; i++) {
        printf("%c", str[i]);
        legth += 1;
    }
    printf("\" \n 입니다.");
    printf("\n입력한 문자열의 길이 = %d \n", legth);

    return 0;
}