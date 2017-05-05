/*******************************************************************
 *   > File Name: 31-val.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 05 May 2017 09:38:47 AM CST
 ******************************************************************/

#include <stdio.h>

void fun1(int);

int main(int argc, char* argv[])
{
    fun1(100);

    return 0;
}

void fun1(int a){
    printf("%s :%d\n", __func__, a);
}
