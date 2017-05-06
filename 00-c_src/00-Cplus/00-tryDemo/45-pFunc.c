/*******************************************************************
 *   > File Name: 45-pFunc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat 06 May 2017 03:24:22 PM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fun(void){
    char *str;

    str = (char*)malloc(100);
    if(NULL == str){
        printf("malloc failed !\n");exit(1);
    }
    strcpy(str, "hello world");

    return str;
}

int main(int argc, char* argv[])
{
    char *p;

    p = fun();
    printf("%s\n", p);
    *p = 'H';
    printf("%s\n", p);

    return 0;
}
