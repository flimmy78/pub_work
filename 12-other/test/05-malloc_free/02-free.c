/*******************************************************************
 *   > File Name: 02-free.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Jul 2017 10:04:16 AM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun1(char *p){
    strcpy(p, "hello");
    printf("%s\n", p);
    free(p);
}
