/*******************************************************************
 *   > File Name: 25-globalVal.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat 25 Mar 2017 03:39:38 PM CST
 ******************************************************************/

#include <stdio.h>

int x1 = 100;
int x2;
int x3;

void fun(int x){
    int x2;
    x1 = 789;
    x2 = 123;
    x3 = 456;
}

int x2 = 200;

int main(int argc, char* argv[])
{
    fun(1);
    printf("in_main : x1= %d\n",x1);
    printf("in_main : x2= %d\n",x2);
    printf("in_main : x3= %d\n",x3);

    return 0;
}

int x3 = 300;
