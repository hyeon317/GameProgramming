#include <stdio.h>

int main()
{
    char string[20];
    char c;

    printf("문자열 입력 > ");
    scanf("%s", string);

    printf("문자 입력 > ");
    scanf(" %c", &c);

    printf("%s\n", string);
    printf("!!%c!!]=\n", c);

    return 0;
}