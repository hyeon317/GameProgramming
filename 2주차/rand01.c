#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
int main(void)
{
    int i; 
    srand(time(NULL)); 
    for(i=1;i<=10;i++)
        printf("%2d:%d\n",i, rand()%6+1);  // +1인 이유는 수가 0부터 %숫자-1 까지의 수이기 때문에 +1
    return 0;
}