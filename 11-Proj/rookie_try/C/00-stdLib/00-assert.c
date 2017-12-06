/*******************************************************************
 *   > File Name: 00-assert.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Fri Nov 24 15:26:20 2017
 ******************************************************************/

#include <stdio.h>
#include <assert.h>

int main(int argc, char* argv[])
{
    int a;
    char str[50];

    printf("请输入一个整数值：");
    scanf("%d", &a);
    assert(a >= 10);
    printf("输入的整数是：%d\n", a);

    printf("请输入一个字符串：");
    scanf("%s", str);
    assert(str != NULL);
    printf("The string is :%s\n", str);

    return 0;
}
