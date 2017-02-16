#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fun(void)
{
    char *str;

    str = (char*)malloc(100);
    if(NULL == str){
	printf("malloc failed!\n");
	exit(1);
    }
    strcpy(str,"hello world");

    return str;
}

int main(void)
{
    char *p;

    p = fun();
    printf("%s\n",p);
    *p = 'H';
    printf("%s\n",p);

   return 0;
}
