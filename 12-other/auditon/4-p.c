/*******************************************************************
 *   > File Name: 4-p.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu Jul 13 18:59:55 2017
 ******************************************************************/

#include <stdio.h>

char* get_mem1(){
    char p[] = "hello world";
    return p;
}

char* get_mem2(){
    char* p = "hello world";
    return p;
}

int main(int argc, char* argv[])
{
    printf("%s, %s\n", get_mem1(), get_mem2());

    return 0;
}
