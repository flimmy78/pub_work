/*******************************************************************
 *   > File Name: 11-pointer.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年05月07日 星期一 13时28分36秒
 ******************************************************************/

#include <stdio.h>

int main(int argc, char* argv[])
{
    int var1;
    char var2[10];

    printf("var1的变量地址: %p\n", &var1);
    printf("var1的变量地址：%p\n", &var2);

    return 0;
}
