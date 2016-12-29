/*******************************************************************
 *   > File Name: 00-hello.c
 *   > Author: fly
 *   > Mail: 1234578@qq.com
 *   > Create Time: Thu 29 Dec 2016 10:08:56 PM CST
 ******************************************************************/

#include <stdio.h>              //预处理指令，告诉C编译器在实际编译之
                                //前要包含stdio.h文件

int main(void)                  //主函数，程序从这里开始执行
{
    /*这是一个C程序*/
    printf("\n\tHello , world !\n\n");//C中的另一个函数，在屏幕输出“Hello ， world ！”；

    return 0;                   //终止main函数，并返回0
}
