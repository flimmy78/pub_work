/*******************************************************************
 *   > File Name: 02-pointer.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri 21 Jul 2017 10:35:55 AM CST
 ******************************************************************/

#include <stdio.h>

/*指针运算：
 *两个同类型的指针不能做加法运算，指针只能与整数相加
 *例如：pa + 1  //正确，表示pa中的地址向高地址方向偏移1倍的pa指向的
 *空间大小（长度）
 *
 * */

int main(int argc, char* argv[])
{
    int a = 100;
    int *pa = &a;   //对P初始化，即定义p的同时给p赋值

    printf("pa = %p\n", pa);
    printf("pa + 1 = %p\n", pa + 1);
    printf("pa + 3 = %p\n", pa + 3);
    printf("*pa = %d\n", *pa);
    printf("*************************\n");

    short b = 50;
    short *pb = &b;
    printf("pb = %p\n", pb);
    printf("pb + 1 = %p\n", pb + 1);
    printf("pb + 3 = %p\n", pb + 3);
    printf("*pa = %hd\n", *pb);
    printf("*************************\n");

    double c = 12.34;
    double *pc = &c;
    printf("pc = %p\n", pc);
    printf("pc + 1 = %p\n", pc + 1);
    printf("pc + 3 = %p\n", pc + 3);
    printf("*pc = %lf\n", *pc);
    printf("************************\n");

    return 0;
}
