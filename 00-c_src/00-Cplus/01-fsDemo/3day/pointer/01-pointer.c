/*******************************************************************
 *   > File Name: 01-pointer.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Jul 2017 10:20:38 AM CST
 ******************************************************************/

#include <stdio.h>

/*说明：
 * 在C语言中，把用于存储内存地址的变量称为指针变量
 *格式：指针指向的数据类型 * 指针类型
 *任何指针在内存中只占4个字节
 * */

int main(int argc, char* argv[])
{
    int a = 100;
    //int *p = &a;  //对p初始化，即定义p的同时给p赋值

    int *p; //p中只可以存储int型数据的地址，也就是说p
    //只能指向int型的数据空间
    p = &a;

    printf("&a\t= %p\n", &a);
    printf("p \t= %p\n", p);
    printf("a \t= %d\n", a);
    printf("*p \t= %d\n", *p);

    return 0;
}
