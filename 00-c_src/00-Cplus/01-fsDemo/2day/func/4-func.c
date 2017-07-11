/*******************************************************************
 *   > File Name: 4-func.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Tue 11 Jul 2017 11:36:41 AM CST
 ******************************************************************/

#include <stdio.h>

void fun1(int* x, int* y){
    *x = 100;
    *y = 200;
}

int main(int argc, char* argv[])
{
    int a = 5, b = 3;

    printf("a = %d, b = %d\n",a,b);
    fun1(&a,&b);  //地址传递
    printf("a = %d, b = %d\n", a,b);

    return 0;
}
