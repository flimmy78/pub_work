/*******************************************************************
 *   > File Name: 02-MemMap.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 09 Feb 2017 11:16:49 AM CST
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a = 0;//全局初始化区
char *p1;//全局未初始化区

int main(int argc, char* argv[])
{
    int b;  //栈
    char s[] = "abc";//栈
    char *p2;   //栈
    char *p3 = "123456";//123456\0在常量区，p3在栈上
    static int c = 0;//全局静态初始化区
    p1 = (char*)malloc(10);
    p2 = (char*)malloc(20);//分配来的10/20字节区域就在堆区
    strcpy(p1,"123456");    //123456\0放在常量区，编译器可能会将它与p3所向"123456"优化成一个 地方。

    return 0;
}
