/*******************************************************************
 *   > File Name: fun.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sat Feb 24 17:58:47 2018
 ******************************************************************/

#include <stdio.h>

/*函数fun只能在当前文件中被调用*/
static void fun(int a, int b){
    printf("a = %d\n", a);
    printf("b = %d\n", b);
}

/*函数fun1可以该程序中所有函数调用*/
void fun1(int a, int b){
    fun(a, b);
}
