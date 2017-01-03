/*******************************************************************
 *   > File Name: 01-sizeof.c
 *   > Author: fly
 *   > Mail: 1234578@qq.com
 *   > Create Time: Thu 29 Dec 2016 10:50:54 PM CST
 ******************************************************************/

#include <stdio.h>

int main(void)
{
    int ret = -1;           //定义一个整型变量，初始值为-1
    char *string = "Hello"; //定义一个字符串
    char STR[]= "Hello";

    ret = sizeof(*string);   //计算字符串在内存中的长度
    printf("ret = %d\n",ret);   //输出
    ret = sizeof(STR);
    printf("ret = %d\n",ret);   //输出
    
    return 0;
}
