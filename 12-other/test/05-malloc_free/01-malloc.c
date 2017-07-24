/*******************************************************************
 *   > File Name: 01-malloc.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Jul 2017 09:59:56 AM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fun(int size){
    char *p;

    p = (char*)malloc(size);
    if(NULL == p){
        printf("malloc failed !\n");
        exit(1);
    }

    return p;
}

extern void fun1(char *);
int main(int argc, char* argv[])
{
    char *str;

    str = fun(100);
    fun1(str);

    strcpy(str, "world");   //非法操作
    printf("%s\n", str);    //非法操作

    return 0;
}
