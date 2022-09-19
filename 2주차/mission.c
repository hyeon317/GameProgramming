// 연달아 문자 입력을 받는 중 Enter를 입력받으면 종료
// while문 사용

#include <stdio.h>

int main() {
    char c;
    
    while(1) {
        printf("문자 입력 > ");
        scanf(" %c", &c);

        if(c == "\n") break;

        printf("입력한 문자는 %c입니다", c);
        scanf(" %c", &c);
    }
    printf("Good Bye\n");
    return 0;
    }