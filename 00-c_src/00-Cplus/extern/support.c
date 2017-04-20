/*******************************************************************
 *   > File Name: support.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 20 Apr 2017 03:57:13 PM CST
 ******************************************************************/

#include <stdio.h>

extern int count;

void write_extern(void){
    printf("count is %d\n", count);
}
