/*******************************************************************
 *   > File Name: FuncPoint.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 14 Apr 2017 10:57:08 AM CST
 ******************************************************************/
#if (0)
//函数指针是指向函数的指针变量
//函数指针可以像一般函数一样，用于调用函数、传递参数。
//函数指针变量的声明：
//typedef int (*fun_ptr)(int,int); // 声明一个指向同样参数、返回值
//的函数指针变量
#endif

#include <stdio.h>

int max(int x, int y){
    return (x>y?x:y);
}

int main(int argc, char* argv[])
{
    int (*p_func)(int ,int);
    p_func = max;//p_func = &max;
    int a,b,c,d;

    printf("Pls input three integers :");
    scanf("%d %d %d", &a, &b, &c);

    d= p_func(p_func(a,b), c);

    printf("the max of integer :%d\n", d);

    return 0;
}
