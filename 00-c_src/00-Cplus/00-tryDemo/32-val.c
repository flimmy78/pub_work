/*******************************************************************
 *   > File Name: 32-val.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 05 May 2017 10:11:33 AM CST
 ******************************************************************/

#include <stdio.h>

void fun1(int a, int b){
    printf("%s :a = %d, b = %d\n",__func__, a, b);
}

int main(int argc, char* argv[])
{
    int x,y;
    x = 100;
    y = 200;
    fun1(x, y); /*值传递*/

    return 0;
}

