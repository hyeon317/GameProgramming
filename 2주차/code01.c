#include <stdio.h> 
#include <conio.h> 
int main(void)
    {
        int chr; 
        do
            {
                chr=getch();
                    if (chr==0 || chr == 0xe0) {
                        chr=getch();
                        printf("%c => 확장키 code=%d\n", chr, chr); }
                    else
                        printf("%c => 아스키 code=%d\n", chr, chr);
                }while(1); 
                
                return 0;
}