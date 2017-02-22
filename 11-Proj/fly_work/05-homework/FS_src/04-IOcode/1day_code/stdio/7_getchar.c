#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    char ch;

   while((ch = getchar()) != '#')
       //printf("%c",ch);
       putchar(ch);
    
    return 0;
}
