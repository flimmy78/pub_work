/*******************************************************************
 *   > File Name: ifdef.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Sun 17 Sep 2017 02:51:43 PM CST
 ******************************************************************/

#include <stdio.h>

#define     DEBUG

//有如下两个函数，如果要测试这两个函数是否正确，则必须写主函数测试
void fun1(void){
    printf("hello world\n");
}

void fun2(void){
    printf("This is a good idea !\n");
}

//下面为测试代码
#ifdef  DEBUG
int main(int argc, char* argv[])
{
    fun1();
    fun2();

    return 0;
}
#endif
